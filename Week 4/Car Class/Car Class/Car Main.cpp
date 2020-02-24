/* Car Class pg 498
Write a class named Car that has the following member variables:
	year. An int that holds the car's model year.
	make. A string object that holds the make of the car.
	speed. An int that holds the car's current speed.

In addition, the class should have the following member functions.

	Constructor. The constructor should accept the car's year and make
		as arguments and assign these values to the object's year and make
		member variables.  The constructor should initialize the speed member
		variable to 0.
	Accessors. Appropriate accessor functions should be created to allow values
		to be retrieved from an object's year, make and speed member variables.
	Accelerate. The accelerate function should add 5 to the speed member variable
		each time it is called.
	Brake. The brake function should subtract 5 from the speed member variable each
		time it is called.

Demonstrate the class in a program that creates a Car object, and then calls the
accelerate function five times.  After each call to the accelerate function, get the
current speed of the car and display it.  Then, call the brake function five times.
After each call to the brake function, get the current speed of the car and display it.

Programmer: Cesar Pena
Date: February 14, 2016
*/
#include<iostream>
#include<string>

#include "Car.h"

using namespace std;

int main()
{
	int year;
	int i;
	string make;

	cout << "Enter a vehicle's year and make: \n";
	cout << "Year (4 digit format ####): ";
	cin >> year;
	cout << "Make: ";
	cin.ignore();

	getline(cin, make);

	Car speed(year, make);

	cout << endl;
	cout << "Vehicle information: \n";
	cout << "Make: " << speed.getMake() << "\t" << speed.getYear() << endl;
	cout << endl;

	cout << endl;
	cout << "Starting speed: " << speed.getSpeed() << endl << endl;

	for(i = 1; i <= 5; i++)
	{
		speed.setAccelerateSpeed(5);
		cout << "Accelerate " << i << ": " << speed.getSpeed() << endl;
	}

	cout << endl;

	for(i = 1; i <= 5; i++)
	{
		speed.setBrakeSpeed(5);
		cout << "Brake " << i << ": " << speed.getSpeed() << endl;
	}

	cout << endl;
	cout << "Ending speed: " << speed.getSpeed() << endl << endl;

	system("pause");
	return 0;
}