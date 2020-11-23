#include <LiquidCrystal.h>
LiquidCrystal lcd(9,8,7,6,5,4);
#define sensor A7
#define led 3
#define buz 10
#define motor A1
void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Alcohol Detector");
  lcd.setCursor(0,1);
  delay(2000);
  pinMode(sensor, INPUT);
  pinMode(buz, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(motor, OUTPUT);
  lcd.clear();
}

void loop() 
{
  float adcValue=0;
  for(int i=0;i<10;i++)
  {
    adcValue+= analogRead(sensor);
    delay(10);
  }
    float v= (adcValue/10) * (5.0/1024.0);
    float mgL= 0.67 * v;
    if(mgL > 0.8)
    { 
      lcd.print("Drunk   ");
      Serial.println("    Drunk");
      digitalWrite(buz, HIGH);
      digitalWrite(led, HIGH);
      digitalWrite(motor, LOW);
    }
    else
    {
      lcd.print("Normal  ");
      Serial.println("    Normal");
      digitalWrite(buz, LOW);
      digitalWrite(led, LOW);
      digitalWrite(motor, HIGH);
    }

    delay(1000);
    
}
