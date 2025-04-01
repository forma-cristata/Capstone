#include "FunkyEffect.h"
#include <Arduino.h>

FunkyEffect::FunkyEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void FunkyEffect::run(int focal) {
    // Define parameters for the funky effect
    int strobeCount1 = 4;  // Number of strobes in first sequence
    int strobeCount2 = 4;  // Number of strobes in second sequence
    int ledsPerGroup = 1;  // Number of LEDs to control in each group
    
    if (focal == -1) {
        // No focal point - standard funky effect with random lights
        while (true) {
            delay(delayTime / 4);

            // First strobe sequence
            for (int strobe = 0; strobe < strobeCount1; strobe++) {
                for (int i = 0; i < ledsPerGroup; i++) {
                    // Choose a random LED
                    int ledIndex = random(0, 16);
                    delay(delayTime / 12);
                    // Turn it on with its pattern color
                    ledController.setLed(ledIndex + 1, 
                                         pattern.red[ledIndex], 
                                         pattern.green[ledIndex], 
                                         pattern.blue[ledIndex], 
                                         pattern.white[ledIndex]);
                }
                delay(delayTime / 12);

                for (int i = 0; i < ledsPerGroup; i++) {
                    // Choose a random LED
                    int ledIndex = random(0, 16);
                    delay(delayTime / 8);
                    // Turn it off
                    ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                }
            }

            // Second strobe sequence
            for (int strobe = 0; strobe < strobeCount2; strobe++) {
                for (int i = 0; i < ledsPerGroup; i++) {
                    delay(delayTime / 12);

                    // Choose a random LED
                    int ledIndex = random(0, 16);
                    // Turn it on with its pattern color
                    ledController.setLed(ledIndex + 1, 
                                         pattern.red[ledIndex], 
                                         pattern.green[ledIndex], 
                                         pattern.blue[ledIndex], 
                                         pattern.white[ledIndex]);
                }
                delay(delayTime / 12);

                for (int i = 0; i < ledsPerGroup; i++) {
                    delay(delayTime / 12);

                    // Choose a random LED
                    int ledIndex = random(0, 16);
                    // Turn it off
                    ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                }
            }
        }
    }
    else {
        // Focal point provided - modified funky effect with pairs of random lights
        while (true) {
            // First strobe sequence - using focal as limit
            for (int strobe = focal; strobe < strobeCount1; strobe++) {
                for (int i = 0; i < ledsPerGroup; i++) {
                    // Choose two random LEDs
                    int ledIndex = random(0, 16);
                    int ledIndex2 = random(0, 16);
                    delay(delayTime / 12);
                    // Turn them on with the same pattern color
                    ledController.setLed(ledIndex + 1, 
                                         pattern.red[ledIndex], 
                                         pattern.green[ledIndex], 
                                         pattern.blue[ledIndex], 
                                         pattern.white[ledIndex]);
                    ledController.setLed(ledIndex2 + 1, 
                                         pattern.red[ledIndex], 
                                         pattern.green[ledIndex], 
                                         pattern.blue[ledIndex], 
                                         pattern.white[ledIndex]);
                }
                delay(delayTime / 12);

                for (int i = focal; i < ledsPerGroup; i++) {
                    // Choose two random LEDs
                    int ledIndex = random(0, 16);
                    int ledIndex2 = random(0, 16);
                    delay(delayTime / 8);
                    // Turn them off
                    ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    ledController.setLed(ledIndex2 + 1, 0, 0, 0, 0);
                }
            }

            // Second strobe sequence - counting down from focal + 1
            for (int strobe = focal + 1; strobe >= 0; strobe--) {
                for (int i = 0; i < ledsPerGroup; i++) {
                    delay(delayTime / 12);

                    // Choose two random LEDs
                    int ledIndex = random(0, 16);
                    int ledIndex2 = random(0, 16);
                    // Turn them on with the same pattern color
                    ledController.setLed(ledIndex + 1, 
                                         pattern.red[ledIndex], 
                                         pattern.green[ledIndex], 
                                         pattern.blue[ledIndex], 
                                         pattern.white[ledIndex]);
                    ledController.setLed(ledIndex2 + 1, 
                                         pattern.red[ledIndex], 
                                         pattern.green[ledIndex], 
                                         pattern.blue[ledIndex], 
                                         pattern.white[ledIndex]);
                }
                delay(delayTime / 12);

                for (int i = focal; i < ledsPerGroup; i++) {
                    delay(delayTime / 12);

                    // Choose two random LEDs
                    int ledIndex = random(0, 16);
                    int ledIndex2 = random(0, 16);
                    // Turn them off
                    ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    ledController.setLed(ledIndex2 + 1, 0, 0, 0, 0);
                }
            }
        }
    }
}


