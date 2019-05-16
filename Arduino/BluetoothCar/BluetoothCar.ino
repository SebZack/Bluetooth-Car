#include <Servo.h> 

const int relay1 = 6;
const int relay2 = 8;
const int tuta = 9;
const int rLight = 10;
const int lLight = 11;
const int servoPin = 3;
int serialData = 1;

Servo Servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(tuta, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
  Servo1.attach(servoPin);
  Servo1.write(0); //Set servo to 0 degrees
  Serial.println("Hej Världen");
  lightsOn();
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
   else if(serialData == '7'){ 
    lightsOn();
   }
   else if(serialData == '8'){ 
    lightsOff();
   }
}
}
void forward() {

   digitalWrite(relay1, HIGH);
   digitalWrite(relay2, LOW);
   Servo1.write(90);
   Serial.println("fram");
   delay(50);
   loop();
}

void backwards() {
  
  digitalWrite(relay2, HIGH);
  digitalWrite(relay1, LOW);
  Serial.println("bak");
  delay(50);
  loop();
}

void off() {

  digitalWrite(relay1, LOW);
  digitalWrite(relay2, LOW);
  Serial.println("stopp");
  delay(50);
  loop();
}

void right(){
  Serial.println("höger");
  Servo1.write(10);
  delay(50);
  loop();
}

void left(){
  Serial.println("vänster");
  Servo1.write(140);
  delay(50);
  loop();
}

void tut(){
  Serial.println("tut");
  digitalWrite(tuta, HIGH);
  delay(100);
  digitalWrite(tuta, LOW);
  delay(50);
  digitalWrite(tuta, HIGH);
  delay(100);
  digitalWrite(tuta, LOW);
  delay(80);
  loop();
}

void lightsOn(){
  digitalWrite(rLight, HIGH);
  digitalWrite(lLight, HIGH);
}

void lightsOff(){
  digitalWrite(rLight, LOW);
  digitalWrite(lLight, LOW);
}
