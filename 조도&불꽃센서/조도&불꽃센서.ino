
void setup() {
  // initialize serial communication at 9600 bits per second:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int j = 1000;
  for ( int f=0; f < 9; f++) {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    delay(100);                       // wait for a second

    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
    delay(100);                       // wait for a second

    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
    delay(100);                       // wait for a second

    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
    delay(100);                       // wait for a second

    digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);                       // wait for a second
    digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
    delay(100);                       // wait for a second
}

  int sensorValue = analogRead(A0);  //조도센서
  int sensorValue2 = analogRead(A1);  // 불꽃센서

    if ( (sensorValue2 < 200) && (sensorValue > 300)) {
          digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(100);                       // wait for a second
          digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
          delay(100);                       // wait for a second  
    }    
    
  Serial.println(sensorValue);
  delay(500);        // delay in between reads for stability
//  Serial.println(sensorValue2);
//  delay(500);        // delay in between reads for stability
  
}
