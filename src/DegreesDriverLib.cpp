#include "DegreesDriverLib.h"

DegreesDriverLib::DegreesDriverLib(DriverLib driver, float anglesPerStep) {
	_driver = driver;
	_anglesPerStep = anglesPerStep;
}

void DegreesDriverLib::rotateBy(float angle) {
	_driver.moveBy((long)(_anglesPerStep * angle))
}
void DegreesDriverLib::rotateTo(float angle) {
	_driver.moveTo((long)(_anglesPerStep * angle))
}