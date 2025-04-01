#include "BlenderEffect.h"
#include <Arduino.h>

BlenderEffect::BlenderEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void BlenderEffect::run(int focal) {
    int numLeds = 16;
    int numColors = 16;
    
    if (focal == -1) {
        // No focal point - create a blending effect across all LEDs
        while (true) {
            // First pattern: colors blend based on position and time
            for (int i = 0; i < numLeds; i++) {
                int colorIndex = (i + millis() / delayTime) % numColors;
                ledController.setLed(i, 
                                    pattern.red[colorIndex], 
                                    pattern.green[colorIndex], 
                                    pattern.blue[colorIndex], 
                                    pattern.white[colorIndex]);
            }
            delay(delayTime);

            // Second pattern: colors blend in reverse direction
            for (int i = 0; i < numLeds; i++) {
                int colorIndex = (numColors - (i + millis() / delayTime) % numColors) % numColors;
                ledController.setLed(i, 
                                    pattern.red[colorIndex], 
                                    pattern.green[colorIndex], 
                                    pattern.blue[colorIndex], 
                                    pattern.white[colorIndex]);
            }
            delay(delayTime);
        }
    }
    else {
        // Focal point provided - blend colors outward from focal point
        while (true) {
            // First pattern: colors blend based on distance from focal and time
            for (int i = 0; i < numLeds / 2; i++) {
                // Calculate LED positions on both sides of focal point
                int led1 = focal - i;
                int led2 = focal + i;

                // Wrap around if needed
                if (led1 < 0) {
                    led1 = 16 + led1;
                }
                if (led2 > 15) {
                    led2 = led2 - 16;
                }
                
                // Calculate color index based on distance and time
                int colorIndex = (i + millis() / delayTime) % numColors;
                
                // Set both LEDs to the same color
                ledController.setLed(led1, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
                ledController.setLed(led2, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
            }
            delay(delayTime);

            // Second pattern: colors blend in reverse direction
            for (int i = 0; i < numLeds / 2; i++) {
                // Calculate LED positions on both sides of focal point
                int led1 = focal - i;
                int led2 = focal + i;

                // Wrap around if needed
                if (led1 < 0) {
                    led1 = 16 + led1;
                }
                if (led2 > 15) {
                    led2 = led2 - 16;
                }
                
                // Calculate color index based on distance and time (reversed)
                int colorIndex = (numColors - (i + millis() / delayTime) % numColors) % numColors;
                
                // Set both LEDs to the same color
                ledController.setLed(led1, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
                ledController.setLed(led2, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
            }
            delay(delayTime);
        }
    }
}

