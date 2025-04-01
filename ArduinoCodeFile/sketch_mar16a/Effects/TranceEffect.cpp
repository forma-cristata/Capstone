#include "TranceEffect.h"
#include <Arduino.h>

TranceEffect::TranceEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void TranceEffect::run(int focal) {
    // Define parameters for the trance effect
    int sc1 = 4; // Number of strobe cycles in first pattern
    int sc2 = 2; // Number of strobe cycles in second pattern
    int ls = 3;  // Number of LEDs to light up in a group
    
    if (focal == -1) {
        // No focal point - standard trance effect
        for (int j = 0; j <= 15; j++) {
            // First pattern: sc1 repeats of strobe effect
            for (int k = 0; k < sc1; k++) {
                // Turn on LEDs
                for (int i = 0; i < ls; i++) {
                    int li = j + i;
                    if (li < 16) { // Bound check
                        ledController.setLed(li + 1, pattern.red[li], pattern.green[li], pattern.blue[li], pattern.white[li]);
                    }
                }
                delay(delayTime);
                
                // Turn off LEDs
                for (int i = 0; i < ls; i++) {
                    int ledIndex = j + i;
                    if (ledIndex < 16) { // Bound check
                        ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    }
                }
                delay(delayTime);
            }

            // Second pattern: sc2 repeats of another strobe effect
            for (int strobe = 0; strobe < sc2; strobe++) {
                // Turn on LEDs
                for (int i = 0; i < ls; i++) {
                    int ledIndex = j + i;
                    if (ledIndex < 16) { // Bound check
                        ledController.setLed(ledIndex + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                    }
                }
                delay(delayTime);
                
                // Turn off LEDs
                for (int i = 0; i < ls; i++) {
                    int ledIndex = j + i;
                    if (ledIndex < 16) { // Bound check
                        ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    }
                }
                delay(delayTime);
            }
        }
    }
    else {
        // Focal point provided - distance-based trance effect
        for (int j = 0; j <= 15; j++) {
            // Calculate the distance from the focal point
            int distance = abs(focal - j);
            
            // First pattern: sc1 repeats of strobe effect
            for (int k = 0; k < sc1; k++) {
                // Turn on LEDs based on distance from focal point
                for (int i = 0; i < ls; i++) {
                    int li = distance + i;  // Use distance from focal point
                    if (li < 16) { // Bound check
                        ledController.setLed(li + 1, pattern.red[li], pattern.green[li], pattern.blue[li], pattern.white[li]);
                    }
                }
                delay(delayTime);
                
                // Turn off LEDs
                for (int i = 0; i < ls; i++) {
                    int ledIndex = distance + i;
                    if (ledIndex < 16) { // Bound check
                        ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    }
                }
                delay(delayTime);
            }

            // Second pattern: sc2 repeats of another strobe effect
            for (int strobe = 0; strobe < sc2; strobe++) {
                // Turn on LEDs based on distance from focal point
                for (int i = 0; i < ls; i++) {
                    int ledIndex = distance + i;
                    if (ledIndex < 16) { // Bound check
                        ledController.setLed(ledIndex + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                    }
                }
                delay(delayTime);
                
                // Turn off LEDs
                for (int i = 0; i < ls; i++) {
                    int ledIndex = distance + i;
                    if (ledIndex < 16) { // Bound check
                        ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    }
                }
                delay(delayTime);
            }
        }
    }
}


