#include <Arduino.h>
#include <Wire.h>
#include "OneWire.h"
#include "DallasTemperature.h"
#include "max6675.h"
#include "LiquidCrystal_I2C.h"

// Pin definitions
#define soPin PB9  // SO=Serial Out
#define csPin PB6  // CS = chip select CS pin
#define sckPin PB5 // SCK = Serial Clock pi
#define ONE_WIRE_0 PB12
#define ONE_WIRE_1 PB13

// Object creation
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

void setup(void)
{

  Serial.begin(115200);
  sensor0.begin();
  sensor1.begin();
  Serial.println("Beginning tests");
  tests();
  Serial.println("Tests complete...........");
}
void loop(void)
{

  sensor0.requestTemperatures();
  sensor1.requestTemperatures(); // Send the command to get temperature readings
                                 // Serial.println("DONE");
  /********************************************************************/
  Serial.print("C = ");
  Serial.println(thermocouple.readCelsius());
  Serial.print("Temp 1 is: ");
  Serial.println(sensor0.getTempCByIndex(0));
  Serial.print("Temp 2 is: ");
  Serial.println(sensor1.getTempCByIndex(0));
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
  Serial.println("Running LCD test!!!!!!!");
  lcd.init();
  lcd.backlight();
  lcd.print("Hello, world!");
  Serial.println("LCD printing......");
  delay(1000);
  return true;
}
bool thermocoupleTest()
{
  Serial.println("Running thermocouple test!!!!");
  int count = 0;
  while (count < 10)
  {
    delay(100);
    if (thermocouple.readCelsius() > 0 && thermocouple.readCelsius() < 50)
    {
      count++;
      Serial.println("The value of coount is: ");
      Serial.print(count);
    }
    else
    {
      continue;
    }
  }
  Serial.println("Thermocouple test complete !!!!!!");
  return true;
}

bool DS18B20Test()
{
  Serial.println("Running DS18B20 test !!!!!!!!!!");
  int count = 0;
  while (count < 10)
  {
    delay(100);
    // while (sensor0.isConnected(&oneWire))
    // {
    //   Serial.println("The DS18B20 sensors are not appropriately connected!!!!!!")
    // }
    Serial.println("There are two DS18B20 sensors connected.");
    if (sensor0.getTempCByIndex(0) > 0 && sensor0.getTempCByIndex(0) < 50 && sensor1.getTempCByIndex(0) > 0 && sensor1.getTempCByIndex(0))
    {
      count++;
      Serial.println("The value of count is: ");
      Serial.print(count);
    }
    else
    {
      continue;
    }
  }
  Serial.println("Exiting DS18B20 test.....!!!!!");
  return true;
}