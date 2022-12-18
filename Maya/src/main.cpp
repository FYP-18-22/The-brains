#include <Arduino.h>
#include <defs.h>

short int firing_time = 0;
int prev_time;
int current_time;
short int initial_time;
short int pump_flag = 0;
void flow_rate_test();



void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(zc_interrupt, INPUT);
  pinMode(pump_control, OUTPUT);
  pinMode(fan_switch, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(white_led, OUTPUT);
  pinMode(PC13, OUTPUT);
  digitalWrite(PC13, LOW);
  digitalWrite(fan_switch, HIGH);
  delay(setup_time);
  digitalWrite(fan_switch, LOW);
  delay(3000);
  attachInterrupt(zc_interrupt, change_flow_rate, CHANGE);
  digitalWrite(green_led, LOW);
  digitalWrite(white_led, LOW);
  prev_time = millis();
  initial_time = millis();
}



void loop()
{
  //put your main code here, to run repeatedly:
  if(firing_time <= 9)
  {
    digitalWrite(green_led, HIGH);
    digitalWrite(fan_switch, LOW);
    flow_rate_test();
  }
  else
  {
    firing_time = 10;
    delay(5000);
    digitalWrite(green_led, LOW);
    digitalWrite(white_led, LOW);
    pump_flag = 0;
    digitalWrite(pump_control, LOW);
    delay(2000);
    digitalWrite(fan_switch, HIGH);
  }
  
}

void change_flow_rate()
{
  if(pump_flag == 0)
  {
    firing_time = firing_time;
  }
  else
  {
    delay(firing_time);
    digitalWrite(pump_control, HIGH);
    delayMicroseconds(10);
    digitalWrite(pump_control, LOW);
  }
  // Serial.println("Mike");
}

void flow_rate_test()
{
  current_time = millis();
  if(pump_flag == 0)
  {
    for(int full_speed = 0; full_speed <= 8; full_speed++)
    {
      delay(1000);
      digitalWrite(pump_control, HIGH);
      Serial.print("Full speed temp. data is : ");
      Serial.println("last value");
    }
    digitalWrite(pump_control, LOW);
    pump_flag = 1;
  }
  else
  {
    
    firing_time = 5;
    Serial.println(firing_time);
    // if((current_time - prev_time >= 8000) && (firing_time <= 9))
    // {
    //   digitalWrite(white_led, HIGH);
    //   firing_time += 1; 
    //   prev_time = current_time;
    //   Serial.println(firing_time);
    //   Serial.print("Controlled temp data is: ");
    //   Serial.println("controlled value");
    // }
    // else
    // {
    //   //digitalWrite(white_led, LOW);
    //   //Serial.println(firing_time);
    //   firing_time = firing_time;
    // }  
  }
    
}