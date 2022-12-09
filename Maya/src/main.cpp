#include <Arduino.h>
#include <defs.h>

int firing_time = 1;
int prev_time;
int current_time;
int initial_time;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(zc_interrupt, INPUT);
  pinMode(pump_control, OUTPUT);
  pinMode(PC13, OUTPUT);
  digitalWrite(PC13, LOW);
  attachInterrupt(zc_interrupt, change_flow_rate, CHANGE);
  
  prev_time = millis();
  initial_time = millis();
}



void loop()
{
  //put your main code here, to run repeatedly:
  current_time = millis();
  if((current_time - prev_time >= 8000) && (firing_time <= 7))
  {
    firing_time += 1; 
    prev_time = current_time;
  }
  else
  {
    firing_time = firing_time;
  }
}

void change_flow_rate()
{
  if (current_time - initial_time <= 6000)
  {
    digitalWrite(pump_control, HIGH);
  }
  else
  {
    delayMicroseconds(5500);
    digitalWrite(pump_control, HIGH);
    delayMicroseconds(10);
    digitalWrite(pump_control, LOW);
  }
  // Serial.println("Mike");
}