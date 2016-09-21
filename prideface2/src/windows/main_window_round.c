#include "main_window_round.h"

static Window *s_window;
static Layer *s_flag_layer;

static void draw_flag(Layer *layer, GContext *ctx) {
  GRect bounds = layer_get_bounds(layer);
  GRect frame = grect_inset(bounds, GEdgeInsets(2));
  graphics_context_set_fill_color(ctx, GColorMagenta);
  graphics_fill_radial(ctx, frame, GOvalScaleModeFitCircle, 5,
                                  DEG_TO_TRIGANGLE(-220), DEG_TO_TRIGANGLE(-45));
  frame = grect_inset(bounds, GEdgeInsets(7));
  graphics_context_set_fill_color(ctx, GColorCyan);
  graphics_fill_radial(ctx, frame, GOvalScaleModeFitCircle, 5,
                                  DEG_TO_TRIGANGLE(-220), DEG_TO_TRIGANGLE(-45));
  frame = grect_inset(bounds, GEdgeInsets(12));
  graphics_context_set_fill_color(ctx, GColorMintGreen);
  graphics_fill_radial(ctx, frame, GOvalScaleModeFitCircle, 5,
                                  DEG_TO_TRIGANGLE(-220), DEG_TO_TRIGANGLE(-45));
  frame = grect_inset(bounds, GEdgeInsets(17));
  graphics_context_set_fill_color(ctx, GColorPastelYellow);
  graphics_fill_radial(ctx, frame, GOvalScaleModeFitCircle, 5,
                                  DEG_TO_TRIGANGLE(-220), DEG_TO_TRIGANGLE(-45));
  frame = grect_inset(bounds, GEdgeInsets(22));
  graphics_context_set_fill_color(ctx, GColorRajah);
  graphics_fill_radial(ctx, frame, GOvalScaleModeFitCircle, 5,
                                  DEG_TO_TRIGANGLE(-220), DEG_TO_TRIGANGLE(-45));
  frame = grect_inset(bounds, GEdgeInsets(27));
  graphics_context_set_fill_color(ctx, GColorFolly);
  graphics_fill_radial(ctx, frame, GOvalScaleModeFitCircle, 5,
                                DEG_TO_TRIGANGLE(-220), DEG_TO_TRIGANGLE(-45));
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  window_set_background_color(s_window, GColorLightGray);

  s_flag_layer = layer_create(bounds);
  layer_set_update_proc(s_flag_layer, draw_flag);
  layer_add_child(window_layer, s_flag_layer);
  layer_mark_dirty(s_flag_layer);
}

static void window_unload(Window *window) {
  window_destroy(s_window);
  //bitmap_layer_destroy(s_flag_layer);
}

void main_window_round_push() {
  if(!s_window) {
    s_window = window_create();
    window_set_window_handlers(s_window, (WindowHandlers) {
      .load = window_load,
      .unload = window_unload,
    });
  }
  window_stack_push(s_window, true);
}
