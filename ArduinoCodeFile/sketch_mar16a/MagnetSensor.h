#ifndef MAGNET_SENSOR_H
#define MAGNET_SENSOR_H

#include <Arduino.h>

class MagnetSensor {
private:
    const byte* hallPins;
    int numPins;
    int offset;
    float span;
    int focal;

public:
    MagnetSensor(const byte* pins, int numPins, int offset, float span);
    void check();
    int getFocal() const;
    void setFocal(int newFocal);
};

#endif // MAGNET_SENSOR_H
