#include <LiquidCrystal.h>
#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN 2
#define ECHO_PIN 12

#define MAX_DISTANCE 40

const int rs=A4,en=A5,d4=A0,d5=A1,d6=A2,d7=A3;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
Servo myservo;
int pos = 0; 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
int enable=digitalRead(8);
lcd.clear();
  if(enable==0){
    
    int up=digitalRead(7);
      int down=digitalRead(4);
      /*-------------------------------------------*/
      if(up==1&&down==0){
        lcd.setCursor(10,0);
        lcd.print("+degs");
        pos+=30;
      }
      else if(up==0&&down==1){
        lcd.setCursor(10,0);
        lcd.print("-degs");
        pos-=30;
      }
      else if(up==1&&down==1){
        lcd.setCursor(10,0);
        lcd.print("reset");
        pos=0;
      }
      else{
        //pass
      }
      /*-------------------------------------------*/
      if(pos<0){
        pos=0;
      }
      else if (pos>180) {
        pos=180;
      }
      myservo.write(pos);
      /*-------------------------------------------*/
      lcd.setCursor(0,1);
      if (pos<100) {
    lcd.print("0");
    lcd.print(pos);
      }
      else{
        lcd.print(pos);
      }
      delay(700);
  }
  else if(enable==0){
    lcd.clear();
    int enable1=digitalRead(13);
    if (enable1==1) {
      Serial.print("Distance = ");
      //Serial.print(sonar.ping_in());
      //Serial.print((sonar.ping() / 2) * 0.0343);
      int iterations = 5;
      float dis=(sonar.ping_median(iterations) / 2) * 0.0341*10;
      lcd.setCursor(10,0);
      lcd.print(dis);
      delay(2500);
    }
  }
}
