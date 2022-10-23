#include <Arduino.h>
#include <defs.h>

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(zc_interrupt, INPUT);
  pinMode(pump_control, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(zc_interrupt), change_flow_rate, CHANGE);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  wait_time = 2;
}

void change_flow_rate()
{
  delay(wait_time);
  digitalWrite(pump_control, HIGH);
  delay(5);
  digitalWrite(pump_control, LOW);
  Serial.print(millis());
}