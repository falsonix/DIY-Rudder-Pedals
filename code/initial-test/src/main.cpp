#include <Arduino.h>
#include <PicoGamepad.h>

PicoGamepad gamepad; // init gamepad object
int rightBrake = 26;
int steering = 27;
int leftBrake = 28;
int rightOffset = 0;
int leftOffset = 0;

// auto calibrate potentiometers in case physical alignment is not 100% perfect,
// averages the amount of readings requested by checkTimes
void calculateOffset(int potentiometer, int checkTimes) {
  int measurements = 0;
  for (int i = 0; i < checkTimes; i++) {
    measurements += analogRead(potentiometer);
    delay(2); // 2ms delay to account for any random fluctuations
  }
  int offset = measurements / checkTimes;

  if (potentiometer == rightBrake) {
    rightOffset = offset;
    Serial.print("Right offset: ");
    Serial.println(rightOffset);
  }
  else if (potentiometer == leftBrake) {
    leftOffset = offset;
    Serial.print("Left offset: ");
    Serial.println(leftOffset);
  }
  else {
    Serial.println("Potentiometer used in offset is invalid!");
    Serial.print("Invalid potentiometer pin: ");
    Serial.println(potentiometer);
  }
}

// having the offsets like that might cause issues due to the potentiometers for each pedal being mirrored, reversing the values for one side
// but oh well that's a problem for future me to fix (once i actually build the device for myself)

void setup() {
  Serial.begin(115200); // in case debugging is needed, hope this doesnt cause issues with COM allocation (light testing reveals it's fine)
  while (!Serial) {
    // do nothing until USB is initialized, idk if this'll help anything
  }
  pinMode(rightBrake, INPUT);
  pinMode(steering, INPUT);
  pinMode(leftBrake, INPUT);

  calculateOffset(rightBrake, 4);
  calculateOffset(leftBrake, 4);

  Serial.println("Setup initialized");
}

// axis mappings (at least how i have them now)
// rightBrake: axis 0
// steering: axis 1
// leftBrake: axis 2

void loop() {
  int rightPos = (analogRead(rightBrake) - rightOffset);
  // taken from the README of the PicoGamepad library, remap the raw ADC data to the full HID range
  rightPos = map(rightPos, 0, 1023, -32767, 32767);
  gamepad.SetAxis(0, rightPos);

  int steeringPos = analogRead(steering);
  steeringPos = map(steeringPos, 0, 1023, -32767, 32767);
  gamepad.SetAxis(1, steeringPos);

  int leftPos = (analogRead(leftBrake) - leftOffset);
  leftPos = map(leftPos, 0, 1023, -32767, 32767);
  gamepad.SetAxis(2, leftPos);

  gamepad.send_update();

  delay(20);
}