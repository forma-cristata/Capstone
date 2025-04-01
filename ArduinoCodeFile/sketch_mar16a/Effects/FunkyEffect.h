#ifndef FUNKY_EFFECT_H
#define FUNKY_EFFECT_H

#include "../LightEffect.h"

class FunkyEffect : public LightEffect {
public:
    FunkyEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // FUNKY_EFFECT_H



