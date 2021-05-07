#include <ESP8266WebServer.h>

#include "ota.h"

// Esp8266 Server running on port 80
ESP8266WebServer server(80);

void powerOn() {
  digitalWrite(D5, HIGH);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
  digitalWrite(D1, LOW);
}

void powerOff() {
  // AKA manual mode, unpowered relay powers manual controls.
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
  digitalWrite(D1, LOW);
}

void low() {
  powerOn();
  digitalWrite(D6, HIGH);
}

void medium() {
  powerOn();
  digitalWrite(D7, HIGH);
}

void high() {
  powerOn();
  digitalWrite(D1, HIGH);
}

void setup() {
  pinMode(D0, OUTPUT);  // LED

  pinMode(D5, OUTPUT);  // Power
  pinMode(D6, OUTPUT);  // Low
  pinMode(D7, OUTPUT);  // Medium
  pinMode(D1, OUTPUT);  // High

  Serial.begin(9600);
  ota_setup();

  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  // IP address assigned to your ESP

  server.on("/", handleRoot);
  server.begin();

  low();  // Start on low when plugged in
}

void loop() {
  ota_loop();
  server.handleClient();
}

String s = R"(<!DOCTYPE html>
  <html>
  <meta name="viewport" content="width=500, initial-scale=1">
  <body>
  <h1>Fan Speed</h1>

  <form action="/">
    <input type="radio" id="off" name="speed" value="off">
    <label for="off">Off/Manual</label><br>
    <input type="radio" id="low" name="speed" value="low">
    <label for="low">Low</label><br>
    <input type="radio" id="medium" name="speed" value="medium">
    <label for="medium">Medium</label><br>
    <input type="radio" id="high" name="speed" value="high">
    <label for="high">High</label><br>

    <input type="submit" value="Submit">
  </form>
  </body>
  </html>
)";

// HTTP root handler. Useable via provided web form or simple HTTP GET.
void handleRoot() {
  digitalWrite(D0, LOW);  // Flash the LED during response
  Serial.print("handleRoot Start");

  String speed = server.arg("speed");
  // TODO: Display current value ¯\_(ツ)_/¯
  // s += speed;
  server.send(200, "text/html", s);

  if (speed == "off") {
    powerOff();
  } else if (speed == "low") {
    low();
  } else if (speed == "medium") {
    medium();
  } else if (speed == "high") {
    high();
  }

  Serial.println("handleRoot Finish");
  digitalWrite(D0, HIGH);
}