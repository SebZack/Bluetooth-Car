const int relay1 = 7;
const int relay2 = 8;

int serialData = 1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(Serial.available() > 0){
    serialData = Serial.read();
    
   if(serialData == '1'){
      Serial.println("1");
      forward();
    }
   else if(serialData == '2') {
    Serial.println("2");
    off();
   }
   else if(serialData == '3') {
    Serial.println("3");
    backwards();
   }
   else if(serialData == '4') {
    Serial.println("4");
    right();
   }
   
   else if(serialData == '5'){ 
   }
   
}
}
void forward() {

digitalWrite(relay1, HIGH);
digitalWrite(relay2, LOW);
  
}

void backwards() {
  
digitalWrite(relay2, HIGH);
digitalWrite(relay1, LOW);
  
}

void off() {

digitalWrite(relay1, LOW);
digitalWrite(relay2, LOW);
  
}

void right(){
  Serial.println("right");
  loop();
}
