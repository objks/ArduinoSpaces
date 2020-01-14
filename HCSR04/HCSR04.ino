#include <HCSR04.h>

HCSR04 hc(5,6);//initialisation class HCSR04 (trig pin , echo pin)

void setup(){ 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
    pinMode(2, OUTPUT);
  Serial.begin(9600); 
  }

void loop(){ 
  float a = hc.dist();  // 거리를 읽어서 a에 넣는다.  
  Serial.println( a ); 
      if ( a < 20) 
          digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
      else
          digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    
  delay(500);  // 0.5초 마다
}
