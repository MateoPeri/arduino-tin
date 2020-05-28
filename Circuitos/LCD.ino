#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int switchPin = 6;

int rows = 2;
int cols = 16;

void setup
  () {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  lcd.begin(cols, rows);
  lcd.print("Hola!");
  
}

void loop() {
  // no pita
  byte state = digitalRead(switchPin);
  Serial.println(state);
  print("Que tal", state == HIGH);
}

int index = 0;
void print(String s, bool forward)
{
  int len = s.length();
  int step = forward ? 1 : -1;
  
  if (index >= cols)
  {
    index = 0;
  }
  if (index < 0)
  {
    index = cols-1;
  }
  
  for (int c = 0; c < cols; c++)
  {
    lcd.setCursor(c, 1);
    if (c >= index && c-index < len)
    {
      lcd.print(s[c-index]);
    } else
    {
      lcd.print(" ");
    }
  }
  
  index += step;
  delay(350);
}
