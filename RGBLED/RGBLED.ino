//11번은 R, 10번은 B, 9번은 G  이렇게 연결되었음 
//(~11,~10,~9,~6,~5,~3 이 핀만 PWM가능)
void setup() {
  Serial.begin(9600);
    pinMode(11,OUTPUT);pinMode(10,OUTPUT);pinMode(9,OUTPUT);
    pinMode(2,INPUT); //디지털 입력신호
}
void loop() {
  Serial.println(digitalRead(2));
  if(digitalRead(2)==HIGH){
      //R LED
       for(int i=255; i>0; i--){ //255부터 1씩줄어든다. 
        analogWrite(11, i);  //하나씩 줄어든 값을 pwm으로 출력      
        delay(10);          //for문의 수행시간이 너무빠르기 때문에 시간지연을 둠
      }  //0일때 끝남 가장밝다.
      analogWrite(11, 255); //바로 led 끔 
      
      //B LED
      for(int i=255; i>0; i--){ //255부터 1씩줄어든다. 
        analogWrite(10, i);  //하나씩 줄어든 값을 pwm으로 출력      
        delay(10);          //for문의 수행시간이 너무빠르기 때문에 시간지연을 둠
      }  //0일때 끝남 가장밝다.
      analogWrite(10, 255); //바로 led 끔 
    
      //G LED
      for(int i=255; i>0; i--){ //255부터 1씩줄어든다. 
        analogWrite(9, i);  //하나씩 줄어든 값을 pwm으로 출력      
        delay(10);          //for문의 수행시간이 너무빠르기 때문에 시간지연을 둠
      }  //0일때 끝남 가장밝다.
      analogWrite(9, 255); //바로 led 끔 
    
    for(int i=0; i<3; i++){
      analogWrite(11, 0); //R 최대밝기  digitalWrite(11, LOW)
      analogWrite(10, 0); //B 최대밝기  digitalWrite(10, LOW)
      analogWrite(9, 0); //G 최대밝기   digitalWrite(9, LOW)
      delay(500);
       analogWrite(11, 255); 
      analogWrite(10, 255); 
      analogWrite(9, 255); 
      delay(500);
    }
  } 
}
