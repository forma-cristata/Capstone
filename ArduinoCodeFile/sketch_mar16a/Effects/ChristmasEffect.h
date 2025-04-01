#ifndef CHRISTMAS_EFFECT_H
#define CHRISTMAS_EFFECT_H

#include "../LightEffect.h"

class ChristmasEffect : public LightEffect {
public:
    ChristmasEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // CHRISTMAS_EFFECT_H






