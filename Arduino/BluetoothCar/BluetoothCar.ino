const int relay1 = 1;

int serialData = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.read();
  
  if(Serial.available() > 0){
    serialData = Serial.read();
    
   if(serialData == '1'){
      Serial.println("1");
    }
   else if(serialData == '2') {
    Serial.println("2");
   }
   else if(serialData == '3') {
    Serial.println("3");
   }
   else if(serialData == '4') {
    Serial.println("4");
   }
   else if(serialData == '0') {
    Serial.println("0");
   }
   }
}
