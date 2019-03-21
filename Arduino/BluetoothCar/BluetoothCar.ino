const int relay1 = 7;

int serialData = 1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  if(Serial.available() > 0){
    serialData = Serial.read();
    
   if(serialData == '1'){
      Serial.println("1");
      digitalWrite(relay1, HIGH);
    }
   else if(serialData == '2') {
    Serial.println("2");
    digitalWrite(relay1, LOW);
   }
   else if(serialData == '3') {
    Serial.println("3");
   }
   else if(serialData == '4') {
    Serial.println("4");
   }
   else{
      delay(1);
   }
   }
   
}
