#ifndef LinearDriverLib_h
#define LinearDriverLib_h
#include <Arduino.h>
#include <DegreesDriverLib.h>
class LinearDriverLib {
public:
	LinearDriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin, float millimetersPerStep);
	void moveBy(float millimeters);
	void moveTo(float millimeters);
	void setMaxSpeed(float millimetersPerSecond);
	void setAcceleration(float acceleration);
	void setMicrosteps(int pow);
private:
	float _millimetersPerStep;
	DriverLib* _driver;

	float transformed(float input);
};
#endif