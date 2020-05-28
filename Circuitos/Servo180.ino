#include <Servo.h>

Servo _servo;

void setup()
{
  Serial.begin(9600);
  _servo.attach(9);
}

void loop()
{
  int val;
  if (Serial.available() > 0)
  	val = Serial.parseInt();
  if (val > 0 && val <= 180)
  {
    _servo.write(val);
    delay(15);
  }
}
