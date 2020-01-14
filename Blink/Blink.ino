
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  int j=1000;
  for(int i=0; i < 10; i++) {    
  digitalWrite(2, HIGH);  
  delay(j-(100*i));                   
  digitalWrite(2, LOW);   
  delay(j-100*i);  
  }
}
