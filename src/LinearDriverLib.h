#ifndef LinearDriverLib_h
#define LinearDriverLib_h
#include <Arduino.h>
#include <DegreesDriverLib.h>
class LinearDriverLib {
public:
	LinearDriverLib(DegreesDriverLib* driver, float millimetersPerRotation);
	void moveBy(float millimeters);
	void moveTo(float millimeters);
private:
	float _millimetersPerRotation;
	DegreesDriverLib* _driver;
};
#endif