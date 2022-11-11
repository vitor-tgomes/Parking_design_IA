#include <LiquidCrystal.h>
#define trigPin1 7
#define trigPin2 8
#define echoPin1 7
#define echoPin2 8
#define led2 6
#define led3 9
#define led5 10
#define led6 13
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

bool bool1=false;
bool bool2=false;
  
  long readUltrasonicDistance(int triggerPin, int echoPin){
    pinMode(triggerPin, OUTPUT);  
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return pulseIn(echoPin, HIGH);
  }

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  lcd.begin(16,2);
  
}
void loop() {
  float distance1;
  float distance2;
  lcd.setCursor(0,0);
  
   distance1 = (readUltrasonicDistance(7, 7) * 0.034)/2;
   Serial.println(distance1);
   if (distance1 <=200|| distance1 <= 0){
     digitalWrite(led2, LOW);
     digitalWrite(led3, HIGH);
     bool1=false;
  }
  else {
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    bool1=true;
  }
    distance2 = (readUltrasonicDistance(8, 8) * 0.034)/2;
   if (distance2 <=200 || distance2 <= 0){
    digitalWrite(led5, LOW);
     digitalWrite(led6, HIGH);
     bool2=false;
  }
  else {
    digitalWrite(led6, LOW);
    digitalWrite(led5, HIGH);
    bool2=true;
  }
  lcd.clear();
  
  if(!bool1&&!bool2)
  {
    lcd.setCursor(0, 0);
    lcd.print("VAGAS OCUPADAS");
  }
  else if(bool1&&!bool2)
  {
        lcd.setCursor(0, 0);
    lcd.print("VAGA 1 LIVRE");
    lcd.setCursor(0,1);
    lcd.print("VAGA 2 OCUPADA");
  }
  else if(!bool1&&bool2)
  {
        lcd.setCursor(0, 0);
    lcd.print("VAGA 1 OCUPADA");
    lcd.setCursor(0,1);
    lcd.print("VAGA 2 LIVRE");
  }
  else if(!bool1&&!bool2)
  {
    lcd.setCursor(0, 0);
    lcd.print("VAGAS LIVRES");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("VAGAS LIVRES");
  }
  delay(500);
  
lcd.clear();
}
