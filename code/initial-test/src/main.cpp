#include <Arduino.h>
#include <PicoGamepad.h>

PicoGamepad gamepad;
int potPin = ADC0;

void setup() {
  pinMode(potPin, INPUT);
}

void loop() {
  int pos = analogRead(potPin);
  // from library's README: Map analog 0-1023 value from pin to max HID range -32767 - 32767
  pos = map(pos, 0, 1023, -32767, 32767);
  gamepad.SetX(pos);

  gamepad.send_update();

  delay(50); // 50ms delay for fast responses
}