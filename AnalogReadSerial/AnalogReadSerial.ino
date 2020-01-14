  int max =0;
  int min=3000;
  int maxflag = 0, minflag=0; // 1이면 값이 변경되었음
void setup() {
  pinMode(11, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);  // 12번핀을 디지털 아웃으로 사용하기 위해 셋팅
  Serial.begin(9600); // 시리얼통신을 사용하기 위해 속도 셋팅
}

void loop() {
  int sensorValue = analogRead(A2);   // 수위센서 읽기  
    if(sensorValue >400) 
      digitalWrite(11, HIGH);   
     else 
      digitalWrite(11, LOW); 
  
    if (sensorValue < min) {
      min = sensorValue; 
      minflag = 1;
    } if (sensorValue > max) {    // 들어온 값이 현재 최대값보다 크면
      max = sensorValue;    // 현재 최대값을 들어온 값으로 변경
      maxflag = 1;
    }
  delay(100); 
  if(maxflag==1 || minflag==1) {
    Serial.print("최대값 : ");  Serial.println(max);
    Serial.print("최소값 : ");  Serial.println(min);       
     maxflag = 0;  minflag = 0;
 }  
}
