const byte hallPin[] = {A0, A1, A2, A3, A4}; // AH3503 sensor connected to A0 5volt and ground
const int offset = 512; // calibrate zero
const float span = 0.3617; // calibrate A/D > mT
float value;

void setup() {
  Serial.begin (9600);
}

void loop() {
  for(int i = 0; i < 5; i++)
  {
  value = (analogRead(hallPin[i]) - offset) * span;
      Serial.println(hallPin[i]);
    Serial.println(value);
  if (value > 5)
  {
    Serial.println("Magnet at pin hallPin");
    Serial.println(hallPin[i]);
    Serial.println(value);
  }
  }
  /*
  Serial.print("Value: ");
  Serial.print(value, 1);
  Serial.println(" mT");
  */
  delay(500);
}