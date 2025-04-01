#ifndef STROBE_CHANGE_EFFECT_H
#define STROBE_CHANGE_EFFECT_H

#include "../LightEffect.h"

class StrobeChangeEffect : public LightEffect {
public:
    StrobeChangeEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // STROBE_CHANGE_EFFECT_H
