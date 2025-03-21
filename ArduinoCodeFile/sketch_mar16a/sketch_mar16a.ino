#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void setLed(int L, int R, int G, int B, int W)
{ 
  switch (L % 3)
  {
    case 1:
      switch (L)
      {
        case 1:
          leds[0].r = R; FastLED.show();
          leds[0].g = G; FastLED.show();
          leds[0].b = B; FastLED.show();
          leds[1].g = W; FastLED.show();
          break;
        case 4:
          leds[4].r = R; FastLED.show();
          leds[4].g = G; FastLED.show();
          leds[4].b = B; FastLED.show();
          leds[5].g = W; FastLED.show();
          break;
        case 7:
          leds[8].r = R; FastLED.show();
          leds[8].g = G; FastLED.show();
          leds[8].b = B; FastLED.show();
          leds[9].g = W; FastLED.show();
          break;
        case 10:
          leds[12].r = R; FastLED.show();
          leds[12].g = G; FastLED.show();
          leds[12].b = B; FastLED.show();
          leds[13].g = W; FastLED.show(); 
          break;
        case 13:
          leds[16].r = R; FastLED.show();
          leds[16].g = G; FastLED.show();
          leds[16].b = B; FastLED.show();
          leds[17].g = W; FastLED.show();
          break;
        case 16:
          leds[20].r = R; FastLED.show(); 
          leds[20].g = G; FastLED.show(); 
          leds[20].b = B; FastLED.show(); 
          leds[21].g = W; FastLED.show(); 
          break;
      }
      break; 
    case 2:
      switch (L)
      {
        case 2:
          leds[1].r = G; FastLED.show();
          leds[1].b = R; FastLED.show();
          leds[2].r = W; FastLED.show();
          leds[2].g = B; FastLED.show();
          break;
        case 5:
          leds[5].b = R; FastLED.show();
          leds[5].r = G; FastLED.show();
          leds[6].g = B; FastLED.show();
          leds[6].r = W; FastLED.show();
          break;
        case 8:
          leds[9].r = G; FastLED.show();
          leds[9].b = R; FastLED.show();
          leds[10].r = W; FastLED.show();
          leds[10].g = B; FastLED.show();  
          break;           
        case 11:
          leds[13].r = G; FastLED.show(); 
          leds[13].b = R; FastLED.show(); 
          leds[14].r = W; FastLED.show(); 
          leds[14].g = B; FastLED.show(); 
          break;
        case 14:
          leds[17].b = R; FastLED.show(); 
          leds[17].r = G; FastLED.show(); 
          leds[18].g = B; FastLED.show(); 
          leds[18].r = W; FastLED.show();   
          break;
      }
      break;
    case 0:
      switch (L) 
      {
        case 3:
          leds[3].r = B; FastLED.show();
          leds[3].g = R; FastLED.show();
          leds[3].b = W; FastLED.show();
          leds[2].b = G; FastLED.show();
          break;
        case 6:
          leds[7].r = B; FastLED.show();
          leds[7].g = R; FastLED.show();
          leds[7].b = W; FastLED.show();
          leds[6].b = G; FastLED.show(); 
          break;
        case 9:
          leds[11].g = R; FastLED.show(); // Ninth Red
          leds[10].b = G; FastLED.show(); // Ninth Green
          leds[11].r = B; FastLED.show(); // Ninth Blue
          leds[11].b = W; FastLED.show(); // Ninth White
          break;
        case 12:
          leds[15].r = B; FastLED.show(); 
          leds[15].g = R; FastLED.show(); 
          leds[15].b = W; FastLED.show(); 
          leds[14].b = G; FastLED.show(); 
          break;
        case 15:
          leds[19].r = B; FastLED.show(); 
          leds[19].g = R; FastLED.show(); 
          leds[19].b = W; FastLED.show(); 
          leds[18].b = G; FastLED.show(); 
          break;
      }
      break;
  }

}
/*
void setLed2 (int R, int G, int B, int W)
{
  leds[1].r = G; FastLED.show();
  leds[1].b = R; FastLED.show();
  leds[2].r = W; FastLED.show();
  leds[2].g = B; FastLED.show();
}

void setLed3 (int R, int G, int B, int W)
{
  leds[3].r = B; FastLED.show();
  leds[3].g = R; FastLED.show();
  leds[3].b = W; FastLED.show();
  leds[2].b = G; FastLED.show();
}

void setLed4 (int R, int G, int B, int W)
{
  leds[4].r = R; FastLED.show();
  leds[4].g = G; FastLED.show();
  leds[4].b = B; FastLED.show();
  leds[5].g = W; FastLED.show();
}

void setLed5 (int R, int G, int B, int W)
{
  leds[5].b = R; FastLED.show();
  leds[5].r = G; FastLED.show();
  leds[6].g = B; FastLED.show();
  leds[6].r = W; FastLED.show();
}

void setLed6 (int R, int G, int B, int W)
{
  leds[7].r = B; FastLED.show();
  leds[7].g = R; FastLED.show();
  leds[7].b = W; FastLED.show();
  leds[6].b = G; FastLED.show();  
}

void setLed7 (int R, int G, int B, int W)
{
  leds[8].r = R; FastLED.show();
  leds[8].g = G; FastLED.show();
  leds[8].b = B; FastLED.show();
  leds[9].g = W; FastLED.show();
}

void setLed8 (int R, int G, int B, int W)
{
  leds[9].r = G; FastLED.show();
  leds[9].b = R; FastLED.show();
  leds[10].r = W; FastLED.show();
  leds[10].g = B; FastLED.show();
}

void setLed9 (int R, int G, int B, int W)
{
    leds[11].g = R; FastLED.show(); // Ninth Red
    leds[10].b = G; FastLED.show(); // Ninth Green
    leds[11].r = B; FastLED.show(); // Ninth Blue
    leds[11].b = W; FastLED.show(); // Ninth White
}

void setLed(10, int R, int G, int B, int W) {
  leds[12].r = R; FastLED.show();
  leds[12].g = G; FastLED.show();
  leds[12].b = B; FastLED.show();
  leds[13].g = W; FastLED.show(); 
}

void setLed(11, int R, int G, int B, int W) {
  leds[13].r = G; FastLED.show(); 
  leds[13].b = R; FastLED.show(); 
  leds[14].r = W; FastLED.show(); 
  leds[14].g = B; FastLED.show(); 
}

void setLed12 (int R, int G, int B, int W) {
  leds[15].r = B; FastLED.show(); 
  leds[15].g = R; FastLED.show(); 
  leds[15].b = W; FastLED.show(); 
  leds[14].b = G; FastLED.show(); 
}

void setLed13 (int R, int G, int B, int W)
{
  leds[16].r = R; FastLED.show();
  leds[16].g = G; FastLED.show();
  leds[16].b = B; FastLED.show();
  leds[17].g = W; FastLED.show();
}

void setLed14 (int R, int G, int B, int W) {
  leds[17].b = R; FastLED.show(); 
  leds[17].r = G; FastLED.show(); 
  leds[18].g = B; FastLED.show(); 
  leds[18].r = W; FastLED.show(); 
}

void setLed15 (int R, int G, int B, int W) {
  leds[19].r = B; FastLED.show(); 
  leds[19].g = R; FastLED.show(); 
  leds[19].b = W; FastLED.show(); 
  leds[18].b = G; FastLED.show(); 
}

void setLed16 (int R, int G, int B, int W) {
  leds[20].r = R; FastLED.show(); 
  leds[20].g = G; FastLED.show(); 
  leds[20].b = B; FastLED.show(); 
  leds[21].g = W; FastLED.show(); 
}
*/
// Todo build speed function to track speeds to less ms
void traceOne (int R, int G, int B, int W, int R1, int G1, int B1, int W1, int delayTime) {
    setLed(1, R1, G1, B1, W1);
    setLed(2, R1, G1, B1, W1);
    setLed(3, R1, G1, B1, W1);
    setLed(4, R1, G1, B1, W1);
    setLed(5, R1, G1, B1, W1);
    setLed(6, R1, G1, B1, W1);
    setLed(7, R1, G1, B1, W1);
    setLed(8, R1, G1, B1, W1);
    setLed(9, R1, G1, B1, W1);
    setLed(10, R1, G1, B1, W1);
    setLed(11, R1, G1, B1, W1);
    setLed(12, R1, G1, B1, W1);
    setLed(13, R1, G1, B1, W1);
    setLed(4, R1, G1, B1, W1);
    setLed(5, R1, G1, B1, W1);
    setLed(6, R1, G1, B1, W1);

    delay(delayTime);

  while (true) {
    setLed(9, R, G, B, W);
    
    setLed(8, R, G, B, W);

    
    delay(delayTime);
    
    setLed(8, R1, G1, B1, W1);
    setLed(9, R1, G1, B1, W1);



    setLed(7, R, G, B, W);
    setLed(10, R, G, B, W);
    delay(delayTime);
    setLed(7, R1, G1, B1, W1);
    setLed(10, R1, G1, B1, W1);

    setLed(6, R, G, B, W);
    setLed(11, R, G, B, W);
    delay(delayTime);
    setLed(6, R1, G1, B1, W1);
    setLed(11, R1, G1, B1, W1);

    setLed(5, R, G, B, W);
    setLed(12, R, G, B, W);
    delay(delayTime);
    setLed(5, R1, G1, B1, W1);
    setLed(12, R1, G1, B1, W1);

    setLed(4, R, G, B, W);
    setLed(13, R, G, B, W);
    delay(delayTime);
    setLed(4, R1, G1, B1, W1);
    setLed(13, R1, G1, B1, W1);

    setLed(3, R, G, B, W);
    setLed(14, R, G, B, W);
    delay(delayTime);
    setLed(3, R1, G1, B1, W1);
    setLed(14, R1, G1, B1, W1);

    setLed(2, R, G, B, W);
    setLed(15, R, G, B, W);
    delay(delayTime);
    setLed(2, R1, G1, B1, W1);
    setLed(15, R1, G1, B1, W1);

    setLed(1, R, G, B, W);
    setLed(16, R, G, B, W);
    delay(delayTime);
    setLed(1, R1, G1, B1, W1);
    setLed(16, R1, G1, B1, W1);
    
  }


}

void func(int R[], int G[], int B[], int W[], int delayTime) {


  delay(delayTime);
  int x = 1;
  while (true) {
    int colorIndex = 0;
    if(x = 17)
    {
      x = 1;
    }
    
    int id = 1;
    while(true) {
      
      setLed((id*2) % 17, R[id%8], G[id%8], B[id%8], W[id%8]); delay(delayTime);
      setLed((id*2) % 17 + 1, R[id%8], G[id%8], B[id%8], W[id%8]); delay(delayTime);
      id++;
    }
    x++;
    
  }
}


void loop() {
  //traceOne(255, 0, 255, 1, 255, 0, 0, 0, random(10, 50)); // !10/10 SETTING!
  int r[] = {242, 215, 209, 245, 250, 242, 242, 242};
  int g[] = {68, 7, 15, 50, 0, 40, 92, 46};
  int b[] = {196, 242, 242, 0, 30, 6, 92, 118};
  int w[] = {0, 0, 0, 0, 0, 0, 0, 0};

  func(r, 
       g, 
       b,
       w, 
       1);
}