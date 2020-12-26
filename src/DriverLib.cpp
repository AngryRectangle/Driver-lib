#include "DriverLib.h"

DriverLib::DriverLib(int stepPin, int ms1Pin, int ms2Pin, int ms3Pin, int dirPin)
{
	_currentPosition = 0;
	_targetPosition = 0;
	_maxSpeed = 0;
	_acceleration = 0;
	_timeBetweenSteps = 0;
	
	_dirPin = dirPin;
	_stepPin = stepPin;
	_ms1Pin = ms1Pin;
	_ms2Pin = ms2Pin;
	_ms3Pin = ms3Pin;
}

void DriverLib::setMaxSpeed(float speed)
{
	_maxSpeed = speed;
}

void DriverLib::setAcceleration(float acceleration) {
	_acceleration = acceleration;
}
void DriverLib::setMicrosteps(int pow) {
	int value = 2;
	int i = 1;
	while (i < pow) {
		value *= 2;
	}

	_microsteps = value;
	digitalWrite(_ms1Pin, microsteps[pow][0])
	digitalWrite(_ms2Pin, microsteps[pow][1])
	digitalWrite(_ms3Pin, microsteps[pow][2])
}

void DriverLib::moveTo(long step) {
	long delta = _targetPosition - _currentPosition;
	moveBy(delta);
}
void DriverLib::moveBy(long delta) {
	_targetPosition += delta;
	if (delta > 0) {
		digitalWrite(_dirPin, LOW);
	}
	else {
		digitalWrite(_dirPin, HIGH);
	}

	if (delta < 0) {
		delta = -delta;
	}
	delta *= _microsteps;
	int stepsForAcceleration = 0;
	if (_acceleration != 0) {
		stepsForAcceleration = _maxSpeed / _acceleration;
	}

	if (stepsForAcceleration < delta / 2) {
		stepsForAcceleration = delta / 2;
	}

	int currentSpeed = _maxSpeed;
	for (int i = 0; i < delta; i++) {

		if (i < stepsForAcceleration) {
			currentSpeed = _acceleration * i;
		}
		else if ((delta - i) < stepsForAcceleration) {
			currentSpeed = _acceleration * (delta - i);
		}
		else {
			currentSpeed = _maxSpeed;
		}

		// /2?
		int waitingDuration = 1000000 / currentSpeed;
		digitalWrite(_stepPin, HIGH);
		delayMicroseconds(waitingDuration);
		digitalWrite(_stepPin, LOW);
		delayMicroseconds(waitingDuration);
	}
}