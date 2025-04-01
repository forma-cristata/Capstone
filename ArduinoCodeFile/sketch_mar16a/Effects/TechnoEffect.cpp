#include "TechnoEffect.h"
#include <Arduino.h>

TechnoEffect::TechnoEffect(LEDController& controller, ColorPattern colorPattern, int delay)
    : LightEffect(controller, colorPattern, delay) {
}

void TechnoEffect::run(int focal) {
    if (focal == -1) {
        // No focal point - techno effect across all LEDs
        while (true) {
            for (int i = 0; i < 11; i++) {
                // Calculate color indices for progression
                int m = i + 1;
                int n = i + 2;
                int o = i + 3;
                int p = i + 4;
                
                for (int j = 10; j >= 0; j--) {
                    // Calculate LED positions for progression
                    int k = j + 1;
                    int l = j + 2;
                    int y = j + 3;
                    int z = j + 4;

                    for (int x = 0; x < 2; x++) {
                        // First LED in sequence
                        ledController.setLed(j, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                        delay(delayTime);
                        ledController.setLed(j, 0, 0, 0, 0);
                        
                        // Second LED in sequence
                        ledController.setLed(k, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);
                        delay(delayTime);
                        ledController.setLed(k, 0, 0, 0, 0);
                        
                        // Third LED in sequence
                        ledController.setLed(l, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);
                        delay(delayTime);
                        ledController.setLed(l, 0, 0, 0, 0);
                        
                        // Fourth LED in sequence
                        ledController.setLed(y, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);
                        delay(delayTime);
                        ledController.setLed(y, 0, 0, 0, 0);
                        
                        // Fifth LED in sequence
                        ledController.setLed(z, pattern.red[p], pattern.green[p], pattern.blue[p], pattern.white[p]);
                        delay(delayTime);
                        ledController.setLed(z, 0, 0, 0, 0);
                    }
                }
            }
        }
    }
    else {
        // Focal point provided - symmetric techno effect
        while (true) {
            for (int i = 0; i < 11; i++) {
                // Calculate color indices for progression
                int m = i + 1;
                int n = i + 2;
                int o = i + 3;
                int p = i + 4;
                
                int jb = focal;
                // Process LEDs from focal point down to 0
                for (int j = focal; j >= 0; j--) {
                    if (jb < 16) {
                        // Calculate LED positions for progression
                        int k = j + 1;
                        int l = j + 2;
                        int y = j + 3;
                        int z = j + 4;

                        int kb = jb + 1;
                        int lb = jb + 2;
                        int yb = jb + 3;
                        int zb = jb + 4;

                        for (int x = 0; x < 2; x++) {
                            // First LED pair in sequence
                            ledController.setLed(j, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                            ledController.setLed(jb, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                            delay(delayTime * 2);
                            ledController.setLed(j, 0, 0, 0, 0);
                            ledController.setLed(jb, 0, 0, 0, 0);

                            // Second LED pair in sequence
                            ledController.setLed(k, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);
                            ledController.setLed(kb, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);
                            delay(delayTime * 2);
                            ledController.setLed(k, 0, 0, 0, 0);
                            ledController.setLed(kb, 0, 0, 0, 0);

                            // Third LED pair in sequence
                            ledController.setLed(l, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);
                            ledController.setLed(lb, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);
                            delay(delayTime * 2);
                            ledController.setLed(l, 0, 0, 0, 0);
                            ledController.setLed(lb, 0, 0, 0, 0);

                            // Fourth LED pair in sequence
                            ledController.setLed(y, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);
                            ledController.setLed(yb, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);
                            delay(delayTime * 2);
                            ledController.setLed(y, 0, 0, 0, 0);
                            ledController.setLed(yb, 0, 0, 0, 0);

                            // Fifth LED pair in sequence
                            ledController.setLed(z, pattern.red[p], pattern.green[p], pattern.blue[p], pattern.white[p]);
                            ledController.setLed(zb, pattern.red[p], pattern.green[p], pattern.blue[p], pattern.white[p]);
                            delay(delayTime * 2);
                            ledController.setLed(z, 0, 0, 0, 0);
                            ledController.setLed(zb, 0, 0, 0, 0);
                        }
                        jb++;
                    }
                }

                // Process LEDs from 0 to focal point
                for (int j = 0; j < focal; j++) {
                    if (jb < 16) {
                        // Calculate LED positions for progression
                        int k = j + 1;
                        int l = j + 2;
                        int y = j + 3;
                        int z = j + 4;

                        int kb = jb + 1;
                        int lb = jb + 2;
                        int yb = jb + 3;
                        int zb = jb + 4;

                        for (int x = 0; x < 2; x++) {
                            // First LED pair in sequence
                            ledController.setLed(j, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                            ledController.setLed(jb, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
                            delay(delayTime * 2);
                            ledController.setLed(j, 0, 0, 0, 0);
                            ledController.setLed(jb, 0, 0, 0, 0);

                            // Second LED pair in sequence
                            ledController.setLed(k, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);
                            ledController.setLed(kb, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);
                            delay(delayTime * 2);
                            ledController.setLed(k, 0, 0, 0, 0);
                            ledController.setLed(kb, 0, 0, 0, 0);

                            // Third LED pair in sequence
                            ledController.setLed(l, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);
                            ledController.setLed(lb, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);
                            delay(delayTime * 2);
                            ledController.setLed(l, 0, 0, 0, 0);
                            ledController.setLed(lb, 0, 0, 0, 0);

                            // Fourth LED pair in sequence
                            ledController.setLed(y, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);
                            ledController.setLed(yb, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);
                            delay(delayTime * 2);
                            ledController.setLed(y, 0, 0, 0, 0);
                            ledController.setLed(yb, 0, 0, 0, 0);

                            // Fifth LED pair in sequence
                            ledController.setLed(z, pattern.red[p], pattern.green[p], pattern.blue[p], pattern.white[p]);
                            ledController.setLed(zb, pattern.red[p], pattern.green[p], pattern.blue[p], pattern.white[p]);
                            delay(delayTime * 2);
                            ledController.setLed(z, 0, 0, 0, 0);
                            ledController.setLed(zb, 0, 0, 0, 0);
                        }
                        jb++;
                    }
                }
            }
        }
    }
}


