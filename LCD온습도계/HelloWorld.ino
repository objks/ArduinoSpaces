//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

LiquidCrystal_I2C lcd(0x27,20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int pinDHT11 = 7;
SimpleDHT11 dht11(pinDHT11);

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
 // Print a message to the LCD.
  lcd.backlight();
/*  lcd.setCursor(3,0);                       // 첫째값은 위치를 의미 0부터 시작, 두번째 값은 line을 의미
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
   lcd.setCursor(0,2);
  lcd.print("Arduino LCM IIC 2004");
   lcd.setCursor(2,3);
  lcd.print("Power By Ec-yuan!");
  */
}


void loop()
{
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    lcd.print("err="); lcd.println(err);delay(1000);
    return;
  }
  
//  온, 습도계
  lcd.setCursor(0, 0); lcd.print((int)temperature); lcd.print(" *C, "); 
  lcd.print((int)humidity); lcd.println(" H");


  /*  lcd.setCursor(0, 0);  lcd.print(".                         ");
  delay(100);
  lcd.setCursor(0, 0);  lcd.print(" .                        ");
    delay(100);
  lcd.setCursor(0, 0);  lcd.print("   .                      ");
    delay(100);
  lcd.setCursor(0, 0);  lcd.print("     .                    ");
    delay(100);
  lcd.setCursor(0, 0);  lcd.print("       .                  ");
    delay(100);
  lcd.setCursor(0, 0);  lcd.print("         .                ");
    delay(100);
  lcd.setCursor(0, 0);  lcd.print("           .              ");
    delay(100);
*/


  
  // DHT11 sampling rate is 1HZ.
  delay(1500);
}
