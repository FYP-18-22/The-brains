#include <Arduino.h>

void change_flow_rate();

float desired_wall_temperature;
float wall_temperature;
float intial_coolant_temperature;
float final_coolant_temperature;

int zc_interrupt = PA0;
int pump_control = PA1;

int wait_time;