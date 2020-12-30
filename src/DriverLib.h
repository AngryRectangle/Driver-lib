#ifndef DriverLib_h
#define DriverLib_h
#include <Arduino.h>

const int FULL_STEP = 0;
const int HALF_STEP = 1;
const int QUARTER_STEP = 2;
const int EIGHTH_STEP = 3;
const int SIXTEENTH_STEP = 4;

class DriverLib {
public:
	DriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin);
	void setMaxSpeed(float stepsPerSecond);
	void setAcceleration(float acceleration);
	void moveTo(long step);
	void moveBy(long pos);
	void setMicrosteps(int pow);
private:
	int _microsteps;
	long _currentPosition;
	long _targetPosition;
	float _maxSpeed;
	float _acceleration;

	int _stepPin;
	int _dirPin;
	int _ms1Pin;
	int _ms2Pin;
	int _ms3Pin;

	int microsteps[5][3] = {
	{0, 0, 0},
	{1, 0, 0},
	{0, 1, 0},
	{1, 1, 0},
	{1, 1, 1}
	};
};
#endif