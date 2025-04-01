#include "TraceOneEffect.h"
#include <Arduino.h>

TraceOneEffect::TraceOneEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void TraceOneEffect::run(int focal) {
    // Set base color for all LEDs
    for (int i = 0; i < 16; i++) {
        ledController.setLed(i, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
    }

    if (focal != -1) {
        // Focal point provided - trace outward from focal point
        while (true) {
            for (int i = 1; i < 16; i++) {
                for (int j = 0; j < 8; j++) {
                    // Calculate positions on both sides of the focal point
                    int position1 = (focal + 1 + j) % 16;
                    int position2 = (16 + focal - j) % 16;
                    
                    // Illuminate LEDs with color i
                    ledController.setLed(position1, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                    ledController.setLed(position2, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                    delay(delayTime);
                    
                    // Reset to base color
                    ledController.setLed(position1, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
                    ledController.setLed(position2, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
                }
            }
        }
    }
    else {
        // No focal point - sequence through all positions
        while (true) {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    // Illuminate each LED in sequence with color i
                    ledController.setLed(j, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                    delay(delayTime * 2);
                    
                    // Reset to base color
                    ledController.setLed(j, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
                }
            }
        }
    }
}
