#include <FastLED.h>

#define NUM_LEDS 22
#define DATA_PIN 6
#define SEED 42
#define LIGHT_COUNT 16
#define COLOR_COUNT 16

class LEDController;
class ColorPattern;
class MagnetSensor;
class LightEffect;



class LEDController {
private:
	CRGB* leds;
	int numLeds;
	int dataPin;

	void handleCase1(int L, int R, int G, int B, int W) {
		switch (L + 1) {
		case 1:
			leds[0].r = R;
			FastLED.show();
			leds[0].g = G;
			FastLED.show();
			leds[0].b = B;
			FastLED.show();
			leds[1].g = W;
			FastLED.show();
			break;
		case 4:
			leds[4].r = R;
			FastLED.show();
			leds[4].g = G;
			FastLED.show();
			leds[4].b = B;
			FastLED.show();
			leds[5].g = W;
			FastLED.show();
			break;
		case 7:
			leds[8].r = R;
			FastLED.show();
			leds[8].g = G;
			FastLED.show();
			leds[8].b = B;
			FastLED.show();
			leds[9].g = W;
			FastLED.show();
			break;
		case 10:
			leds[12].r = R;
			FastLED.show();
			leds[12].g = G;
			FastLED.show();
			leds[12].b = B;
			FastLED.show();
			leds[13].g = W;
			FastLED.show();
			break;
		case 13:
			leds[16].r = R;
			FastLED.show();
			leds[16].g = G;
			FastLED.show();
			leds[16].b = B;
			FastLED.show();
			leds[17].g = W;
			FastLED.show();
			break;
		case 16:
			leds[20].r = R;
			FastLED.show();
			leds[20].g = G;
			FastLED.show();
			leds[20].b = B;
			FastLED.show();
			leds[21].g = W;
			FastLED.show();
			break;
		}
	}

	void handleCase2(int L, int R, int G, int B, int W) {
		switch (L + 1) {
		case 2:
			leds[1].r = G;
			FastLED.show();
			leds[1].b = R;
			FastLED.show();
			leds[2].r = W;
			FastLED.show();
			leds[2].g = B;
			FastLED.show();
			break;
		case 5:
			leds[5].b = R;
			FastLED.show();
			leds[5].r = G;
			FastLED.show();
			leds[6].g = B;
			FastLED.show();
			leds[6].r = W;
			FastLED.show();
			break;
		case 8:
			leds[9].r = G;
			FastLED.show();
			leds[9].b = R;
			FastLED.show();
			leds[10].r = W;
			FastLED.show();
			leds[10].g = B;
			FastLED.show();
			break;
		case 11:
			leds[13].r = G;
			FastLED.show();
			leds[13].b = R;
			FastLED.show();
			leds[14].r = W;
			FastLED.show();
			leds[14].g = B;
			FastLED.show();
			break;
		case 14:
			leds[17].b = R;
			FastLED.show();
			leds[17].r = G;
			FastLED.show();
			leds[18].g = B;
			FastLED.show();
			leds[18].r = W;
			FastLED.show();
			break;
		}
	}

	void handleCase0(int L, int R, int G, int B, int W) {
		switch (L + 1) {
		case 3:
			leds[3].r = B;
			FastLED.show();
			leds[3].g = R;
			FastLED.show();
			leds[3].b = W;
			FastLED.show();
			leds[2].b = G;
			FastLED.show();
			break;
		case 6:
			leds[7].r = B;
			FastLED.show();
			leds[7].g = R;
			FastLED.show();
			leds[7].b = W;
			FastLED.show();
			leds[6].b = G;
			FastLED.show();
			break;
		case 9:
			leds[11].g = R;
			FastLED.show();
			leds[10].b = G;
			FastLED.show();
			leds[11].r = B;
			FastLED.show();
			leds[11].b = W;
			FastLED.show();
			break;
		case 12:
			leds[15].r = B;
			FastLED.show();
			leds[15].g = R;
			FastLED.show();
			leds[15].b = W;
			FastLED.show();
			leds[14].b = G;
			FastLED.show();
			break;
		case 15:
			leds[19].r = B;
			FastLED.show();
			leds[19].g = R;
			FastLED.show();
			leds[19].b = W;
			FastLED.show();
			leds[18].b = G;
			FastLED.show();
			break;
		}
	}
public:
	LEDController(int numLeds, int dataPin)
		: numLeds(numLeds), dataPin(dataPin) {
		leds = new CRGB[numLeds];
		randomSeed(SEED);
	}

	~LEDController() {
		delete[] leds;
	}

	void begin() {
		FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, numLeds);
	}

	void setLed(int L, int R, int G, int B, int W) {
		switch ((L + 1) % 3) {
		case 1:
			handleCase1(L, R, G, B, W);
			break;
		case 2:
			handleCase2(L, R, G, B, W);
			break;
		case 0:
			handleCase0(L, R, G, B, W);
			break;
		}
	}
};

class ColorPattern {
public:
	int* red;
	int* green;
	int* blue;
	int* white;

	ColorPattern(int* r, int* g, int* b, int* w)
		: red(r), green(g), blue(b), white(w) {
	}
};

class MagnetSensor {
private:
	const byte* hallPins;
	int numPins;
	int offset;
	float span;
	int focal;
public:
	MagnetSensor(const byte* pins, int numPins, int offset, float span)
		: hallPins(pins), numPins(numPins), offset(offset), span(span), focal(-1) {
	}

	void check() {
		float highestVal = 0;
		for (int i = 0; i < numPins; i++) {
			float value = abs((analogRead(hallPins[i]) - offset) * span);
      Serial.println("Pin" + String(hallPins[i]));
      Serial.println("Value" + String(value));

			highestVal = value > highestVal ? value : highestVal;
			if (value > 7) {
				switch (hallPins[i]) {
				case (18): focal = 2; break;
				case (17): focal = 5; break;
				case (16): focal = 8; break;
				case (15): focal = 12; break;
				case (14): focal = 15; break;
				}
			}
			else if (highestVal < 7)
			{
				focal = -1;
			}
		}
	}

	int getFocal() const {
		return focal;
	}

	void setFocal(int newFocal) {
		focal = newFocal;
	}
};

class LightEffect {
protected:
	LEDController& ledController;
	ColorPattern pattern;
	int delayTime;

public:
	LightEffect(LEDController& controller, ColorPattern colorPattern, int delay)
		: ledController(controller), pattern(colorPattern), delayTime(delay) {
	}

	virtual void run(int focal = -1) = 0;
};




class StillOneEffect : public LightEffect {
public:
	StillOneEffect(LEDController& controller, ColorPattern colorPattern, int delay)
		: LightEffect(controller, colorPattern, delay) {
	}

	void run(int focal = -1) override {
		for (int i = 0; i < LIGHT_COUNT; i++) {
			ledController.setLed(i, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
		}
	}
};

class StillManyEffect : public LightEffect {
public:
	StillManyEffect(LEDController& controller, ColorPattern colorPattern, int delay)
		: LightEffect(controller, colorPattern, delay) {
	}

	void run(int focal = -1) override {
		for (int i = 0; i < LIGHT_COUNT; i++) {
			ledController.setLed(i, pattern.red[i % COLOR_COUNT], pattern.green[i%COLOR_COUNT], pattern.blue[i%COLOR_COUNT], pattern.white[i%COLOR_COUNT]);
		}
	}
};


// Successful magnet focal implementation
class StrobeChangeEffect : public LightEffect {
public:
	StrobeChangeEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}

private:
	MagnetSensor& magSensor;

public:
	void run(int focal = -1) override {
		if (focal == -1) {
			for (int i = 0; i < COLOR_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int j = 0; j < LIGHT_COUNT / 2; j++) {

					int offset = (i + j * 2) % LIGHT_COUNT;
					for (int k = 0; k < delayTime * 2; k++) {
						// Check magnets more frequently


						ledController.setLed(offset, 0, 0, 0, 0);
						delay(3); // Shorter delays
						ledController.setLed(offset, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
						delay(3); // Shorter delays
					}
				}
			}
		}
		else {
			for (int i = 0; i < COLOR_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int j = 0; j < LIGHT_COUNT / 2; j++) {
					int position1 = (focal + 1 + (i + j * 2) % LIGHT_COUNT) % LIGHT_COUNT;
					int position2 = (16 + focal - (i + j * 2) % LIGHT_COUNT) % LIGHT_COUNT;
					for (int k = 0; k < delayTime * 2; k++) {
						ledController.setLed(position1, 0, 0, 0, 0);
						ledController.setLed(position2, 0, 0, 0, 0);
						delay(3); // Shorter delays
						ledController.setLed(position1, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
						ledController.setLed(position2, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
						delay(3); // Shorter delays
					}
				}
			}
		}
	}
};

// Successful magnet focal implementation
class TraceOneEffect : public LightEffect {
public:
	TraceOneEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}

private:
	MagnetSensor& magSensor;
public:

	void run(int focal = -1) override {
		for (int i = 0; i < LIGHT_COUNT; i++) {
			ledController.setLed(i, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
		}

		if (focal != -1) {
			for (int i = 1; i < COLOR_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int j = 0; j < LIGHT_COUNT / 2; j++) {
					int position1 = (focal + 1 + j) % LIGHT_COUNT;
					int position2 = (16 + focal - j) % LIGHT_COUNT;
					ledController.setLed(position1, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
					ledController.setLed(position2, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
					delay(delayTime);
					ledController.setLed(position1, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
					ledController.setLed(position2, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
				}
			}
		}
		else {
			for (int i = 0; i < COLOR_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int j = 0; j < LIGHT_COUNT; j++) {
					ledController.setLed(j, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
					delay(delayTime * 2);
					ledController.setLed(j, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
				}
			}
		}

	}
};

class ProgressiveEffect : public LightEffect {
public:
	ProgressiveEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override {

		if (focal != -1) {
			for (int j = 0; j < COLOR_COUNT; j++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int i = 0; i < LIGHT_COUNT / 2; i++) {
					int ledIndex = (focal + i) % LIGHT_COUNT;
					int ledIndex2 = (focal - i + 16) % LIGHT_COUNT;
					ledController.setLed(ledIndex, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
					ledController.setLed(ledIndex2, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
					delay(delayTime);

					ledIndex = (focal + i + 1) % LIGHT_COUNT;
					ledIndex2 = (focal - i - 1 + 16) % LIGHT_COUNT;
					ledController.setLed(ledIndex, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
					ledController.setLed(ledIndex2, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
					delay(delayTime);
				}
			}
		}
		else {
			for (int j = 0; j < COLOR_COUNT; j++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int i = 0; i < LIGHT_COUNT; i++) {
					int ledIndex = (j + i) % LIGHT_COUNT;
					int ledIndex2 = (j + i + 1) % LIGHT_COUNT;
					ledController.setLed(ledIndex, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
					ledController.setLed(ledIndex2, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
					delay(delayTime * 2);

					ledIndex = (j + i + 1) % LIGHT_COUNT;
					ledIndex2 = (j + i + 2) % LIGHT_COUNT;
					ledController.setLed(ledIndex, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
					ledController.setLed(ledIndex2, pattern.red[j], pattern.green[j], pattern.blue[j], pattern.white[j]);
					delay(delayTime * 2);
				}
			}
		}
	}
};

class TraceManyEffect : public LightEffect {
public:
	TraceManyEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override {
		for (int i = 0; i < LIGHT_COUNT; i++) {
			ledController.setLed(i, pattern.red[0], pattern.green[0], pattern.blue[0], pattern.white[0]);
		}
		if (focal == -1) {
			for (int i = 0; i < LIGHT_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int j = 0; j < LIGHT_COUNT / 2; j++) {
					int offset = (i + j * 2) % LIGHT_COUNT;
					ledController.setLed(offset, pattern.red[(i + 1) % (COLOR_COUNT/2)], pattern.green[(i + 1) % COLOR_COUNT], pattern.blue[(i + 1) % COLOR_COUNT], pattern.white[(i + 1) % COLOR_COUNT]);
					delay(delayTime * 2);

					offset = (i + j * 2 + 8) % LIGHT_COUNT;
					ledController.setLed(offset, pattern.red[(i + 1) % (COLOR_COUNT/2)], pattern.green[(i + 2) % COLOR_COUNT], pattern.blue[(i + 2) % COLOR_COUNT], pattern.white[(i + 2) % COLOR_COUNT]);
				}
			}
		}
		else {
			for (int i = 0; i < COLOR_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int j = 0; j < LIGHT_COUNT / 2; j++) {
					int position1 = (focal + 1 + j) % LIGHT_COUNT;
					int position2 = (LIGHT_COUNT + focal - j) % LIGHT_COUNT;
					ledController.setLed(position1, pattern.red[(i + 1) % COLOR_COUNT], pattern.green[(i + 1) % COLOR_COUNT], pattern.blue[(i + 1) % COLOR_COUNT], pattern.white[(i + 1) % COLOR_COUNT]);
					delay(delayTime);
					ledController.setLed(position2, pattern.red[(i + 1) % COLOR_COUNT], pattern.green[(i + 2) % COLOR_COUNT], pattern.blue[(i + 2) % COLOR_COUNT], pattern.white[(i + 2) % COLOR_COUNT]);
				}
			}

		}
	}
};

class ComfortSongStrobeEffect : public LightEffect {
public:
	ComfortSongStrobeEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override {
		int patternIndices[] = { 1, 2, 3, 2, 4, 3, 2, 1, 0, 1, 2, 1, 3, 2, 1, 0 };
		int pattern2Indices[] = { 7, 8, 9, 8, 10, 9, 8, 7, 6, 7, 8, 7, 9, 8, 7, 6 };
		int pattern3Indices[] = { 13, 14, 15, 14, 16, 15, 14, 13, 12, 13, 14, 13, 15, 14, 13, 12 };

		if (focal == -1) {
			for (int x = 0; x < COLOR_COUNT; x++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int i = 0; i < delayTime; i++) {
					ledController.setLed(patternIndices[x], pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
					ledController.setLed(pattern2Indices[x], pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
					ledController.setLed(pattern3Indices[x], pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
					delay(5);
					ledController.setLed(patternIndices[x], 0, 0, 0, 0);
					ledController.setLed(pattern2Indices[x], 0, 0, 0, 0);
					ledController.setLed(pattern3Indices[x], 0, 0, 0, 0);
					delay(5);
				}
			}
		}
		else {
			int pattern4Indices[] = { 3, 4, 5, 4, 6, 5, 4, 3, 2, 3, 4, 3, 5, 4, 3, 2 };
			for (int x = 0; x < COLOR_COUNT; x++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int i = 0; i < delayTime; i++) {
					int led1 = pattern4Indices[x] + focal;
					if (led1 < 0) {
						led1 = LIGHT_COUNT + led1;
					}
					else if (led1 > 15) {
						led1 = led1 - LIGHT_COUNT;
					}

					int led2 = focal - pattern4Indices[x];
					if (led2 < 0) {
						led2 = LIGHT_COUNT + led2;
					}
					else if (led2 > 15) {
						led2 = led2 - LIGHT_COUNT;
					}
					ledController.setLed(led1, pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
					ledController.setLed(led2, pattern.red[x], pattern.green[x], pattern.blue[x], pattern.white[x]);
					delay(5);
					ledController.setLed(led1, 0, 0, 0, 0);
					ledController.setLed(led2, 0, 0, 0, 0);
					delay(5);
				}
			}
		}
	}
};

class BlenderEffect : public LightEffect {
public:
	BlenderEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override {
		if (focal == -1) {
			for (int i = 0; i < LIGHT_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				int colorIndex = (i + millis() / delayTime) % COLOR_COUNT;
				ledController.setLed(i, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
			}
			delay(delayTime);

			for (int i = 0; i < LIGHT_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				int colorIndex = (COLOR_COUNT - (i + millis() / delayTime) % COLOR_COUNT) % COLOR_COUNT;
				ledController.setLed(i, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
			}
			delay(delayTime);
		}
		else {
			for (int i = 0; i < LIGHT_COUNT / 2; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				int led1 = focal - i;
				int led2 = focal + i;

				if (led1 < 0) {
					led1 = LIGHT_COUNT + led1;
				}
				if (led2 > (LIGHT_COUNT-1)) {
					led2 = led2 - LIGHT_COUNT;
				}
				int colorIndex = (i + millis() / delayTime) % COLOR_COUNT;
				ledController.setLed(led1, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
				ledController.setLed(led2, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
			}
			delay(delayTime);

			for (int i = 0; i < LIGHT_COUNT / 2; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				int led1 = focal - i;
				int led2 = focal + i;

				if (led1 < 0) {
					led1 = LIGHT_COUNT + led1;
				}
				if (led2 > (LIGHT_COUNT-1)) {
					led2 = led2 - LIGHT_COUNT;
				}
				int colorIndex = (COLOR_COUNT - (i + millis() / delayTime) % COLOR_COUNT) % COLOR_COUNT;
				ledController.setLed(led1, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
				ledController.setLed(led2, pattern.red[colorIndex], pattern.green[colorIndex], pattern.blue[colorIndex], pattern.white[colorIndex]);
			}
			delay(delayTime);
		}
	}
};

class TechnoEffect : public LightEffect {
public:
	TechnoEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override {
		if (focal == -1) {
			for (int i = 0; i < COLOR_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				int m = (i + 1) % COLOR_COUNT;
				int n = (i + 2) % COLOR_COUNT;
				int o = (i + 3) % COLOR_COUNT;
				int p = (i + 4) % COLOR_COUNT;
				for (int j = 15; j >= 0; j--) {
					int k = (j + 1) % LIGHT_COUNT;
					int l = (j + 2) % LIGHT_COUNT;
					int y = (j + 3) % LIGHT_COUNT;
					int z = (j + 4) % LIGHT_COUNT;

					for (int x = 0; x < 2; x++) {
						ledController.setLed(j, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
						delay(delayTime);
						ledController.setLed(j, 0, 0, 0, 0);
						ledController.setLed(k, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);
						delay(delayTime);
						ledController.setLed(k, 0, 0, 0, 0);
						ledController.setLed(l, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);
						delay(delayTime);
						ledController.setLed(l, 0, 0, 0, 0);
						ledController.setLed(y, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);
						delay(delayTime);
						ledController.setLed(y, 0, 0, 0, 0);
						ledController.setLed(z, pattern.red[p], pattern.green[p], pattern.blue[p], pattern.white[p]);
						delay(delayTime);
						ledController.setLed(z, 0, 0, 0, 0);
					}
				}
			}
		}
		else {
			for (int i = 0; i < COLOR_COUNT; i++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				int m = (i + 1) % COLOR_COUNT;
				int n = (i + 2) % COLOR_COUNT;
				int o = (i + 3) % COLOR_COUNT;
				int p = (i + 4) % COLOR_COUNT;
				int jb = focal;
				for (int j = focal; j >= 0; j--) {
					if (jb < 16) {
						int k = j + 1;
						int l = j + 2;
						int y = j + 3;
						int z = j + 4;

						int kb = jb + 1;
						int lb = jb + 2;
						int yb = jb + 3;
						int zb = jb + 4;

						for (int x = 0; x < 2; x++) {
							ledController.setLed(j, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
							ledController.setLed(jb, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);

							delay(delayTime * 2);
							ledController.setLed(j, 0, 0, 0, 0);
							ledController.setLed(jb, 0, 0, 0, 0);

							ledController.setLed(k, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);
							ledController.setLed(kb, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);

							delay(delayTime * 2);
							ledController.setLed(k, 0, 0, 0, 0);
							ledController.setLed(kb, 0, 0, 0, 0);

							ledController.setLed(l, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);
							ledController.setLed(lb, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);

							delay(delayTime * 2);
							ledController.setLed(l, 0, 0, 0, 0);
							ledController.setLed(lb, 0, 0, 0, 0);

							ledController.setLed(y, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);
							ledController.setLed(yb, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);

							delay(delayTime * 2);
							ledController.setLed(y, 0, 0, 0, 0);
							ledController.setLed(yb, 0, 0, 0, 0);

							ledController.setLed(z, pattern.red[p], pattern.green[p], pattern.blue[p], pattern.white[p]);
							ledController.setLed(zb, pattern.red[p], pattern.green[p], pattern.blue[p], pattern.white[p]);

							delay(delayTime * 2);
							ledController.setLed(z, 0, 0, 0, 0);
							ledController.setLed(zb, 0, 0, 0, 0);
						}
						jb++;
					}
				}

				for (int j = 0; j < focal; j++) {
					if (jb < 16) {
						int k = j + 1;
						int l = j + 2;
						int y = j + 3;
						int z = j + 4;

						int kb = jb + 1;
						int lb = jb + 2;
						int yb = jb + 3;
						int zb = jb + 4;

						for (int x = 0; x < 2; x++) {
							ledController.setLed(j, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);
							ledController.setLed(jb, pattern.red[i], pattern.green[i], pattern.blue[i], pattern.white[i]);

							delay(delayTime * 2);
							ledController.setLed(j, 0, 0, 0, 0);
							ledController.setLed(jb, 0, 0, 0, 0);

							ledController.setLed(k, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);
							ledController.setLed(kb, pattern.red[m], pattern.green[m], pattern.blue[m], pattern.white[m]);

							delay(delayTime * 2);
							ledController.setLed(k, 0, 0, 0, 0);
							ledController.setLed(kb, 0, 0, 0, 0);

							ledController.setLed(l, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);
							ledController.setLed(lb, pattern.red[n], pattern.green[n], pattern.blue[n], pattern.white[n]);

							delay(delayTime * 2);
							ledController.setLed(l, 0, 0, 0, 0);
							ledController.setLed(lb, 0, 0, 0, 0);

							ledController.setLed(y, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);
							ledController.setLed(yb, pattern.red[o], pattern.green[o], pattern.blue[o], pattern.white[o]);

							delay(delayTime * 2);
							ledController.setLed(y, 0, 0, 0, 0);
							ledController.setLed(yb, 0, 0, 0, 0);

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
};

class TranceEffect : public LightEffect {
public:
	TranceEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override {
		int sc1 = 4;  // Fixed the undefined variable 'a'
		int sc2 = 2;
		int ls = 3;
		if (focal == -1) {
			for (int j = 0; j < LIGHT_COUNT; j++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int k = 0; k < sc1; k++) {
					for (int i = 0; i < ls; i++) {
						int li = j + i;
						if (li < LIGHT_COUNT) {  // Add bound check
							ledController.setLed(li + 1, pattern.red[li % COLOR_COUNT], pattern.green[li % COLOR_COUNT], pattern.blue[li % COLOR_COUNT], pattern.white[li % COLOR_COUNT]);
						}
					}
					delay(delayTime);
					for (int i = 0; i < ls; i++) {
						int ledIndex = j + i;
						if (ledIndex < LIGHT_COUNT) {  // Add bound check
							ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
						}
					}
					delay(delayTime);
				}

				for (int strobe = 0; strobe < sc2; strobe++) {
					for (int i = 0; i < ls; i++) {
						int ledIndex = j + i;
						if (ledIndex < LIGHT_COUNT) {  // Add bound check
							ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
						}
					}
					delay(delayTime);
					for (int i = 0; i < ls; i++) {
						int ledIndex = j + i;
						if (ledIndex < LIGHT_COUNT) {  // Add bound check
							ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
						}
					}
					delay(delayTime);
				}
			}
		}
		else {
			for (int j = 0; j < LIGHT_COUNT; j++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				// Calculate the distance from the focal point (spread outwards)
				int distance = abs(focal - j);  // Distance from focal point

				for (int k = 0; k < sc1; k++) {
					for (int i = 0; i < ls; i++) {
						int li = distance + i;  // Adjust lighting based on distance
						if (li < LIGHT_COUNT) {          // Add bound check
							ledController.setLed((li + 1), pattern.red[li % COLOR_COUNT], pattern.green[li % COLOR_COUNT], pattern.blue[li % COLOR_COUNT], pattern.white[li % COLOR_COUNT]);
						}
					}
					delay(delayTime);

					for (int i = 0; i < ls; i++) {
						int ledIndex = distance + i;
						if (ledIndex < LIGHT_COUNT) {  // Add bound check
							ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
						}
					}
					delay(delayTime);
				}

				for (int strobe = 0; strobe < sc2; strobe++) {
					for (int i = 0; i < ls; i++) {
						int ledIndex = distance + i;
						if (ledIndex < LIGHT_COUNT) {  // Add bound check
							ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
						}
					}
					delay(delayTime);

					for (int i = 0; i < ls; i++) {
						int ledIndex = distance + i;
						if (ledIndex < LIGHT_COUNT) {  // Add bound check
							ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
						}
					}
					delay(delayTime);
				}
			}
		}
	}
};

class MoldEffect : public LightEffect {
public:
	MoldEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override {
		int strobeCount1 = 2;
		int strobeCount2 = 2;
		int ledsPerGroup = LIGHT_COUNT * 3 / 4;
		if (focal == -1) {
			for (int startIdx = LIGHT_COUNT - 1; startIdx >= 0; startIdx--) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int strobe = 0; strobe < strobeCount1; strobe++) {
					for (int i = 0; i < ledsPerGroup; i++) {
						int ledIndex = startIdx + i;
						for (int ha = 0; ha < LIGHT_COUNT / 4; ha++) {
							ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
							ledController.setLed(ledIndex, 0, 0, 0, 0);
						}
					}
					for (int i = 0; i < ledsPerGroup; i++) {
						int ledIndex = startIdx + i;
						ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
					}
				}

				for (int strobe = 0; strobe < strobeCount2; strobe++) {
					for (int i = 0; i < ledsPerGroup; i++) {
						int ledIndex = startIdx + i;
						for (int ha = 0; ha < 4; ha++) {
							ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
							ledController.setLed(ledIndex, 0, 0, 0, 0);
						}
					}
					for (int i = 0; i < ledsPerGroup; i++) {
						int ledIndex = startIdx + i;
						ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
					}
				}
			}
			for (int startIdx = 0; startIdx < LIGHT_COUNT; startIdx++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int strobe = 0; strobe < strobeCount1; strobe++) {
					for (int i = 0; i < ledsPerGroup; i++) {
						int ledIndex = startIdx + i;
						for (int ha = 0; ha < 4; ha++) {
							ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
							ledController.setLed(ledIndex, 0, 0, 0, 0);
						}
					}
					for (int i = 0; i < ledsPerGroup; i++) {
						int ledIndex = startIdx + i;
						ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
					}
				}

				for (int strobe = 0; strobe < strobeCount2; strobe++) {
					for (int i = 0; i < ledsPerGroup; i++) {
						int ledIndex = startIdx + i;
						for (int ha = 0; ha < 4; ha++) {
							ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex], pattern.white[ledIndex]);
							ledController.setLed(ledIndex, 0, 0, 0, 0);
						}
					}
					for (int i = 0; i < ledsPerGroup; i++) {
						int ledIndex = startIdx + i;
						ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
					}
				}
			}
		}
		else {
			for (int startIdx = LIGHT_COUNT-1; startIdx >= focal; startIdx--) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int startIdx = focal; startIdx < LIGHT_COUNT; startIdx++) {
					for (int strobe = 0; strobe < strobeCount1; strobe++) {
						for (int i = 0; i < ledsPerGroup; i++) {
							int ledIndex = startIdx + i;
							int ledIndex2 = startIdx + i - 8;
							for (int ha = 0; ha < 4; ha++) {
								ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
								ledController.setLed(ledIndex2 + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
								ledController.setLed(ledIndex, 0, 0, 0, 0);
								ledController.setLed(ledIndex2, 0, 0, 0, 0);
							}
						}
						for (int i = 0; i < ledsPerGroup; i++) {
							int ledIndex = startIdx + i;
							int ledIndex2 = startIdx - i;
							ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
							ledController.setLed(ledIndex2 + 1, 0, 0, 0, 0);
						}
					}

					for (int strobe = 0; strobe < strobeCount2; strobe++) {
						for (int i = 0; i < ledsPerGroup; i++) {
							int ledIndex = startIdx + i;
							int ledIndex2 = startIdx - i;
							for (int ha = 0; ha < 4; ha++) {
								ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
								ledController.setLed(ledIndex2 + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
								ledController.setLed(ledIndex, 0, 0, 0, 0);
								ledController.setLed(ledIndex2, 0, 0, 0, 0);
							}
						}
						for (int i = 0; i < ledsPerGroup; i++) {
							int ledIndex = startIdx + i;
							int ledIndex2 = startIdx - i;
							ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
							ledController.setLed(ledIndex2 + 1, 0, 0, 0, 0);
						}
					}
				}
			}
		}
	}
};

class FunkyEffect : public LightEffect {
public:
	FunkyEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override {
		int strobeCount1 = 4;
		int strobeCount2 = 4;
		int ledsPerGroup = 1;

		if (focal == -1) {
			delay(delayTime / 4);

			for (int strobe = 0; strobe < strobeCount1; strobe++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int i = 0; i < ledsPerGroup; i++) {
					int ledIndex = random(0, LIGHT_COUNT);
					delay(delayTime / 12);
					ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
				}
				delay(delayTime / 12);

				for (int i = 0; i < ledsPerGroup; i++) {
					int ledIndex = random(0, LIGHT_COUNT);
					delay(delayTime / 8);
					ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
				}
			}

			for (int strobe = 0; strobe < strobeCount2; strobe++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int i = 0; i < ledsPerGroup; i++) {
					delay(delayTime / 12);

					int ledIndex = random(0, LIGHT_COUNT);
					ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
				}
				delay(delayTime / 12);

				for (int i = 0; i < ledsPerGroup; i++) {
					delay(delayTime / 12);

					int ledIndex = random(0, LIGHT_COUNT);
					ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
				}
			}
		}
		else {
			for (int strobe = focal; strobe < strobeCount1; strobe++) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int i = 0; i < ledsPerGroup; i++) {
					int ledIndex = random(0, LIGHT_COUNT);
					int ledIndex2 = random(0, LIGHT_COUNT);
					delay(delayTime / 12);
					ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
					ledController.setLed(ledIndex2 + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
				}
				delay(delayTime / 12);

				for (int i = focal; i < ledsPerGroup; i++) {
					int ledIndex = random(0, LIGHT_COUNT);
					int ledIndex2 = random(0, LIGHT_COUNT);
					delay(delayTime / 8);
					ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
					ledController.setLed(ledIndex2 + 1, 0, 0, 0, 0);
				}
			}

			for (int strobe = focal + 1; strobe >= 0; strobe--) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				for (int i = 0; i < ledsPerGroup; i++) {
					delay(delayTime / 12);

					int ledIndex = random(0, LIGHT_COUNT);
					int ledIndex2 = random(0, LIGHT_COUNT);
					ledController.setLed(ledIndex + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
					ledController.setLed(ledIndex2 + 1, pattern.red[ledIndex % COLOR_COUNT], pattern.green[ledIndex % COLOR_COUNT], pattern.blue[ledIndex % COLOR_COUNT], pattern.white[ledIndex % COLOR_COUNT]);
				}
				delay(delayTime / 12);

				for (int i = focal; i < ledsPerGroup; i++) {
					delay(delayTime / 12);

					int ledIndex = random(0, LIGHT_COUNT);
					int ledIndex2 = random(0, LIGHT_COUNT);
					ledController.setLed(ledIndex + 1, 0, 0, 0, 0);
					ledController.setLed(ledIndex2 + 1, 0, 0, 0, 0);
				}
			}
		}
	}
};

class ChristmasEffect : public LightEffect { // This effect is not working.
public:
	ChristmasEffect(LEDController& controller, ColorPattern colorPattern, int delay, MagnetSensor& sensor)
		: LightEffect(controller, colorPattern, delay), magSensor(sensor) {
	}
private:
	MagnetSensor& magSensor;
public:
	void run(int focal = -1) override
	{
		int i = 0;

		if (focal == -1) {
			while (i < 16) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				delay(delayTime);
				i++;
				i = i % 2;
				for (int xy = 0; xy < COLOR_COUNT; xy++) {

					if (i == 0) {
						for (int j = 0; j < 18; j += 2) {
							ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
							if (j == 8) {
								ledController.setLed(j, pattern.red[(xy + 1) % COLOR_COUNT], pattern.green[(xy + 1) % COLOR_COUNT], pattern.blue[(xy + 1) % COLOR_COUNT], pattern.white[(xy + 1) % COLOR_COUNT]);
							}
							if (j == 12) {
								ledController.setLed(j, pattern.red[(xy + 2) % COLOR_COUNT], pattern.green[(xy + 2) % COLOR_COUNT], pattern.blue[(xy + 2) % COLOR_COUNT], pattern.white[(xy + 2) % COLOR_COUNT]);
							}
							ledController.setLed(j + 1, pattern.red[(xy + 3) % COLOR_COUNT], pattern.green[(xy + 3) % COLOR_COUNT], pattern.blue[(xy + 3) % COLOR_COUNT], pattern.white[(xy + 3) % COLOR_COUNT]);
						}


						for (int j = 1; j < LIGHT_COUNT + 3; j += 2) {
							ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
							ledController.setLed(j - 1, pattern.red[(xy + 3) % COLOR_COUNT], pattern.green[(xy + 3) % COLOR_COUNT], pattern.blue[(xy + 3) % COLOR_COUNT], pattern.white[(xy + 3) % COLOR_COUNT]);
						}
					}
				}
			}
		}
		else {
			while (i < 16) {
				int originalFocal = focal;
				magSensor.check();
				focal = magSensor.getFocal();
				Serial.println("Focal: " + String(focal));

				// If focal point changed, restart effect with new value
				if (focal != originalFocal) {
					run(focal);
					return;
				}
				delay(delayTime);
				i++;

				i = i % 2;

				for (int xy = 0; xy < COLOR_COUNT; xy++) {
					if (i == 0) {
						for (int j = focal; j < LIGHT_COUNT; j += 2) {
							ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
							if (j == 8) {
								ledController.setLed(j, pattern.red[(xy + 1) % COLOR_COUNT], pattern.green[(xy + 1) % COLOR_COUNT], pattern.blue[(xy + 1) % COLOR_COUNT], pattern.white[(xy + 1) % COLOR_COUNT]);
							}
							if (j == 12) {
								ledController.setLed(j, pattern.red[(xy + 2) % COLOR_COUNT], pattern.green[(xy + 2) % COLOR_COUNT], pattern.blue[(xy + 2) % COLOR_COUNT], pattern.white[(xy + 2) % COLOR_COUNT]);
							}
							ledController.setLed((j + 1) % LIGHT_COUNT, pattern.red[(xy + 3) % COLOR_COUNT], pattern.green[(xy + 3) % COLOR_COUNT], pattern.blue[(xy + 3) % COLOR_COUNT], pattern.white[(xy + 3) % COLOR_COUNT]);
						}

						for (int j = focal; j >= 0; j -= 2) {
							ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
							if (j == 8) {
								ledController.setLed(j, pattern.red[(xy + 1) % COLOR_COUNT], pattern.green[(xy + 1) % COLOR_COUNT], pattern.blue[(xy + 1) % COLOR_COUNT], pattern.white[(xy + 1) % COLOR_COUNT]);
							}
							if (j == 12) {
								ledController.setLed(j, pattern.red[(xy + 2) % COLOR_COUNT], pattern.green[(xy + 2) % COLOR_COUNT], pattern.blue[(xy + 2) % COLOR_COUNT], pattern.white[(xy + 2) % COLOR_COUNT]);
							}
							ledController.setLed((j + 1) % LIGHT_COUNT, pattern.red[(xy + 3) % COLOR_COUNT], pattern.green[(xy + 3) % COLOR_COUNT], pattern.blue[(xy + 3) % COLOR_COUNT], pattern.white[(xy + 3) % COLOR_COUNT]);
						}


						for (int j = focal; j < LIGHT_COUNT+1; j += 2) {
							ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
							ledController.setLed(j - 1, pattern.red[(xy + 3) % COLOR_COUNT], pattern.green[(xy + 3) % COLOR_COUNT], pattern.blue[(xy + 3) % COLOR_COUNT], pattern.white[(xy + 3) % COLOR_COUNT]);
						}
						for (int j = focal; j >= 0; j -= 2) {
							ledController.setLed(j, pattern.red[xy], pattern.green[xy], pattern.blue[xy], pattern.white[xy]);
							ledController.setLed(j - 1, pattern.red[(xy + 3) % COLOR_COUNT], pattern.green[(xy + 3) % COLOR_COUNT], pattern.blue[(xy + 3) % COLOR_COUNT], pattern.white[(xy + 3) % COLOR_COUNT]);
						}
					}
				}
			}
		}
	}
};

// Main application class to coordinate everything
class LightApplication {
private:
	LEDController ledController;
	MagnetSensor magnetSensor;
	LightEffect* currentEffect;

	// Color arrays
	int wr[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int r1[16] = { 255,   255,    255,    255,  255,  0,    0,    0,    0,    0,    0,    136,  255,  255,  255,  255 };
	int g1[16] = { 0,     68,     106,     145,   238,  255,  255,  255,  255,  136,  0,    0,    0,    0,    0,    0 };
	int b1[16] = { 0,     0,      0,      0,    0,    30,   68,   150,  255,  255,  255,  255,  255,  187,  136,  68 };

	int r2[16] = { 255, 255, 255, 255, 0, 255, 255, 255, 255, 255, 255, 255, 0, 255, 255, 255 };
	int g2[16] = { 0, 85, 40, 15, 0, 45, 59, 2, 0, 85, 40, 15, 0, 45, 59, 2 };
	int b2[16] = { 0, 1, 0, 2, 239, 3, 0, 0, 0, 1, 0, 2, 239, 3, 0, 0 };

	int r4[16] = { 161, 205, 172, 19, 71, 215, 205, 190, 190, 205, 215, 71, 19, 172, 205, 161 };
	int g4[16] = { 0, 52, 19, 21, 0, 35, 38, 40, 20, 38, 33, 0, 55, 19, 52, 0 };
	int b4[16] = { 0, 0, 42, 52, 35, 0, 15, 82, 82, 35, 0, 65, 75, 10, 0, 12 };

	int r5[16] = { 255, 	58, 		30, 		80, 		30, 		30, 		83, 		30, 		30, 		30, 		30, 	30, 		30, 	30, 	30, 	30 };
	int g5[16] = { 0, 		145, 		25, 		73, 		75, 		45, 		139, 		27, 		75, 		27, 		36, 	5, 			75, 	27, 	75, 	50 };
	int b5[16] = { 0, 		38, 		155, 		145, 		120, 		155, 		153, 		55, 		10, 		155, 		55, 	155, 		55, 	25, 	155, 	20 };

	int r6[16] = { 255, 0, 255, 0, 255, 255, 0, 0, 0, 255, 255, 0, 0, 255, 0, 255 };
	int g6[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int b6[16] = { 255, 0, 255, 255, 255, 0, 255, 255, 255, 255, 0, 255, 255, 255, 0, 0 };

	int r7[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int g7[16] = { 255, 200, 100, 150, 50, 255, 180, 230, 90, 50, 180, 210, 0, 120, 100, 255 };
	int b7[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

public:
	LightApplication()
		: ledController(NUM_LEDS, DATA_PIN),
		magnetSensor(new byte[5]{ A0, A1, A2, A3, A4 }, 5, 512, 0.3617),
		currentEffect(nullptr) {
		// Initialize with a default effect
		ColorPattern defaultPattern(r1, g1, b1, wr);
		currentEffect = new StillOneEffect(ledController, defaultPattern, 10);
	}

	~LightApplication() {
		delete currentEffect;
	}

	void setup() {
		ledController.begin();
		// Any additional setup
	}

	void loop() {
		// Check for magnets and update focal point
		magnetSensor.check();                 // Configures magnet to focal index

		int focal = magnetSensor.getFocal();  // Getter
		Serial.println("Focal: " + String(focal));

		// Run the current effect with the current focal point
		if (currentEffect) {
			currentEffect->run(focal);  // Every pattern has a run() function since they inherit from LightEffect
		}
	}

	void setEffect(LightEffect* newEffect) {
		if (currentEffect) {     // Checks if there is already an active effect
			delete currentEffect;  // If an effect exists, deletes it to free the memory
		}
		currentEffect = newEffect;  // Assigns the newEffect to the currentEffect;
	}

	void selectEffect(int effectNumber, int delayTime = -1) {
		// Define the different color patterns
		ColorPattern pattern1(r1, g1, b1, wr);
		ColorPattern pattern2(r2, g2, b2, wr);
		ColorPattern pattern4(r4, g4, b4, wr);
		ColorPattern pattern5(r5, g5, b5, wr);
		ColorPattern pattern6(r6, g6, b6, wr); // Here is where you need sqlite to save the user's preferences.
		ColorPattern pattern7(r7, g7, b7, wr);

		switch (effectNumber) {
		case 0:                                                                                        // stillOne
			setEffect(new StillOneEffect(ledController, pattern1, (delayTime == -1) ? 10 : delayTime));  // TODO no delay time necessary 
			break;
		case 1:                                                                                         // stillMany
			setEffect(new StillManyEffect(ledController, pattern1, (delayTime == -1) ? 10 : delayTime));  // TODO no delay time necessary
			break;
		case 2:  // traceOne
			setEffect(new TraceOneEffect(ledController, pattern5, (delayTime == -1) ? 10 : delayTime, magnetSensor));
			break;
		case 3:  // progressive
			setEffect(new ProgressiveEffect(ledController, pattern2, (delayTime == -1) ? 7 : delayTime, magnetSensor));
			break;
		case 4:  // traceMany
			setEffect(new TraceManyEffect(ledController, pattern4, (delayTime == -1) ? 15 : delayTime, magnetSensor));
			break;
		case 5:  // strobeChange
			setEffect(new StrobeChangeEffect(ledController, pattern4, (delayTime == -1) ? 2 : delayTime, magnetSensor));
			break;
		case 6:  // comfortSongStrobe
			setEffect(new ComfortSongStrobeEffect(ledController, pattern1, (delayTime == -1) ? 3 : delayTime, magnetSensor));
			break;
		case 7:  // blender
			setEffect(new BlenderEffect(ledController, pattern6, (delayTime == -1) ? 2 : delayTime, magnetSensor));
			break;
		case 8:  // techno
			setEffect(new TechnoEffect(ledController, pattern1, (delayTime == -1) ? 1 : delayTime, magnetSensor));
			break;
		case 9:  // trance
			setEffect(new TranceEffect(ledController, pattern7, (delayTime == -1) ? 1 : delayTime, magnetSensor));
			break;
		case 10:  // mold
			setEffect(new MoldEffect(ledController, pattern4, (delayTime == -1) ? 1 : delayTime, magnetSensor));
			break;
		case 11:  // funky
			setEffect(new FunkyEffect(ledController, pattern5, (delayTime == -1) ? 8 : delayTime, magnetSensor));
			break;
		case 12:  // christmas
			setEffect(new ChristmasEffect(ledController, pattern6, (delayTime == -1) ? 10 : delayTime, magnetSensor));
			break;
		default:
			setEffect(new StillOneEffect(ledController, pattern1, (delayTime == -1) ? 10 : delayTime));  // No delay time needed TODO
			break;
		}
	}
};

// Global application instance
LightApplication lightApp;

void setup() {
	Serial.begin(9600);
	while (!Serial) { delay(100); } // Serial needs time to initialize
	lightApp.setup();  // Understood path
	lightApp.selectEffect(7); // 5 is good, testing 2
	// 7 is weirdly unsettling.
}

void loop() {

	lightApp.loop();
}

/// <summary>
/// This is just notation for the interface of received information from the React application.
/// </summary>
/*
class CustomSetting {
public:
	int effectNumber; // Mode
	int delayTime;    // Delay
	int r[16];        // Red Values
	int g[16];        // Green Values
	int b[16];        // Blue Values
	int w[16];        // White Values
	float bright[16]; // Brightness Values	
	CustomSetting CustomSetting(int effectNumber, int delayTime, int r[16], int g[16], int b[16], int w[16], float bright[16]) {
		this->effectNumber = effectNumber;
		this->delayTime = delayTime;
		this->r = r;
		this->g = g;
		this->b = b;
		this->w = w;
		this->bright = bright;
	}

}
*/