#include "DegreesDriverLib.h"

DegreesDriverLib::DegreesDriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin, float degreesPerStep) {
	_driver = new DriverLib(stepPin, stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin);
	_degreesPerStep = degreesPerStep;
}

void DegreesDriverLib::rotateBy(float angle) {
	_driver->moveBy((long)transformed(angle));
}

void DegreesDriverLib::rotateTo(float angle) {
	_driver->moveTo((long)transformed(angle));
}

void DegreesDriverLib::setMaxSpeed(float angle) {
	_driver->setMaxSpeed(transformed(angle))
}

void DegreesDriverLib::setAcceleration(float angle) {
	_driver->setAcceleration(transformed(angle))
}

void DegreesDriverLib::setMicrosteps(int pow) {
	_driver->setMicrosteps(pow);
}

float DegreesDriverLib::transformed(float input) {
	return angle / _degreesPerStep;
}