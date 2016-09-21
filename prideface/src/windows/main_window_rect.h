#pragma once

void show_main_window(void);
void hide_main_window(void);
void change_time(struct tm* tick_time);
void change_date(struct tm* tick_time);
void set_bitmap_for_charge_level (BatteryChargeState charge);
void handle_bluetooth (bool connected);
