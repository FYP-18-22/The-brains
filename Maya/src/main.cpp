#include <Arduino.h>
#include "max6675.h" 

int soPin = PB9;// SO=Serial Out
int csPin = PB6;// CS = chip select CS pin
int sckPin = PB5;// SCK = Serial Clock pin


MAX6675 Module(sckPin, csPin, soPin);// create instance object of MAX6675

void setup() {

          
  Serial.begin(9600);// initialize serial monitor with 9600 baud
  Serial.println("MAX6675"); 

}

void loop() {
  // basic readout test, just print the current temp
   Serial.print("C = "); 
   Serial.println(Module.readCelsius());
   delay(1000);
}
