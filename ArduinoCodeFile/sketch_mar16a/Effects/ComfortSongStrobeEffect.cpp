#include "ComfortSongStrobeEffect.h"
#include <Arduino.h>

ComfortSongStrobeEffect::ComfortSongStrobeEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void ComfortSongStrobeEffect::run(int focal) {
    // Define pattern indices for different LED groups
    int patternIndices[] = { 1, 2, 3, 2, 4, 3, 2, 1, 0, 1, 2, 1, 3, 2, 1, 0 };
    int pattern2Indices[] = { 7, 8, 9, 8, 10, 9, 8, 7, 6, 7, 8, 7, 9, 8, 7, 6 };
    int pattern3Indices[] = { 13, 14, 15, 14, 16, 15, 14, 13, 12, 13, 14, 13, 15, 14, 13, 12 };

    if (focal == -1) {
        // No focal point - apply strobe effect using three pattern sets
        while (true) {
            for (int x = 0; x < 16; x++) {
                for (int i = 0; i < delayTime; i++) {
                    // Turn on LEDs in the three pattern groups
                    ledController.setLed(patternIndices[x], pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
                    ledController.setLed(pattern2Indices[x], pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
                    ledController.setLed(pattern3Indices[x], pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
                    delay(5);
                    
                    // Turn off LEDs to create strobe effect
                    ledController.setLed(patternIndices[x], 0, 0, 0, 0);
                    ledController.setLed(pattern2Indices[x], 0, 0, 0, 0);
                    ledController.setLed(pattern3Indices[x], 0, 0, 0, 0);
                    delay(5);
                }
            }
        }
    }
    else {
        // Focal point provided - create pattern relative to focal point
        int pattern4Indices[] = { 3, 4, 5, 4, 6, 5, 4, 3, 2, 3, 4, 3, 5, 4, 3, 2 };
        while (true) {
            for (int x = 0; x < 16; x++) {
                for (int i = 0; i < delayTime; i++) {
                    // Calculate LED positions relative to focal point
                    int led1 = pattern4Indices[x] + focal;
                    if (led1 < 0) {
                        led1 = 16 + led1;
                    }
                    else if (led1 > 15) {
                        led1 = led1 - 16;
                    }

                    int led2 = focal - pattern4Indices[x];
                    if (led2 < 0) {
                        led2 = 16 + led2;
                    }
                    else if (led2 > 15) {
                        led2 = led2 - 16;
                    }
                    
                    // Turn on LEDs with the pattern color
                    ledController.setLed(led1, pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
                    ledController.setLed(led2, pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
                    delay(5);
                    
                    // Turn off LEDs to create strobe effect
                    ledController.setLed(led1, 0, 0, 0, 0);
                    ledController.setLed(led2, 0, 0, 0, 0);
                    delay(5);
                }
            }
        }
    }
}

