#include "StillManyEffect.h"

StillManyEffect::StillManyEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void StillManyEffect::run(int focal) {
    for (int i = 0; i < 16; i++) {
        ledController.setLed(i, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
    }
}
