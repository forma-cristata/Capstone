#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void turnOn1()
{
  //leds[0] = CRGB(255, 0, 0); FastLED.show(); // First Red
  //leds[0] = CRGB(0, 255, 0); FastLED.show(); // First Green
  //leds[0] = CRGB(0, 0, 255); FastLED.show(); // First Blue
  leds[1] = CRGB(0, 255, 0); FastLED.show(); // First White
}

void turnOn2() 
{
  //leds[1] = CRGB(0, 0, 255); FastLED.show(); // Second Red
  //leds[1] = CRGB(255, 0, 0); FastLED.show(); // Second Green
  //leds[2] = CRGB(0, 255, 0); FastLED.show(); // Second Blue
  leds[2] = CRGB(255, 0, 0); FastLED.show(); // Second White
  

}

void turnOn3()
{
  //leds[3] = CRGB(0, 255, 0); FastLED.show(); // Third Red
  //leds[2] = CRGB(0, 0, 255); FastLED.show(); // Third Green
  //leds[3] = CRGB(255, 0, 0); FastLED.show(); // Third Blue
  leds[3] = CRGB(0, 0, 255); FastLED.show(); // Third White
}

void turnOn4()
{
  //leds[4] = CRGB(255, 0, 0); FastLED.show(); // Fourth Red
  //leds[4] = CRGB(0, 255, 0); FastLED.show(); // Fourth Green
  //leds[4] = CRGB(0, 0, 255); FastLED.show(); // Fourth Blue
  leds[5] = CRGB(0, 255, 0); FastLED.show(); // Fourth White

}

void turnOn5() {
  //leds[5] = CRGB(0, 0, 255); FastLED.show(); // Fifth Red
  //leds[5] = CRGB(255, 0, 0); FastLED.show(); // Fifth Green
  //leds[6] = CRGB(0, 255, 0); FastLED.show(); // Fifth Blue
  leds[6] = CRGB(255, 0, 0); FastLED.show(); // Fifth White

}

void turnOn6() {
  //leds[7] = CRGB(0, 255, 0); FastLED.show(); // Sixth Red
  //leds[6] = CRGB(0, 0, 255); FastLED.show(); // Sixth Green
  // leds[7] = CRGB(255, 0, 0); FastLED.show(); // Sixth Blue
  leds[7] = CRGB(0, 0, 255); FastLED.show(); // Sixth White

}

void turnOn7() {
  //leds[8] = CRGB(255, 0, 0); FastLED.show(); // Seventh Red
  //leds[8] = CRGB(0, 255, 0); FastLED.show(); // Seventh Green
  //leds[8] = CRGB(0, 0, 255); FastLED.show(); // Seventh Blue
  leds[9] = CRGB(0, 255, 0); FastLED.show(); // Seventh White

}

void turnOn8() {
  //leds[9] = CRGB(0, 0, 255); FastLED.show(); // Eighth Red
  //leds[9] = CRGB(255, 0, 0); FastLED.show(); // Eighth Green
  //leds[10] = CRGB(0, 255, 0); FastLED.show(); // Eighth Blue
  leds[10] = CRGB(255, 0, 0); FastLED.show(); // Eighth White

}

void turnOn9() {
  //leds[11] = CRGB(0, 255, 0); FastLED.show(); // Ninth Red
  //leds[10] = CRGB(0, 0, 255); FastLED.show(); // Ninth Green
  //leds[11] = CRGB(255, 0, 0); FastLED.show(); // Ninth Blue
  leds[11] = CRGB(0, 0, 255); FastLED.show(); // Ninth White

}

void turnOn10() {
  //leds[12] = CRGB(255, 0, 0); FastLED.show(); // Tenth Red
  //leds[12] = CRGB(0, 255, 0); FastLED.show(); // Tenth Green
  //leds[12] = CRGB(0, 0, 255); FastLED.show(); // Tenth Blue
  leds[13] = CRGB(0, 255, 0); FastLED.show(); // Tenth White

}

void turnOn11() {
  //leds[13] = CRGB(0, 0, 255); FastLED.show(); // Eleventh Red
  //leds[13] = CRGB(255, 0, 0); FastLED.show(); // Eleventh Green
  //leds[14] = CRGB(0, 255, 0); FastLED.show(); // Eleventh Blue
  leds[14] = CRGB(255, 0, 0); FastLED.show(); // Eleventh White

}

void turnOn12() {
  //leds[15] = CRGB(0, 255, 0); FastLED.show(); // Twelfth Red
  //leds[14] = CRGB(0, 0, 255); FastLED.show(); // Twelfth Green
  //leds[15] = CRGB(255, 0, 0); FastLED.show(); // Twelfth Blue
  leds[15] = CRGB(0, 0, 255); FastLED.show(); // Twelfth White

}

void turnOn13() {
  //leds[16] = CRGB(255, 0, 0); FastLED.show(); // Thirteenth Red
  //leds[16] = CRGB(0, 255, 0); FastLED.show(); // Thirteenth Green
  //leds[16] = CRGB(0, 0, 255); FastLED.show(); // Thirteenth Blue
  leds[17] = CRGB(0, 255, 0); FastLED.show(); // Thirteenth White

}

void turnOn14() {
  //leds[17] = CRGB(0, 0, 255); FastLED.show(); // Fourteenth Red
  //leds[17] = CRGB(255, 0, 0); FastLED.show(); // Fourteenth Green
  //leds[18] = CRGB(0, 255, 0); FastLED.show(); // Fourteenth Blue
  leds[18] = CRGB(255, 0, 0); FastLED.show(); // Fourteenth White

}

void turnOn15() {
  //leds[19] = CRGB(0, 255, 0); FastLED.show(); // Fifteenth Red
  //leds[18] = CRGB(0, 0, 255); FastLED.show(); // Fifteenth Green
  //leds[19] = CRGB(255, 0, 0); FastLED.show(); // Fifteenth Blue
  leds[19] = CRGB(0, 0, 255); FastLED.show(); // Fifteenth White

}

void turnOn16() {
  //leds[20] = CRGB(255, 0, 0); FastLED.show(); // Sixteenth Red
  //leds[20] = CRGB(0, 255, 0); FastLED.show(); // Sixteenth Green
  //leds[20] = CRGB(0, 0, 255); FastLED.show(); // Sixteenth Green
  leds[21] = CRGB(0, 255, 0); FastLED.show(); // Sixteenth White
}

void turnOff(int led)
{
  leds[led] = CRGB(0, 0, 0); FastLED.show();
}


void loop() {
  turnOn1();
  turnOn2();
  turnOn3();
  turnOn4();
  turnOn5();
  turnOn6();
  turnOn7();
  turnOn8();
  turnOn9();
  turnOn10();
  turnOn11();
  turnOn12();
  turnOn13();
  turnOn14();
  turnOn15();
  turnOn16();

  while(true){
  turnOff(0);
  delay(100);
  turnOn1();

  turnOff(1);
    delay(100);
  turnOn2();

  turnOff(3);
    delay(100);
  turnOn3();

  turnOff(4);
    delay(100);
  turnOn4();

  turnOff(5);
    delay(100);
  turnOn5();

  turnOff(7);
    delay(100);
  turnOn6();

  turnOff(8);
    delay(100);
  turnOn7();

  turnOff(9);
    delay(100);
  turnOn8();

  turnOff(11);
    delay(100);
  turnOn9();

  turnOff(12);
    delay(100);
  turnOn10();

  turnOff(13);
    delay(100);
  turnOn11();

  turnOff(15);
    delay(100);
  turnOn12();

  turnOff(16);
    delay(100);
  turnOn13();

  turnOff(17);
    delay(100);
  turnOn14();

  turnOff(19);
    delay(100);
  turnOn15();

  turnOff(20);
    delay(100);
  turnOn16();
  }
}