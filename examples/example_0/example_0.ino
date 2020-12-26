#include "DriverLib.h"

#define stepPin 2
#define dirPin 3
#define ms1Pin 4
#define ms2Pin 5
#define ms3Pin 6

DriverLib *driver;
void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(ms1Pin, OUTPUT);
  pinMode(ms2Pin, OUTPUT);
  pinMode(ms3Pin, OUTPUT);
  // Create driver class exemplar
  driver = new DriverLib(stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin);
  // Set speed in steps per second
  driver->setMaxSpeed(100000);
}

void loop() {
  // Move by 5000 steps forward
  driver->moveBy(5000);
  // Move by 10000 steps backward
  driver->moveBy(-10000);
}