#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void led_1(int R, int G, int B, int W)
{
  leds[0].r = R; FastLED.show();
  leds[0].g = G; FastLED.show();
  leds[0].b = B; FastLED.show();
  leds[1].g = W; FastLED.show();
}

void led_2 (int R, int G, int B, int W)
{
  leds[1].r = G; FastLED.show();
  leds[1].b = R; FastLED.show();
  leds[2].r = W; FastLED.show();
  leds[2].g = B; FastLED.show();
}

void led_3 (int R, int G, int B, int W)
{
  leds[3].r = B; FastLED.show();
  leds[3].g = R; FastLED.show();
  leds[3].b = W; FastLED.show();
  leds[2].b = G; FastLED.show();
}

void led_4 (int R, int G, int B, int W)
{
  leds[4].r = R; FastLED.show();
  leds[4].g = G; FastLED.show();
  leds[4].b = B; FastLED.show();
  leds[5].g = W; FastLED.show();
}

void led_5 (int R, int G, int B, int W)
{
  leds[5].b = R; FastLED.show();
  leds[5].r = G; FastLED.show();
  leds[6].g = B; FastLED.show();
  leds[6].r = W; FastLED.show();
}

void led_6 (int R, int G, int B, int W)
{
  leds[7].r = B; FastLED.show();
  leds[7].g = R; FastLED.show();
  leds[7].b = W; FastLED.show();
  leds[6].b = G; FastLED.show();
}

void led_7 (int R, int G, int B, int W)
{
  leds[8].r = R; FastLED.show();
  leds[8].g = G; FastLED.show();
  leds[8].b = B; FastLED.show();
  leds[9].g = W; FastLED.show();
}

void led_8 (int R, int G, int B, int W)
{
  leds[9].r = G; FastLED.show();
  leds[9].b = R; FastLED.show();
  leds[10].r = W; FastLED.show();
  leds[10].g = B; FastLED.show();
}

void led_9 (int R, int G, int B, int W)
{
    leds[11].g = R; FastLED.show(); // Ninth Red
    leds[10].b = G; FastLED.show(); // Ninth Green
    leds[11].r = B; FastLED.show(); // Ninth Blue
    leds[11].b = W; FastLED.show(); // Ninth White
}

void led_10(int R, int G, int B, int W) {
  leds[12].r = R; FastLED.show();
  leds[12].g = G; FastLED.show();
  leds[12].b = B; FastLED.show();
  leds[13].g = W; FastLED.show(); 
}

void led_11(int R, int G, int B, int W) {
  leds[13].r = G; FastLED.show(); 
  leds[13].b = R; FastLED.show(); 
  leds[14].r = W; FastLED.show(); 
  leds[14].g = B; FastLED.show(); 
}

void led_12 (int R, int G, int B, int W) {
  leds[15].r = B; FastLED.show(); 
  leds[15].g = R; FastLED.show(); 
  leds[15].b = W; FastLED.show(); 
  leds[14].b = G; FastLED.show(); 
}

void led_13 (int R, int G, int B, int W)
{
  leds[16].r = R; FastLED.show();
  leds[16].g = G; FastLED.show();
  leds[16].b = B; FastLED.show();
  leds[17].g = W; FastLED.show();
}

void led_14 (int R, int G, int B, int W) {
  leds[17].b = R; FastLED.show(); 
  leds[17].r = G; FastLED.show(); 
  leds[18].g = B; FastLED.show(); 
  leds[18].r = W; FastLED.show(); 
}

void led_15 (int R, int G, int B, int W) {
  leds[19].r = B; FastLED.show(); 
  leds[19].g = R; FastLED.show(); 
  leds[19].b = W; FastLED.show(); 
  leds[18].b = G; FastLED.show(); 
}

void led_16 (int R, int G, int B, int W) {
  leds[20].r = R; FastLED.show(); 
  leds[20].g = G; FastLED.show(); 
  leds[20].b = B; FastLED.show(); 
  leds[21].g = W; FastLED.show(); 
}

// Todo build speed function to track speeds to less ms
void traceOne (int R, int G, int B, int W, int R1, int G1, int B1, int W1, int delayTime) {
    led_1(R1, G1, B1, W1);
    led_2(R1, G1, B1, W1);
    led_3(R1, G1, B1, W1);
    led_4(R1, G1, B1, W1);
    led_5(R1, G1, B1, W1);
    led_6(R1, G1, B1, W1);
    led_7(R1, G1, B1, W1);
    led_8(R1, G1, B1, W1);
    led_9(R1, G1, B1, W1);
    led_10(R1, G1, B1, W1);
    led_11(R1, G1, B1, W1);
    led_12(R1, G1, B1, W1);
    led_13(R1, G1, B1, W1);
    led_14(R1, G1, B1, W1);
    led_15(R1, G1, B1, W1);
    led_16(R1, G1, B1, W1);

    delay(delayTime);

  while (true) {
    led_9(R, G, B, W);
    
    led_8(R, G, B, W);

    
    delay(delayTime);
    
    led_8(R1, G1, B1, W1);
    led_9(R1, G1, B1, W1);



    led_7(R, G, B, W);
    led_10(R, G, B, W);
    delay(delayTime);
    led_7(R1, G1, B1, W1);
    led_10(R1, G1, B1, W1);

    led_6(R, G, B, W);
    led_11(R, G, B, W);
    delay(delayTime);
    led_6(R1, G1, B1, W1);
    led_11(R1, G1, B1, W1);

    led_5(R, G, B, W);
    led_12(R, G, B, W);
    delay(delayTime);
    led_5(R1, G1, B1, W1);
    led_12(R1, G1, B1, W1);

    led_4(R, G, B, W);
    led_13(R, G, B, W);
    delay(delayTime);
    led_4(R1, G1, B1, W1);
    led_13(R1, G1, B1, W1);

    led_3(R, G, B, W);
    led_14(R, G, B, W);
    delay(delayTime);
    led_3(R1, G1, B1, W1);
    led_14(R1, G1, B1, W1);

    led_2(R, G, B, W);
    led_15(R, G, B, W);
    delay(delayTime);
    led_2(R1, G1, B1, W1);
    led_15(R1, G1, B1, W1);

    led_1(R, G, B, W);
    led_16(R, G, B, W);
    delay(delayTime);
    led_1(R1, G1, B1, W1);
    led_16(R1, G1, B1, W1);
    
  }


}

void func2(int R1, int G1, int B1, int W1, 
                int R2, int G2, int B2, int W2, 
                int R3, int G3, int B3, int W3,
                int R4, int G4, int B4, int W4,
                int R5, int G5, int B5, int W5,
                int R6, int G6, int B6, int W6,
                int R7, int G7, int B7, int W7,
                int R8, int G8, int B8, int W8,int delayTime) {


  delay(delayTime);

  while (true) {
    led_1(R1, G1, B1, W1); delay(delayTime);
    led_2(R1, G1, B1, W1); delay(delayTime);
    led_3(R2, G2, B2, W2); delay(delayTime);
    led_4(R2, G2, B2, W2); delay(delayTime);
    led_5(R3, G3, B3, W3); delay(delayTime);
    led_6(R3, G3, B3, W3); delay(delayTime);
    led_7(R4, G4, B4, W4); delay(delayTime);
    led_8(R4, G4, B4, W4); delay(delayTime);
    led_9(R5, G5, B5, W5); delay(delayTime);
    led_10(R5, G5, B5, W5); delay(delayTime);
    led_11(R6, G6, B6, W6); delay(delayTime);
    led_12(R6, G6, B6, W6); delay(delayTime);
    led_13(R7, G7, B7, W7); delay(delayTime);
    led_14(R7, G7, B7, W7); delay(delayTime);
    led_15(R8, G8, B8, W8); delay(delayTime);
    led_16(R8, G8, B8, W8); delay(delayTime);
    led_2(R1, G1, B1, W1); delay(delayTime);
    led_3(R1, G1, B1, W1); delay(delayTime);
    led_4(R2, G2, B2, W2); delay(delayTime);
    led_5(R2, G2, B2, W2); delay(delayTime);
    led_6(R3, G3, B3, W3); delay(delayTime);
    led_7(R3, G3, B3, W3); delay(delayTime);
    led_8(R4, G4, B4, W4); delay(delayTime);
    led_9(R4, G4, B4, W4); delay(delayTime);
    led_10(R5, G5, B5, W5); delay(delayTime);
    led_11(R5, G5, B5, W5); delay(delayTime);
    led_12(R6, G6, B6, W6); delay(delayTime);
    led_13(R6, G6, B6, W6); delay(delayTime);
    led_14(R7, G7, B7, W7); delay(delayTime);
    led_15(R7, G7, B7, W7); delay(delayTime);
    led_16(R8, G8, B8, W8); delay(delayTime);
    led_1(R8, G8, B8, W8); delay(delayTime);
    led_3(R1, G1, B1, W1); delay(delayTime);
    led_4(R1, G1, B1, W1); delay(delayTime);
    led_5(R2, G2, B2, W2); delay(delayTime);
    led_6(R2, G2, B2, W2); delay(delayTime);
    led_7(R3, G3, B3, W3); delay(delayTime);
    led_8(R3, G3, B3, W3); delay(delayTime);
    led_9(R4, G4, B4, W4); delay(delayTime);
    led_10(R4, G4, B4, W4); delay(delayTime);
    led_11(R5, G5, B5, W5); delay(delayTime);
    led_12(R5, G5, B5, W5); delay(delayTime);
    led_13(R6, G6, B6, W6); delay(delayTime);
    led_14(R6, G6, B6, W6); delay(delayTime);
    led_15(R7, G7, B7, W7); delay(delayTime);
    led_16(R7, G7, B7, W7); delay(delayTime);
    led_1(R8, G8, B8, W8); delay(delayTime);
    led_2(R8, G8, B8, W8); delay(delayTime);
    led_4(R1, G1, B1, W1); delay(delayTime);
    led_5(R1, G1, B1, W1); delay(delayTime);
    led_6(R2, G2, B2, W2); delay(delayTime);
    led_7(R2, G2, B2, W2); delay(delayTime);
    led_8(R3, G3, B3, W3); delay(delayTime);
    led_9(R3, G3, B3, W3); delay(delayTime);
    led_10(R4, G4, B4, W4); delay(delayTime);
    led_11(R4, G4, B4, W4); delay(delayTime);
    led_12(R5, G5, B5, W5); delay(delayTime);
    led_13(R5, G5, B5, W5); delay(delayTime);
    led_14(R6, G6, B6, W6); delay(delayTime);
    led_15(R6, G6, B6, W6); delay(delayTime);
    led_16(R7, G7, B7, W7); delay(delayTime);
    led_1(R7, G7, B7, W7); delay(delayTime);
    led_2(R8, G8, B8, W8); delay(delayTime);
    led_3(R8, G8, B8, W8); delay(delayTime);
    led_5(R1, G1, B1, W1); delay(delayTime);
    led_6(R1, G1, B1, W1); delay(delayTime);
    led_7(R2, G2, B2, W2); delay(delayTime);
    led_8(R2, G2, B2, W2); delay(delayTime);
    led_9(R3, G3, B3, W3); delay(delayTime);
    led_10(R3, G3, B3, W3); delay(delayTime);
    led_11(R4, G4, B4, W4); delay(delayTime);
    led_12(R4, G4, B4, W4); delay(delayTime);
    led_13(R5, G5, B5, W5); delay(delayTime);
    led_14(R5, G5, B5, W5); delay(delayTime);
    led_15(R6, G6, B6, W6); delay(delayTime);
    led_16(R6, G6, B6, W6); delay(delayTime);
    led_1(R7, G7, B7, W7); delay(delayTime);
    led_2(R7, G7, B7, W7); delay(delayTime);
    led_3(R8, G8, B8, W8); delay(delayTime);
    led_4(R8, G8, B8, W8); delay(delayTime);

    led_6(R1, G1, B1, W1); delay(delayTime);
    led_7(R1, G1, B1, W1);delay(delayTime); 
    led_8(R2, G2, B2, W2);delay(delayTime);
    led_9(R2, G2, B2, W2);delay(delayTime);
    led_10(R3, G3, B3, W3);delay(delayTime);
    led_11(R3, G3, B3, W3);delay(delayTime);
    led_12(R4, G4, B4, W4);delay(delayTime);
    led_13(R4, G4, B4, W4);delay(delayTime);
    led_14(R5, G5, B5, W5);delay(delayTime);
    led_15(R5, G5, B5, W5);delay(delayTime);
    led_16(R6, G6, B6, W6);delay(delayTime);
    led_1(R6, G6, B6, W6);delay(delayTime);
    led_2(R7, G7, B7, W7);delay(delayTime);
    led_3(R7, G7, B7, W7);delay(delayTime);
    led_4(R8, G8, B8, W8);delay(delayTime);
    led_5(R8, G8, B8, W8);delay(delayTime);

    led_7(R1, G1, B1, W1);delay(delayTime);
    led_8(R1, G1, B1, W1);delay(delayTime);
    led_9(R2, G2, B2, W2);delay(delayTime);
    led_10(R2, G2, B2, W2);delay(delayTime);
    led_11(R3, G3, B3, W3);delay(delayTime);
    led_12(R3, G3, B3, W3);delay(delayTime);
    led_13(R4, G4, B4, W4);delay(delayTime);
    led_14(R4, G4, B4, W4);delay(delayTime);
    led_15(R5, G5, B5, W5);delay(delayTime);
    led_16(R5, G5, B5, W5);delay(delayTime);
    led_1(R6, G6, B6, W6);delay(delayTime);
    led_2(R6, G6, B6, W6);delay(delayTime);
    led_3(R7, G7, B7, W7);delay(delayTime);
    led_4(R7, G7, B7, W7);delay(delayTime);
    led_5(R8, G8, B8, W8);delay(delayTime);
    led_6(R8, G8, B8, W8);delay(delayTime);

    led_8(R1, G1, B1, W1);delay(delayTime);
    led_9(R1, G1, B1, W1);delay(delayTime);
    led_10(R2, G2, B2, W2);delay(delayTime);
    led_11(R2, G2, B2, W2);delay(delayTime);
    led_12(R3, G3, B3, W3);delay(delayTime);
    led_13(R3, G3, B3, W3);delay(delayTime);
    led_14(R4, G4, B4, W4);delay(delayTime);
    led_15(R4, G4, B4, W4);delay(delayTime);
    led_16(R5, G5, B5, W5);delay(delayTime);
    led_1(R5, G5, B5, W5);delay(delayTime);
    led_2(R6, G6, B6, W6);delay(delayTime);
    led_3(R6, G6, B6, W6);delay(delayTime);
    led_4(R7, G7, B7, W7);delay(delayTime);
    led_5(R7, G7, B7, W7);delay(delayTime);
    led_6(R8, G8, B8, W8);delay(delayTime);
    led_7(R8, G8, B8, W8);delay(delayTime);

    
    led_9(R1, G1, B1, W1);delay(delayTime);
    led_10(R1, G1, B1, W1);delay(delayTime);
    led_11(R2, G2, B2, W2);delay(delayTime);
    led_12(R2, G2, B2, W2);delay(delayTime);
    led_13(R3, G3, B3, W3);delay(delayTime);
    led_14(R3, G3, B3, W3);delay(delayTime);
    led_15(R4, G4, B4, W4);delay(delayTime);
    led_16(R4, G4, B4, W4);delay(delayTime);
    led_1(R5, G5, B5, W5);delay(delayTime);
    led_2(R5, G5, B5, W5);delay(delayTime);
    led_3(R6, G6, B6, W6);delay(delayTime);
    led_4(R6, G6, B6, W6);delay(delayTime);
    led_5(R7, G7, B7, W7);delay(delayTime);
    led_6(R7, G7, B7, W7);delay(delayTime);
    led_7(R8, G8, B8, W8);delay(delayTime);
    led_8(R8, G8, B8, W8);delay(delayTime);

    
    led_10(R1, G1, B1, W1);delay(delayTime);
    led_11(R1, G1, B1, W1);delay(delayTime);
    led_12(R2, G2, B2, W2);delay(delayTime);
    led_13(R2, G2, B2, W2);delay(delayTime);
    led_14(R3, G3, B3, W3);delay(delayTime);
    led_15(R3, G3, B3, W3);delay(delayTime);
    led_16(R4, G4, B4, W4);delay(delayTime);
    led_1(R4, G4, B4, W4);delay(delayTime);
    led_2(R5, G5, B5, W5);delay(delayTime);
    led_3(R5, G5, B5, W5);delay(delayTime);
    led_4(R6, G6, B6, W6);delay(delayTime);
    led_5(R6, G6, B6, W6);delay(delayTime);
    led_6(R7, G7, B7, W7);delay(delayTime);
    led_7(R7, G7, B7, W7);delay(delayTime);
    led_8(R8, G8, B8, W8);delay(delayTime);
    led_9(R8, G8, B8, W8);delay(delayTime);

     
    led_11(R1, G1, B1, W1);delay(delayTime);
    led_12(R1, G1, B1, W1);delay(delayTime);
    led_13(R2, G2, B2, W2);delay(delayTime);
    led_14(R2, G2, B2, W2);delay(delayTime);
    led_15(R3, G3, B3, W3);delay(delayTime);
    led_16(R3, G3, B3, W3);delay(delayTime);
    led_1(R4, G4, B4, W4);delay(delayTime);
    led_2(R4, G4, B4, W4);delay(delayTime);
    led_3(R5, G5, B5, W5);delay(delayTime);
    led_4(R5, G5, B5, W5);delay(delayTime);
    led_5(R6, G6, B6, W6);delay(delayTime);
    led_6(R6, G6, B6, W6);delay(delayTime);
    led_7(R7, G7, B7, W7);delay(delayTime);
    led_8(R7, G7, B7, W7);delay(delayTime);
    led_9(R8, G8, B8, W8);delay(delayTime);
    led_10(R8, G8, B8, W8);delay(delayTime);

         
    led_12(R1, G1, B1, W1);delay(delayTime);
    led_13(R1, G1, B1, W1);delay(delayTime);
    led_14(R2, G2, B2, W2);delay(delayTime);
    led_15(R2, G2, B2, W2);delay(delayTime);
    led_16(R3, G3, B3, W3);delay(delayTime);
    led_1(R3, G3, B3, W3);delay(delayTime);
    led_2(R4, G4, B4, W4);delay(delayTime);
    led_3(R4, G4, B4, W4);delay(delayTime);
    led_4(R5, G5, B5, W5);delay(delayTime);
    led_5(R5, G5, B5, W5);delay(delayTime);
    led_6(R6, G6, B6, W6);delay(delayTime);
    led_7(R6, G6, B6, W6);delay(delayTime);
    led_8(R7, G7, B7, W7);delay(delayTime);
    led_9(R7, G7, B7, W7);delay(delayTime);
    led_10(R8, G8, B8, W8);delay(delayTime);
    led_11(R8, G8, B8, W8);delay(delayTime);

         
    led_12(R1, G1, B1, W1);delay(delayTime);
    led_13(R1, G1, B1, W1);delay(delayTime);
    led_14(R2, G2, B2, W2);delay(delayTime);
    led_15(R2, G2, B2, W2);delay(delayTime);
    led_16(R3, G3, B3, W3);delay(delayTime);
    led_1(R3, G3, B3, W3);delay(delayTime);
    led_2(R4, G4, B4, W4);delay(delayTime);
    led_3(R4, G4, B4, W4);delay(delayTime);
    led_4(R5, G5, B5, W5);delay(delayTime);
    led_5(R5, G5, B5, W5);delay(delayTime);
    led_6(R6, G6, B6, W6);delay(delayTime);
    led_7(R6, G6, B6, W6);delay(delayTime);
    led_8(R7, G7, B7, W7);delay(delayTime);
    led_9(R7, G7, B7, W7);delay(delayTime);
    led_10(R8, G8, B8, W8);delay(delayTime);
    led_11(R8, G8, B8, W8);delay(delayTime);

             
    led_13(R1, G1, B1, W1);delay(delayTime);
    led_14(R1, G1, B1, W1);delay(delayTime);
    led_15(R2, G2, B2, W2);delay(delayTime);
    led_16(R2, G2, B2, W2);delay(delayTime);
    led_1(R3, G3, B3, W3);delay(delayTime);
    led_2(R3, G3, B3, W3);delay(delayTime);
    led_3(R4, G4, B4, W4);delay(delayTime);
    led_4(R4, G4, B4, W4);delay(delayTime);
    led_5(R5, G5, B5, W5);delay(delayTime);
    led_6(R5, G5, B5, W5);delay(delayTime);
    led_7(R6, G6, B6, W6);delay(delayTime);
    led_8(R6, G6, B6, W6);delay(delayTime);
    led_9(R7, G7, B7, W7);delay(delayTime);
    led_10(R7, G7, B7, W7);delay(delayTime);
    led_11(R8, G8, B8, W8);delay(delayTime);
    led_12(R8, G8, B8, W8);delay(delayTime);

    
             
    led_14(R1, G1, B1, W1);delay(delayTime);
    led_15(R1, G1, B1, W1);delay(delayTime);
    led_16(R2, G2, B2, W2);delay(delayTime);
    led_1(R2, G2, B2, W2);delay(delayTime);
    led_2(R3, G3, B3, W3);delay(delayTime);
    led_3(R3, G3, B3, W3);delay(delayTime);
    led_4(R4, G4, B4, W4);delay(delayTime);
    led_5(R4, G4, B4, W4);delay(delayTime);
    led_6(R5, G5, B5, W5);delay(delayTime);
    led_7(R5, G5, B5, W5);delay(delayTime);
    led_8(R6, G6, B6, W6);delay(delayTime);
    led_9(R6, G6, B6, W6);delay(delayTime);
    led_10(R7, G7, B7, W7);delay(delayTime);
    led_11(R7, G7, B7, W7);delay(delayTime);
    led_12(R8, G8, B8, W8);delay(delayTime);
    led_13(R8, G8, B8, W8);delay(delayTime);
    
             
    led_15(R1, G1, B1, W1);delay(delayTime);
    led_16(R1, G1, B1, W1);delay(delayTime);
    led_1(R2, G2, B2, W2);delay(delayTime);
    led_2(R2, G2, B2, W2);delay(delayTime);
    led_3(R3, G3, B3, W3);delay(delayTime);
    led_4(R3, G3, B3, W3);delay(delayTime);
    led_5(R4, G4, B4, W4);delay(delayTime);
    led_6(R4, G4, B4, W4);delay(delayTime);
    led_7(R5, G5, B5, W5);delay(delayTime);
    led_8(R5, G5, B5, W5);delay(delayTime);
    led_9(R6, G6, B6, W6);delay(delayTime);
    led_10(R6, G6, B6, W6);delay(delayTime);
    led_11(R7, G7, B7, W7);delay(delayTime);
    led_12(R7, G7, B7, W7);delay(delayTime);
    led_13(R8, G8, B8, W8);delay(delayTime);
    led_14(R8, G8, B8, W8);delay(delayTime);
                 
    led_16(R1, G1, B1, W1);delay(delayTime);
    led_1(R1, G1, B1, W1);delay(delayTime);
    led_2(R2, G2, B2, W2);delay(delayTime);
    led_3(R2, G2, B2, W2);delay(delayTime);
    led_4(R3, G3, B3, W3);delay(delayTime);
    led_5(R3, G3, B3, W3);delay(delayTime);
    led_6(R4, G4, B4, W4);delay(delayTime);
    led_7(R4, G4, B4, W4);delay(delayTime);
    led_8(R5, G5, B5, W5);delay(delayTime);
    led_9(R5, G5, B5, W5);delay(delayTime);
    led_10(R6, G6, B6, W6);delay(delayTime);
    led_11(R6, G6, B6, W6);delay(delayTime);
    led_12(R7, G7, B7, W7);delay(delayTime);
    led_13(R7, G7, B7, W7);delay(delayTime);
    led_14(R8, G8, B8, W8);delay(delayTime);
    led_15(R8, G8, B8, W8);delay(delayTime);
  }
}


void loop() {
  //traceOne(255, 0, 255, 1, 255, 0, 0, 0, random(10, 50)); // !10/10 SETTING!
  func2(242, 68, 196, 0, 
                215, 7, 242, 0, 
                109, 15, 242, 0,
                24, 20, 140, 0,
                200, 185, 12, 0,
                242, 140, 68, 0,
                242, 92, 92, 0,
                242, 46, 118, 0, 5);
}