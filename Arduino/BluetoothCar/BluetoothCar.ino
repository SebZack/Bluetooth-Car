/*
 * Bluetooth Controlled Car made by Emil and Sebastian.
 * GitHub Repo: https://github.com/SebZack/Bluetooth-Car
 * 
 * HC-06 Bluetooth Chip.
 * Purple -> D0
 * Blue -> D1
 */

#include <Servo.h> 

const int relayF = 6;
const int rLight = 10;
const int lLight = 11;
const int servoPin = 9;
int serialData = 1;

Servo Servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayF, OUTPUT);
  //pinMode(tuta, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(rLight, OUTPUT);
  pinMode(lLight, OUTPUT);
  digitalWrite(12, HIGH);
  Servo1.attach(servoPin);
  Servo1.write(0);       //Set steering framåt
}

void loop() {
  
  if(Serial.available() > 0){
    serialData = Serial.read();
    
   if(serialData == '1'){
     forward();
    }
   else if(serialData == '2') {
    right();
   }
   else if(serialData == '3') {
    left();
   }
   else if(serialData == '4'){ 
    //tut();
   }
   else if(serialData == '5'){ 
    off();
   }
   else if(serialData == '6'){ 
    lightsOn();
   }
   else if(serialData == '7'){ 
    lightsOff();
   }
   else if(serialData >= '8'){
    Serial.println("error, too big input");
   }
}
}
void forward() {

   digitalWrite(relayF, HIGH);
   Servo1.write(0);
   Serial.println("fram");
   delay(50);
   loop();
}



void off() {

  digitalWrite(relayF, LOW);
  Servo1.write(90);       //Set steering framåt
  Serial.println("stopp");
  delay(50);
  loop();
}

void right(){
  Serial.println("höger");
  Servo1.write(30);
  delay(50);
  loop();
}

void left(){
  Serial.println("vänster");
  Servo1.write(140);
  delay(50);
  loop();
}

/**
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
**/

void lightsOn(){
  digitalWrite(rLight, HIGH);
  digitalWrite(lLight, HIGH);
  Serial.println("Lampor PÅ");
  loop();
}

void lightsOff(){
  digitalWrite(rLight, LOW);
  digitalWrite(lLight, LOW);
  Serial.println("Lampor AV");
  loop();
}
