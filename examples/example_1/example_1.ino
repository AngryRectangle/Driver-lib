#include "DegreesDriverLib.h"

#define stepPin 2
#define dirPin 3
#define ms1Pin 4
#define ms2Pin 5
#define ms3Pin 6

static DegreesDriverLib *degreeDriver;
void setup() {
  // Create degrees driver for motor with rotates each steps by 1.8 degrees
  degreeDriver = new DegreesDriverLib(stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin, 1.8f);
  // Set speed in angles per second
  degreeDriver->setMaxSpeed(100);
}

void loop() {
  // Rotate by 720 degrees clockwise
  degreeDriver->rotateBy(720);
  // Rotate to 0 degrees
  degreeDriver->rotateTo(0);
}
