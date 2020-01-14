#include <HCSR04.h>

HCSR04 hc(2, 3);//initialisation class HCSR04 (trig pin , echo pin)

void setup()
{ 
  Serial.begin(9600); 
  pinMode(9, OUTPUT);
}

void loop()
{ 
  int dist = hc.dist();
  Serial.println( dist );
  if( dist < 40 ){
      digitalWrite(9, HIGH);  
      delay(100); 
      digitalWrite(9, LOW);
  }
  if (dist < 1000) 
      delay(dist*10);
}
