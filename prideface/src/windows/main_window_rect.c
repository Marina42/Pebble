#include <pebble.h>
#include "main_window_rect.h"
#include "battery_charge_manager.h"

static char *dateFormat = "%m-%d-%y";
static Window *s_window;
static GBitmap *s_res_background_img;
static GFont s_res_hour_font_48;
static GBitmap *s_res_battery_100;
static GBitmap *s_res_bt_disconnect;
static GFont s_res_date_font_20;
static BitmapLayer *background_layer;
static TextLayer *hour_layer;
static BitmapLayer *battery_layer;
static BitmapLayer *no_bt_layer;
static TextLayer *date_layer;

static void initialise_ui(void) {
  s_window = window_create();
  #ifndef PBL_SDK_3
    window_set_fullscreen(s_window, true);
  #endif

  s_res_background_img = gbitmap_create_with_resource(RESOURCE_ID_BACKGROUND_IMG);
  s_res_hour_font_48 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_HOUR_FONT_48));
  s_res_battery_100 = gbitmap_create_with_resource(RESOURCE_ID_BATTERY_100);
  s_res_bt_disconnect = gbitmap_create_with_resource(RESOURCE_ID_BT_DISCONNECT);
  s_res_date_font_20 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_DATE_FONT_20));
  // background_layer
  background_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(background_layer, s_res_background_img);
  layer_add_child(window_get_root_layer(s_window), (Layer *)background_layer);

  // hour_layer
  hour_layer = text_layer_create(GRect(32, -18, 112, 53));
  text_layer_set_background_color(hour_layer, GColorClear);
  text_layer_set_text_color(hour_layer, GColorWhite);
  text_layer_set_text(hour_layer, "19:58");
  text_layer_set_text_alignment(hour_layer, GTextAlignmentCenter);
  text_layer_set_font(hour_layer, s_res_hour_font_48);
  layer_add_child(window_get_root_layer(s_window), (Layer *)hour_layer);

  // battery_layer
  battery_layer = bitmap_layer_create(GRect(0, 3, 25, 15));
  bitmap_layer_set_bitmap(battery_layer, s_res_battery_100);
  layer_add_child(window_get_root_layer(s_window), (Layer *)battery_layer);

  // no_bt_layer
  no_bt_layer = bitmap_layer_create(GRect(0, 19, 10, 10));
  bitmap_layer_set_bitmap(no_bt_layer, s_res_bt_disconnect);
  layer_add_child(window_get_root_layer(s_window), (Layer *)no_bt_layer);

  // date_layer
  date_layer = text_layer_create(GRect(55, 32, 100, 26));
  text_layer_set_background_color(date_layer, GColorClear);
  text_layer_set_text_color(date_layer, GColorWhite);
  text_layer_set_text(date_layer, "08-07-15");
  text_layer_set_text_alignment(date_layer, GTextAlignmentCenter);
  text_layer_set_font(date_layer, s_res_date_font_20);
  layer_add_child(window_get_root_layer(s_window), (Layer *)date_layer);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  bitmap_layer_destroy(background_layer);
  text_layer_destroy(hour_layer);
  bitmap_layer_destroy(battery_layer);
  bitmap_layer_destroy(no_bt_layer);
  text_layer_destroy(date_layer);
  gbitmap_destroy(s_res_background_img);
  fonts_unload_custom_font(s_res_hour_font_48);
  gbitmap_destroy(s_res_battery_100);
  gbitmap_destroy(s_res_bt_disconnect);
  fonts_unload_custom_font(s_res_date_font_20);
}
// END AUTO-GENERATED UI CODE

void change_time(struct tm* tick_time){
  static char time_text[] = "00:00"; // Needs to be static because it's used by the system later.
  clock_copy_time_string(time_text, 6);
  text_layer_set_text(hour_layer, time_text);
}

void change_date(struct tm* tick_time) {
  static char date_text[] = "00-00-00";
  strftime(date_text, sizeof(date_text), dateFormat, tick_time);
  text_layer_set_text(date_layer, date_text);
}

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_main_window(void) {
  initialise_ui();

  time_t now = time(NULL);
  struct tm *current_time = localtime(&now);
  change_date(current_time);

  static char time_text[] = "00:00"; // Needs to be static because it's used by the system later.
  clock_copy_time_string(time_text, 6);
  text_layer_set_text(hour_layer, time_text);

  if (bluetooth_connection_service_peek()) {
    layer_set_hidden((Layer *)no_bt_layer, false);
  }
  else {
    layer_set_hidden((Layer *)no_bt_layer, false);
  }

  //last_charge_level = 0;
  reset_charge_level();
  BatteryChargeState charge = battery_state_service_peek();
  set_bitmap_for_charge_level(charge, s_res_battery_100);

  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_main_window(void) {
  window_stack_remove(s_window, true);
}

void handle_bluetooth(bool connected){
  if (connected) {
    layer_set_hidden((Layer *)no_bt_layer, true);
  }
  else {
    vibes_double_pulse();
    layer_set_hidden((Layer *)no_bt_layer, false);
  }
}

/*void set_bitmap_for_charge_level (BatteryChargeState charge){
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
}*/
