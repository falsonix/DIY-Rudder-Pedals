#include <Arduino.h>
#include <PicoGamepad.h>

PicoGamepad gamepad; // init gamepad object
int rightBrake = 26;
int steering = 27;
int leftBrake = 28;

void setup() {
  Serial.begin(115200); // in case debugging is needed, hope this doesnt cause issues with COM allocation (light testing reveals it's fine)
  pinMode(rightBrake, INPUT);
  pinMode(steering, INPUT);
  pinMode(leftBrake, INPUT);
}

// axis mappings (at least how i have them now)
// rightBrake: axis 0
// steering: axis 1
// leftBrake: axis 2

void loop() {
  int rightPos = analogRead(rightBrake);
  // taken from the README of the PicoGamepad library, remap the raw ADC data to the full HID range
  rightPos = map(rightPos, 0, 1023, -32767, 32767);
  gamepad.SetAxis(0, rightPos);

  int steeringPos = analogRead(steering);
  steeringPos = map(steeringPos, 0, 1023, -32767, 32767);
  gamepad.SetAxis(1, steeringPos);

  int leftPos = analogRead(leftBrake);
  leftPos = map(leftPos, 0, 1023, -32767, 32767);
  gamepad.SetAxis(2, leftPos);

  gamepad.send_update();

  delay(20);
}