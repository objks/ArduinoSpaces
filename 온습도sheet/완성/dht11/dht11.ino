void setup() {
  Serial.begin(9600);

}

void loop() {
  int humidity=0;
  int temperature=0;
   int sensorValue[40];
  
  //1.out으로 바꾸고 바로 low신호를 줘야 동작 (지연도 있으면 안됨)
  pinMode(7, OUTPUT);

  //2.low(0V)로 18ms 유지
  digitalWrite(7,LOW);
  delay(18);
  
  //3.high로 20-40us 유지
  digitalWrite(7,HIGH);
  delayMicroseconds(30);

  //4.gpio를 인풋모드로 변경
  pinMode(7, INPUT);
  int count=0;
  int err=0; //0으로 에러없음, 1=첫번째에러, 2=두번째 에러
  while(!digitalRead(7)){
      count++;
      if(count > 100 ){
        err=1;
        break; //뭔가 문제가 발생
      }
    }///센서준비완료(high일때)
    
  if(err==0){
    count=0;
    while(digitalRead(7)){
       count++;
       if(count > 100 ){
        err=2;
        break; //두번째 문제 발생
      }
    }//값 보내기 시작 (low일때)
    if(err==0){
    sensorValue[40];
      
    for(int i=0; i<40; i++){
      int temp=readBitValue(); //임시로 받고
   //   if(temp==0 || temp==1){
      sensorValue[i]=temp;
   //   }else{
   //     err=temp; //에러값 셋팅후 그만
  //      break;
  //    }
    }
    //습도값만들기
    byte highHumi=0;
    for(int i=0; i<8 ;i++){
      highHumi+=sensorValue[i];
      if(i!=7)//마지막은 밀면 안된다.
        highHumi=highHumi<<1;  //왼쪽으로 1bit 밀겠다.
    }
    byte lowHumi=0;
    for(int i=8; i<16 ;i++){
      lowHumi+=sensorValue[i];
      if(i!=15)
        lowHumi=lowHumi<<1;  //왼쪽으로 1bit 밀겠다.
    }
    byte hightemp=0;
    for(int i=16; i<24 ;i++){
      hightemp+=sensorValue[i];
      if(i!=23)
        hightemp=hightemp<<1;  //왼쪽으로 1bit 밀겠다.
    }
    byte lowtemp=0;
    for(int i=24; i<32 ;i++){
      lowtemp+=sensorValue[i];
      if(i!=31)
      lowtemp=lowtemp<<1;  //왼쪽으로 1bit 밀겠다.
    }
    byte parityBit=0;
    for(int i=32; i<40 ;i++){
      parityBit+=sensorValue[i];
      parityBit<<1;  //왼쪽으로 1bit 밀겠다.
    }  
    //습도만들기
      humidity=highHumi;
    //온도만들기
     temperature=hightemp;
    }//if(err==0)
  }//if(err==0)
  Serial.print("humi:");Serial.println(humidity);
  Serial.print("temp:");Serial.println(temperature);
  Serial.print("error:");Serial.println(err);

  for(int i=0; i<40; i++){
    if(i%8==0) Serial.print(" ");
    Serial.print(sensorValue[i]);
    
  }
  Serial.println(" ");
    delay(2000);
}

int readBitValue(){
  int count=0;
  int err=0;
  while(!digitalRead(7)){
     count++;
     if(count > 100){
      err=3;
      break;
     }
    }//센서에서 high 값이 출력되는 순간 찾아서
  if(err==0){
    count=0;
    while(digitalRead(7)){  //신호가 low로 떨어지는 순간까지 읽기 
      count++;
     // Serial.println(count);
      if(count > 100){
        err=4;
        break;
     }
    }
    if(err==0){
      //70us이면 1이고 26~28us0 이다
      if(count >10)
        return 1;
      else 
        return 0;
    }else{
      return err; //4
    }
  }else{
    return err; //3
  }
  
}
