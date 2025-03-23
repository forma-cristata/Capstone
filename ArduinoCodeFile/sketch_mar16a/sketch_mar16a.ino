#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void setLed(int L, int R, int G, int B, int W) {
  switch (L % 3) {
    case 1:
      switch (L) {
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
      switch (L) {
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
      switch (L) {
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

// Todo build speed function to track speeds to less ms
void traceOne(int R, int G, int B, int W, int R1, int G1, int B1, int W1, int delayTime) {
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
  while (true) {
    for (int i = 1; i < 17; i++) {
      for (int j = 0; j < 8; j++) {  
        setLed((i + j * 2) % 17, R[j], G[j], B[j], W[j]);
        delay(delayTime);
        setLed((i + j * 2 + 1) % 17, R[j], G[j], B[j], W[j]);
        delay(delayTime);
      }
    }
  }
}

void funcx(int R[], int G[], int B[], int W[], int delayTime) {
  while (true) {
    for (int i = 0; i < 17; i++) {
      for (int j = 0; j < 8; j++) { 
        int offset = (i + j * 2) % 17;
        setLed(offset, R[(j + 1) % 8], G[(j + 1) % 8], B[(j + 1) % 8], W[(j + 1) % 8]);
        delay(delayTime);

        offset = (i + j * 2 + 8) % 17;
        setLed(offset, R[(j + 2) % 8], G[(j + 2) % 8], B[(j + 2) % 8], W[(j + 2) % 8]);
        delay(delayTime);
      }
    }
  }
}

void funcy(int R[], int G[], int B[], int W[], int delayTime) {
  while (true) {
    for (int i = 0; i < 17; i++) {
      for (int j = 0; j < 8; j++) { 
        int offset = (i + j * 2) % 17;

        int flicker = random(50, 150); 

        setLed(offset, R[j] * flicker / 255, G[j] * flicker / 255, B[j] * flicker / 255, W[j] * flicker / 255);
      }
      delay(delayTime);
    }
  }
}

void funcz(int r[], int g[], int b[], int w[], int delayTime) {
  int numLeds = 16;

  // Precompute color values for setLed calls to avoid repeating modulus calculations.
  int color[8][4];  // Store RGBW for each LED pattern.
  for (int i = 0; i < 8; i++) {
    color[i][0] = r[i];  // Store red values
    color[i][1] = g[i];  // Store green values
    color[i][2] = b[i];  // Store blue values
    color[i][3] = w[i];  // Store white values
  }

  while (true) {
    bool setNewLedState = false;  // Flag to track whether to update all LEDs.

    // Only generate a new random pattern when necessary
    if (random(0, 2) == 0) {
      for (int i = 0; i < numLeds; i++) {
        if (random(0, 2) == 0) {  
          // Set LED to a random color
          setLed(i, color[i % 8][0], color[i % 8][1], color[i % 8][2], color[i % 8][3]); 
        } else {
          // Turn LED off
          setLed(i, 0, 0, 0, 0); 
        }
      }
      setNewLedState = true;  // Mark that we updated the LEDs
    }

    if (random(0, 5) == 0) {  
      bool allOn = random(0, 2) == 0; 
      for (int i = 0; i < numLeds; i++) {
        if (allOn) {
          setLed(i, color[i % 8][0], color[i % 8][1], color[i % 8][2], color[i % 8][3]);
        } else {
          setLed(i, 0, 0, 0, 0);  
        }
      }
      setNewLedState = true;
    }

    if (setNewLedState) {
      delay(delayTime); // Delay only after updating the LED states
    }
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



void loop() {
  //traceOne(255, 0, 255, 1, 255, 0, 0, 0, random(10, 50)); // !10/10 SETTING!

  int r[] = { 242, 215, 209, 245, 250, 242, 242, 242 };
  int g[] = { 68, 7, 15, 50, 0, 40, 92, 46 };
  int b[] = { 196, 242, 242, 0, 30, 6, 92, 118 };
  int w[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

  //func(r, g, b, w, 1);

  int r1[] = { 201, 245, 212, 59, 111, 255, 245, 230 };
  int g1[] = { 0, 92, 59, 235, 40, 116, 78, 146 };
  int b1[] = { 64, 15, 235, 185, 153, 10, 119, 245 };
  int w1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

  //funcx(r1, g1, b1, w1, 100);

  int r2[] = { 255, 255, 255, 255, 0, 255, 255, 255 };
  int g2[] = { 0, 85, 40, 15, 0, 45, 59, 2 };
  int b2[] = { 0, 1, 0, 2, 239, 3, 0, 0 };
  int w2[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

  //funcy(r2, g2, b2, w2, 1);

  int r3[] = { 139, 204, 0, 25, 139, 0, 48, 184 };
  int g3[] = { 0, 45, 51, 25, 39, 128, 25, 0 };
  int b3[] = { 0, 0, 51, 0, 19, 128, 52, 51 };
  int w3[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

  //funcz(r3, g3, b3, w3, 1);

  int r4[] = { 161, 205, 172, 19, 71, 215, 205, 190, 190, 205, 215, 71, 19, 172, 205, 161 };
  int g4[] = { 0, 52, 19, 21, 0, 35, 38, 40, 20, 38, 33, 0, 55, 19, 52, 0 };
  int b4[] = { 0, 0, 42, 52, 35, 0, 15, 82, 82, 35, 0, 65, 75, 10, 0, 12 };
  int w4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  //funca(r4, g4, b4, w4, 2);


  int r5[] = { 255, 0, 255, 0, 255, 255, 0, 255, 255, 0, 255, 255, 255, 0, 0, 255 };
  int g5[] = { 0, 255, 0, 255, 255, 0, 0, 255, 255, 255, 0, 0, 255, 255, 255, 0 };
  int b5[] = { 0, 0, 255, 255, 0, 255, 255, 0, 0, 255, 255, 255, 255, 0, 255, 0 };
  int w5[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  //funcb(r5, g5, b5, w5, 1); 

  int r6[] = { 255, 0, 255, 0, 255, 255, 0, 0, 0, 255, 255, 0, 0, 255, 0, 255 };        
  int g6[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };                        
  int b6[] = { 255, 0, 255, 255, 255, 0, 255, 255, 255, 255, 0, 255, 255, 255, 0, 0 };  
  int w6[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  //funcc(r6, g6, b6, w6, 1);

  int r7[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };                             
  int g7[] = { 255, 200, 100, 150, 50, 255, 180, 230, 90, 50, 180, 210, 0, 120, 100, 255 };  
  int b7[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };                             
  int w7[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  //funcd(r6, g6, b2, w7, 1);

  int r8[] = { 33, 255, 0, 16 };  
  int g8[] = { 20, 0, 255, 10 };  
  int b8[] = { 10, 0, 0, 5 };     
  int w8[] = { 0, 0, 0, 0 };

  christmas(r2, g2, b2, w2, 10); // THIS IS SMOLDER NEVER DELETE IT
}