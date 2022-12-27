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
=======
#include <Wire.h>
#include <string.h>
#include "OneWire.h"
#include "DallasTemperature.h"
#include "max6675.h"
#include "LiquidCrystal_I2C.h"
#include "defs.h"


// Objects
MAX6675 thermocouple(sckPin, csPin, soPin); // create instance object of MAX6675
OneWire oneWire(ONE_WIRE_0);
OneWire oneWire1(ONE_WIRE_1);
DallasTemperature sensor0(&oneWire);
DallasTemperature sensor1(&oneWire1);
LiquidCrystal_I2C lcd(0x27, 20, 4);

// function prototypes
bool tests();
bool lcdTest();
bool thermocoupleTest();
bool DS18B20Test();
void print_lcd(float temp1, float temp2, float temp3);
void controlFlowrate(float tempDifference, float wallTemperature);


//Global variables
unsigned long lastRead = 0;
float thermocoupleTemp = 0.0;
float DS18B20Temp0 = 0.0;
float DS18B20Temp1 = 0.0; 

void setup(void)
{

  Serial.begin(115200);
  sensor0.begin();
  sensor1.begin();
  tests();
}
void loop(void)
{
  
  sensor0.requestTemperatures();
  sensor1.requestTemperatures(); // Send the command to get temperature readings
                                 // Serial.println("DONE");
  /********************************************************************/
  float thermocoupleTemp = thermocouple.readCelsius();
  float DS18B20Temp0 = sensor0.getTempCByIndex(0);
  float DS18B20Temp1 = sensor1.getTempCByIndex(0);

  Serial.print("C = ");
  Serial.println(thermocoupleTemp);
  Serial.print("Temp 1 is: ");
  Serial.println(DS18B20Temp0);
  Serial.print("Temp 2 is: ");
  Serial.println(DS18B20Temp1);
  if(millis()-lastRead >= 1000){
    print_lcd(thermocoupleTemp,DS18B20Temp0,DS18B20Temp1);
    lastRead=millis();
  }

 
  
}

bool tests()
{
  while (!lcdTest())
  {
  }
  while (!thermocoupleTest())
  {
  }
  while (!DS18B20Test())
  {
  }
  return true;
}

bool lcdTest()
{
  lcd.init();
  lcd.backlight();
  lcd.print("Maya v0.0.1");
  lcd.setCursor(7,3);
  lcd.print("FYP 18-22");
  delay(1000);
  lcd.clear();
  lcd.print("Starting tests ........");
  delay(1000);
  return true;
}
bool thermocoupleTest()
{
  lcd.clear();
  lcd.print("Running thermocouple test!!!!");
  int count = 0;
  while (count < 10)
  {
    delay(100);
    if (thermocouple.readCelsius() > 0 && thermocouple.readCelsius() < 50)
    {
      count++;
    }
    else
    {
      continue;
    }
  }
  lcd.clear();
  lcd.println("Thermocouple test complete !!!!!!");
  delay(1000);
  return true;
}

bool DS18B20Test()
{
  lcd.clear();
  lcd.println("Running DS18B20 test !!!!!!!!!!");
  delay(1000);
  int count = 0;
  while (count < 10)
  {
    delay(100);
    if (sensor0.getTempCByIndex(0) > 0 && sensor0.getTempCByIndex(0) < 50 && sensor1.getTempCByIndex(0) > 0 && sensor1.getTempCByIndex(0))
    {
      count++;
    }
    else
    {
      continue;
    }
  }
  lcd.clear();
  lcd.println("DS18B20 test complete.....!!!!!");
  delay(1000);
  return true;
}

void print_lcd(float temp1, float temp2, float temp3){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Thermocouple: ");
  lcd.print(temp1);
  lcd.setCursor(0,1);
  lcd.print("Probe 1: ");
  lcd.print(temp2);
  lcd.setCursor(0,2);
  lcd.print("Probe 2: ");
  lcd.print(temp3);

}

/**
 * @brief Function to control the pump flowrate
 * @param tempDifference temperature difference from probes
 * @param wallTemperature wall temperature of outer chamber
 * @return void return
*/
void controlFlowrate(float tempDifference, float wallTemperature){
  if(wallTemperature> CONTROL_TEMP_VALUE){
    if(tempDifference >= MAX_TEMP_DIFF){
      //control temperature
      

    }
  }

}
/**
 * @brief function to log data
*/
void logData(){


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
    
=======

}