#include "LinearDriverLib.h"

#define stepPin 2
#define dirPin 3
#define ms1Pin 4
#define ms2Pin 5
#define ms3Pin 6

LinearDriverLib *linearDriver;
void setup() {
  // Create linear driver for motor with which moves by 0.5 milimeters each step
  linearDriver = new LinearDriverLib(stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin, 0.5f);
  // Set speed in milimeters per second
  linearDriver->setMaxSpeed(2);
}

void loop() {
  // Move by 2m
  linearDriver->moveBy(2000);
  // Move to 1 cm
  linearDriver->moveTo(10);
}
