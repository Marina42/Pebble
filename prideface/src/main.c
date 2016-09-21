#include <pebble.h>
#include "modules/kiezelpay.h"
#include "windows/main_window_rect.h"
#include "windows/main_window_round.h"



static void handle_time (struct tm* tick_time, TimeUnits units_changed) {
  if (units_changed & MINUTE_UNIT){
    change_time(tick_time);
  }
  if (units_changed & DAY_UNIT){
    change_date(tick_time);
  }
}

static void handle_battery(BatteryChargeState charge){
  set_bitmap_for_charge_level(charge);
}

void init() {
  // Initiate KiezelPay
 // kiezelpay_init();
  // Init watchFace
  show_main_window();
  tick_timer_service_subscribe(MINUTE_UNIT, handle_time);
  battery_state_service_subscribe(handle_battery);
  bluetooth_connection_service_subscribe(handle_bluetooth);
}

void deinit() {
  //kiezelpay_deinit();
  hide_main_window();
  tick_timer_service_unsubscribe();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
