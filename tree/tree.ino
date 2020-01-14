
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(6, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  yby (6, 8, 10);
}

void yby (int a, int b, int c) {
  int i=500;

  for(int x=0; x < 5; x++) {
    digitalWrite(a, HIGH); 
    delay(i);                     
    digitalWrite(a, LOW);    
    delay(i);                   
    digitalWrite(b, HIGH); 
    delay(i);                     
    digitalWrite(b, HIGH); 
    delay(i);                     
    digitalWrite(b, LOW);    
    delay(i);                   
    digitalWrite(b, HIGH); 
    delay(i);           
    digitalWrite(c, LOW);    
    delay(i);    
    digitalWrite(c, HIGH); 
    delay(i);                     
    digitalWrite(c, LOW);    
    delay(i);    
  }
  return yby;
}
