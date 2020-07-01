#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN 2
#define NUMPIXELS 15

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  pixels.begin();
  pixels.setBrightness(254);
  pixels.show();
}

void loop()
{
  int color1[3] = {155, 0, 115};
  int color2[3] = {35, 0, 100};
  int delayval = 70;
  //twinspin(color1, color2, delayval);
  // buffer(color1, delayval);
   //bufferdual(color1, delayval);
  //bufferpenta(color1, delayval);
  //twinfill(color1, color2, delayval);
  twinfillwblack(color1, color2, delayval);
}

void twinspin(int c1[3], int c2[3], int delayval)
{
  int colormatrix[15][3] = {
      {(int)floor(0.75 * c1[0] + 0.25 * c2[0]), (int)floor(0.75 * c1[1] + 0.25 * c2[1]), (int)floor(0.75 * c1[2] + 0.25 * c2[2])},
      {(int)floor(0.5 * c1[0] + 0.5 * c2[0]), (int)floor(0.5 * c1[1] + 0.5 * c2[1]), (int)floor(0.5 * c1[2] + 0.5 * c2[2])},
      {(int)floor(0.25 * c1[0] + 0.75 * c2[0]), (int)floor(0.25 * c1[1] + 0.75 * c2[1]), (int)floor(0.25 * c1[2] + 0.75 * c2[2])},
      {c2[0], c2[1], c2[2]},
      {c2[0], c2[1], c2[2]},
      {c2[0], c2[1], c2[2]},
      {c2[0], c2[1], c2[2]},
      {c2[0], c2[1], c2[2]},
      {(int)floor(0.75 * c2[0] + 0.25 * c1[0]), (int)floor(0.75 * c2[1] + 0.25 * c1[1]), (int)floor(0.75 * c2[2] + 0.25 * c1[2])},
      {(int)floor(0.5 * c2[0] + 0.5 * c1[0]), (int)floor(0.5 * c2[1] + 0.5 * c1[1]), (int)floor(0.5 * c2[2] + 0.5 * c1[2])},
      {(int)floor(0.25 * c2[0] + 0.75 * c1[0]), (int)floor(0.25 * c2[1] + 0.75 * c1[1]), (int)floor(0.25 * c2[2] + 0.75 * c1[2])},
      {c1[0], c1[1], c1[2]},
      {c1[0], c1[1], c1[2]},
      {c1[0], c1[1], c1[2]},
      {c1[0], c1[1], c1[2]}};

  for (int i = NUMPIXELS - 1; i >= 0; i--)
  {
    for (int j = NUMPIXELS - 1; j >= 0; j--)
    {
      pixels.setPixelColor((i + j) % (NUMPIXELS), pixels.Color(colormatrix[j][0], colormatrix[j][1], colormatrix[j][2]));
    }
    pixels.show();
    delay(0.5 * delayval);
    for (int j = NUMPIXELS - 1; j >= 0; j--)
    {
      pixels.setPixelColor((i + j) % (NUMPIXELS), pixels.Color(0.5 * colormatrix[j][0] + 0.5 * colormatrix[(j + 1) % 15][0], 0.5 * colormatrix[j][1] + 0.5 * colormatrix[(j + 1) % 15][1], 0.5 * colormatrix[j][2] + 0.5 * colormatrix[(j + 1) % 15][2]));
    }
    pixels.show();
    delay(0.5 * delayval);
  }
}
void buffer(int c1[3], int delayval)
{

  int colormatrix[15][3] = {
      {c1[0], c1[1], c1[2]},
      {c1[0], c1[1], c1[2]},
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.75 * c1[0]), (int)floor(0.75 * c1[1]), (int)floor(0.75 * c1[2])},
      {(int)floor(0.5 * c1[0]), (int)floor(0.5 * c1[1]), (int)floor(0.5 * c1[2])},
      {(int)floor(0.25 * c1[0]), (int)floor(0.25 * c1[1]), (int)floor(0.25 * c1[2])},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}};

  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //rotater
    for (int j = NUMPIXELS - 1; j >= 0; j--)
    { //map matrix to led
      pixels.setPixelColor((i + j) % (NUMPIXELS), pixels.Color(colormatrix[j][0], colormatrix[j][1], colormatrix[j][2]));
    }
    pixels.show();
    delay(0.5 * delayval);
    for (int j = NUMPIXELS - 1; j >= 0; j--)
    {
      pixels.setPixelColor((i + j) % (NUMPIXELS), pixels.Color(0.5 * colormatrix[j][0] + 0.5 * colormatrix[(j + 1) % 15][0], 0.5 * colormatrix[j][1] + 0.5 * colormatrix[(j + 1) % 15][1], 0.5 * colormatrix[j][2] + 0.5 * colormatrix[(j + 1) % 15][2]));
    }
    pixels.show();
    delay(0.5 * delayval);
  }
}
void bufferdual(int c1[3], int delayval)
{

  int colormatrix[15][3] = {
      {c1[0], c1[1], c1[2]},
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.75 * c1[0]), (int)floor(0.75 * c1[1]), (int)floor(0.75 * c1[2])},
      {(int)floor(0.5 * c1[0]), (int)floor(0.5 * c1[1]), (int)floor(0.5 * c1[2])},
      {(int)floor(0.25 * c1[0]), (int)floor(0.25 * c1[1]), (int)floor(0.25 * c1[2])},
      {0, 0, 0},
      {0, 0, 0},
      {c1[0], c1[1], c1[2]},
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.75 * c1[0]), (int)floor(0.75 * c1[1]), (int)floor(0.75 * c1[2])},
      {(int)floor(0.5 * c1[0]), (int)floor(0.5 * c1[1]), (int)floor(0.5 * c1[2])},
      {(int)floor(0.25 * c1[0]), (int)floor(0.25 * c1[1]), (int)floor(0.25 * c1[2])},
      {0, 0, 0},
      {0, 0, 0},
      {0, 0, 0}};

  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //rotater
    for (int j = NUMPIXELS - 1; j >= 0; j--)
    { //map matrix to led
      pixels.setPixelColor((i + j) % (NUMPIXELS), pixels.Color(colormatrix[j][0], colormatrix[j][1], colormatrix[j][2]));
    }
    pixels.show();
    delay(0.5 * delayval);
    for (int j = NUMPIXELS - 1; j >= 0; j--)
    {
      pixels.setPixelColor((i + j) % (NUMPIXELS), pixels.Color(0.5 * colormatrix[j][0] + 0.5 * colormatrix[(j + 1) % 15][0], 0.5 * colormatrix[j][1] + 0.5 * colormatrix[(j + 1) % 15][1], 0.5 * colormatrix[j][2] + 0.5 * colormatrix[(j + 1) % 15][2]));
    }
    pixels.show();
    delay(0.5 * delayval);
  }
}
void bufferpenta(int c1[3], int delayval)
{

  int colormatrix[15][3] = {
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])},
      {(int)floor(0.1 * c1[0]), (int)floor(0.1 * c1[1]), (int)floor(0.1 * c1[2])}

  };

  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //rotater
    for (int j = NUMPIXELS - 1; j >= 0; j--)
    { //map matrix to led
      pixels.setPixelColor((i + j) % (NUMPIXELS), pixels.Color(colormatrix[j][0], colormatrix[j][1], colormatrix[j][2]));
    }
    pixels.show();
    delay(0.5 * delayval);
    for (int j = NUMPIXELS - 1; j >= 0; j--)
    {
      pixels.setPixelColor((i + j) % (NUMPIXELS), pixels.Color(0.5 * colormatrix[j][0] + 0.5 * colormatrix[(j + 1) % 15][0], 0.5 * colormatrix[j][1] + 0.5 * colormatrix[(j + 1) % 15][1], 0.5 * colormatrix[j][2] + 0.5 * colormatrix[(j + 1) % 15][2]));
    }
    pixels.show();
    delay(0.5 * delayval);
  }
}

void twinfill(int c1[3], int c2[3], int delayval)
{

  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //c2 to c1
    pixels.setPixelColor(i, pixels.Color(c1[0], c1[1], c1[2]));
    pixels.show();
    delay(0.5 * delayval);
    pixels.setPixelColor((i - 1), pixels.Color(0.5 * c1[0] + 0.5 * c2[0], 0.5 * c1[1] + 0.5 * c2[1], 0.5 * c1[2] + 0.5 * c2[2]));
    pixels.show();
    delay(0.5 * delayval);
  }
  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //c1 to c2
    pixels.setPixelColor(i, pixels.Color(c2[0], c2[1], c2[2]));
    pixels.show();
    delay(0.5 * delayval);
    pixels.setPixelColor((i - 1), pixels.Color(0.5 * c1[0] + 0.5 * c2[0], 0.5 * c1[1] + 0.5 * c2[1], 0.5 * c1[2] + 0.5 * c2[2]));
    pixels.show();
    delay(0.5 * delayval);
  }
  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //hold c2
    pixels.setPixelColor(i, pixels.Color(c2[0], c2[1], c2[2]));
    pixels.show();
    delay(delayval);
  }
}

void twinfillwblack(int c1[3], int c2[3], int delayval)
{

  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //black to c1
    pixels.setPixelColor(i, pixels.Color(c1[0], c1[1], c1[2]));
    pixels.show();
    delay(0.5 * delayval);
    pixels.setPixelColor((i - 1), pixels.Color(0.5 * c1[0], 0.5 * c1[1], 0.5 * c1[2]));
    pixels.show();
    delay(0.5 * delayval);
  }
  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //c1 to c2
    pixels.setPixelColor(i, pixels.Color(c2[0], c2[1], c2[2]));
    pixels.show();
    delay(0.5 * delayval);
    pixels.setPixelColor((i - 1), pixels.Color(0.5 * c1[0] + 0.5 * c2[0], 0.5 * c1[1] + 0.5 * c2[1], 0.5 * c1[2] + 0.5 * c2[2]));
    pixels.show();
    delay(0.5 * delayval);
  }
  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //hold c2
    pixels.setPixelColor(i, pixels.Color(c2[0], c2[1], c2[2]));
    pixels.show();
    delay(delayval);
  }
  for (int i = NUMPIXELS - 1; i >= 0; i--)
  { //c2 to black
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
    delay(0.5 * delayval);
    pixels.setPixelColor((i - 1), pixels.Color(0.5 * c2[0], 0.5 * c2[1], 0.5 * c2[2]));
    pixels.show();
    delay(0.5 * delayval);
  }
}
