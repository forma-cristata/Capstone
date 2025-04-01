#ifndef PROGRESSIVE_EFFECT_H
#define PROGRESSIVE_EFFECT_H

#include "../LightEffect.h"

class ProgressiveEffect : public LightEffect {
public:
    ProgressiveEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // PROGRESSIVE_EFFECT_H

