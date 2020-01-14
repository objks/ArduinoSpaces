
void setup() {
  pinMode( 12, OUTPUT);
  pinMode( 13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // 아날로그 값을 읽는다 - 조정버튼
  int value = analogRead(0);
  // 읽은 값은 0~1023 값이 들어오기 때문에 필요한 값 pwm 0~255로 변환해 준다
 
  int result = map(value, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  analogWrite (13, result);
  analogWrite (12, 0);
}
