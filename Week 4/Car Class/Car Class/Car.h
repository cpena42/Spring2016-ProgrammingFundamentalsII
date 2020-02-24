//Header File - includes Car class - Function Declarations
#include<iostream>
#include<string>

using namespace std;

#ifndef CAR_H
#define CAR_H

class Car{
private:
	int newYear;
	string newMake;
	int newSpeed;
public:
	//Default Constructor Function
	Car();

	//Constructor Function
	Car(int, string);

	//Accessor Functions
	int getYear();
	string getMake();
	int getSpeed();

	//Mutator Functions with Calculations
	void setAccelerateSpeed(int);
	void setBrakeSpeed(int);

};

#endif