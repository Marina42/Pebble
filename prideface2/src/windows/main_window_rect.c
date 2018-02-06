#include "main_window_rect.h"
#include "modules/flag.h"


static Window *s_window;
static Layer *s_flag_layer;
static TextLayer *s_time_layer;
static TextLayer *s_date_layer;
static TextLayer *s_battery_text_layer;
static GFont s_res_hour_font_big;
static GFont s_res_hour_font_small;
static GFont s_res_date_font;
static GFont s_res_battery_font;
static char *dateFormat = "%m-%d";
static GBitmap *s_res_battery_100;
static GBitmap *s_res_bt_disconnect;
static BitmapLayer *battery_layer;
static uint16_t last_charge_level;
static BitmapLayer *no_bt_layer;

void handle_bluetooth(bool connected){
  if (connected) {
    layer_set_hidden(bitmap_layer_get_layer(no_bt_layer), true);
  }
  else {
    vibes_double_pulse();
    layer_set_hidden(bitmap_layer_get_layer(no_bt_layer), false);
  }
}

void adapt_bt_proc(){
  if (connection_service_peek_pebble_app_connection()) {
    layer_set_hidden(bitmap_layer_get_layer(no_bt_layer), true);
  }
  else {
    layer_set_hidden(bitmap_layer_get_layer(no_bt_layer), false);
    Layer *window_layer = window_get_root_layer(s_window);
    GRect fullscreen = layer_get_bounds(window_layer);
    GRect unobstructed_bounds = layer_get_unobstructed_bounds(window_layer);
    int16_t obstruction_height = fullscreen.size.h - unobstructed_bounds.size.h;

    if (obstruction_height > 0){
      layer_set_frame(bitmap_layer_get_layer(no_bt_layer), GRect(25, 125-obstruction_height, 25, 15));
    }
    else {
      layer_set_frame(bitmap_layer_get_layer(no_bt_layer), GRect(125, 50, 25, 15));
    }
  }
}

void reset_charge_level(){
  last_charge_level = 0;
}

void adapt_battery_proc(){
  Layer *window_layer = window_get_root_layer(s_window);
  GRect fullscreen = layer_get_bounds(window_layer);
  GRect unobstructed_bounds = layer_get_unobstructed_bounds(window_layer);
  int16_t obstruction_height = fullscreen.size.h - unobstructed_bounds.size.h;

  if (obstruction_height > 0){
    layer_set_frame(text_layer_get_layer(s_battery_text_layer),GRect(70, 125-obstruction_height, 50, 20));
    layer_set_frame(bitmap_layer_get_layer(battery_layer), GRect(120, 120-obstruction_height, 25, 15));
  }
  else {
    layer_set_frame(text_layer_get_layer(s_battery_text_layer),GRect(95, 23, 50, 20));
    layer_set_frame(bitmap_layer_get_layer(battery_layer), GRect(120, 35, 25, 15));
  }
}

void set_bitmap_for_charge_level (BatteryChargeState charge){
  static char battery_buffer[] = "100%%";
  snprintf(battery_buffer, 5, "%d%%", charge.charge_percent);
  text_layer_set_text(s_battery_text_layer, battery_buffer);

  if (charge.is_charging){
    s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_CHARGING);
    bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);

  }
  else if (charge.charge_percent > 82){
    if (last_charge_level != 100){
      s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_100);
      bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
      last_charge_level = 100;
    }
  }
  else if (charge.charge_percent <= 82 && charge.charge_percent > 64){
    if (last_charge_level != 82){
      s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_82);
      bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
      last_charge_level = 82;
    }
  }
  else if (charge.charge_percent <= 64 && charge.charge_percent > 48){
    if (last_charge_level != 64){
      s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_64);
      bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
      last_charge_level = 64;
    }
  }
  else if (charge.charge_percent <= 48 && charge.charge_percent > 32){
    if (last_charge_level != 48){
      s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_48);
      bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
      last_charge_level = 48;
    }
  }
  else if (charge.charge_percent <= 32 && charge.charge_percent > 16){
    if (last_charge_level != 32){
      s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_32);
      bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
      last_charge_level = 32;
    }
  }
  else if (charge.charge_percent <= 16 && charge.charge_percent > 5){
    if (last_charge_level != 16){
      s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_16);
      bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
      last_charge_level = 16;
    }
  }
  else if (charge.charge_percent <= 5){
    if (last_charge_level != 5){
      s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_5);
      bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
      last_charge_level = 5;
    }
  }
}

void update_date(struct tm* tick_time) {
  static char date_text[] = "00-00";
  strftime(date_text, sizeof(date_text), dateFormat, tick_time);
  text_layer_set_text(s_date_layer, date_text);
}

static void update_time(int obstruct) {
  // Get a tm structure
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);

  // Write the current hours and minutes into a buffer
  static char s_buffer[8];
  if (obstruct == -1){
    Layer *window_layer = window_get_root_layer(s_window);
    GRect fullscreen = layer_get_bounds(window_layer);
    GRect unobstructed_bounds = layer_get_unobstructed_bounds(window_layer);
    int16_t obstruction_height = fullscreen.size.h - unobstructed_bounds.size.h;
    obstruct = obstruction_height;
  }
  if (obstruct > 0){
  strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style() ?
                                          "%H:%M" : "%I:%M", tick_time);
  }
  else {
    strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style() ?
                                            "%H\n%M" : "%I\n%M", tick_time);
  }

  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, s_buffer);
}

static void time_handler(struct tm *tick_time, TimeUnits units_changed) {
  if (units_changed & MINUTE_UNIT){
    update_time(-1);
  }
  if (units_changed & DAY_UNIT){
    update_date(tick_time);
  }
}

static void adapt_time_layer_proc(){
  Layer *window_layer = window_get_root_layer(s_window);
  GRect fullscreen = layer_get_bounds(window_layer);
  GRect unobstructed_bounds = layer_get_unobstructed_bounds(window_layer);
  int16_t obstruction_height = fullscreen.size.h - unobstructed_bounds.size.h;

  if (obstruction_height > 0){
    text_layer_set_text(s_time_layer, "19:58");
    text_layer_set_font(s_time_layer, s_res_hour_font_small);
    update_time(obstruction_height);
  }
  else {
    text_layer_set_text(s_time_layer, "19\n58");
    text_layer_set_font(s_time_layer, s_res_hour_font_big);
    update_time(obstruction_height);
  }
}

static void draw_flag_proc(Layer *layer, GContext *ctx){
  draw_vertical_flag_proc(layer,ctx);
  draw_horizontal_flag_proc(layer, ctx);
}

static void prv_unobstructed_change(AnimationProgress progress, void *context){
  layer_mark_dirty(s_flag_layer);
  adapt_time_layer_proc();
  adapt_battery_proc();
  adapt_bt_proc();
}

static void window_load(Window *window) {
  /* Initiate KiezelPay
  kiezelpay_init();

  // Open AppMessage channel with pebble-events package
  events_app_message_open();

  kiezelpay_start_purchase();*/

  UnobstructedAreaHandlers handler = {
    .change = prv_unobstructed_change
  };
  unobstructed_area_service_subscribe(handler, NULL);
  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, time_handler);
  // Register for battery level updates
  battery_state_service_subscribe(set_bitmap_for_charge_level);



  connection_service_subscribe((ConnectionHandlers) {
    .pebble_app_connection_handler = handle_bluetooth
  });



  s_res_hour_font_big =  fonts_load_custom_font(resource_get_handle(RESOURCE_ID_HOUR_FONT_55));
  s_res_hour_font_small =  fonts_load_custom_font(resource_get_handle(RESOURCE_ID_HOUR_FONT_40));
  s_res_date_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_DATE_FONT_20));
  s_res_battery_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_BATTERY_FONT_10));
  s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_100);
  s_res_bt_disconnect = gbitmap_create_with_resource(RESOURCE_ID_BT_DISCONNECT);


  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  window_set_background_color(s_window, GColorBlack);

  s_flag_layer = layer_create(bounds);
  layer_set_update_proc(s_flag_layer, draw_flag_proc);
  layer_add_child(window_layer, s_flag_layer);
  layer_mark_dirty(s_flag_layer);

  //s_time_layer = text_layer_create(GRect(27, 0, 150, 50));

  // hour_layer
  s_time_layer = text_layer_create(GRect(32, 11, 130, 150));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorWhite);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentLeft);
  adapt_time_layer_proc();
  update_time(-1);
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  //text_layer_mark_dirty(s_time_layer);

  s_battery_text_layer = text_layer_create(GRect(95, 23, 50, 20));
  text_layer_set_background_color(s_battery_text_layer, GColorClear);
  text_layer_set_text_color(s_battery_text_layer, GColorWhite);
  text_layer_set_text(s_battery_text_layer, "100%%");
  text_layer_set_text_alignment(s_battery_text_layer, GTextAlignmentRight);
  text_layer_set_font(s_battery_text_layer, s_res_battery_font);
  layer_add_child(window_layer, text_layer_get_layer(s_battery_text_layer));

  // date_layer
  s_date_layer = text_layer_create(GRect(65, 0, 100, 26));
  text_layer_set_background_color(s_date_layer, GColorClear);
  text_layer_set_text_color(s_date_layer, GColorWhite);
  text_layer_set_text(s_date_layer, "08/13");
  text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);
  text_layer_set_font(s_date_layer, s_res_date_font);
  layer_add_child(window_layer, text_layer_get_layer(s_date_layer));

  time_t now = time(NULL);
  struct tm *current_time = localtime(&now);
  update_date(current_time);

  // no_bt_layer
  no_bt_layer = bitmap_layer_create(GRect(125, 50, 25, 15));
  bitmap_layer_set_bitmap(no_bt_layer, s_res_bt_disconnect);
  layer_add_child(window_layer, bitmap_layer_get_layer(no_bt_layer));

  // battery_layer
  battery_layer = bitmap_layer_create(GRect(120, 35, 25, 15));
  bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
  layer_add_child(window_layer, bitmap_layer_get_layer(battery_layer));

  //last_charge_level = 0;
  reset_charge_level();
  BatteryChargeState charge = battery_state_service_peek();
  set_bitmap_for_charge_level(charge);

  adapt_battery_proc();
  adapt_bt_proc();

}

static void window_unload(Window *window) {
//   kiezelpay_deinit();
  window_destroy(s_window);
}

void main_window_rect_push() {
  if(!s_window) {
    s_window = window_create();
    window_set_window_handlers(s_window, (WindowHandlers) {
      .load = window_load,
      .unload = window_unload,
    });
  }
  window_stack_push(s_window, false);
}
