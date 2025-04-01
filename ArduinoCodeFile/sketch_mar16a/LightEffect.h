#ifndef LIGHT_EFFECT_H
#define LIGHT_EFFECT_H

#include "LEDController.h"
#include "ColorPattern.h"

class LightEffect {
protected:
    LEDController& ledController;
    ColorPattern pattern;
    int delayTime;

public:
    LightEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    virtual void run(int focal = -1) = 0;
    virtual ~LightEffect() = default;
};

#endif // LIGHT_EFFECT_H
