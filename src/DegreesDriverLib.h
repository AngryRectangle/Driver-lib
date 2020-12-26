#ifndef DegreesDriverLib_h
#define DegreesDriverLib_h
#include <Arduino.h>
#include <DriverLib.h>
class DegreesDriverLib {
public:
	DegreesDriverLib(DriverLib driver, float anglesPerStep);
	void rotateBy(float angle);
	void rotateTo(float angle);
private:
	float _anglesPerStep;
	DriverLib _driver;
};
#endif