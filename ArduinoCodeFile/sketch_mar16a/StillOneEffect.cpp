// Effects.cpp
#include "Effects.h"
#include <Arduino.h>

//===========================================================================
// StillOneEffect Implementation
//===========================================================================
StillOneEffect::StillOneEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void StillOneEffect::run(int focal) {
    // Light up a single LED based on the focal point
    // If no focal point, use a default
    int pos = (focal >= 0) ? focal : 0;
    
    for (int i = 0; i < 22; i++) {
        if (i == pos) {
            int colorIdx = i % 16;
            ledController.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                               pattern.blue[colorIdx], pattern.white[colorIdx]);
        } else {
            ledController.setLed(i, 0, 0, 0, 0); // Turn off other LEDs
        }
    }
    
    delay(delayTime);
}

//===========================================================================
// StillManyEffect Implementation
//===========================================================================
StillManyEffect::StillManyEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void StillManyEffect::run(int focal) {
    // Light up all LEDs with different colors from the pattern
    for (int i = 0; i < 22; i++) {
        int colorIdx = i % 16;
        controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                           pattern.blue[colorIdx], pattern.white[colorIdx]);
    }
    
    delay(delayTime);
}

//===========================================================================
// TraceOneEffect Implementation
//===========================================================================
TraceOneEffect::TraceOneEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void TraceOneEffect::run(int focal) {
    static int currentPos = 0;
    
    // Clear all LEDs
    for (int i = 0; i < 22; i++) {
        controller.setLed(i, 0, 0, 0, 0);
    }
    
    // Light up the current position
    int colorIdx = currentPos % 16;
    controller.setLed(currentPos, pattern.red[colorIdx], pattern.green[colorIdx], 
                       pattern.blue[colorIdx], pattern.white[colorIdx]);
    
    // Move to next position or use focal point if available
    if (focal >= 0) {
        currentPos = focal;
    } else {
        currentPos = (currentPos + 1) % 22;
    }
    
    delay(delayTime);
}

//===========================================================================
// ProgressiveEffect Implementation
//===========================================================================
ProgressiveEffect::ProgressiveEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void ProgressiveEffect::run(int focal) {
    static int progressLevel = 0;
    
    // Light up LEDs progressively
    for (int i = 0; i < 22; i++) {
        if (i <= progressLevel) {
            int colorIdx = i % 16;
            controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                               pattern.blue[colorIdx], pattern.white[colorIdx]);
        } else {
            controller.setLed(i, 0, 0, 0, 0);
        }
    }
    
    // Increase progress level or reset
    progressLevel = (progressLevel + 1) % 23;
    
    delay(delayTime);
}

//===========================================================================
// TraceManyEffect Implementation
//===========================================================================
TraceManyEffect::TraceManyEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void TraceManyEffect::run(int focal) {
    static int offset = 0;
    
    // Create a moving pattern of lights
    for (int i = 0; i < 22; i++) {
        int colorIdx = (i + offset) % 16;
        controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                           pattern.blue[colorIdx], pattern.white[colorIdx]);
    }
    
    // Move the pattern
    offset = (offset + 1) % 16;
    
    delay(delayTime);
}

//===========================================================================
// StrobeChangeEffect Implementation
//===========================================================================
StrobeChangeEffect::StrobeChangeEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void StrobeChangeEffect::run(int focal) {
    static bool isOn = false;
    static int colorOffset = 0;
    
    if (isOn) {
        // Turn all LEDs off
        for (int i = 0; i < 22; i++) {
            controller.setLed(i, 0, 0, 0, 0);
        }
    } else {
        // Turn all LEDs on with the current color offset
        for (int i = 0; i < 22; i++) {
            int colorIdx = (i + colorOffset) % 16;
            controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                               pattern.blue[colorIdx], pattern.white[colorIdx]);
        }
        // Change the color pattern for the next cycle
        colorOffset = (colorOffset + 1) % 16;
    }
    
    isOn = !isOn;
    delay(delayTime);
}

//===========================================================================
// ComfortSongStrobeEffect Implementation
//===========================================================================
ComfortSongStrobeEffect::ComfortSongStrobeEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void ComfortSongStrobeEffect::run(int focal) {
    static int phase = 0;
    static int beatCount = 0;
    
    if (phase == 0) {
        // All on with first color set
        for (int i = 0; i < 22; i++) {
            int colorIdx = i % 16;
            controller.setLed(i, pattern.red[colorIdx], 0, 0, 0);
        }
    } else if (phase == 1) {
        // All off
        for (int i = 0; i < 22; i++) {
            controller.setLed(i, 0, 0, 0, 0);
        }
    } else if (phase == 2) {
        // All on with second color set
        for (int i = 0; i < 22; i++) {
            int colorIdx = i % 16;
            controller.setLed(i, 0, 0, pattern.blue[colorIdx], 0);
        }
    } else {
        // All off
        for (int i = 0; i < 22; i++) {
            controller.setLed(i, 0, 0, 0, 0);
        }
    }
    
    phase = (phase + 1) % 4;
    
    // Every 8 beats, change the pattern slightly
    beatCount++;
    if (beatCount >= 8) {
        beatCount = 0;
    }
    
    delay(delayTime);
}

//===========================================================================
// BlenderEffect Implementation
//===========================================================================
BlenderEffect::BlenderEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void BlenderEffect::run(int focal) {
    static int rotation = 0;
    
    // Create a blended effect of colors
    for (int i = 0; i < 22; i++) {
        int colorIdx1 = (i + rotation) % 16;
        int colorIdx2 = (i + rotation + 8) % 16;
        
        // Blend two colors based on position
        int r = (pattern.red[colorIdx1] + pattern.red[colorIdx2]) / 2;
        int g = (pattern.green[colorIdx1] + pattern.green[colorIdx2]) / 2;
        int b = (pattern.blue[colorIdx1] + pattern.blue[colorIdx2]) / 2;
        int w = (pattern.white[colorIdx1] + pattern.white[colorIdx2]) / 2;
        
        controller.setLed(i, r, g, b, w);
    }
    
    rotation = (rotation + 1) % 16;
    delay(delayTime);
}

//===========================================================================
// TechnoEffect Implementation
//===========================================================================
TechnoEffect::TechnoEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void TechnoEffect::run(int focal) {
    static int phase = 0;
    
    switch (phase) {
        case 0: {
            // Quick flash all LEDs
            for (int i = 0; i < 22; i++) {
                int colorIdx = i % 16;
                controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                                   pattern.blue[colorIdx], pattern.white[colorIdx]);
            }
            break;
        }
        case 1: {
            // All off
            for (int i = 0; i < 22; i++) {
                controller.setLed(i, 0, 0, 0, 0);
            }
            break;
        }
        case 2: {
            // Alternate LEDs
            for (int i = 0; i < 22; i++) {
                if (i % 2 == 0) {
                    int colorIdx = i % 16;
                    controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                                       pattern.blue[colorIdx], pattern.white[colorIdx]);
                } else {
                    controller.setLed(i, 0, 0, 0, 0);
                }
            }
            break;
        }
        case 3: {
            // Reverse alternate
            for (int i = 0; i < 22; i++) {
                if (i % 2 != 0) {
                    int colorIdx = i % 16;
                    controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                                       pattern.blue[colorIdx], pattern.white[colorIdx]);
                } else {
                    controller.setLed(i, 0, 0, 0, 0);
                }
            }
            break;
        }
    }
    
    phase = (phase + 1) % 4;
    delay(delayTime);
}

//===========================================================================
// TranceEffect Implementation
//===========================================================================
TranceEffect::TranceEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void TranceEffect::run(int focal) {
    static int pulseSize = 0;
    static bool growing = true;
    
    // Clear all LEDs
    for (int i = 0; i < 22; i++) {
        controller.setLed(i, 0, 0, 0, 0);
    }
    
    // Determine center position
    int center = (focal >= 0) ? focal : 11;
    
    // Create a pulse effect
    for (int i = center - pulseSize; i <= center + pulseSize; i++) {
        if (i >= 0 && i < 22) {
            int colorIdx = i % 16;
            controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                               pattern.blue[colorIdx], pattern.white[colorIdx]);
        }
    }
    
    // Update pulse size
    if (growing) {
        pulseSize++;
        if (pulseSize >= 11) {
            growing = false;
        }
    } else {
        pulseSize--;
        if (pulseSize <= 0) {
            growing = true;
        }
    }
    
    delay(delayTime);
}

//===========================================================================
// MoldEffect Implementation
//===========================================================================
MoldEffect::MoldEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void MoldEffect::run(int focal) {
    static bool ledState[22] = {false};
    static int growthPoints[5] = {0, 5, 10, 15, 20};
    
    // Randomly spread the "mold"
    for (int i = 0; i < 22; i++) {
        // If this LED is already on, check neighbors to spread
        if (ledState[i]) {
            if (i > 0 && !ledState[i-1] && random(100) < 30) {
                ledState[i-1] = true;
            }
            if (i < 21 && !ledState[i+1] && random(100) < 30) {
                ledState[i+1] = true;
            }
        }
    }
    
    // Ensure the growth points are always on
    for (int i = 0; i < 5; i++) {
        if (growthPoints[i] >= 0 && growthPoints[i] < 22) {
            ledState[growthPoints[i]] = true;
        }
    }
    
    // Update LEDs based on state
    for (int i = 0; i < 22; i++) {
        if (ledState[i]) {
            int colorIdx = i % 16;
            controller.setLed(i, pattern.red[colorIdx], pattern.green[colorIdx], 
                               pattern.blue[colorIdx], pattern.white[colorIdx]);
        } else {
            controller.setLed(i, 0, 0, 0, 0);
        }
    }
    
    // Reset occasionally
    static int counter = 0;
    counter++;
    if (counter > 100) {
        counter = 0;
        for (int i = 0; i < 22; i++) {
            ledState[i] = false;
        }
    }
    
    delay(delayTime);
}

//===========================================================================
// FunkyEffect Implementation
//===========================================================================
FunkyEffect::FunkyEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void FunkyEffect::run(int focal) {
    static int counter = 0;
    
    // Create funky random patterns that change smoothly
    for (int i = 0; i < 22; i++) {
        int colorIdx = (i + counter) % 16;
        
        // Modulate the colors for extra funkiness
        int r = pattern.red[colorIdx];
        int g = pattern.green[colorIdx];
        int b = pattern.blue[colorIdx];
        
        // Add some random variation
        if (random(100) < 20) {
            r = constrain(r + random(-20, 20), 0, 255);
            g = constrain(g + random(-20, 20), 0, 255);
            b = constrain(b + random(-20, 20), 0, 255);
        }
        
        controller.setLed(i, r, g, b, pattern.white[colorIdx]);
    }
    
    counter = (counter + 1) % 16;
    delay(delayTime);
}

//===========================================================================
// ChristmasEffect Implementation
//===========================================================================
ChristmasEffect::ChristmasEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void ChristmasEffect::run(int focal) {
    static int counter = 0;
    
    // Christmas colors (red and green alternating)
    for (int i = 0; i < 22; i++) {
        if ((i + counter) % 2 == 0) {
            // Red
            controller.setLed(i, 255, 0, 0, 0);
        } else {
            // Green
            controller.setLed(i, 0, 255, 0, 0);
        }
    }
    
    // Every few seconds, add a white twinkle
    if (counter % 10 == 0) {
        int twinklePos = random(22);
        controller.setLed(twinklePos, 255, 255, 255, 255);
    }
    
    counter++;
    delay(delayTime);
}
