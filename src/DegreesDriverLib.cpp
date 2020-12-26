#include "DegreesDriverLib.h"

DegreesDriverLib::DegreesDriverLib(DriverLib driver, float degreesPerStep) {
	_driver = driver;
	_degreesPerStep = degreesPerStep;
}

void DegreesDriverLib::rotateBy(float angle) {
	_driver.moveBy((long)(angle / _degreesPerStep))
}
void DegreesDriverLib::rotateTo(float angle) {
	_driver.moveTo((long)(angle / _degreesPerStep))
}