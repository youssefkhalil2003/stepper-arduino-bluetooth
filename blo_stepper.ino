const int dirPin1 = 2;  // Direction
const int stepPin1 = 3; // Step
const int dirPin2 = 4;  // Direction
const int stepPin2 = 5; // Step
 
 
// Motor steps per rotation
const int STEPS_PER_REV = 200;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Define Baud rate 9600
   pinMode(stepPin1, OUTPUT);
   pinMode(dirPin2, OUTPUT);
   pinMode(stepPin2,OUTPUT); 
   pinMode(dirPin2,OUTPUT);
}
 
 void forward (){
 // Set motor direction clockwise
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,LOW); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(2000); 
  }
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000); 
  }
  
    
  }

  void backward (){
  // Set motor direction clockwise
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,HIGH); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(2000); 
  }
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000); 
  }
  
  }
  
   void right (){
  // Set motor direction clockwise
  digitalWrite(dirPin1,HIGH);
  digitalWrite(dirPin2,LOW); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(2000); 
  }
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000); 
  }
  
  }
  
   void left (){
  // Set motor direction clockwise
  digitalWrite(dirPin1,LOW);
  digitalWrite(dirPin2,HIGH); 
  
  // Spin motor one rotation slowly
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin1,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin1,LOW); 
    delayMicroseconds(2000); 
  }
  for(int x = 0; x < STEPS_PER_REV; x++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(2000); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(2000); 
  }
  
  }
 

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
   {      
      char data= Serial.read(); // reading the data received from the bluetooth module
      switch(data)
      {
        case 'F': {forward();} 
        case 'B': {backward();} 
        case 'R': {right();}
        case 'L': {left();}  
        default : break;
      }
      
      Serial.println(data);
   }
   delay(50);
}
