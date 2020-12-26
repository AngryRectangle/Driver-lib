#include "LinearDriverLib.h"

LinearDriverLib::LinearDriverLib(DegreesDriverLib driver, float millimetersPerRotation) {
	_driver = driver;
	_millimetersPerRotation = millimetersPerRotation;
}

void LinearDriverLib::moveBy(float millimeters) {
	_driver.rotateBy(millimeters / _millimetersPerRotation * 360)
}
void LinearDriverLib::moveTo(float millimeters) {
	_driver.rotateTo(millimeters / _millimetersPerRotation * 360)
}