#include "LightApplication.h"
#include <Arduino.h>

LightApplication::LightApplication() :
    ledController(LED_COUNT, LED_DATA_PIN),
    magnetSensor(new byte[5]{ A0, A1, A2, A3, A4 }, 5, 512, 0.3617),
    currentEffect(nullptr) {
    // Initialize the color arrays
    initializeColorArrays();

    // Initialize with a default effect
    ColorPattern defaultPattern(r1, g1, b1, wr);
    currentEffect = new StillOneEffect(ledController, defaultPattern, 10);
}

void LightApplication::initializeColorArrays() {
    // Initialize white (all zeros)
    for (int i = 0; i < 16; i++) {
        wr[i] = 0;
    }

    // Rainbow gradient
    r1[0] = 255; r1[1] = 255; r1[2] = 255; r1[3] = 136; r1[4] = 0; r1[5] = 0; 
    r1[6] = 0; r1[7] = 0; r1[8] = 0; r1[9] = 0; r1[10] = 0; r1[11] = 136; 
    r1[12] = 255; r1[13] = 255; r1[14] = 255; r1[15] = 255;
    
    g1[0] = 0; g1[1] = 136; g1[2] = 255; g1[3] = 255; g1[4] = 255; g1[5] = 255; 
    g1[6] = 255; g1[7] = 255; g1[8] = 255; g1[9] = 136; g1[10] = 0; g1[11] = 0; 
    g1[12] = 0; g1[13] = 0; g1[14] = 0; g1[15] = 0;
    
    b1[0] = 0; b1[1] = 0; b1[2] = 0; b1[3] = 0; b1[4] = 0; b1[5] = 68; 
    b1[6] = 136; b1[7] = 187; b1[8] = 255; b1[9] = 255; b1[10] = 255; b1[11] = 255; 
    b1[12] = 255; b1[13] = 187; b1[14] = 136; b1[15] = 68;

    // Pattern 2
    r2[0] = 255; r2[1] = 255; r2[2] = 255; r2[3] = 255; r2[4] = 0; r2[5] = 255; 
    r2[6] = 255; r2[7] = 255; r2[8] = 255; r2[9] = 255; r2[10] = 255; r2[11] = 255; 
    r2[12] = 0; r2[13] = 255; r2[14] = 255; r2[15] = 255;
    
    g2[0] = 0; g2[1] = 85; g2[2] = 40; g2[3] = 15; g2[4] = 0; g2[5] = 45; 
    g2[6] = 59; g2[7] = 2; g2[8] = 0; g2[9] = 85; g2[10] = 40; g2[11] = 15; 
    g2[12] = 0; g2[13] = 45; g2[14] = 59; g2[15] = 2;
    
    b2[0] = 0; b2[1] = 1; b2[2] = 0; b2[3] = 2; b2[4] = 239; b2[5] = 3; 
    b2[6] = 0; b2[7] = 0; b2[8] = 0; b2[9] = 1; b2[10] = 0; b2[11] = 2; 
    b2[12] = 239; b2[13] = 3; b2[14] = 0; b2[15] = 0;

    // Pattern 4
    r4[0] = 161; r4[1] = 205; r4[2] = 172; r4[3] = 19; r4[4] = 71; r4[5] = 215; 
    r4[6] = 205; r4[7] = 190; r4[8] = 190; r4[9] = 205; r4[10] = 215; r4[11] = 71; 
    r4[12] = 19; r4[13] = 172; r4[14] = 205; r4[15] = 161;
    
    g4[0] = 0; g4[1] = 52; g4[2] = 19; g4[3] = 21; g4[4] = 0; g4[5] = 35; 
    g4[6] = 38; g4[7] = 40; g4[8] = 20; g4[9] = 38; g4[10] = 33; g4[11] = 0; 
    g4[12] = 55; g4[13] = 19; g4[14] = 52; g4[15] = 0;
    
    b4[0] = 0; b4[1] = 0; b4[2] = 42; b4[3] = 52; b4[4] = 35; b4[5] = 0; 
    b4[6] = 15; b4[7] = 82; b4[8] = 82; b4[9] = 35; b4[10] = 0; b4[11] = 65; 
    b4[12] = 75; b4[13] = 10; b4[14] = 0; b4[15] = 12;

    // Pattern 5
    r5[0] = 255; r5[1] = 30; r5[2] = 30; r5[3] = 30; r5[4] = 30; r5[5] = 30; 
    r5[6] = 30; r5[7] = 30; r5[8] = 30; r5[9] = 30; r5[10] = 30; r5[11] = 30; 
    r5[12] = 30; r5[13] = 30; r5[14] = 30; r5[15] = 30;
    
    g5[0] = 0; g5[1] = 75; g5[2] = 25; g5[3] = 27; g5[4] = 75; g5[5] = 45; 
    g5[6] = 50; g5[7] = 27; g5[8] = 75; g5[9] = 27; g5[10] = 36; g5[11] = 5; 
    g5[12] = 75; g5[13] = 27; g5[14] = 75; g5[15] = 50;
    
    b5[0] = 0; b5[1] = 20; b5[2] = 155; b5[3] = 55; b5[4] = 120; b5[5] = 155; 
    b5[6] = 55; b5[7] = 55; b5[8] = 10; b5[9] = 155; b5[10] = 55; b5[11] = 155; 
    b5[12] = 55; b5[13] = 25; b5[14] = 155; b5[15] = 20;

    // Pattern 6
    r6[0] = 255; r6[1] = 0; r6[2] = 255; r6[3] = 0; r6[4] = 255; r6[5] = 255; 
    r6[6] = 0; r6[7] = 0; r6[8] = 0; r6[9] = 255; r6[10] = 255; r6[11] = 0; 
    r6[12] = 0; r6[13] = 255; r6[14] = 0; r6[15] = 255;
    
    for (int i = 0; i < 16; i++) {
        g6[i] = 0;
    }
    
    b6[0] = 255; b6[1] = 0; b6[2] = 255; b6[3] = 255; b6[4] = 255; b6[5] = 0; 
    b6[6] = 255; b6[7] = 255; b6[8] = 255; b6[9] = 255; b6[10] = 0; b6[11] = 255; 
    b6[12] = 255; b6[13] = 255; b6[14] = 0; b6[15] = 0;

    // Pattern 7
    for (int i = 0; i < 16; i++) {
        r7[i] = 0;
    }
    
    g7[0] = 255; g7[1] = 200; g7[2] = 100; g7[3] = 150; g7[4] = 50; g7[5] = 255; 
    g7[6] = 180; g7[7] = 230; g7[8] = 90; g7[9] = 50; g7[10] = 180; g7[11] = 210; 
    g7[12] = 0; g7[13] = 120; g7[14] = 100; g7[15] = 255;
    
    for (int i = 0; i < 16; i++) {
        b7[i] = 0;
    }

    // Initialize with a default effect
    ColorPattern defaultPattern(r1, g1, b1, wr);
    currentEffect = new StillOneEffect(ledController, defaultPattern, 10);
}

LightApplication::~LightApplication() {
    delete currentEffect;
}

void LightApplication::setup() {
    ledController.begin();
    // Any additional setup can be added here
}

void LightApplication::loop() {
    // Check for magnets and update focal point
    magnetSensor.check();
    int focal = magnetSensor.getFocal();

    // Run the current effect with the current focal point
    if (currentEffect) {
        currentEffect->run(focal);
    }
}

void LightApplication::setEffect(LightEffect* newEffect) {
    if (currentEffect) {
        delete currentEffect;
    }
    currentEffect = newEffect;
}

void LightApplication::selectEffect(int effectNumber) {
    // Define the different color patterns
    ColorPattern pattern1(r1, g1, b1, wr);
    ColorPattern pattern2(r2, g2, b2, wr);
    ColorPattern pattern4(r4, g4, b4, wr);
    ColorPattern pattern5(r5, g5, b5, wr);
    ColorPattern pattern6(r6, g6, b6, wr);

    switch (effectNumber) {
    case 0: // stillOne
        setEffect(new StillOneEffect(ledController, pattern1, 10));
        break;
    case 1: // stillMany
        setEffect(new StillManyEffect(ledController, pattern1, 10));
        break;
    case 2: // traceOne
        setEffect(new TraceOneEffect(ledController, pattern5, 10));
        break;
    case 3: // progressive
        setEffect(new ProgressiveEffect(ledController, pattern2, 7));
        break;
    case 4: // traceMany
        setEffect(new TraceManyEffect(ledController, pattern4, 15));
        break;
    case 5: // strobeChange
        setEffect(new StrobeChangeEffect(ledController, pattern4, 2));
        break;
    case 6: // comfortSongStrobe
        setEffect(new ComfortSongStrobeEffect(ledController, pattern6, 3));
        break;
    case 7: // blender
        setEffect(new BlenderEffect(ledController, pattern6, 2));
        break;
    case 8: // techno
        setEffect(new TechnoEffect(ledController, pattern4, 1));
        break;
    case 9: // trance
        setEffect(new TranceEffect(ledController, pattern1, 1));
        break;
    case 10: // mold
        setEffect(new MoldEffect(ledController, pattern4, 1));
        break;
    case 11: // funky
        setEffect(new FunkyEffect(ledController, pattern5, 8));
        break;
    case 12: // christmas
        setEffect(new ChristmasEffect(ledController, pattern6, 10));
        break;
    default:
        setEffect(new StillOneEffect(ledController, pattern1, 10));
        break;
    }
}
