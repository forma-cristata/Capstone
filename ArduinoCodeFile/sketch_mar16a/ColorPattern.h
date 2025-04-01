#ifndef COLOR_PATTERN_H
#define COLOR_PATTERN_H

class ColorPattern {
public:
    int* red;
    int* green;
    int* blue;
    int* white;

    ColorPattern(int* r, int* g, int* b, int* w);
};

#endif // COLOR_PATTERN_H
