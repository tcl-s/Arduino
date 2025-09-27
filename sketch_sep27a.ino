  #include <LiquidCrystal.h>
  #include <Servo.h>
  Servo myservo;
  int pos = 0;
  const int rs=A4,en=A5,d4=A0,d5=A1,d6=A2,d7=A3;
  LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

  void setup() {
    // put your setup code here, to run once:
    lcd.begin(16,2);
    myservo.attach(9);
    lcd.print("operation:");
  }

  void loop() {
    // put your main code here, to run repeatedly:
    int up=digitalRead(7);
    int down=digitalRead(4);
    
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
