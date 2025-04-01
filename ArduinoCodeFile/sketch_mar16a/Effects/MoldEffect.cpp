#include "MoldEffect.h"
#include <Arduino.h>

MoldEffect::MoldEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void MoldEffect::run(int focal) {
    // Define parameters for the effect
    int strobeCount1 = 2;  // Number of strobes in first sequence
    int strobeCount2 = 2;  // Number of strobes in second sequence
    int ledsPerGroup = 12; // Number of LEDs to control in each group
    
    if (focal == -1) {
        // No focal point - run standard mold effect
        while (true) {
            // First sweep: Start from right side (15) and move left
            for (int startIdx = 15; startIdx >= 0; startIdx--) {
                // First strobe sequence
                for (int strobe = 0; strobe < strobeCount1; strobe++) {
                    // Turn on LEDs
                    for (int i = 0; i < ledsPerGroup; i++) {
                        int ledIndex = startIdx + i;
                        for (int ha = 0; ha < 4; ha++) {
                            // Set LED with pattern color and turn off adjacent LED
                            ledController.setLed(ledIndex + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                            ledController.setLed(ledIndex, 0, 0, 0, 0);
                        }
                    }
                    // Turn off all LEDs in the group
                    for (int i = 0; i < ledsPerGroup; i++) {
                        int ledIndex = startIdx + i;
                        ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    }
                }

                // Second strobe sequence
                for (int strobe = 0; strobe < strobeCount2; strobe++) {
                    // Turn on LEDs
                    for (int i = 0; i < ledsPerGroup; i++) {
                        int ledIndex = startIdx + i;
                        for (int ha = 0; ha < 4; ha++) {
                            // Set LED with pattern color and turn off adjacent LED
                            ledController.setLed(ledIndex + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                            ledController.setLed(ledIndex, 0, 0, 0, 0);
                        }
                    }
                    // Turn off all LEDs in the group
                    for (int i = 0; i < ledsPerGroup; i++) {
                        int ledIndex = startIdx + i;
                        ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    }
                }
            }
            
            // Second sweep: Start from left side (0) and move right
            for (int startIdx = 0; startIdx <= 15; startIdx++) {
                // First strobe sequence
                for (int strobe = 0; strobe < strobeCount1; strobe++) {
                    // Turn on LEDs
                    for (int i = 0; i < ledsPerGroup; i++) {
                        int ledIndex = startIdx + i;
                        for (int ha = 0; ha < 4; ha++) {
                            // Set LED with pattern color and turn off adjacent LED
                            ledController.setLed(ledIndex + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                            ledController.setLed(ledIndex, 0, 0, 0, 0);
                        }
                    }
                    // Turn off all LEDs in the group
                    for (int i = 0; i < ledsPerGroup; i++) {
                        int ledIndex = startIdx + i;
                        ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    }
                }

                // Second strobe sequence
                for (int strobe = 0; strobe < strobeCount2; strobe++) {
                    // Turn on LEDs
                    for (int i = 0; i < ledsPerGroup; i++) {
                        int ledIndex = startIdx + i;
                        for (int ha = 0; ha < 4; ha++) {
                            // Set LED with pattern color and turn off adjacent LED
                            ledController.setLed(ledIndex + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                            ledController.setLed(ledIndex, 0, 0, 0, 0);
                        }
                    }
                    // Turn off all LEDs in the group
                    for (int i = 0; i < ledsPerGroup; i++) {
                        int ledIndex = startIdx + i;
                        ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                    }
                }
            }
        }
    }
    else {
        // Focal point provided - run symmetric mold effect
        while (true) {
            // Start from outer boundary and work toward focal point, then from focal point outwards
            for (int startIdx = 15; startIdx >= focal; startIdx--) {
                for (int startIdx = focal; startIdx <= 15; startIdx++) {
                    // First strobe sequence
                    for (int strobe = 0; strobe < strobeCount1; strobe++) {
                        // Turn on LEDs
                        for (int i = 0; i < ledsPerGroup; i++) {
                            // Calculate positions on both sides of focal point
                            int ledIndex = startIdx + i;
                            int ledIndex2 = startIdx + i - 8;
                            
                            for (int ha = 0; ha < 4; ha++) {
                                // Set LEDs with pattern color and turn off adjacent LEDs
                                ledController.setLed(ledIndex + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                                ledController.setLed(ledIndex2 + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                                ledController.setLed(ledIndex, 0, 0, 0, 0);
                                ledController.setLed(ledIndex2, 0, 0, 0, 0);
                            }
                        }
                        // Turn off all LEDs in the groups
                        for (int i = 0; i < ledsPerGroup; i++) {
                            int ledIndex = startIdx + i;
                            int ledIndex2 = startIdx - i;
                            ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                            ledController.setLed(ledIndex2 + 1, 0, 0, 0, 0);
                        }
                    }

                    // Second strobe sequence
                    for (int strobe = 0; strobe < strobeCount2; strobe++) {
                        // Turn on LEDs
                        for (int i = 0; i < ledsPerGroup; i++) {
                            // Calculate positions on both sides of focal point
                            int ledIndex = startIdx + i;
                            int ledIndex2 = startIdx - i;
                            
                            for (int ha = 0; ha < 4; ha++) {
                                // Set LEDs with pattern color and turn off adjacent LEDs
                                ledController.setLed(ledIndex + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                                ledController.setLed(ledIndex2 + 1, pattern.red[ledIndex], pattern.green[ledIndex], pattern.blue[ledIndex], pattern.white[ledIndex]);
                                ledController.setLed(ledIndex, 0, 0, 0, 0);
                                ledController.setLed(ledIndex2, 0, 0, 0, 0);
                            }
                        }
                        // Turn off all LEDs in the groups
                        for (int i = 0; i < ledsPerGroup; i++) {
                            int ledIndex = startIdx + i;
                            int ledIndex2 = startIdx - i;
                            ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
                            ledController.setLed(ledIndex2 + 1, 0, 0, 0, 0);
                        }
                    }
                }
            }
        }
    }
}

