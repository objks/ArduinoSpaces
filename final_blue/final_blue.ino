#include <SoftwareSerial.h>
 
SoftwareSerial bt(3,2); //3번에 블루투스 TX, 2번에 블루투스 RX를 연결
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  bt.begin(9600); //해당값 사용할것
}
 
void loop() {
  // put your main code here, to run repeatedly:
  while(bt.available()){
    byte data=bt.read();
    Serial.write(data);
  }
  while(Serial.available()){

    byte data=Serial.read();
    bt.write(data);
  }
}
