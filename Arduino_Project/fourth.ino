#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(8,OUTPUT);//motor direction control
  pinMode(9,OUTPUT);//motor direction control
  pinMode(10,OUTPUT);//motor speed control
  pinMode(6,OUTPUT);//led pin
  pinMode(7,OUTPUT);//led pin
  pinMode(A0,INPUT);//analog input
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp=analogRead(A0);
  if(temp>41){
  if(temp>41&&temp<=62){//here,42 is analog reading from 21'C & 62 is 30'C
  digitalWrite(6,LOW);//led pin
  digitalWrite(7,HIGH);//led pin
  digitalWrite(8,LOW);//motor direction
  digitalWrite(9,HIGH);//motor direction
  analogWrite(10,64);//pwm
  lcd.setCursor(0,0);
  lcd.print("Speed 1");
  }
  else if(temp>62&&temp<=72){//here,62 is analog reading from 30'C & 62 is 30'C
  digitalWrite(6,LOW);//led pin
  digitalWrite(7,HIGH);//led pin
  digitalWrite(8,LOW);//motor direction
  digitalWrite(9,HIGH);//motor direction
  analogWrite(10,128);
  lcd.setCursor(0,0);
  lcd.print("Speed 2");
  }
  else{
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);//motor direction
  digitalWrite(9,HIGH);//motor direction
  analogWrite(10,255);
  lcd.setCursor(0,0);
  lcd.print("Speed 3");
  }
  }
  else{
  digitalWrite(6,LOW);//led pin
  digitalWrite(7,LOW);//led pin
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  analogWrite(10,0);
  lcd.setCursor(0,0); 
  lcd.print("Fan OFF");
  }
}
