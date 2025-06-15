#include <Arduino.h>
#include <PicoGamepad.h>

int potPin = ADC0;

void setup() {
  Serial.begin(115200);
  pinMode(potPin, INPUT);
}

void loop() {
  int pos = analogRead(potPin);
  Serial.println(pos);
  delay(500); // 0.5sec delay to allow for readability during testing
}