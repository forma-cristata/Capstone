#ifndef STILL_ONE_EFFECT_H
#define STILL_ONE_EFFECT_H

#include "../LightEffect.h"

class StillOneEffect : public LightEffect {
public:
    StillOneEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // STILL_ONE_EFFECT_H
