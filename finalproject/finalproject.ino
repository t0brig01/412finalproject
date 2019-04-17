#include<LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13); //initalize LCD

const int interruptPinQuarter = 2; 
const int interruptPinDime = 3;
const int interruptPinNickel = 4;  
const int interruptPinPenny = 5;  

int sum = 0;
 

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.display();

  pinMode(interruptPinQuarter,INPUT);
  pinMode(interruptPinDime,INPUT);
  pinMode(interruptPinNickel,INPUT);
  pinMode(interruptPinPenny,INPUT);

  attachInterrupt(digitalPinToInterrupt(interruptPinQuarter), brokenQuarter, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPinDime), brokenDime, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPinNickel), brokenNickel, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPinPenny), brokenPenny, FALLING);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  displayLCD();
  Serial.println(sum);
}
void displayLCD(){
  lcd.clear();
  lcd.print("Total:");
  lcd.print(sum);
}
void brokenQuarter(){
  sum += 25;
  delay(500);
}
void brokenDime(){
  sum += 10;
  delay(500);
}
void brokenNickel(){
  sum += 5;
  delay(500);
}
void brokenPenny(){
  sum += 1;
  delay(500);
}


