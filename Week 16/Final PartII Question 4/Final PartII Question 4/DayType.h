//dayType class - Header file
#include<iostream>
#include<string>		//Required to use string variables
using namespace std;

#ifndef DAYTYPE_H		//Prevents the header file from being opened multiple times
#define DAYTYPE_H		//If header file isn't define this defines it

class dayType
{
private:
	string day;		//Variable to hold the current day

public:
	//Default Constructor
	dayType();

	//Constructor - with parameter (*not listed in the question)
	dayType(string);

	//Copy Constructor
	dayType(const dayType & d);

	//Mutator Function - Sets the day
	void setDay(int);
	void updateDay(int);

	//Prints the current day
	void printDay();

	//Returning Functions / Accessor Functions
	string getDay();		//Returns the day
	string getNextDay();	//Returns the next day
	string getPreviousDay();//Returns the previous day

};

#endif		//End of defined header file