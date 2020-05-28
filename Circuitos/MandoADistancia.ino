#include <IRremote.h>
#define len(array) ((sizeof(array))/(sizeof(array[0])))


int recPin = 2;
int ledDict[3][2] = {{13, 1}, {12, 0}, {11, 0}};
int index = 0;

IRrecv rec(recPin);

decode_results results;

void setup() {
  Serial.begin(9600);
  rec.enableIRIn();
  for (int i = 0; i < len(ledDict); i++)
  {
    pinMode(ledDict[i][0], OUTPUT);
  }
  setLed();
}

void refresh()
{
  for (int i = 0; i < len(ledDict); i++)
  {
    digitalWrite(ledDict[i][0], ledDict[i][1]);
  }
}

void setLed()
{
  // importante pasar de long a int, si no la comparación no es correcta
  int l = len(ledDict);
  if (index >= l)
  {
    Serial.println("4rj");
    index = 0;
  }
  if (index < 0)
  {
    Serial.println("eoo");
    index = l-1;
  }
  for (int i = 0; i < len(ledDict); i++)
  {
    ledDict[i][1] = i == index ? 1 : 0;
  }
  Serial.print("Encenciendo el led ");
  Serial.println(index);
  refresh();
}

void loop() {
  if (rec.decode(&results))
  {
    int val = results.value;
    Serial.println(val);
    Serial.println("");
    
    switch (val)
    {
      case 255:
        Serial.println("apagao");
        for (int i = 0; i < len(ledDict); i++)
        {
          ledDict[i][1] = 0;
        }
        refresh();
      	break;
      case 20655:
      	Serial.println("up");
      	index++;
      	setLed();
      	break;
      case 4335:
      	Serial.println("down");
      	index--;
      	setLed();
      	break;
      default:
      	Serial.println("?");
      	break;
    }
    
    rec.resume();
    delay(100);
  }
}
