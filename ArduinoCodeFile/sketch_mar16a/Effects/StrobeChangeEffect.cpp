#include "StrobeChangeEffect.h"
#include <Arduino.h>

StrobeChangeEffect::StrobeChangeEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void StrobeChangeEffect::run(int focal) {
    // Set base color for all LEDs
    for (int i = 0; i < 16; i++) {
        ledController.setLed(i, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
    }
    
    if (focal == -1) {
        // No focal point - strobe effect with changing positions
        while (true) {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 8; j++) {
                    // Calculate LED position
                    int offset = (i + j * 2) % 16;
                    
                    // Strobe the LED (turn on and off rapidly)
                    for (int k = 0; k < delayTime * 2; k++) {
                        // Turn off
                        ledController.setLed(offset, 0, 0, 0, 0);
                        delay(6);
                        
                        // Turn on with color
                        ledController.setLed(offset, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                        delay(6);
                    }
                }
            }
        }
    }
    else {
        // Focal point provided - strobe effect radiating from focal point
        while (true) {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 8; j++) {
                    // Calculate positions relative to focal point
                    int position1 = (focal + 1 + (i + j * 2) % 16) % 16;
                    int position2 = (16 + focal - (i + j * 2) % 16) % 16;
                    
                    // Strobe both LEDs (turn on and off rapidly)
                    for (int k = 0; k < delayTime * 2; k++) {
                        // Turn off
                        ledController.setLed(position1, 0, 0, 0, 0);
                        ledController.setLed(position2, 0, 0, 0, 0);
                        delay(6);
                        
                        // Turn on with color
                        ledController.setLed(position1, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                        ledController.setLed(position2, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                        delay(6);
                    }
                }
            }
        }
    }
}
