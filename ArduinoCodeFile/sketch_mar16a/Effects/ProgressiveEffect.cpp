#include "ProgressiveEffect.h"
#include <Arduino.h>

ProgressiveEffect::ProgressiveEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void ProgressiveEffect::run(int focal) {
    // Set base color for all LEDs
    for (int i = 0; i < 16; i++) {
        ledController.setLed(i, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
    }

    if (focal != -1) {
        // Focal point provided - progressive animation centered on focal point
        while (true) {
            for (int j = 0; j < 16; j++) {
                for (int i = 0; i < 8; i++) {
                    // Calculate positions symmetrically around focal point
                    int ledIndex = (focal + i) % 16;
                    int ledIndex2 = (focal - i + 16) % 16;
                    
                    // Set LEDs with color j
                    ledController.setLed(ledIndex, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
                    ledController.setLed(ledIndex2, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
                    delay(delayTime);

                    // Move one step further from focal
                    ledIndex = (focal + i + 1) % 16;
                    ledIndex2 = (focal - i - 1 + 16) % 16;
                    ledController.setLed(ledIndex, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
                    ledController.setLed(ledIndex2, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
                    delay(delayTime);
                }
            }
        }
    }
    else {
        // No focal point - sequential progressive animation
        while (true) {
            for (int j = 0; j < 16; j++) {
                for (int i = 0; i < 16; i++) {
                    // Set adjacent LEDs with color j and move them around the ring
                    int ledIndex = (j + i) % 16;
                    int ledIndex2 = (j + i + 1) % 16;
                    ledController.setLed(ledIndex, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
                    ledController.setLed(ledIndex2, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
                    delay(delayTime * 2);

                    // Move one step forward
                    ledIndex = (j + i + 1) % 16;
                    ledIndex2 = (j + i + 2) % 16;
                    ledController.setLed(ledIndex, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
                    ledController.setLed(ledIndex2, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
                    delay(delayTime * 2);
                }
            }
        }
    }
}

