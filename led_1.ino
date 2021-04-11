int LED=4;
boolean LEDStatus=false;
int soundSensor=2;
int pirSensor = 7;
 
void setup() {
 pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);
 pinMode(pirSensor, INPUT);
 Serial.begin(9600);

}

void loop() {
  Serial.print("Led:"+LEDStatus);
//  LEDStatus=false;
  digitalWrite(LED,LOW);
  int SensorData=digitalRead(soundSensor); 
  if(SensorData==1){
Serial.print("TTTTTTTT");
    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LED,HIGH);
//        delay(5000);
    }
    else{
        LEDStatus=false;
        digitalWrite(LED,LOW);
//        delay(5000);
    }
    delay(1000);
  }
  digitalWrite(LED,LOW);

//  int sensorValue = digitalRead(pirSensor);
//  if (sensorValue == 1) {
//    if(LEDStatus==false){
//        LEDStatus=true;
//        digitalWrite(LED,HIGH);
//    }
//    else{
//        LEDStatus=false;
//        digitalWrite(LED,LOW);
//    }
// } 
//  Serial.print("Sense:"+sensorValue);
//  digitalWrite(LED,LOW);

}
