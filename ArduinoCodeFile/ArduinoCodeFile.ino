// TextAnimation works only when ArduinoGraphics is installed and used.
// ArduinoGraphics is an external library and needs to be installed using
// Library Manager.
// To use ArduinoGraphics APIs, please include BEFORE Arduino_LED_Matrix

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include <FastLED.h>

#include "arduino_secrets.h"

#include <WiFiS3.h>

ArduinoLEDMatrix matrix;
CRGBW leds[NUM_LEDS];

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
char ssid[] = SECRET_SSID_HOME; // your network SSID (name)
char pass[] = SECRET_PASS_HOME; // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;     // the WiFi radio's status
const char* hostname = "Cloe";

void LED_matrix_draw_welcome_message(){
  matrix.begin();
  matrix.beginDraw();
  matrix.stroke(0xFFFFFFFF);
  matrix.textScrollSpeed(50);
  const char text[] = " ENSCHULDIGUNG ";
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

void printWifiData() {
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print your MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  printMacAddress(mac);
}

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the MAC address of the router you're attached to:
  byte bssid[6];
  WiFi.BSSID(bssid);
  Serial.print("BSSID: ");
  printMacAddress(bssid);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

  // print the encryption type:
  byte encryption = WiFi.encryptionType();
  Serial.print("Encryption Type:");
  Serial.println(encryption, HEX);
  Serial.println();
}

void printMacAddress(byte mac[]) {
  for (int i = 0; i < 6; i++) {
    if (i > 0) {
      Serial.print(":");
    }
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
  }
  Serial.println();
}

void setup_wifi_connection(){
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    WiFi.setHostname(hostname);
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  // you're connected now, so print out the data:
  Serial.print("You're connected to the network");
  printCurrentNet();
  printWifiData();
}

void fast_LED_setup(){
  FastLED.addLeds<NEOPIXEL, DATA_PIN>, GRB>(leds, NUM_LEDS); 
  FastLED.setBrightness(100);
}

void fast_LED_Snake(){
  for(int i = 0; i < NUM_LEDS; i++)
  {
    // Using hex code for RGBW
    // CRGBW colorRGBW = CRGBW(0xFF, 0x57, 0x33, 0xFF);  // Hex for RGBW (Red: 255, Green: 87, Blue: 51, White: 255)
    // fillColorRGBW(colorRGBW);  // Fill LEDs with the RGBW color
    // delay(1000);
    // fillColor(CRGBW::Red) <-- Maybe insteAD?? not sure of validity
    // leds[i] = CRGB::White; FastLED.show(); delay(30);
    // (i > 0) ? leds[i - 1] : continue;
    Serial.println("LED:" + String(i) + "...ON");
    Serial.println("LED" + (i > 0) ? String(i) : "-1") + "...OFF";
    delay(100);
  }
}




/*****************SETUP & LOOP******************/

void setup() {
  LED_matrix_draw_welcome_message();
  LED_matrix_draw_heart_beat();
  LED_matrix_draw_heart_beat();
  LED_matrix_draw_heart_beat();

  setup_wifi_connection();
  printCurrentNet();

  fast_LED_setup();
}

void loop(){

    // check the network connection once every 10 seconds:
  fast_LED_Snake();
}