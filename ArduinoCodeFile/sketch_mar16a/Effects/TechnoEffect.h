#ifndef TECHNO_EFFECT_H
#define TECHNO_EFFECT_H

#include "../LightEffect.h"

class TechnoEffect : public LightEffect {
public:
    TechnoEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // TECHNO_EFFECT_H

