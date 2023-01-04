triac_test
#include <Arduino.h>

void change_flow_rate();

float desired_wall_temperature;
float wall_temperature;
float intial_coolant_temperature;
float final_coolant_temperature;

// #ifdef ARDUINO_ARCH_AVR
// #define zc_interrupt 0
// #define pump_control 7 
//#else
#define zc_interrupt PB8
#define pump_control PB14
#define fan_switch PB4
#define green_led PB15
#define white_led PA9
#define setup_time 20000
// #endif

int wait_time;
=======
#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H


#define soPin PA6  // SO=Serial Out
#define csPin PA7  // CS = chip select CS pin
#define sckPin PA5 // SCK = Serial Clock pi
#define ONE_WIRE_0 PB12 // One Wire Probe 1
#define ONE_WIRE_1 PB13 // One wire Probe 2

#define MAX_WALL_TEMP 400.0
#define MAX_TEMP_DIFF 5.0
#define CONTROL_TEMP_VALUE 200.0




#endif

