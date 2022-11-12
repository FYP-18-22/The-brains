#include <Arduino.h>
#include <defs.h>

volatile bool state = true;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  // pinMode(PA0, INPUT);
  // pinMode(pump_control, OUTPUT);
  // pinMode(PC13, OUTPUT);
  // digitalWrite(PC13, LOW);
  attachInterrupt(zc_interrupt, change_flow_rate, CHANGE);
}

void loop()
{
  //put your main code here, to run repeatedly:
  //  Serial.println("Mike"); // wait_time = 2;
  
}

void change_flow_rate()
{
  delay(2);
  digitalWrite(pump_control, HIGH);
  delayMicroseconds(10);
  digitalWrite(pump_control, LOW);
  Serial.println(millis());
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