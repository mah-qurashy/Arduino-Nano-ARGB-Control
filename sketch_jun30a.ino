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
  int color1[3] = {255, 0, 0};
  int color2[3] = {3, 2, 200};
  int color3[3] = {255, 150, 255};
  int delayval = 120;
  //twinspin(color1, color2, delayval);
  //buffer(color1, delayval);
  //bufferdual(color1,color2, delayval);
  //bufferpenta(color3, delayval);
  //twinfill(color1, color3, delayval);
  rainbowrevisited(delayval);
  //twinfillwblack(color1, color2, delayval);
}
void rainbowrevisited(int delayval)
{
  int arrlen = 15;
  int colormatrix[15][3] = {{255, 0, 125},
                            {255, 0, 255},
                            {255, 0, 255},
                            {125, 0, 255},
                            {0, 0, 255},
                            {0, 0, 255},
                            {0, 125, 255},
                            {0, 255, 255},
                            {0, 255, 125},
                            {0, 255, 0},
                            {0, 255, 0},
                            {125, 255, 0},
                            {255, 125, 0},
                            {255, 0, 0},
                            {255, 0, 0}

  };
  /*
  int colormatrix[30][3] = {{255,0,0},
                            {255,51,0},
                            {255,102,0},
                            {255,153,0},
                            {255,204,0},
                            {255,255,0},
                            {204,255,0},
                            {153,255,0},
                            {102,255,0},
                            {51,255,0},
                            {0,255,0},
                            {0,255,51},
                            {0,255,102},
                            {0,255,153},
                            {0,255,204},
                            {0,255,255},
                            {0,204,255},
                            {0,153,255},
                            {0,102,255},
                            {0,51,255},
                            {0,0,255},
                            {51,0,255},
                            {102,0,255},
                            {153,0,255},
                            {204,0,255},
                            {255,0,255},
                            {255,0,204},
                            {255,0,153},
                            {255,0,102},
                            {255,0,53}}; */

  for (int i = 0; i < arrlen; i++)
  {
    for (int j = 0; j < NUMPIXELS; j++)
    {
      pixels.setPixelColor(j, pixels.Color(colormatrix[(i + j) % (arrlen)][0], colormatrix[(i + j) % (arrlen)][1], colormatrix[(i + j) % (arrlen)][2]));
    }
    pixels.show();
    delay(0.25 * delayval);
    for (int j = 0; j < NUMPIXELS; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0.72 * colormatrix[(i + j) % (arrlen)][0] + 0.25 * colormatrix[(i + j + 1) % (arrlen)][0], 0.75 * colormatrix[(i + j) % (arrlen)][1] + 0.25 * colormatrix[(i + j + 1) % (arrlen)][1], 0.75 * colormatrix[(i + j) % (arrlen)][2] + 0.25 * colormatrix[(i + j + 1) % (arrlen)][2]));
    }
    pixels.show();
    delay(0.25 * delayval);
  
      for (int j = 0; j < NUMPIXELS; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0.5 * colormatrix[(i + j) % (arrlen)][0] + 0.5 * colormatrix[(i + j + 1) % (arrlen)][0], 0.5 * colormatrix[(i + j) % (arrlen)][1] + 0.5 * colormatrix[(i + j + 1) % (arrlen)][1], 0.5 * colormatrix[(i + j) % (arrlen)][2] + 0.5 * colormatrix[(i + j + 1) % (arrlen)][2]));
    }
    pixels.show();
    delay(0.25 * delayval);
  
      for (int j = 0; j < NUMPIXELS; j++)
    {
      pixels.setPixelColor(j, pixels.Color(0.25 * colormatrix[(i + j) % (arrlen)][0] + 0.75 * colormatrix[(i + j + 1) % (arrlen)][0], 0.25 * colormatrix[(i + j) % (arrlen)][1] + 0.75 * colormatrix[(i + j + 1) % (arrlen)][1], 0.25 * colormatrix[(i + j) % (arrlen)][2] + 0.75 * colormatrix[(i + j + 1) % (arrlen)][2]));
    }
    pixels.show();
    delay(0.25 * delayval);
  
}
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
void bufferdual(int c1[3], int c2[3], int delayval)
{

  int colormatrix[15][3] = {
      {c1[0], c1[1], c1[2]},
      {c1[0], c1[1], c1[2]},
      {(int)floor(0.75 * c1[0]), (int)floor(0.75 * c1[1]), (int)floor(0.75 * c1[2])},
      {(int)floor(0.5 * c1[0]), (int)floor(0.5 * c1[1]), (int)floor(0.5 * c1[2])},
      {(int)floor(0.25 * c1[0]), (int)floor(0.25 * c1[1]), (int)floor(0.25 * c1[2])},
      {0, 0, 0},
      {0, 0, 0},
      {c2[0], c2[1], c2[2]},
      {c2[0], c2[1], c2[2]},
      {(int)floor(0.75 * c2[0]), (int)floor(0.75 * c2[1]), (int)floor(0.75 * c2[2])},
      {(int)floor(0.5 * c2[0]), (int)floor(0.5 * c2[1]), (int)floor(0.5 * c2[2])},
      {(int)floor(0.25 * c2[0]), (int)floor(0.25 * c2[1]), (int)floor(0.25 * c2[2])},
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
