#include "LightEffect.h"

LightEffect::LightEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : ledController(controller), pattern(colorPattern), delayTime(delay) {
}
