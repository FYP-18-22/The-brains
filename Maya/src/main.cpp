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
#define ONE_WIRE_BUS PB10

// Object creation
MAX6675 thermocouple(sckPin, csPin, soPin); // create instance object of MAX6675
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup(void)
{

  Serial.begin(115200);
  sensors.begin();
  Serial.println("Beginning tests");
  tests();
  Serial.println("Tests complete...........")
}
void loop(void)
{

  sensors.requestTemperatures(); // Send the command to get temperature readings
                                 // Serial.println("DONE");
  /********************************************************************/
  Serial.print("C = ");
  Serial.println(thermocouple.readCelsius());
  Serial.print("Temp 1 is: ");
  Serial.println(sensors.getTempCByIndex(0));
  Serial.print("Temp 2 is: ");
  Serial.println(sensors.getTempCByIndex(1)); // Why "byIndex"?
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
}

bool lcdTest()
{
  Serial.prinntln("Running LCD test!!!!!!!")
      lcd.init();
  lcd.backlight();
  lcd.print("Hello, world!");
  Serial.println("LCD printing......")
      delay(1000);
  return true
}
bool thermocoupleTest()
{
  Serial.println("Running thermocouple test!!!!");
  int count = 0;
  while (count < 10)
  {
    delay(100);
    if (thermocouple.readCelsius() > 0 && thermocouple.readCelsius < 50)
    {
      count++;
      Serial.println("The value of coount is: ", count);
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
  int count == 0;
  while (count < 10)
  {
    delay(100);
    while (sensors.getDS18Count != 2)
    {
      Serial.println("The DS18B20 sensors are not appropriately connected!!!!!!")
    }
    Serial.println("There are two DS18B20 sensors connected.") if (sensors.getTempCByIndex(0) 2 > 0 && sensors.getTempCByIndex(0) < 50 && sensors.getTempCByIndex(1) > 0 && sensors.getTempCByIndex(1))
    {
      count++;
      Serial.println("The value of count is: ", count);
    }
    else
    {
      continue;
    }
  }
  Serial.println("Exiting DS18B20 test.....!!!!!");
  return true;
}