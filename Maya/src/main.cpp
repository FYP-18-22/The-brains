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
LiquidCrystal_I2C lcd(0x27,20,4); 


void setup(void)
{

  Serial.begin(115200);
  lcd.init(); 
  lcd.backlight();
  lcd.print("Hello, world!");
  sensors.begin();
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