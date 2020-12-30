#ifndef DegreesDriverLib_h
#define DegreesDriverLib_h
#include <Arduino.h>
#include <DriverLib.h>
class DegreesDriverLib {
public:
	DegreesDriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin, float degreesPerStep);
	void rotateBy(float angle);
	void rotateTo(float angle);
	void setMaxSpeed(float anglesPerSecond);
	void setAcceleration(float acceleration);
	void setMicrosteps(int pow);
private:
	float _degreesPerStep;
	DriverLib* _driver;

	float transformed(float input) {
		return angle / _degreesPerStep;
	}
};
#endif