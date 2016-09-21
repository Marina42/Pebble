#include "main_window_rect.h"
#include "resources/flag.h"

static Window *s_window;
static Layer *s_flag_layer;

static void draw_flag_proc(Layer *layer, GContext *ctx){
  draw_vertical_flag_proc(layer,ctx);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_unobstructed_bounds(window_layer);
  window_set_background_color(s_window, GColorLightGray);

  s_flag_layer = layer_create(bounds);
  layer_set_update_proc(s_flag_layer, draw_flag_proc);
  layer_add_child(window_layer, s_flag_layer);
  layer_mark_dirty(s_flag_layer);
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
