#include <Arduino.h>
#include "OneWire.h"
#include "DallasTemperature.h"



#define ONE_WIRE_BUS PB10


OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);


void setup(void) 
{ 
 // start serial port 
Serial.begin(115200); 
// Serial.println("Dallas Temperature IC Control Library Demo"); 
 // Start up the library 
 sensors.begin(); 
} 
void loop(void) 
{ 
 // call sensors.requestTemperatures() to issue a global temperature 
 // request to all devices on the bus 
/********************************************************************/
 //Serial.print(" Requesting temperatures..."); 
 sensors.requestTemperatures(); // Send the command to get temperature readings 
 //Serial.println("DONE"); 
/********************************************************************/
  Serial.print("Temp 1 is: "); 
 Serial.println(sensors.getTempCByIndex(0)); 
 Serial.print("Temp 2 is: "); 
 Serial.println(sensors.getTempCByIndex(1));// Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on 
} 