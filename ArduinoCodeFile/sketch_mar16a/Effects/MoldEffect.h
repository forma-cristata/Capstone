#ifndef MOLD_EFFECT_H
#define MOLD_EFFECT_H

#include "../LightEffect.h"

class MoldEffect : public LightEffect {
public:
    MoldEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // MOLD_EFFECT_H


