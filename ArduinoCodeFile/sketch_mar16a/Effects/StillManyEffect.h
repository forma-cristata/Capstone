#ifndef STILL_MANY_EFFECT_H
#define STILL_MANY_EFFECT_H

#include "../LightEffect.h"

class StillManyEffect : public LightEffect {
public:
    StillManyEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // STILL_MANY_EFFECT_H
