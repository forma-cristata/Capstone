#include "MagnetSensor.h"

MagnetSensor::MagnetSensor(const byte* pins, int numPins, int offset, float span)
    : hallPins(pins), numPins(numPins), offset(offset), span(span), focal(-1) {
}

void MagnetSensor::check() {
    for (int i = 0; i < numPins; i++) {
        float value = (analogRead(hallPins[i]) - offset) * span;

        if (value > 5) {
            switch (hallPins[i]) {
            case (18): focal = 3; break;
            case (17): focal = 6; break;
            case (16): focal = 8; break;
            case (15): focal = 11; break;
            case (14): focal = 15; break;
            }
        }
    }
}

int MagnetSensor::getFocal() const {
    return focal;
}

void MagnetSensor::setFocal(int newFocal) {
    focal = newFocal;
}
