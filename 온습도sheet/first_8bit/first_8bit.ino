void setup() {
  Serial.begin(9600);

}

void loop() {
  delay(2000); //2초마다 테스트
  int value[80];
  pinMode(7, OUTPUT);
  digitalWrite(7,LOW);
  delay(18);
  digitalWrite(7,HIGH);
  delayMicroseconds(30);
  
  pinMode(7, INPUT); //data 읽기
  int count=0;
  while(!digitalRead(7)){ //low 값길이
    count++;
  }
  count=0;
  while(digitalRead(7)){ //high 값길이
    count++;
  }
  //data 보내기 시작
   for(int i=0; i<8; i++){
    count=0;
    while(!digitalRead(7)){ //low 값길이
      count++;
    }
    value[i*2]=count;
    count=0;
    while(digitalRead(7)){ //high 값길이
      count++;
    }
    value[i*2+1]=count;
  }
  for(int i=0; i<16; i++){
    Serial.print(value[i]);Serial.print(" ");
  }
   Serial.println(""); 

  
}
