#include "main_window_rect.h"
#include "modules/flag.h"

static Window *s_window;
static Layer *s_flag_layer;
static TextLayer *s_time_layer;
static GFont s_res_hour_font_big;
static GFont s_res_hour_font_small;

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

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time(-1);
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
}

static void window_load(Window *window) {
  UnobstructedAreaHandlers handler = {
    .change = prv_unobstructed_change
  };
  unobstructed_area_service_subscribe(handler, NULL);
  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);

  s_res_hour_font_big =  fonts_load_custom_font(resource_get_handle(RESOURCE_ID_HOUR_FONT_55));
  s_res_hour_font_small =  fonts_load_custom_font(resource_get_handle(RESOURCE_ID_HOUR_FONT_40));

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  window_set_background_color(s_window, GColorBlack);

  s_flag_layer = layer_create(bounds);
  layer_set_update_proc(s_flag_layer, draw_flag_proc);
  layer_add_child(window_layer, s_flag_layer);
  layer_mark_dirty(s_flag_layer);

  //s_time_layer = text_layer_create(GRect(27, 0, 150, 50));

  // hour_layer
  s_time_layer = text_layer_create(GRect(32, 7, 130, 150));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorWhite);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentLeft);
  adapt_time_layer_proc();
  update_time(-1);
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  //text_layer_mark_dirty(s_time_layer);

}

static void window_unload(Window *window) {
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
