#include "LEDController.h"
#define SEED 42
#define LED_DATA_PIN 6 // Define DATA_PIN here or include it from a common header

LEDController::LEDController(int numLeds, int dataPin) : numLeds(numLeds), dataPin(dataPin) {
    leds = new CRGB[numLeds];
    randomSeed(SEED);
}

LEDController::~LEDController() {
    delete[] leds;
}

void LEDController::begin() {
    FastLED.addLeds<NEOPIXEL, LED_DATA_PIN>(leds, numLeds);
}

void LEDController::setLed(int L, int R, int G, int B, int W) {
    switch ((L + 1) % 3) {
    case 1:
        handleCase1(L, R, G, B, W);
        break;
    case 2:
        handleCase2(L, R, G, B, W);
        break;
    case 0:
        handleCase0(L, R, G, B, W);
        break;
    }
}

void LEDController::handleCase1(int L, int R, int G, int B, int W) {
    switch (L + 1) {
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
}

void LEDController::handleCase2(int L, int R, int G, int B, int W) {
    switch (L + 1) {
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
}

void LEDController::handleCase0(int L, int R, int G, int B, int W) {
    switch (L + 1) {
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
        leds[11].g = R; FastLED.show();
        leds[10].b = G; FastLED.show();
        leds[11].r = B; FastLED.show();
        leds[11].b = W; FastLED.show();
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
}
