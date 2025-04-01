#include <FastLED.h>
#include "Constants.h"
#include "LightApplication.h"

// Global application instance
LightApplication app;

void setup() {
    app.setup();
    app.selectEffect(10); // Select mold effect
}

void loop() {
    app.loop();
}



//#include <FastLED.h>
//
//#define NUM_LEDS 22
//#define DATA_PIN 6
//#define SEED 42
//
//class LEDController;
//class ColorPattern;
//class MagnetSensor;
//class LightEffect;
//
//

//
//// Main application class to coordinate everything
//class LightApplication {
//private:
//    LEDController ledController;
//    MagnetSensor magnetSensor;
//    LightEffect* currentEffect;
//
//    // Color arrays
//    int wr[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//    int r1[16] = { 255, 255, 255, 136, 0, 0, 0, 0, 0, 0, 0, 136, 255, 255, 255, 255 };
//    int g1[16] = { 0, 136, 255, 255, 255, 255, 255, 255, 255, 136, 0, 0, 0, 0, 0, 0 };
//    int b1[16] = { 0, 0, 0, 0, 0, 68, 136, 187, 255, 255, 255, 255, 255, 187, 136, 68 };
//
//    int r2[16] = { 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255 };
//    int g2[16] = { 0, 85, 40, 15, 0, 45, 59, 2, 0, 85, 40, 15, 0, 45, 59, 2 };
//    int b2[16] = { 0, 1, 0, 2, 239, 3, 0, 0, 0, 1, 0, 2, 239, 3, 0, 0 };
//
//    int r4[16] = { 161, 205, 172, 19, 71, 215, 205, 190, 190, 205, 215, 71, 19, 172, 205, 161 };
//    int g4[16] = { 0, 52, 19, 21, 0, 35, 38, 40, 20, 38, 33, 0, 55, 19, 52, 0 };
//    int b4[16] = { 0, 0, 42, 52, 35, 0, 15, 82, 82, 35, 0, 65, 75, 10, 0, 12 };
//
//    int r5[16] = { 255, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30 };
//    int g5[16] = { 0, 75, 25, 27, 75, 45, 50, 27, 75, 27, 36, 5, 75, 27, 75, 50 };
//    int b5[16] = { 0, 20, 155, 55, 120, 155, 55, 55, 10, 155, 55, 155, 55, 25, 155, 20 };
//
//    int r6[16] = { 255, 0, 255, 0, 255, 255, 0, 0, 0, 255, 255, 0, 0, 255, 0, 255 };
//    int g6[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//    int b6[16] = { 255, 0, 255, 255, 255, 0, 255, 255, 255, 255, 0, 255, 255, 255, 0, 0 };
//
//    int r7[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//    int g7[16] = { 255, 200, 100, 150, 50, 255, 180, 230, 90, 50, 180, 210, 0, 120, 100, 255 };
//    int b7[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//
//public:
//    LightApplication() :
//        ledController(NUM_LEDS, DATA_PIN),
//        magnetSensor(new byte[5]{ A0, A1, A2, A3, A4 }, 5, 512, 0.3617),
//        currentEffect(nullptr) {
//        // Initialize with a default effect
//        ColorPattern defaultPattern(r1, g1, b1, wr);
//        currentEffect = new StillOneEffect(ledController, defaultPattern, 10);
//    }
//
//    ~LightApplication() {
//        delete currentEffect;
//    }
//
//    void setup() {
//        ledController.begin();
//        // Any additional setup
//    }
//
//    void loop() {
//        // Check for magnets and update focal point
//        magnetSensor.check();
//        int focal = magnetSensor.getFocal();
//
//        // Run the current effect with the current focal point
//        if (currentEffect) {
//            currentEffect->run(focal);
//        }
//    }
//
//    void setEffect(LightEffect* newEffect) {
//        if (currentEffect) {
//            delete currentEffect;
//        }
//        currentEffect = newEffect;
//    }
//
//    void selectEffect(int effectNumber) {
//        // Define the different color patterns
//        ColorPattern pattern1(r1, g1, b1, wr);
//        ColorPattern pattern2(r2, g2, b2, wr);
//        ColorPattern pattern4(r4, g4, b4, wr);
//        ColorPattern pattern5(r5, g5, b5, wr);
//        ColorPattern pattern6(r6, g6, b6, wr);
//
//        switch (effectNumber) {
//        case 0: // stillOne
//            setEffect(new StillOneEffect(ledController, pattern1, 10));
//            break;
//        case 1: // stillMany
//            setEffect(new StillManyEffect(ledController, pattern1, 10));
//            break;
//        case 2: // traceOne
//            setEffect(new TraceOneEffect(ledController, pattern5, 10));
//            break;
//        case 3: // progressive
//            setEffect(new ProgressiveEffect(ledController, pattern2, 7));
//            break;
//        case 4: // traceMany
//            setEffect(new TraceManyEffect(ledController, pattern4, 15));
//            break;
//        case 5: // strobeChange
//            setEffect(new StrobeChangeEffect(ledController, pattern4, 2));
//            break;
//        case 6: // comfortSongStrobe
//            setEffect(new ComfortSongStrobeEffect(ledController, pattern6, 3));
//            break;
//        case 7: // blender
//            setEffect(new BlenderEffect(ledController, pattern6, 2));
//            break;
//        case 8: // techno
//            setEffect(new TechnoEffect(ledController, pattern4, 1));
//            break;
//        case 9: // trance
//            setEffect(new TranceEffect(ledController, pattern1, 1));
//            break;
//        case 10: // mold
//            setEffect(new MoldEffect(ledController, pattern4, 1));
//            break;
//        case 11: // funky
//            setEffect(new FunkyEffect(ledController, pattern5, 8));
//            break;
//        case 12: // christmas
//            setEffect(new ChristmasEffect(ledController, pattern6, 10));
//            break;
//        default:
//            setEffect(new StillOneEffect(ledController, pattern1, 10));
//            break;
//        }
//    }
//};
//
//// Global application instance
//LightApplication app;
//
//void setup()
//{
//    app.setup();
//	  app.selectEffect(10);
//}
//
//void loop()
//{
//    app.loop();
//}
//
//
