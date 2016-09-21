#include <pebble.h>
#include "windows/main_window_rect.h"
#include "windows/main_window_round.h"

void init() {
  /**** Initiate KiezelPay ****/
 // kiezelpay_init();
  /**** Init watchFace ****/
  #if defined(PBL_RECT)
    /* Rectangular UI code */
    main_window_rect_push();
  #elif defined(PBL_ROUND)
    /* Round UI code */
    main_window_round_push();
  #endif
}

void deinit() {
  //kiezelpay_deinit();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
