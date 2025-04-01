#ifndef TRACE_ONE_EFFECT_H
#define TRACE_ONE_EFFECT_H

#include "../LightEffect.h"

class TraceOneEffect : public LightEffect {
public:
    TraceOneEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // TRACE_ONE_EFFECT_H
