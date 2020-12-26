#ifndef DriverLib_h
#define DriverLib_h
#include <Arduino.h>
class DriverLib {
public:
	DriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin);
	void setMaxSpeed(float speed);
	void setAcceleration(int acceleration);
	void setCurrentStep(long step);
	void moveBySteps(long pos);
private:
	long _currentPosition;
	long _targetPosition;
	float _speed;
	float _maxSpeed;
	float _acceleration;
	long _timeBetweenSteps;

	int _stepPin;
	int _ms1Pin;
	int _ms2Pin;
	int _ms3Pin;
};
#endif