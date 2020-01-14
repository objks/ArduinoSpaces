
const int led = 9;   

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  for(int i=0; i<256; i++) {
    digitalWrite(11, HIGH);  
    delay(10); 
  }
  for( int i=255; i>=0; i--) {
      digitalWrite(11, LOW);
      delay(10); 
  }
}
