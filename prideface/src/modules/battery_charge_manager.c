#include <pebble.h>

static uint16_t last_charge_level;

void reset_charge_level(){
  last_charge_level = 0;
}

void set_bitmap_for_charge_level (BatteryChargeState charge, GBitmap &s_res_battery_100){
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
