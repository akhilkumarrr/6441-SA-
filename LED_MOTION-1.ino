#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int LED=4;
boolean LEDStatus=false;
boolean pirMsg=false;
int soundSensor=2;
int pirPin=7;
int blueLed = 8;
int smokeA0 = A1;
// Your threshold value
int sensorThres = 500;


void setup() {
   Serial.begin(9600);
   pinMode(LED,OUTPUT);
   pinMode(soundSensor,INPUT);
   pinMode(pirPin, INPUT);
   pinMode(blueLed, OUTPUT);
   pinMode(smokeA0, INPUT);
   lcd.init();                     
   lcd.backlight();
}

void loop() {
   soundSensorMethod();
   PIRSensor();
   smokeSensor();
//   delay(2000);
}



void light(boolean temp){
   if(temp==true){
        digitalWrite(LED,HIGH);
        Serial.println("Light On");
    }
    else{
        digitalWrite(LED,LOW);
        Serial.println("Light Off");
    }  
  }

void sendDistplay(String myMsg){
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print(myMsg);
//  delay(3000);
  }
  
void PIRSensor() {
  int SensorData=digitalRead(pirPin);
   Serial.println("PIR Test");
   Serial.println(SensorData);
  if(SensorData==1){
    Serial.println("PIR Test True");
    if(pirMsg==false){
      Serial.println("PIR Test True 1");
         pirMsg==true;
         Serial.println("Motion detected.");
         sendDistplay("Motion detected.");
    }
   }
    else{
      Serial.println("PIR Test False");
//      if(pirMsg==true){
        Serial.println("PIR Test False 1");
         Serial.println("Motion ended.");
         pirMsg==false;
         sendDistplay("Motion ended."); 
  }
//   delay(2000);
}

void soundSensorMethod() {
 Serial.println("Sound Test");
  int SensorData=digitalRead(soundSensor); 
  Serial.println(SensorData);
  if(SensorData==1){
  Serial.println("Sound Sences");
    if(LEDStatus==false){
        LEDStatus=true;
        light(true);
//        delay(5000);
    }
    else{
        LEDStatus=false;
        light(false);
//        delay(5000);
    }
  }
    Serial.println("Sound Completed");

}
void smokeSensor() {
   Serial.println("Ssmoke Test");
   int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(blueLed, HIGH);
  }
  else
  {
    digitalWrite(blueLed, LOW);
  }
  }
