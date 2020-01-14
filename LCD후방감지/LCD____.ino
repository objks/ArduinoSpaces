//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <HCSR04.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
HCSR04 hc(2, 3);//initialisation class HCSR04 (trig pin , echo pin)

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  Serial.begin(9600); 
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop()
{
   Serial.println( hc.dist() );
  int dist = hc.dist();
  lcd.setCursor(0,0);   lcd.print(dist );
  delay(100);
  lcd.setCursor(0,0);  lcd.print("                                   " );
  if( dist < 40 ){
      digitalWrite(9, HIGH);  
      delay(100);
      digitalWrite(9, LOW);
  }
  if (dist < 1000)
    delay(dist * 10);
}
