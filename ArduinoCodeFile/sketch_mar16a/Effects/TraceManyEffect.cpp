#include "TraceManyEffect.h"
#include <Arduino.h>

TraceManyEffect::TraceManyEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void TraceManyEffect::run(int focal) {
    // Set base color for all LEDs
    for (int i = 0; i < 16; i++) {
        ledController.setLed(i, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
    }
    
    if (focal == -1) {
        // No focal point - trace many colors in a sequential pattern
        while (true) {
            for (int i = 0; i < 17; i++) {
                for (int j = 0; j < 8; j++) {
                    // Calculate first offset position
                    int offset = (i + j * 2) % 17;
                    ledController.setLed(offset, 
                                        pattern.red[(i + 1) % 8], 
                                        pattern.green[(i + 1) % 16], 
                                        pattern.blue[(i + 1) % 16], 
                                        pattern.white[(i + 1) % 16]);
                    delay(delayTime * 2);

                    // Calculate second offset position (opposite side)
                    offset = (i + j * 2 + 8) % 17;
                    ledController.setLed(offset, 
                                        pattern.red[(i + 1) % 8], 
                                        pattern.green[(i + 2) % 16], 
                                        pattern.blue[(i + 2) % 16], 
                                        pattern.white[(i + 2) % 16]);
                }
            }
        }
    }
    else {
        // Focal point provided - trace colors from focal point
        while (true) {
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 8; j++) {
                    // Calculate positions relative to focal point
                    int position1 = (focal + 1 + j) % 16;
                    int position2 = (16 + focal - j) % 16;
                    
                    // Set first position
                    ledController.setLed(position1, 
                                        pattern.red[(i + 1) % 16], 
                                        pattern.green[(i + 1) % 16], 
                                        pattern.blue[(i + 1) % 16], 
                                        pattern.white[(i + 1) % 16]);
                    delay(delayTime);
                    
                    // Set second position with a slightly different color pattern
                    ledController.setLed(position2, 
                                        pattern.red[(i + 1) % 16], 
                                        pattern.green[(i + 2) % 16], 
                                        pattern.blue[(i + 2) % 16], 
                                        pattern.white[(i + 2) % 16]);
                }
            }
        }
    }
}
