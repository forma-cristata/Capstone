#include "ChristmasEffect.h"
#include <Arduino.h>

ChristmasEffect::ChristmasEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void ChristmasEffect::run(int focal) {
    int i = 0;
    
    if (focal == -1) {
        // No focal point - standard Christmas effect
        while (true) {
            delay(delayTime);
            i++;
            
            // Use modulo to create alternating pattern (every other iteration)
            i = i % 2;
            
            for (int xy = 0; xy < 13; xy++) {
                if (i == 0) {
                    // Light up even-numbered LEDs with base color
                    for (int j = 0; j < 18; j += 2) {
                        ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
                        
                        // Special colors for special positions
                        if (j == 8) {
                            ledController.setLed(j, pattern.red[xy + 1], pattern.green[xy + 1], pattern.blue[xy + 1], pattern.white[xy + 1]);
                        }
                        if (j == 12) {
                            ledController.setLed(j, pattern.red[xy + 2], pattern.green[xy + 2], pattern.blue[xy + 2], pattern.white[xy + 2]);
                        }
                        
                        // Set next LED with alternate color
                        ledController.setLed(j + 1, pattern.red[xy + 3], pattern.green[xy + 3], pattern.blue[xy + 3], pattern.white[xy + 3]);
                    }
                    
                    // Reverse pattern for odd-numbered LEDs
                    for (int j = 1; j < 19; j += 2) {
                        ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
                        ledController.setLed(j - 1, pattern.red[xy + 3], pattern.green[xy + 3], pattern.blue[xy + 3], pattern.white[xy + 3]);
                    }
                }
            }
        }
    }
    else {
        // Focal point provided - modified Christmas effect centered at focal point
        while (true) {
            delay(delayTime);
            i++;
            
            // Use modulo to create alternating pattern (every other iteration)
            i = i % 2;
            
            for (int xy = 0; xy < 13; xy++) {
                if (i == 0) {
                    // Light up even-numbered LEDs from focal point upward
                    for (int j = focal; j < 18; j += 2) {
                        ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
                        
                        // Special colors for special positions
                        if (j == 8) {
                            ledController.setLed(j, pattern.red[xy + 1], pattern.green[xy + 1], pattern.blue[xy + 1], pattern.white[xy + 1]);
                        }
                        if (j == 12) {
                            ledController.setLed(j, pattern.red[xy + 2], pattern.green[xy + 2], pattern.blue[xy + 2], pattern.white[xy + 2]);
                        }
                        
                        // Set next LED with alternate color
                        ledController.setLed(j + 1, pattern.red[xy + 3], pattern.green[xy + 3], pattern.blue[xy + 3], pattern.white[xy + 3]);
                    }
                    
                    // Light up even-numbered LEDs from focal point downward
                    for (int j = focal; j >= 0; j -= 2) {
                        ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
                        
                        // Special colors for special positions
                        if (j == 8) {
                            ledController.setLed(j, pattern.red[xy + 1], pattern.green[xy + 1], pattern.blue[xy + 1], pattern.white[xy + 1]);
                        }
                        if (j == 12) {
                            ledController.setLed(j, pattern.red[xy + 2], pattern.green[xy + 2], pattern.blue[xy + 2], pattern.white[xy + 2]);
                        }
                        
                        // Set next LED with alternate color
                        ledController.setLed(j + 1, pattern.red[xy + 3], pattern.green[xy + 3], pattern.blue[xy + 3], pattern.white[xy + 3]);
                    }
                    
                    // Reverse pattern for odd-numbered LEDs from focal point upward
                    for (int j = focal; j < 18; j += 2) {
                        ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
                        ledController.setLed(j - 1, pattern.red[xy + 3], pattern.green[xy + 3], pattern.blue[xy + 3], pattern.white[xy + 3]);
                    }
                    
                    // Reverse pattern for odd-numbered LEDs from focal point downward
                    for (int j = focal; j >= 0; j -= 2) {
                        ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
                        ledController.setLed(j - 1, pattern.red[xy + 3], pattern.green[xy + 3], pattern.blue[xy + 3], pattern.white[xy + 3]);
                    }
                }
            }
        }
    }
}




