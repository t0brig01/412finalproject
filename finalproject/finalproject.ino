  #include<LiquidCrystal.h>

LiquidCrystal lcd(12,13,8,9,10,11); //initalize LCD

const int interruptPinQuarter = 2; 
const int interruptPinDime = 3;
const int interruptPinNickel = 4;  
const int interruptPinPenny = 5;  

int sum = 0;
bool changed = true;

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
  if (changed == true){
    displayLCD();
    Serial.println(sum);
    changed = false;
  }
}
void displayLCD(){
  lcd.clear();
  lcd.print("Total:");
  lcd.print(sum);
}
void brokenQuarter(){
  changed = true;
  delay(500);
  sum += 25;
  Serial.println("Break - Quarter");
}
void brokenDime(){
  changed = true;
  delay(500);
  sum += 10;
  Serial.println("Break - Dime");
}
void brokenNickel(){
  changed = true;
  delay(500);
  sum += 5;
  Serial.println("Break - Nickel");
}
void brokenPenny(){
  changed = true;
  delay(500);
  sum += 1;
  Serial.println("Break - Penny");
}
