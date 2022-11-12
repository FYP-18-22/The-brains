#include <Arduino.h>

void change_flow_rate();

float desired_wall_temperature;
float wall_temperature;
float intial_coolant_temperature;
float final_coolant_temperature;

#ifdef ARDUINO_ARCH_AVR
#define zc_interrupt 0
#define pump_control 7 
#else
#define zc_interrupt PA0
#define pump_control PB4
#endif

int wait_time;