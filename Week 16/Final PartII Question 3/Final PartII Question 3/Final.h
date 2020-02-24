//Header File - Final class
#include<iostream>
#include<string>		// Required to use string variables
using namespace std;

#ifndef FINAL_H		//Prevents the program from opening the header file more than once
#define FINAL_H		//If header file is not define this defines it

class final
{
private:
	//Variables
	string x;
	string y;

public:
	//Default Constructor
	final();

	//Constructor with parameters
	final(string a, string b);

	//Copy Constructor
	final(const final & f);

	//Returns the appended sum of the private data members
	string sum();

	//Prints the private data members
	void print() const;

	//Destructor
	~final();
};


#endif