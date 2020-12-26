#include "LinearDriverLib.h"

#define stepPin 2
#define dirPin 3
#define ms1Pin 4
#define ms2Pin 5
#define ms3Pin 6

DriverLib *driver;
DegreesDriverLib *degreeDriver;
LinearDriverLib *linearDriver;
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
  // Create linear driver for motor with which moves by 10 milimeters per revolution
  linearDriver = new LinearDriverLib(degreeDriver, 10);
  // Set speed in steps per second
  driver->setMaxSpeed(100000);
}

void loop() {
  // Move by 2m
  linearDriver->moveBy(2000);
  // Move to 1 cm
  linearDriver->moveTo(10);
}
