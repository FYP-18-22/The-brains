#include <Arduino.h>
#include "OneWire.h"
#include "DallasTemperature.h"



#define ONE_WIRE_BUS PB10


OneWire oneWire(ONE_WIRE_BUS);  
DallasTemperature sensors(&oneWire);


void setup(void) 
{ 

Serial.begin(115200); 
 
 sensors.begin(); 
} 
void loop(void) 
{ 

 sensors.requestTemperatures(); // Send the command to get temperature readings 
 //Serial.println("DONE"); 
/********************************************************************/
  Serial.print("Temp 1 is: "); 
 Serial.println(sensors.getTempCByIndex(0)); 
 Serial.print("Temp 2 is: "); 
 Serial.println(sensors.getTempCByIndex(1));// Why "byIndex"?  
   
} 