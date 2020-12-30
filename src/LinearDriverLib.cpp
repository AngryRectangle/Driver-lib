#include "LinearDriverLib.h"

LinearDriverLib::LinearDriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin, float millimetersPerStep) {
	_driver = new DriverLib(stepPin, ms1Pin, ms2Pin, ms3Pin, dirPin);
	_millimetersPerStep = millimetersPerStep;
}

void LinearDriverLib::moveBy(float millimeters) {
	_driver->moveBy((long)transformed(millimeters));
}
void LinearDriverLib::moveTo(float millimeters) {
	_driver->moveTo((long)transformed(millimeters));
}

void LinearDriverLib::setMaxSpeed(float millimetersPerSecond) {
	_driver->setMaxSpeed(transformed(millimetersPerSecond));
}

void LinearDriverLib::setAcceleration(float acceleration) {
	_driver->setAcceleration(transformed(acceleration));
}

void LinearDriverLib::setMicrosteps(int pow) {
	_driver->setMicrosteps(pow);
}

float LinearDriverLib::transformed(float input) {
	return input / _millimetersPerStep;
}