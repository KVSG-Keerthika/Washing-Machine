#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int SWITCH_ON = 13;
int LED_RED = A0;
int LED_GREEN =A1;
int MOTAR_IN_1=8;
int MOTAR_IN_2=9;
int MOTAR_PIN2_IN1=7;
int MOTAR_PIN2_IN2=6;
int S = 0;


void setup() {
  // put your setup code here, to run once:
pinMode(SWITCH_ON,INPUT);
pinMode(LED_RED,OUTPUT);
pinMode(LED_GREEN,OUTPUT);
pinMode( MOTAR_IN_1,OUTPUT);
pinMode(MOTAR_IN_2,OUTPUT);
pinMode( MOTAR_PIN2_IN1,OUTPUT);
pinMode( MOTAR_PIN2_IN2,OUTPUT);
lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
  S=digitalRead(SWITCH_ON);
  if(S==HIGH){
    lcd.setCursor(0,0);
    lcd.print("WELCOME TO ");
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print("WASHING MACHINE");
    delay(1000);
    lcd.clear();
    
    digitalWrite(LED_RED,HIGH);
    delay(1000);
    digitalWrite( MOTAR_IN_1,HIGH);
    digitalWrite( MOTAR_IN_2,LOW);
    delay(1500);
    
    //clockwise motion
     digitalWrite( MOTAR_IN_1,LOW);
    digitalWrite( MOTAR_IN_2,LOW);
    digitalWrite( MOTAR_PIN2_IN1,HIGH);
    digitalWrite( MOTAR_PIN2_IN2,LOW);
    lcd.print("SPINNING MODE");
    delay(1500);
    lcd.clear();
    //anticlock wise motion
     digitalWrite( MOTAR_PIN2_IN1,LOW);
    digitalWrite( MOTAR_PIN2_IN2,HIGH);
    lcd.print("DRYING MODE");
    delay(1000);
    lcd.clear();
     digitalWrite(LED_GREEN,HIGH);
     lcd.print("WASHING DONE");
      delay(1000);
    lcd.clear();
  }

}
