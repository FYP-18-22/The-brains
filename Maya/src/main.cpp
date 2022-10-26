#include <Arduino.h>
#include <defs.h>

bool state = true;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PB10, INPUT);
  pinMode(pump_control, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(PB10, change_flow_rate, FALLING);
}

void loop()
{
  //put your main code here, to run repeatedly:
  // wait_time = 2;
  Serial.println(state);
  if(state)
  {
    digitalWrite(PC13, LOW);
  }
  else
  {
    digitalWrite(PC13, HIGH);
  }
  delay(100);
  

}

void change_flow_rate()
{
  // delay(wait_time);
  // digitalWrite(pump_control, HIGH);
  // delay(5);
  // digitalWrite(pump_control, LOW);
  // Serial.print(millis());
  state != state;

}