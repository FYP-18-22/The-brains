#include <Arduino.h>
#include <defs.h>

volatile boolean state = true;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PA0, INPUT);
  pinMode(pump_control, OUTPUT);
  pinMode(PC13, OUTPUT);
  digitalWrite(PC13, LOW);
  attachInterrupt(digitalPinToInterrupt(PA0), change_flow_rate, CHANGE);
}

void loop()
{
  //put your main code here, to run repeatedly:
  wait_time = 2;
  
}

void change_flow_rate()
{
  delay(wait_time);
  digitalWrite(pump_control, HIGH);
  delay(5);
  digitalWrite(pump_control, LOW);
  Serial.print(millis());
  // state != state;
  // if(state)
  // {
  //   state = false;
  //   digitalWrite(PC13, LOW);
  // }
  // else
  // {
  //   state = true;
  //   digitalWrite(PC13, HIGH);
  // }
}