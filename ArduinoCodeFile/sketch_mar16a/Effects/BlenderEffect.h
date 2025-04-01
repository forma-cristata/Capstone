#ifndef BLENDER_EFFECT_H
#define BLENDER_EFFECT_H

#include "../LightEffect.h"

class BlenderEffect : public LightEffect {
public:
    BlenderEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // BLENDER_EFFECT_H

