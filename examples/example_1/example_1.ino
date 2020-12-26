#include "DegreesDriverLib.h"

#define stepPin 2
#define dirPin 3
#define ms1Pin 4
#define ms2Pin 5
#define ms3Pin 6

DriverLib *driver;
DegreesDriverLib *degreeDriver;
void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ms1Pin, OUTPUT);
  pinMode(ms2Pin, OUTPUT);
  pinMode(ms3Pin, OUTPUT);
  // Create driver class exemplar
  driver = new DriverLib(stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin);
  // Create degrees driver for motor with rotates each steps by 1.8 degrees
  degreeDriver = new DegreesDriverLib(driver, 1.8f);
  // Set speed in steps per second
  driver->setMaxSpeed(100000);
}

void loop() {
  // Rotate by 720 degrees clockwise
  degreeDriver->rotateBy(720);
  // Rotate to 0 degrees
  degreeDriver->rotateTo(0);
}
