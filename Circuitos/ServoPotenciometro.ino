#include <Servo.h>

Servo _servo;

void setup()
{
  _servo.attach(9);
}

void loop()
{
  int val = analogRead(0);
  val = map(val, 0, 1023, 0, 179);
  _servo.write(val);
  delay(15);
}
