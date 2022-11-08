// include files

#include <Arduino.h>
#include "max6675.h" 

//Pin definitions
#define  soPin  PB9// SO=Serial Out
#define  csPin  PB6// CS = chip select CS pin
#define sckPin  PB5// SCK = Serial Clock pin

// Object creation
MAX6675 thermocouple(sckPin, csPin, soPin);// create instance object of MAX6675



void setup() {

          
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  Serial.println("MAX6675"); 

}

void loop() {
  // basic readout test, just print the current temp
   Serial.print("C = "); 
   Serial.println(thermocouple.readCelsius());
   delay(1000);
}
