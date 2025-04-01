#ifndef TRANCE_EFFECT_H
#define TRANCE_EFFECT_H

#include "../LightEffect.h"

class TranceEffect : public LightEffect {
public:
    TranceEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // TRANCE_EFFECT_H


