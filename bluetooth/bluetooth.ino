#include <SoftwareSerial.h>
 
SoftwareSerial hm10(3,2); //3번에 블루투스 TX, 2번에 블루투스 RX를 연결
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  hm10.begin(115200);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  while(hm10.available()){
    byte data=hm10.read();
    Serial.write(data);
  }
  while(Serial.available()){

    byte data=Serial.read();
    hm10.write(data);
  }
}
