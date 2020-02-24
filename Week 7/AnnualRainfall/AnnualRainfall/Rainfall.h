//Header file containing structures and functions
#include <iostream>
#include <string>		// Needed for using string variables
using namespace std;

#ifndef RAINFALL_H	//Prevents the header file from being included more than once - if not define
#define RAINFALL_H	//If RAINFALL is not define, this will define it

struct Month
{
	//Variables
	string month;
	double rain;

	//Constructor
	Month(string m = "", double r = 0.0) : month(m), rain(r) {}

	//Accessor Functions
	string getMonth()
	{
		string m = month;
		return m;
	}

	double getRain()
	{
		double r = rain;
		return r;
	}
};

#endif //End of define RAINFALL_H