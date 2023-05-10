#include <LiquidCrystal.h>


LiquidCrystal lcd(2, 3, 4, 5, 6,7);
const int buzzer_Pin = 12;
const int led_Pin = 9;
char sleep_status = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(buzzer_Pin, OUTPUT);
  pinMode(led_Pin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Driver Sleep ");
  Serial.print("Driver Sleep ");
  lcd.setCursor(0,2);
  lcd.print("Detection SYSTEM");
  Serial.print("Detection SYSTEM");
  digitalWrite(buzzer_Pin, LOW); 
  digitalWrite(led_Pin, LOW);
}
void loop() 
{
    while (Serial.available() > 0) 
  {
    sleep_status = Serial.read();
    if(sleep_status == 'a')
    { 
        lcd.clear();
        lcd.print("Please wake up");
        Serial.print("Please wake up");
        digitalWrite(buzzer_Pin, HIGH); 
        digitalWrite(led_Pin, HIGH);
        delay(2000);
        digitalWrite(buzzer_Pin, LOW); 
        digitalWrite(led_Pin, LOW);
        
        delay(100);
    }
    else if(sleep_status == 'b')
    {
        lcd.clear();
        lcd.print("All Ok");
        Serial.print("All Ok");
        lcd.setCursor(0,2);
        lcd.print("Drive Safe");
        Serial.print("Drive Safe");
        digitalWrite(buzzer_Pin, LOW); 
        digitalWrite(led_Pin, LOW);
        delay(2000);
    }
    else
    {
      /* Do Nothing */
    }
  }
}
