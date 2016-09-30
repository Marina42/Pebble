static void draw_vertical_flag_proc(Layer *layer, GContext *ctx){
  //GRect bounds = layer_get_unobstructed_bounds(layer);
  graphics_context_set_fill_color(ctx, GColorFolly);
  GRect rect = GRect(0,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorRajah);
  rect = GRect(5,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorIcterine);
  rect = GRect(10,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorMalachite);
  rect = GRect(15,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorVividCerulean);
  rect = GRect(20,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, GColorVividViolet);
  rect = GRect(25,0,5,168);
  graphics_fill_rect(ctx, rect, 0, GCornerNone);
}

static void draw_horizontal_flag_proc (Layer *layer, GContext *ctx){
    GRect bounds = (GRect)(layer_get_bounds(layer));
    GRect unoBounds = (GRect)(layer_get_unobstructed_bounds(layer));
    int16_t offset = bounds.size.h - unoBounds.size.h;

    graphics_context_set_fill_color(ctx, GColorFolly);
    GRect rect = GRect(5,163-offset,163,5);
    graphics_fill_rect(ctx, rect, 0, GCornerNone);
    graphics_context_set_fill_color(ctx, GColorRajah);
    rect = GRect(10,158-offset,158,5);
    graphics_fill_rect(ctx, rect, 0, GCornerNone);
    graphics_context_set_fill_color(ctx, GColorIcterine);
    rect = GRect(15,153-offset,153,5);
    graphics_fill_rect(ctx, rect, 0, GCornerNone);
    graphics_context_set_fill_color(ctx, GColorMalachite);
    rect = GRect(20,148-offset,148,5);
    graphics_fill_rect(ctx, rect, 0, GCornerNone);
    graphics_context_set_fill_color(ctx, GColorVividCerulean);
    rect = GRect(25,143-offset,143,5);
    graphics_fill_rect(ctx, rect, 0, GCornerNone);
    graphics_context_set_fill_color(ctx, GColorVividViolet);
    rect = GRect(30,138-offset,138,5);
    graphics_fill_rect(ctx, rect, 0, GCornerNone);
}
