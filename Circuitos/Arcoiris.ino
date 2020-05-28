int RPin = 6;
int GPin = 9;
int BPin = 5;

int rgb [3] = {0, 0, 0};

void setup()
{
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
  pinMode(BPin, OUTPUT);
}

void loop()
{
  // Los colores del arcoíris
  int r [3] = {255, 0, 0};
  int g [3] = {0, 255, 0};
  int b [3] = {0, 0, 255};
  int y [3] = {255, 255, 0};
  int p [3] = {80, 0, 80};
  int a [3] = {0, 255, 255};
  smooth(r, 10);
  smooth(g, 10);
  smooth(b, 10);
  smooth(y, 10);
  smooth(p, 10);
  smooth(a, 10);
}

void refreshColors()
{
  analogWrite(RPin, rgb[0]);
  analogWrite(GPin, rgb[1]);
  analogWrite(BPin, rgb[2]); 
}

// cambia los valores rgb poco a poco
void smooth(int desired[], int t)
{
  while (!compareArrays(rgb, desired))
  {
    for (int i = 0; i < 3; i++)
    {
      if (rgb[i] == desired[i])
        continue;
      int sign = rgb[i] < desired[i] ? 1 : -1;
      rgb[i] += sign;
    }
    refreshColors();
    delay(t);
  }
}

// función extra para comparar si dos arrays tienen los mismos valores
bool compareArrays(int a[], int b[])
{
  for (int i = 0;  i < 3; i++)
  {
    if(a[i] != b[i])
    {
      return false;
    }
  }
  return true;
}
