#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 6
#define SEED 42

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  randomSeed(SEED);
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
      switch (L + 1) {
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
      switch (L + 1) {
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

void stillOne(int r, int g, int b, int w) {
  for (int i = 0; i < 16; i++) {
    setLed(i, r, g, b, w);
  }
}

void stillMany(int r[], int g[], int b[], int w[]) {
  for (int i = 0; i < 16; i++) {
    setLed(i, r[i], g[i], b[i], w[i]);
  }
}

void traceOne(int R[], int G[], int B[], int W[], int delayTime, int focal = -1) {
  for (int i = 0; i < 16; i++) {
    setLed(i, R[0], G[0], B[0], W[0]);
  }

  if (focal != -1) {

    while (true) {
      for (int i = 1; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
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
  } else {
    while (true) {
      for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
          setLed(j, R[i], G[i], B[i], W[i]);
          delay(delayTime * 2);
          setLed(j, R[0], G[0], B[0], W[0]);
        }
      }
    }
  }
}

void progressive(int R[], int G[], int B[], int W[], int delayTime, int focal = -1) {
  for (int i = 0; i < 16; i++) {
    setLed(i, R[0], G[0], B[0], W[0]);
  }
  if (focal != -1) {
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
  } else {
    while (true) {
      for (int j = 0; j < 16; j++) {  // Iterate through all LEDs (0-15)
        for (int i = 0; i < 16; i++) {
          // Forward iteration from LED 0 to LED 15
          int ledIndex = (j + i) % 16;                // Move forward circularly
          int ledIndex2 = (j + i + 1) % 16;           // Move backward circularly
          setLed(ledIndex, R[j], G[j], B[j], W[j]);   // Set LED colors
          setLed(ledIndex2, R[j], G[j], B[j], W[j]);  // Set LED colors
          delay(delayTime * 2);

          // Move one step further in both forward and backward directions
          ledIndex = (j + i + 1) % 16;                // Move forward circularly
          ledIndex2 = (j + i + 2) % 16;               // Move backward circularly
          setLed(ledIndex, R[j], G[j], B[j], W[j]);   // Set LED colors
          setLed(ledIndex2, R[j], G[j], B[j], W[j]);  // Set LED colors
          delay(delayTime * 2);
        }
      }
    }
  }
}

void traceMany(int R[], int G[], int B[], int W[], int delayTime, int focal = -1) {
  for (int i = 0; i < 16; i++) {
    setLed(i, R[0], G[0], B[0], W[0]);
  }
  if (focal == -1) {
    while (true) {
      for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 8; j++) {
          int offset = (i + j * 2) % 17;
          setLed(offset, R[(i + 1) % 8], G[(i + 1) % 16], B[(i + 1) % 16], W[(i + 1) % 16]);
          delay(delayTime * 2);

          offset = (i + j * 2 + 8) % 17;
          setLed(offset, R[(i + 1) % 8], G[(i + 2) % 16], B[(i + 2) % 16], W[(i + 2) % 16]);
        }
      }
    }
  } else {
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
  for (int i = 0; i < 16; i++) {
    setLed(i, R[0], G[0], B[0], W[0]);
  }
  if (focal == -1) {
    while (true) {
      for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
          int offset = (i + j * 2) % 16;
          for (int k = 0; k < delayTime * 2; k++) {
            setLed(offset, 0, 0, 0, 0);
            delay(6);
            setLed(offset, R[i], G[i], B[i], W[i]);
            delay(6);
          }
        }
      }
    }
  } else {
    while (true) {
      for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 8; j++) {
          int position1 = (focal + 1 + (i + j * 2) % 16) % 16;
          int position2 = (16 + focal - (i + j * 2) % 16) % 16;
          for (int k = 0; k < delayTime * 2; k++) {
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

// this function sucks. It needs changed entirely
void comfortSongStrobe(int r[], int g[], int b[], int w[], int delayTime, int focal = -1) {


  // 1 2 3 2 4 3 2 1 0 1 2 1 3 2 1 0
  int pattern[] = { 1, 2, 3, 2, 4, 3, 2, 1, 0, 1, 2, 1, 3, 2, 1, 0 };
  int pattern2[] = { 7, 8, 9, 8, 10, 9, 8, 7, 6, 7, 8, 7, 9, 8, 7, 6 };
  int pattern3[] = { 13, 14, 15, 14, 16, 15, 14, 13, 12, 13, 14, 13, 15, 14, 13, 12 };

  if (focal == -1) {  // Non-magnet mode
    while (true) {
      for (int x = 0; x < 16; x++) {
        for (int i = 0; i < delayTime; i++) {
          setLed(pattern[x], r[x], g[x], b[x], w[x]);
          setLed(pattern2[x], r[x], g[x], b[x], w[x]);
          setLed(pattern3[x], r[x], g[x], b[x], w[x]);
          delay(5);
          setLed(pattern[x], 0, 0, 0, 0);
          setLed(pattern2[x], 0, 0, 0, 0);
          setLed(pattern3[x], 0, 0, 0, 0);
          delay(5);
        }
      }
    }
  } else {  // Magnet mode
    // 2, 3, 4, 3, 5, 4, 3, 2, 1, 2, 3, 2, 4, 3, 2, 1
    int pattern4[] = { 3, 4, 5, 4, 6, 5, 4, 3, 2, 3, 4, 3, 5, 4, 3, 2 };
    while (true) {
      for (int x = 0; x < 16; x++) {
        for (int i = 0; i < delayTime; i++) {
          int led1 = pattern4[x] + focal;
          if (led1 < 0) {
            led1 = 16 + led1;
          } else if (led1 > 15) {
            led1 = led1 - 16;
          }

          int led2 = focal - pattern4[x];
          if (led2 < 0) {
            led1 = 16 + led1;
          } else if (led2 > 15) {
            led1 = led1 - 16;
          }
          setLed(led1, r[x], g[x], b[x], w[x]);
          setLed(led2, r[x], g[x], b[x], w[x]);
          delay(5);
          setLed(led1, 0, 0, 0, 0);
          setLed(led2, 0, 0, 0, 0);
          delay(5);
        }
      }
    }
  }
}

void blender(int r[], int g[], int b[], int w[], int delayTime, int focal = -1) {
  int numLeds = 16;
  int numColors = 16;
  if (focal == -1) {  // non-magnet mode
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
  } else {  // magnet mode
    while (true) {
      for (int i = 0; i < numLeds / 2; i++) {
        int led1 = focal - i;
        int led2 = focal + i;

        if (led1 < 0) {
          led1 = 16 + led1;
        }
        if (led2 > 15) {
          led2 = led2 - 16;
        }
        int colorIndex = (i + millis() / delayTime) % numColors;
        setLed(led1, r[colorIndex], g[colorIndex], b[colorIndex], w[colorIndex]);
        setLed(led2, r[colorIndex], g[colorIndex], b[colorIndex], w[colorIndex]);
      }
      delay(delayTime);

      for (int i = 0; i < numLeds / 2; i++) {
        int led1 = focal - i;
        int led2 = focal + i;

        if (led1 < 0) {
          led1 = 16 + led1;
        }
        if (led2 > 15) {
          led2 = led2 - 16;
        }
        int colorIndex = (numColors - (i + millis() / delayTime) % numColors) % numColors;
        setLed(led1, r[colorIndex], g[colorIndex], b[colorIndex], w[colorIndex]);
        setLed(led2, r[colorIndex], g[colorIndex], b[colorIndex], w[colorIndex]);
      }
      delay(delayTime);
    }
  }
}

void techno(int r[], int g[], int b[], int w[], int delayTime, int focal = -1) {
  if (focal == -1) {  // Not Magnet Mode
    while (true) {
      for (int i = 0; i < 11; i++) {
        int m = i + 1;
        int n = i + 2;
        int o = i + 3;
        int p = i + 4;
        for (int j = 10; j >= 0; j--) {
          int k = j + 1;
          int l = j + 2;
          int y = j + 3;
          int z = j + 4;

          for (int x = 0; x < 2; x++) {
            setLed(j, r[i], g[i], b[i], w[i]);
            delay(delayTime);
            setLed(j, 0, 0, 0, 0);
            setLed(k, r[m], g[m], b[m], w[m]);
            delay(delayTime);
            setLed(k, 0, 0, 0, 0);
            setLed(l, r[n], g[n], b[n], w[n]);
            delay(delayTime);
            setLed(l, 0, 0, 0, 0);
            setLed(y, r[o], g[o], b[o], w[o]);
            delay(delayTime);
            setLed(y, 0, 0, 0, 0);
            setLed(z, r[p], g[p], b[p], w[p]);
            delay(delayTime);
            setLed(z, 0, 0, 0, 0);
          }
        }
      }
    }
  }

  else {  // MAGNET MODE
    while (true) {
      for (int i = 0; i < 11; i++) {
        int m = i + 1;
        int n = i + 2;
        int o = i + 3;
        int p = i + 4;
        int jb = focal;
        for (int j = focal; j >= 0; j--) {
          if (jb < 16) {
            int k = j + 1;
            int l = j + 2;
            int y = j + 3;
            int z = j + 4;

            int kb = jb + 1;
            int lb = jb + 2;
            int yb = jb + 3;
            int zb = jb + 4;

            for (int x = 0; x < 2; x++) {
              setLed(j, r[i], g[i], b[i], w[i]);
              setLed(jb, r[i], g[i], b[i], w[i]);

              delay(delayTime * 2);
              setLed(j, 0, 0, 0, 0);
              setLed(jb, 0, 0, 0, 0);

              setLed(k, r[m], g[m], b[m], w[m]);
              setLed(kb, r[m], g[m], b[m], w[m]);

              delay(delayTime * 2);
              setLed(k, 0, 0, 0, 0);
              setLed(kb, 0, 0, 0, 0);

              setLed(l, r[n], g[n], b[n], w[n]);
              setLed(lb, r[n], g[n], b[n], w[n]);

              delay(delayTime * 2);
              setLed(l, 0, 0, 0, 0);
              setLed(lb, 0, 0, 0, 0);

              setLed(y, r[o], g[o], b[o], w[o]);
              setLed(yb, r[o], g[o], b[o], w[o]);

              delay(delayTime * 2);
              setLed(y, 0, 0, 0, 0);
              setLed(yb, 0, 0, 0, 0);

              setLed(z, r[p], g[p], b[p], w[p]);
              setLed(zb, r[p], g[p], b[p], w[p]);

              delay(delayTime * 2);
              setLed(z, 0, 0, 0, 0);
              setLed(zb, 0, 0, 0, 0);
            }
            jb++;
          }
        }
      }
    }
  }
}

void trance(int* R, int* G, int* B, int* W, int delayTime, int focal = -1) {
  int sc1 = 4;
  int sc2 = 2;
  int ls = 3;
  if (focal == -1) {


    for (int j = 0; j <= 15; j++) {
      for (int k = 0; k < sc1; k++) {
        for (int i = 0; i < ls; i++) {
          int li = j + i;
          setLed(li + 1, R[li], G[li], B[li], W[li]);
        }
        delay(delayTime);
        for (int i = 0; i < ls; i++) {
          int ledIndex = j + i;
          setLed(ledIndex + 1, 0, 0, 0, 0);
        }
        delay(delayTime);
      }

      for (int strobe = 0; strobe < sc2; strobe++) {
        for (int i = 0; i < ls; i++) {
          int ledIndex = j + i;
          setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
        }
        delay(delayTime);
        for (int i = 0; i < ls; i++) {
          int ledIndex = j + i;
          setLed(ledIndex + 1, 0, 0, 0, 0);
        }
        delay(delayTime);
      }
    }
  } else {
    int focal = 7;  // Set the focal point, it can be from 0 to 15

    for (int j = 0; j <= 15; j++) {
      // Calculate the distance from the focal point (spread outwards)
      int distance = abs(focal - j);  // Distance from focal point

      for (int k = 0; k < sc1; k++) {
        for (int i = 0; i < ls; i++) {
          int li = distance + i;  // Adjust lighting based on distance
          setLed(li + 1, R[li], G[li], B[li], W[li]);
        }
        delay(delayTime);

        for (int i = 0; i < ls; i++) {
          int ledIndex = distance + i;
          setLed(ledIndex + 1, 0, 0, 0, 0);
        }
        delay(delayTime);
      }

      for (int strobe = 0; strobe < sc2; strobe++) {
        for (int i = 0; i < ls; i++) {
          int ledIndex = distance + i;
          setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
        }
        delay(delayTime);

        for (int i = 0; i < ls; i++) {
          int ledIndex = distance + i;
          setLed(ledIndex + 1, 0, 0, 0, 0);
        }
        delay(delayTime);
      }
    }
  }
}

void mold(int* R, int* G, int* B, int* W, int delayTime, int focal = -1) {
  int strobeCount1 = 2;
  int strobeCount2 = 2;
  int ledsPerGroup = 12;
  if (focal == -1) {
    while (true) {
      for (int startIdx = 15; startIdx >= 0; startIdx--) {
        for (int strobe = 0; strobe < strobeCount1; strobe++) {
          for (int i = 0; i < ledsPerGroup; i++) {
            int ledIndex = startIdx + i;
            for (int ha = 0; ha < 4; ha++) {
              setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
              setLed(ledIndex, 0, 0, 0, 0);
            }
          }
          for (int i = 0; i < ledsPerGroup; i++) {
            int ledIndex = startIdx + i;
            setLed(ledIndex + 1, 0, 0, 0, 0);
          }
        }

        for (int strobe = 0; strobe < strobeCount2; strobe++) {
          for (int i = 0; i < ledsPerGroup; i++) {
            int ledIndex = startIdx + i;
            for (int ha = 0; ha < 4; ha++) {
              setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
              setLed(ledIndex, 0, 0, 0, 0);
            }
          }
          for (int i = 0; i < ledsPerGroup; i++) {
            int ledIndex = startIdx + i;
            setLed(ledIndex + 1, 0, 0, 0, 0);
          }
        }
      }
      for (int startIdx = 0; startIdx <= 15; startIdx++) {
        for (int strobe = 0; strobe < strobeCount1; strobe++) {
          for (int i = 0; i < ledsPerGroup; i++) {
            int ledIndex = startIdx + i;
            for (int ha = 0; ha < 4; ha++) {
              setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
              setLed(ledIndex, 0, 0, 0, 0);
            }
          }
          for (int i = 0; i < ledsPerGroup; i++) {
            int ledIndex = startIdx + i;
            setLed(ledIndex + 1, 0, 0, 0, 0);
          }
        }

        for (int strobe = 0; strobe < strobeCount2; strobe++) {
          for (int i = 0; i < ledsPerGroup; i++) {
            int ledIndex = startIdx + i;
            for (int ha = 0; ha < 4; ha++) {
              setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
              setLed(ledIndex, 0, 0, 0, 0);
            }
          }
          for (int i = 0; i < ledsPerGroup; i++) {
            int ledIndex = startIdx + i;
            setLed(ledIndex + 1, 0, 0, 0, 0);
          }
        }
      }
    }
  } else {
    while (true) {
      for (int startIdx = 15; startIdx >= focal; startIdx--) {
        for (int startIdx = focal; startIdx <= 15; startIdx++) {
          for (int strobe = 0; strobe < strobeCount1; strobe++) {
            for (int i = 0; i < ledsPerGroup; i++) {
              int ledIndex = startIdx + i;
              int ledIndex2 = startIdx + i - 8;
              for (int ha = 0; ha < 4; ha++) {
                setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
                setLed(ledIndex2 + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
                setLed(ledIndex, 0, 0, 0, 0);
                setLed(ledIndex2, 0, 0, 0, 0);
              }
            }
            for (int i = 0; i < ledsPerGroup; i++) {
              int ledIndex = startIdx + i;
              int ledIndex2 = startIdx - i;
              setLed(ledIndex + 1, 0, 0, 0, 0);
              setLed(ledIndex2 + 1, 0, 0, 0, 0);
            }
          }

          for (int strobe = 0; strobe < strobeCount2; strobe++) {
            for (int i = 0; i < ledsPerGroup; i++) {
              int ledIndex = startIdx + i;
              int ledIndex2 = startIdx - i;
              for (int ha = 0; ha < 4; ha++) {
                setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
                setLed(ledIndex2 + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
                setLed(ledIndex, 0, 0, 0, 0);
                setLed(ledIndex2, 0, 0, 0, 0);
              }
            }
            for (int i = 0; i < ledsPerGroup; i++) {
              int ledIndex = startIdx + i;
              int ledIndex2 = startIdx - i;
              setLed(ledIndex + 1, 0, 0, 0, 0);
              setLed(ledIndex2 + 1, 0, 0, 0, 0);
            }
          }
        }
      }
    }
  }
}

void funky(int* R, int* G, int* B, int* W, int delayTime, int focal = -1) {
  int strobeCount1 = 4;
  int strobeCount2 = 4;
  int ledsPerGroup = 1;


  if (focal == -1) {
    while (true) {
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
  } else {
    while (true) {

      for (int strobe = focal; strobe < strobeCount1; strobe++) {
        for (int i = 0; i < ledsPerGroup; i++) {
          int ledIndex = random(0, 16);
          int ledIndex2 = random(0, 16);
          delay(delayTime / 12);
          setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
          setLed(ledIndex2 + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
        }
        delay(delayTime / 12);

        for (int i = focal; i < ledsPerGroup; i++) {
          int ledIndex = random(0, 16);
          int ledIndex2 = random(0, 16);
          delay(delayTime / 8);
          setLed(ledIndex + 1, 0, 0, 0, 0);
          setLed(ledIndex2 + 1, 0, 0, 0, 0);
        }
      }

      for (int strobe = focal + 1; strobe >= 0; strobe--) {
        for (int i = 0; i < ledsPerGroup; i++) {
          delay(delayTime / 12);

          int ledIndex = random(0, 16);
          int ledIndex2 = random(0, 16);
          setLed(ledIndex + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
          setLed(ledIndex2 + 1, R[ledIndex], G[ledIndex], B[ledIndex], W[ledIndex]);
        }
        delay(delayTime / 12);

        for (int i = focal; i < ledsPerGroup; i++) {
          delay(delayTime / 12);

          int ledIndex = random(0, 16);
          int ledIndex2 = random(0, 16);
          setLed(ledIndex + 1, 0, 0, 0, 0);
          setLed(ledIndex2 + 1, 0, 0, 0, 0);
        }
      }
    }
  }
}

void christmas(int r[], int g[], int b[], int w[], int delayTime, int focal = -1) {
  int i = 0;
  if (focal == -1) {
    while (true) {
      delay(delayTime);
      i++;

      i = i % 2;

      for (int xy = 0; xy < 13; xy++) {
        if (i == 0) {
          for (int j = 0; j < 18; j += 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            if (j == 8) {
              setLed(j, r[xy + 1], g[xy + 1], b[xy + 1], w[xy + 1]);
            }
            if (j == 12) {
              setLed(j, r[xy + 2], g[xy + 2], b[xy + 2], w[xy + 2]);
            }
            setLed(j + 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }


          for (int j = 1; j < 19; j += 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            setLed(j - 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }
        }
      }
    }
  } else {
    while (true) {
      delay(delayTime);
      i++;

      i = i % 2;

      for (int xy = 0; xy < 13; xy++) {
        if (i == 0) {
          for (int j = focal; j < 18; j += 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            if (j == 8) {
              setLed(j, r[xy + 1], g[xy + 1], b[xy + 1], w[xy + 1]);
            }
            if (j == 12) {
              setLed(j, r[xy + 2], g[xy + 2], b[xy + 2], w[xy + 2]);
            }
            setLed(j + 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }

          for (int j = focal; j >= 0; j -= 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            if (j == 8) {
              setLed(j, r[xy + 1], g[xy + 1], b[xy + 1], w[xy + 1]);
            }
            if (j == 12) {
              setLed(j, r[xy + 2], g[xy + 2], b[xy + 2], w[xy + 2]);
            }
            setLed(j + 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }


          for (int j = focal; j < 18; j += 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            setLed(j - 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }
          for (int j = focal; j >= 0; j -= 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            setLed(j - 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }
        }
      }
    }
  }
}




void loop() {
  // yes
  int rr[] = { random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256) };
  int gr[] = { random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256) };
  int br[] = { random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256), random(0, 256) };
  int wr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

  // 16 yes
  int r2[] = { 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255 };
  int g2[] = { 0, 85, 40, 15, 0, 45, 59, 2, 0, 85, 40, 15, 0, 45, 59, 2 };
  int b2[] = { 0, 1, 0, 2, 239, 3, 0, 0, 0, 1, 0, 2, 239, 3, 0, 0 };

  // 16 yes
  int r4[] = { 161, 205, 172, 19, 71, 215, 205, 190, 190, 205, 215, 71, 19, 172, 205, 161 };
  int g4[] = { 0, 52, 19, 21, 0, 35, 38, 40, 20, 38, 33, 0, 55, 19, 52, 0 };
  int b4[] = { 0, 0, 42, 52, 35, 0, 15, 82, 82, 35, 0, 65, 75, 10, 0, 12 };
  // 16 yes
  int r5[] = { 255, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30 };
  int g5[] = { 0, 75, 25, 27, 75, 45, 50, 27, 75, 27, 36, 5, 75, 27, 75, 50 };
  int b5[] = { 0, 20, 155, 55, 120, 155, 55, 55, 10, 155, 55, 155, 55, 25, 155, 20 };
  // 16 yes
  int r6[] = { 255, 0, 255, 0, 255, 255, 0, 0, 0, 255, 255, 0, 0, 255, 0, 255 };
  int g6[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int b6[] = { 255, 0, 255, 255, 255, 0, 255, 255, 255, 255, 0, 255, 255, 255, 0, 0 };
  // 16
  int r7[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int g7[] = { 255, 200, 100, 150, 50, 255, 180, 230, 90, 50, 180, 210, 0, 120, 100, 255 };
  int b7[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


  
  // 3, 6, 8, 11, 14
  // MAGNET POSITIONS ^^


  // DONE
  //traceOne(r5, g5, b5, wr, 10); // PERFECT
  //traceOne(r5, g5, b5, wr, 10, 4); // PERFECT 1st TRI
  traceOne(r5, g5, b5, wr, 10, 8); // PERFECT 1st TRI
  //progressive(r2, g2, b2, wr, 7);
  //traceMany(r4, g4, b4, wr, 30, 8);
  //strobeChange(r5, g5, b5, wr, 1, 2);
  //comfortSongStrobe(r6, g6, b6, wr, 8, 8);
  //stillOne(255, 0, 255, wr[0]);
  //stillMany(r7, g7, b7, wr);
  //blender(rr, gr, b2, wr, 2, 8);
  //techno(rr, g2, b2, wr, 1, 8);
  //trance(r5, g2, b4, wr, 1, 8);
  //mold(r4, g4, b5, wr, 1, 8);
  //funky(r5, g5, b6, wr, 8, 3);
  //christmas(r6, g6, b7, wr, 10, 8);  // THIS IS SMOLDER NEVER DELETE IT

  // TESTING
  // something(r7, b7, gr, wr, 1, 1);
  // somethingElse(rr, g2, b4, wr, 1, 1);

  // INCOMPLETE
}