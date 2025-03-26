#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}
//TODO: Brightness
void setLed(int L, int R, int G, int B, int W) {
  switch ((L + 1) % 3) {
    case 1:
      switch (L + 1) {
        case 1:
          leds[0].r = R;
          FastLED.show();
          leds[0].g = G;
          FastLED.show();
          leds[0].b = B;
          FastLED.show();
          leds[1].g = W;
          FastLED.show();
          break;
        case 4:
          leds[4].r = R;
          FastLED.show();
          leds[4].g = G;
          FastLED.show();
          leds[4].b = B;
          FastLED.show();
          leds[5].g = W;
          FastLED.show();
          break;
        case 7:
          leds[8].r = R;
          FastLED.show();
          leds[8].g = G;
          FastLED.show();
          leds[8].b = B;
          FastLED.show();
          leds[9].g = W;
          FastLED.show();
          break;
        case 10:
          leds[12].r = R;
          FastLED.show();
          leds[12].g = G;
          FastLED.show();
          leds[12].b = B;
          FastLED.show();
          leds[13].g = W;
          FastLED.show();
          break;
        case 13:
          leds[16].r = R;
          FastLED.show();
          leds[16].g = G;
          FastLED.show();
          leds[16].b = B;
          FastLED.show();
          leds[17].g = W;
          FastLED.show();
          break;
        case 16:
          leds[20].r = R;
          FastLED.show();
          leds[20].g = G;
          FastLED.show();
          leds[20].b = B;
          FastLED.show();
          leds[21].g = W;
          FastLED.show();
          break;
      }
      break;
    case 2:
      switch (L+1) {
        case 2:
          leds[1].r = G;
          FastLED.show();
          leds[1].b = R;
          FastLED.show();
          leds[2].r = W;
          FastLED.show();
          leds[2].g = B;
          FastLED.show();
          break;
        case 5:
          leds[5].b = R;
          FastLED.show();
          leds[5].r = G;
          FastLED.show();
          leds[6].g = B;
          FastLED.show();
          leds[6].r = W;
          FastLED.show();
          break;
        case 8:
          leds[9].r = G;
          FastLED.show();
          leds[9].b = R;
          FastLED.show();
          leds[10].r = W;
          FastLED.show();
          leds[10].g = B;
          FastLED.show();
          break;
        case 11:
          leds[13].r = G;
          FastLED.show();
          leds[13].b = R;
          FastLED.show();
          leds[14].r = W;
          FastLED.show();
          leds[14].g = B;
          FastLED.show();
          break;
        case 14:
          leds[17].b = R;
          FastLED.show();
          leds[17].r = G;
          FastLED.show();
          leds[18].g = B;
          FastLED.show();
          leds[18].r = W;
          FastLED.show();
          break;
      }
      break;
    case 0:
      switch (L+1) {
        case 3:
          leds[3].r = B;
          FastLED.show();
          leds[3].g = R;
          FastLED.show();
          leds[3].b = W;
          FastLED.show();
          leds[2].b = G;
          FastLED.show();
          break;
        case 6:
          leds[7].r = B;
          FastLED.show();
          leds[7].g = R;
          FastLED.show();
          leds[7].b = W;
          FastLED.show();
          leds[6].b = G;
          FastLED.show();
          break;
        case 9:
          leds[11].g = R;
          FastLED.show();  // Ninth Red
          leds[10].b = G;
          FastLED.show();  // Ninth Green
          leds[11].r = B;
          FastLED.show();  // Ninth Blue
          leds[11].b = W;
          FastLED.show();  // Ninth White
          break;
        case 12:
          leds[15].r = B;
          FastLED.show();
          leds[15].g = R;
          FastLED.show();
          leds[15].b = W;
          FastLED.show();
          leds[14].b = G;
          FastLED.show();
          break;
        case 15:
          leds[19].r = B;
          FastLED.show();
          leds[19].g = R;
          FastLED.show();
          leds[19].b = W;
          FastLED.show();
          leds[18].b = G;
          FastLED.show();
          break;
      }
      break;
  }
}

// COMPLETE
void traceOne(int R[], int G[], int B[], int W[], int delayTime, int focal = -1) {
  for(int i = 0; i < 16; i++)
  {
  setLed(i, R[0], G[0], B[0], W[0]);
  }

  if (focal != -1) {

    while (true) {
      for (int i = 0; i < 16; i++) {
        for(int j = 0; j < 8; j++){
          int position1 = (focal + 1 + j) % 16;
          int position2 = (16 + focal - j) % 16;
          setLed(position1, R[i], G[i], B[i], W[i]);
          setLed(position2, R[i], G[i], B[i], W[i]);
          delay(delayTime);
          setLed(position1, R[0], G[0], B[0], W[0]);
          setLed(position2, R[0], G[0], B[0], W[0]);
        }
      }
    }
  }
  else{
    while (true) {
      for (int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++)
        {
          setLed(j, R[i], G[i], B[i], W[i]);
          delay(delayTime*2);
          setLed(j, R[0], G[0], B[0], W[0]);
        }
      }
    }
  }
}
//COMPLETE
void progressive(int R[], int G[], int B[], int W[], int delayTime, int focal = -1) {
  for(int i = 0; i < 16; i++)
  {
    setLed(i, R[0], G[0], B[0], W[0]);
  }
  if(focal != -1)
  {
    while (true) {
      for (int j = 0; j < 16; j++) {  // Iterate through the color array
        // Iterate forwards from the focal point
        for (int i = 0; i < 8; i++) {
            int ledIndex = (focal + i) % 16;  // Move forward circularly
            int ledIndex2 = (focal - i + 16) % 16;
            setLed(ledIndex, R[j], G[j], B[j], W[j]);
            setLed(ledIndex2, R[j], G[j], B[j], W[j]);
            delay(delayTime);

            ledIndex = (focal + i + 1) % 16;  // Move forward circularly
            ledIndex2 = (focal - i - 1 + 16) % 16;
            setLed(ledIndex, R[j], G[j], B[j], W[j]);
            setLed(ledIndex2, R[j], G[j], B[j], W[j]);
            delay(delayTime);
        }
      }
    }
  }
  else
  {
    while (true) {
       for (int j = 0; j < 16; j++) {  // Iterate through all LEDs (0-15)
        for (int i = 0; i < 16; i++) {
            // Forward iteration from LED 0 to LED 15
            int ledIndex = (j + i) % 16;  // Move forward circularly
            int ledIndex2 = (j + i + 1) % 16;  // Move backward circularly
            setLed(ledIndex, R[j], G[j], B[j], W[j]);  // Set LED colors
            setLed(ledIndex2, R[j], G[j], B[j], W[j]);  // Set LED colors
            delay(delayTime * 2);

            // Move one step further in both forward and backward directions
            ledIndex = (j + i + 1) % 16;  // Move forward circularly
            ledIndex2 = (j + i + 2) % 16;  // Move backward circularly
            setLed(ledIndex, R[j], G[j], B[j], W[j]);  // Set LED colors
            setLed(ledIndex2, R[j], G[j], B[j], W[j]);  // Set LED colors
            delay(delayTime * 2);
        }
    }
    }
  }
}
// 
void traceMany(int R[], int G[], int B[], int W[], int delayTime, int focal = -1) {
  for(int i = 0; i < 16; i++)
  {
    setLed(i, R[0], G[0], B[0], W[0]);
  }
  if(focal == -1)
  {
    while (true) {
      for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 8; j++) {
          int offset = (i + j * 2) % 17;
          setLed(offset, R[(i + 1) % 8], G[(i + 1) % 16], B[(i + 1) % 16], W[(i + 1) % 16]);
          delay(delayTime*2);

          offset = (i + j * 2 + 8) % 17;
          setLed(offset, R[(i + 1) % 8], G[(i + 2) % 16], B[(i + 2) % 16], W[(i + 2) % 16]);
        }
      }
    }
  }
  else
  {
    while (true) {
      for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
          int position1 = (focal + 1 + j) % 16;
          int position2 = (16 + focal - j) % 16;
          setLed(position1, R[(i + 1) % 16], G[(i + 1) % 16], B[(i + 1) % 16], W[(i + 1) % 16]);
          delay(delayTime);
          setLed(position2, R[(i + 1) % 16], G[(i + 2) % 16], B[(i + 2) % 16], W[(i + 2) % 16]);
        }
      }
    }
  }
}

void strobeChange(int R[], int G[], int B[], int W[], int delayTime, int focal = -1) {
  for(int i = 0; i < 16; i++)
  {
    setLed(i, R[0], G[0], B[0], W[0]);
  }
  if (focal == -1)
  {
    while (true) {
      for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
          int offset = (i + j * 2) % 16;
          for(int k = 0; k < delayTime*2; k++)
          {
            setLed(offset, 0, 0, 0, 0);
            delay(6);
            setLed(offset, R[i], G[i], B[i], W[i]);
            delay(6);
          }
          
          
        }
      }
    }
  }
  else 
  {
    while (true) {
      for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
          int position1 = (focal + 1 + (i + j * 2) % 16) % 16;
          int position2 = (16 + focal - (i + j * 2) % 16) % 16;
          for(int k = 0; k < delayTime*2; k++)
          {
            setLed(position1, 0, 0, 0, 0);
            setLed(position2, 0, 0, 0, 0);
            delay(6);
            setLed(position1, R[i], G[i], B[i], W[i]);
            setLed(position2, R[i], G[i], B[i], W[i]);
            delay(6);
          }
          
          
        }
      }
    }
  }
}

void funcz(int r[], int g[], int b[], int w[], int delayTime) {
  int numLeds = 16;

  // Precompute color values for setLed calls to avoid repeating modulus calculations.
  int color[8][4];  // Store RGBW for each LED pattern.
  for (int i = 0; i < 16; i++) {
    color[i][0] = r[i];  // Store red values
    color[i][1] = g[i];  // Store green values
    color[i][2] = b[i];  // Store blue values
    color[i][3] = w[i];  // Store white values
  }

  while (true) {
    bool setNewLedState = false;

    for (int i = 0; i < numLeds; i++) 
    {
      if (random(0, 2) == 0) {
        setLed(i, color[i % 8][0], color[i % 8][1], color[i % 8][2], color[i % 8][3]);
        delay(delayTime); 
      } 
      else 
      {
        // Turn LED off
        setLed(i, 0, 0, 0, 0);
      }
    }
    setNewLedState = true;
  }
}


void funca(int r[], int g[], int b[], int w[], int delayTime) {
  int numLeds = 16;
  int numColors = 16;

  while (true) {
    for (int i = 0; i < numLeds; i++) {
      int colorIndex = (i + millis() / delayTime) % numColors;
      setLed(i, r[colorIndex], g[colorIndex], b[colorIndex], w[colorIndex]);
    }
    delay(delayTime);

    for (int i = 0; i < numLeds; i++) {
      int colorIndex = (numColors - (i + millis() / delayTime) % numColors) % numColors;
      setLed(i, r[colorIndex], g[colorIndex], b[colorIndex], w[colorIndex]);
    }
    delay(delayTime);
  }
}

void funcb(int* R, int* G, int* B, int* W, int delayTime) {
  int strobeCount1 = 4;
  int strobeCount2 = 2;
  int ledsPerGroup = 3;

  for (int startIdx = 0; startIdx <= 15; startIdx++) {
    for (int strobe = 0; strobe < strobeCount1; strobe++) {
      for (int i = 0; i < ledsPerGroup; i++) {
        int ledIndex = startIdx + i;
        setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
      }
      delay(delayTime);
      for (int i = 0; i < ledsPerGroup; i++) {
        int ledIndex = startIdx + i;
        setLed(ledIndex + 1, 0, 0, 0, 0);
      }
      delay(delayTime);
    }

    for (int strobe = 0; strobe < strobeCount2; strobe++) {
      for (int i = 0; i < ledsPerGroup; i++) {
        int ledIndex = startIdx + i;
        setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
      }
      delay(delayTime);
      for (int i = 0; i < ledsPerGroup; i++) {
        int ledIndex = startIdx + i;
        setLed(ledIndex + 1, 0, 0, 0, 0);
      }
      delay(delayTime);
    }
  }
}

void funcc(int* R, int* G, int* B, int* W, int delayTime) {
  int strobeCount1 = 2;
  int strobeCount2 = 3;
  int ledsPerGroup = 1;
  delay(delayTime / 5);

  for (int startIdx = 0; startIdx <= 15; startIdx++) {
    for (int strobe = 0; strobe < strobeCount1; strobe++) {
      for (int i = 0; i < ledsPerGroup; i++) {
        int ledIndex = startIdx + i;
        setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
      }
      for (int i = 0; i < ledsPerGroup; i++) {
        int ledIndex = startIdx + i;
        setLed(ledIndex + 1, 0, 0, 0, 0);
      }
    }

    for (int strobe = 0; strobe < strobeCount2; strobe++) {
      for (int i = 0; i < ledsPerGroup; i++) {
        int ledIndex = startIdx + i;
        setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
      }
      for (int i = 0; i < ledsPerGroup; i++) {
        int ledIndex = startIdx + i;
        setLed(ledIndex + 1, 0, 0, 0, 0);
      }
    }
  }
}

void funcd(int* R, int* G, int* B, int* W, int delayTime) {
  int strobeCount1 = 4;
  int strobeCount2 = 4;
  int ledsPerGroup = 1;

  delay(delayTime / 4);

  for (int strobe = 0; strobe < strobeCount1; strobe++) {
    for (int i = 0; i < ledsPerGroup; i++) {
      int ledIndex = random(0, 16);
      delay(delayTime / 12);
      setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
    }
    delay(delayTime / 12);

    for (int i = 0; i < ledsPerGroup; i++) {
      int ledIndex = random(0, 16);
      delay(delayTime / 8);
      setLed(ledIndex + 1, 0, 0, 0, 0);
    }
  }

  for (int strobe = 0; strobe < strobeCount2; strobe++) {
    for (int i = 0; i < ledsPerGroup; i++) {
      delay(delayTime / 12);

      int ledIndex = random(0, 16);
      setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
    }
    delay(delayTime / 12);

    for (int i = 0; i < ledsPerGroup; i++) {
      delay(delayTime / 12);

      int ledIndex = random(0, 16);
      setLed(ledIndex + 1, 0, 0, 0, 0);
    }
  }
}

void christmas(int r[], int g[], int b[], int w[], int delayTime) {
  int i = 0;
  while (true) {
    delay(delayTime);
    i++;

    i = i % 2;

    if (i == 0) {
      for (int j = 0; j < 18; j += 2) {
        setLed(j, r[0], g[0], b[0], w[0]);
        if (j == 8) {
          setLed(j, r[1], g[1], b[1], w[1]);
        }
        if (j == 12) {
          setLed(j, r[2], g[2], b[2], w[2]);
        }
        setLed(j + 1, r[3], g[3], b[3], w[3]);
      }


      for (int j = 1; j < 19; j += 2) {
        setLed(j, r[0], g[0], b[0], w[0]);
        setLed(j - 1, r[3], g[3], b[3], w[3]);
      }
    }
  }
}

void stillOne(int r, int g, int b, int w)
{
  for(int i = 0; i < 16; i++)
  {
    setLed(i, r, g, b, w);
  }
}

void stillMany(int r[], int g[], int b[], int w[])
{
  for(int i = 0; i < 16; i++)
  {
    setLed(i, r[i], g[i], b[i], w[i]);
  }
}



void loop() {
  // 8
  int r[] = { 242, 215, 209, 245, 250, 242, 242, 242 };
  int g[] = { 68, 7, 15, 50, 0, 40, 92, 46 };
  int b[] = { 196, 242, 242, 0, 30, 6, 92, 118 };
  int w[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  // 8
  int r1[] = { 201, 245, 212, 59, 111, 255, 245, 230 };
  int g1[] = { 0, 92, 59, 235, 40, 116, 78, 146 };
  int b1[] = { 64, 15, 235, 185, 153, 10, 119, 245 };
  int w1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  // 16
  int r2[] = { 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255 };
  int g2[] = { 0, 85, 40, 15, 0, 45, 59, 2, 0, 85, 40, 15, 0, 45, 59, 2 };
  int b2[] = { 0, 1, 0, 2, 239, 3, 0, 0, 0, 1, 0, 2, 239, 3, 0, 0 };
  int w2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  // 8
  int r3[] = { 139, 204, 0, 25, 139, 0, 48, 184 };
  int g3[] = { 0, 45, 51, 25, 39, 128, 25, 0 };
  int b3[] = { 0, 0, 51, 0, 19, 128, 52, 51 };
  int w3[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
  // 16
  int r4[] = { 161, 205, 172, 19, 71, 215, 205, 190, 190, 205, 215, 71, 19, 172, 205, 161 };
  int g4[] = { 0, 52, 19, 21, 0, 35, 38, 40, 20, 38, 33, 0, 55, 19, 52, 0 };
  int b4[] = { 0, 0, 42, 52, 35, 0, 15, 82, 82, 35, 0, 65, 75, 10, 0, 12 };
  int w4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  // 16
  int r5[] = { 255, 0, 255, 0, 255, 255, 0, 255, 255, 0, 255, 255, 255, 0, 0, 255 };
  int g5[] = { 0, 255, 0, 255, 255, 0, 0, 255, 255, 255, 0, 0, 255, 255, 255, 0 };
  int b5[] = { 0, 0, 255, 255, 0, 255, 255, 0, 0, 255, 255, 255, 255, 0, 255, 20 };
  int w5[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  // 16
  int r6[] = { 255, 0, 255, 0, 255, 255, 0, 0, 0, 255, 255, 0, 0, 255, 0, 255 };
  int g6[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int b6[] = { 255, 0, 255, 255, 255, 0, 255, 255, 255, 255, 0, 255, 255, 255, 0, 0 };
  int w6[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  // 16
  int r7[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int g7[] = { 255, 200, 100, 150, 50, 255, 180, 230, 90, 50, 180, 210, 0, 120, 100, 255 };
  int b7[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int w7[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  // 4
  int r8[] = { 33, 255, 0, 16 };
  int g8[] = { 20, 0, 255, 10 };
  int b8[] = { 10, 0, 0, 5 };
  int w8[] = { 0, 0, 0, 0 };

  // DONE
  //traceOne(r5, g5, b5, w5, random(10, 50));
  //progressive(r5, g5, b5, w5, 10, 12); 
  //traceMany(r1, g1, b1, w1, 10);
  //strobeChange(r4, g4, b4, w4, 1, 8);

  // TESTING
  funcz(r4, g4, b4, w4, 1);

  // INCOMPLETE


  // STILL
  //stillOne(255, 0, 255, 0);
  //stillMany(r4, g4, b4, w4);

  //funca(r4, g4, b4, w4, 2);
  //funcb(r5, g5, b5, w5, 1);
  //funcc(r6, g6, b6, w6, 1);
  //funcd(r6, g6, b2, w7, 1);
  //christmas(r2, g2, b2, w2, 10); // THIS IS SMOLDER NEVER DELETE IT
}