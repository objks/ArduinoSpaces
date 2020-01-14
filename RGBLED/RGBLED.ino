// R =9, G = 10, B = 11
// pwm은 ~표시 핀에만 꽂아야 됨

void setup() {
  pinMode(2, INPUT);    // 디지털 입력 신호 터치센서
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  if(digitalRead(2) == HIGH) {
  Serial.begin(9600);
   for (int i=255; i > 0; i--) { // 255부터 1씩 줄어든다
  analogWrite(9, i);
  delay(25);
  } // 0일때 끝남 가장밝다.
  analogWrite(9, 255);  // 바로 led 끔
  
    for (int i=255; i > 0; i--) { // 255부터 1씩 줄어든다
  analogWrite(10, i);
  delay(25);
  } // 0일때 끝남 가장밝다.
  analogWrite(10, 255);  // 바로 led 끔
  
  for (int i=255; i > 0; i--) { // 255부터 1씩 줄어든다
  analogWrite(11, i); // 하나씩 줄어든 값을 pwm으로 출력
  delay(25);
  } // 0일때 끝남 가장밝다.
  analogWrite(11, 255);  // 바로 led 끔

for (int i=0; i<3; i++) {
  analogWrite(9, 0);  // R 최대밝기     // = digitalWrite(9, LOW) 
  analogWrite(10, 0);  // R 최대밝기
  analogWrite(11, 0);  // R 최대밝기
  delay(500);

  analogWrite(9, 255);  // R 최대밝기     // = digitalWrite(9, LOW) 
  analogWrite(10, 255);  // R 최대밝기
  analogWrite(11, 255);  // R 최대밝기
  delay(500);
}
  }

}
