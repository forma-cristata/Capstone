// Effects.h
#ifndef EFFECTS_H
#define EFFECTS_H

#include "LightEffect.h"
#include "LEDController.h"
#include "ColorPattern.h"

// Basic effects
class StillOneEffect : public LightEffect {
public:
    StillOneEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class StillManyEffect : public LightEffect {
public:
    StillManyEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class TraceOneEffect : public LightEffect {
public:
    TraceOneEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class ProgressiveEffect : public LightEffect {
public:
    ProgressiveEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class TraceManyEffect : public LightEffect {
public:
    TraceManyEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class StrobeChangeEffect : public LightEffect {
public:
    StrobeChangeEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

// More complex effects
class ComfortSongStrobeEffect : public LightEffect {
public:
    ComfortSongStrobeEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class BlenderEffect : public LightEffect {
public:
    BlenderEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class TechnoEffect : public LightEffect {
public:
    TechnoEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class TranceEffect : public LightEffect {
public:
    TranceEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class MoldEffect : public LightEffect {
public:
    MoldEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class FunkyEffect : public LightEffect {
public:
    FunkyEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

class ChristmasEffect : public LightEffect {
public:
    ChristmasEffect(LEDController& controller, ColorPattern colorPattern, int delay);
    void run(int focal = -1) override;
};

#endif // EFFECTS_H
