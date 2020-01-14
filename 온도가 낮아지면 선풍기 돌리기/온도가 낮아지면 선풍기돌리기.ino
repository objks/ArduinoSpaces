#include <SimpleDHT.h>
int pinDHT11 = 7;
SimpleDHT11 dht11(pinDHT11);

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
    // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
   // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  if( temperature > 28) {
  digitalWrite(3, 7);   // 27의 속도로 오른쪽으로 돌아라
  digitalWrite(2, 0);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  }
}
