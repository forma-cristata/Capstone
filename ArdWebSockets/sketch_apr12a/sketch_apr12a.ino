/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-websocket
 */

#include <WiFiS3.h>
#include <WebSocketServer.h>
#include "index.h"

using namespace net;

WebSocketServer wss(81);
WiFiServer server(80);

const char ssid[] = "friskyfishes";  // change your network SSID
const char pass[] = "allthatjazz";   // change your network password

int status = WL_IDLE_STATUS;

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
    Serial.println("Please upgrade the firmware");

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 4 seconds for connection:
    delay(4000);
  }

  // print your board's IP address:
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();

  wss.onConnection([](WebSocket &ws) {
    const auto protocol = ws.getProtocol();
    if (protocol) {
      Serial.print(F("Client protocol: "));
      Serial.println(protocol);
    }

    ws.onMessage([](WebSocket &ws, const WebSocket::DataType dataType,
                    const char *message, uint16_t length) {
      switch (dataType) {
        case WebSocket::DataType::TEXT:
          Serial.print(F("Received: "));
          Serial.println(message);
          break;
        case WebSocket::DataType::BINARY:
          Serial.println(F("Received binary data"));
          break;
      }

      String reply = "Received: " + String((char *)message);
      ws.send(dataType, reply.c_str(), reply.length());
    });

    ws.onClose([](WebSocket &, const WebSocket::CloseCode, const char *,
                  uint16_t) {
      Serial.println(F("Disconnected"));
    });

    Serial.print(F("New WebSocket Connnection from client: "));
    Serial.println(ws.getRemoteIP());

    const char message[]{ "Hello from Arduino server!" };
    ws.send(WebSocket::DataType::TEXT, message, strlen(message));
  });

  wss.begin();
}

void loop() {
  // put light loop here. Main loop of main
  wss.listen();

  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    // read the HTTP request header line by line
    while (client.connected()) {
      if (client.available()) {
        String HTTP_header = client.readStringUntil('\n');  // read the header line of HTTP request

        if (HTTP_header.equals("\r"))  // the end of HTTP request
          break;

        Serial.print("<< ");
        Serial.println(HTTP_header);  // print HTTP request to Serial Monitor
        // THIS IS HOW i HAVE SUCCESSFULLY RELAYED DATA TO THE ARDUINO
      }
    }

    // send the HTTP response header
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");  // the connection will be closed after completion of the response
    client.println();                     // the separator between HTTP header and body

    String html = String(HTML_CONTENT);

    client.println(html);
    client.flush();

    // give the web browser time to receive the data
    delay(50);

    // close the connection:
    client.stop();
  }
}
