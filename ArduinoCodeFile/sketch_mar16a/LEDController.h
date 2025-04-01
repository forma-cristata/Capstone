#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include <FastLED.h>

class LEDController {
private:
    CRGB* leds;
    int numLeds;
    int dataPin;
    
    void handleCase1(int L, int R, int G, int B, int W);
    void handleCase2(int L, int R, int G, int B, int W);
    void handleCase0(int L, int R, int G, int B, int W);
    
public:
    LEDController(int numLeds, int dataPin);
    ~LEDController();
    void begin();
    void setLed(int L, int R, int G, int B, int W);
};

#endif // LED_CONTROLLER_H
