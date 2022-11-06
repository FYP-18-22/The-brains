#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  lcd.setCursor(0,1);
  lcd.printstr("Ywrobot Arduino!");
   lcd.setCursor(0,2);
  lcd.printstr("Arduino LCM IIC 2004");
   lcd.setCursor(0,3);
  lcd.printstr("Power By Ec-yuan!");
}

void loop()
{ 
  lcd.setCursor(0,0);
  lcd.printstr("konichiwaa");
  delay(1000);
  lcd.clear();
  delay(500);
  
}