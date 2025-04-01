#include "StillOneEffect.h"

StillOneEffect::StillOneEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void StillOneEffect::run(int focal) {
    for (int i = 0; i < 16; i++) {
        ledController.setLed(i, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
    }
}
