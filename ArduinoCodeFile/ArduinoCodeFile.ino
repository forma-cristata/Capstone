// TextAnimation works only when ArduinoGraphics is installed and used.
// ArduinoGraphics is an external library and needs to be installed using
// Library Manager.
// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix
#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

const uint32_t heart[] = {
    0x3184a444,
    0x44042081,
    0x100a0040
};
const uint32_t heart_smaller[] = {
  0x1b024,
  0x82081100,
  0xa0040000,
  66
};

void LED_matrix_draw_welcome_message(){
  matrix.begin();
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(100);
  const char text[] = " hello gorgeous ";
  matrix.textFont(Font_4x6);
  matrix.beginText(0, 1, 0xFFFFFF);
  matrix.println(text);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();
}
void LED_matrix_draw_heart_beat(){
  matrix.loadFrame(heart_smaller);
  delay(450);
  matrix.loadFrame(heart);
  delay(100);
  matrix.loadFrame(heart_smaller);
  delay(900);
  matrix.loadFrame(heart);
  delay(100);
}

/*****************SETUP & LOOP******************/

void setup() {
  LED_matrix_draw_welcome_message();
}

void loop(){
  LED_matrix_draw_heart_beat();
}