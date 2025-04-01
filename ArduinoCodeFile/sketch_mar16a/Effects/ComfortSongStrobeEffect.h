#ifndef COMFORT_SONG_STROBE_EFFECT_H
#define COMFORT_SONG_STROBE_EFFECT_H

#include "../LightEffect.h"

class ComfortSongStrobeEffect : public LightEffect {
public:
    ComfortSongStrobeEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // COMFORT_SONG_STROBE_EFFECT_H

