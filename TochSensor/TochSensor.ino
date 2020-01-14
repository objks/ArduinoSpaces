int touchSensor = 2;

int led = 8;           // R
int led2 = 9;         // G
int led3 = 10;        // B
int count = 0;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(touchSensor, INPUT);
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int value = digitalRead(touchSensor);
//   for (int i=255; i > 0; i--) { // 255부터 1씩 줄어든다
//  analogWrite(8, i);
//  delay(25);
//  } // 0일때 끝남 가장밝다.
//  analogWrite(8, 255);  // 바로 led 끔
//  
//    for (int i=255; i > 0; i--) { // 255부터 1씩 줄어든다
//  analogWrite(9, i);
//  delay(25);
//  } // 0일때 끝남 가장밝다.
//  analogWrite(9, 255);  // 바로 led 끔
//  
//  for (int i=255; i > 0; i--) { // 255부터 1씩 줄어든다
//  analogWrite(10, i); // 하나씩 줄어든 값을 pwm으로 출력
//  delay(25);
//  } // 0일때 끝남 가장밝다.
//  analogWrite(10, 255);  // 바로 led 끔

  
  if(value == 1){
  analogWrite(8, HIGH);
  analogWrite(9, HIGH);
  analogWrite(10, HIGH);
    count++;
    Serial.println("터치!");
    if(count > 60)
      analogWrite(8, HIGH);
    else if (count > 40)
      analogWrite(9, HIGH);
    else if (count > 20)
      analogWrite(10, HIGH);    
  }else{
    count--;
    Serial.println("대기중....");    
    if(count < 0)
    count = 0;
      
    if(count <= 0)
      analogWrite(8, LOW);
    else if (count < 20)
      analogWrite(9, LOW);
    else if (count < 40)
      analogWrite(10, LOW);
  }

  delay(30);
}
