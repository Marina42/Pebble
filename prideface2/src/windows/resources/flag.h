static void draw_vertical_flag_proc(Layer *layer, GContext *ctx){
  //GRect bounds = layer_get_unobstructed_bounds(layer);
  graphics_context_set_fill_color(ctx, GColorRed);
  GRect rect = GRect(0,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorOrange);
  rect = GRect(5,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorPastelYellow);
  rect = GRect(10,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorMintGreen);
  rect = GRect(15,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorCyan);
  rect = GRect(20,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorMagenta);
  rect = GRect(25,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
}
