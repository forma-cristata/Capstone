#ifndef LIGHT_APPLICATION_H
#define LIGHT_APPLICATION_H

#include "Constants.h"  // Add this line
#include "LEDController.h"
#include "MagnetSensor.h"
#include "LightEffect.h"
#include "ColorPattern.h"
#include "Effects.h"

class LightApplication {
private:
    LEDController ledController;
    MagnetSensor magnetSensor;
    LightEffect* currentEffect;

    // Color arrays
    int wr[16];
    int r1[16];
    int g1[16];
    int b1[16];

    int r2[16];
    int g2[16];
    int b2[16];

    int r4[16];
    int g4[16];
    int b4[16];

    int r5[16];
    int g5[16];
    int b5[16];

    int r6[16];
    int g6[16];
    int b6[16];

    int r7[16];
    int g7[16];
    int b7[16];

    void initializeColorArrays();
public:
    LightApplication();
    ~LightApplication();
    void setup();
    void loop();
    void setEffect(LightEffect* newEffect);
    void selectEffect(int effectNumber);
};

#endif // LIGHT_APPLICATION_H
