const byte hallPin[] = { A0, A1, A2, A3, A4 };  // AH3503 sensor connected to A0 5volt and ground
const int offset = 512;                         // calibrate zero
const float span = 0.3617;                      // calibrate A/D > mT
float value;
int pin = -1;
#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 6
#define SEED 42

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  randomSeed(SEED);
}
int r6[] = { 255, 0, 255, 0, 255, 255, 0, 0, 0, 255, 255, 0, 0, 255, 0, 255 };
int g4[] = { 0, 52, 19, 21, 0, 35, 38, 40, 20, 38, 33, 0, 55, 19, 52, 0 };
int b4[] = { 0, 0, 42, 52, 35, 0, 15, 82, 82, 35, 0, 65, 75, 10, 0, 12 };
int wr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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
void christmas(int r[] = r6, int g[] = g4, int b[] = b4, int w[] = wr, int delayTime = 10) {
  int i = 0;
  magnetCheck();
  if (pin == -1) {
    for (int aa = 0; aa < 2; aa++) {
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
    for (int aa = 0; aa < 2; aa++) {
      Serial.println(pin);
      delay(delayTime);
      i++;

      i = i % 2;

      for (int xy = 0; xy < 13; xy++) {
        if (i == 0) {
          for (int j = pin; j < 18; j += 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            if (j == 8) {
              setLed(j, r[xy + 1], g[xy + 1], b[xy + 1], w[xy + 1]);
            }
            if (j == 12) {
              setLed(j, r[xy + 2], g[xy + 2], b[xy + 2], w[xy + 2]);
            }
            setLed(j + 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }

          for (int j = pin; j >= 0; j -= 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            if (j == 8) {
              setLed(j, r[xy + 1], g[xy + 1], b[xy + 1], w[xy + 1]);
            }
            if (j == 12) {
              setLed(j, r[xy + 2], g[xy + 2], b[xy + 2], w[xy + 2]);
            }
            setLed(j + 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }


          for (int j = pin; j < 18; j += 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            setLed(j - 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }
          for (int j = pin; j >= 0; j -= 2) {
            setLed(j, r[xy], g[xy], b[xy], w[xy]);
            setLed(j - 1, r[xy + 3], g[xy + 3], b[xy + 3], w[xy + 3]);
          }
        }
      }
    }
  }
}

void magnetCheck() {
  for (int i = 0; i < 5; i++) {
    value = (analogRead(hallPin[i]) - offset) * span;
   
    if (value > 5) {
      switch(hallPin[i])
      {
        case (18):
          pin = 3;
          break;
        case (17):
          pin = 6;
          break;
        case (16):
          pin = 8;
          break;
        case (15):
          pin = 11;
          break;
        case (14):
          pin = 15;
          break;
      }
      

      /*Serial.println("Magnet at pin hallPin"); // 18 17 16 15 14
    Serial.println(hallPin[i]);
    Serial.println(value);*/
    }
  }
}

void loop() {
  
  
  christmas();
  /*
  Serial.print("Value: ");
  Serial.print(value, 1);
  Serial.println(" mT");
  */
}


// ff0000
// ff8800
// ffff00
// 88ff00
// 00ff00
// 00ff44
// 00ff88
// 00ffbb
// 00ffff
//0088ff
// 0000ff
// 8800ff
// ff00ff
// ff00bb
// ff0088
// ff0044