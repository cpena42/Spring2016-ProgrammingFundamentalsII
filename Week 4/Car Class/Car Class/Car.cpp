//Function Definitions 

#include "Car.h"

Car::Car()
{
	newSpeed = 0;
}

Car::Car(int year, string make)
{
	newYear = year;
	newMake = make;
	newSpeed = 0;
}

int Car::getYear()
{
	return newYear;
}

string Car::getMake()
{
	return newMake;
}

int Car::getSpeed()
{
	return newSpeed;
}

void Car::setAccelerateSpeed(int s)
{
	newSpeed += s;
}

void Car::setBrakeSpeed(int s)
{
	newSpeed -= s;
}