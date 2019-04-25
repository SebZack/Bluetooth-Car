#include <Servo.h> 

const int relay1 = 7;
const int relay2 = 8;
const int tuta = 9;
int servoPin = 3;
int serialData = 1;

Servo Servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(tuta, OUTPUT);
  Servo1.attach(servoPin);
  Servo1.write(0); //Set servo to 0 degrees
  Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(Serial.available() > 0){
    serialData = Serial.read();
    
   if(serialData == '1'){
      forward();
    }
   else if(serialData == '2') {
    backwards();
   }
   else if(serialData == '3') {
    right();
   }
   else if(serialData == '4') {
    left();
   }
   else if(serialData == '5'){ 
    tut();
   }
   else if(serialData == '6'){ 
    off();
   }
   
}
}
void forward() {

   digitalWrite(relay1, HIGH);
   digitalWrite(relay2, LOW);
   Servo1.write(0);
   Serial.println("forward");
   delay(50);
   loop();
}

void backwards() {
  
  digitalWrite(relay2, HIGH);
  digitalWrite(relay1, LOW);
  Serial.println("backwards");
  delay(50);
  loop();
}

void off() {

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  Serial.println("off");
  delay(50);
  loop();
}

void right(){
  Serial.println("right");
  Servo1.write(90);
  delay(50);
  loop();
}

void left(){
  Serial.println("left");
  delay(50);
  loop();
}

void tut(){
  Serial.println("tut");
  digitalWrite(tuta, HIGH);
  delay(1000);
  digitalWrite(tuta, LOW);
  delay(500);
  digitalWrite(tuta, HIGH);
  delay(1000);
  digitalWrite(tuta, LOW);
  delay(80);
  loop();
}
