#define sensor 2
#define valve 4

int value;

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(valve,OUTPUT);
  digitalRead(sensor);
  digitalWrite(valve,LOW);
  
}

void loop() {
  value=digitalRead(sensor);
  if(value==0){
    value=digitalRead(sensor);
    delay(200);
    Serial.println("sensor");
  }
  else{
    for(int i=0;i<=6;i++){
      if(value==1){
        value=digitalRead(sensor);
        delay(500);
        Serial.print("for ");
        Serial.println(i);
      }
      else{return 0 ;}
    }
    delay(2000);
    digitalWrite(valve,HIGH);
    Serial.println("valve-open");
    delay(5000);
    digitalWrite(valve,LOW);
    Serial.println("valve-close");
  }
}
