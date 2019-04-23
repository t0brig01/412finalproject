
#include<LiquidCrystal.h>
LiquidCrystal lcd(12,13,8,9,10,11); //sets pins for lcd
#define SENSORPIN 2 //dime
#define SENSORPIN2 3 //nickel
#define SENSORPIN3 4 //quarter

int sensorState = 0;
int lastState = 0;
int sensorState2 = 0;
int sensorState3 = 0;
int sum; // keeps track of current money total
void setup() {      
  pinMode(SENSORPIN, INPUT); //initialize sensor as input 
  pinMode(SENSORPIN2, INPUT);//initialize sensor as input
  pinMode(SENSORPIN3, INPUT);//initialize sensor as input     
  digitalWrite(SENSORPIN, HIGH); 
  digitalWrite(SENSORPIN2, HIGH);
  digitalWrite(SENSORPIN3, HIGH);
  
  Serial.begin(9600);
}
 
void loop(){
  sensorState = digitalRead(SENSORPIN); //reads sensor value
  sensorState2 = digitalRead(SENSORPIN2); //reads sensor value
  sensorState3 = digitalRead(SENSORPIN3); //reads sensor value
 
  if (sensorState == LOW) { //checks if sensor 1 beam is broken    
    delay(500);
    sum += 10;
    displayLCD();
 
  } 

   if (sensorState2 == LOW){ //checks if sensor 2 beam is broken
    delay(500);
    sum += 5;
    displayLCD();
  }
  if(sensorState3 == LOW) { //checks if sensor 3 beam is broken
    delay(500);
    sum += 25;
    displayLCD();
  }
 
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
  }
  lastState = sensorState;
}
void displayLCD(){ //function to display total value
  lcd.clear();
  lcd.print("Total:");
  lcd.print(sum);
}
