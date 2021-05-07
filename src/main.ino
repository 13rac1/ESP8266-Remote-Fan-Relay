
#include "ota.h"


void setup() {
  pinMode(D0, OUTPUT); //Declare Pin mode
  pinMode(D5, OUTPUT); //Declare Pin mode   
  pinMode(D6, OUTPUT); //Declare Pin mode
  pinMode(D7, OUTPUT); //Declare Pin mode
  pinMode(D1, OUTPUT); //Declare Pin mode

  Serial.begin(115200);
  ota_setup();


}

void loop() {
  ota_loop();
  digitalWrite(D0, LOW);
  delay(1000);
  digitalWrite(D0, HIGH);
  delay(1000);

  digitalWrite(D5, HIGH);
  delay(500);
  digitalWrite(D5, LOW);
  digitalWrite(D6, HIGH);
  delay(500);
  digitalWrite(D6, LOW);
  digitalWrite(D7, HIGH);
  delay(500);
  digitalWrite(D7, LOW);
  digitalWrite(D1, HIGH);
  delay(500);
  digitalWrite(D1, LOW);
  delay(500);
  
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  digitalWrite(D1, HIGH);
  delay(500);
  digitalWrite(D7, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  delay(500);
  
}

