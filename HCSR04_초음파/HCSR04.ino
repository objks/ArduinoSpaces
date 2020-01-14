#include <HCSR04.h>

HCSR04 hc(5,6);//initialisation class HCSR04 (trig pin , echo pin)

void setup()
{ Serial.begin(9600); }

void loop(){ 
  //거리에 따라서 부저가 빨리 반복되는 시스템
  
  float value = hc.dist();
  Serial.println( value ); 
  
  digitalWrite(11, HIGH);   
  delay(value * 10);
  
  digitalWrite(11, HIGH);   
  delay(value * 10 ) ;
  
  }
