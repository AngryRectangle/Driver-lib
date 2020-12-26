#ifndef DegreesDriverLib_h
#define DegreesDriverLib_h
#include <Arduino.h>
#include <DriverLib.h>
class DegreesDriverLib {
public:
	DegreesDriverLib(DriverLib driver, float degreesPerStep);
	void rotateBy(float angle);
	void rotateTo(float angle);
private:
	float _degreesPerStep;
	DriverLib _driver;
};
#endif