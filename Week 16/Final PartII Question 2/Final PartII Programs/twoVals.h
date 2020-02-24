#include<iostream>
#include<string>

using namespace std;

#ifndef TWOVALS_H
#define TWOVALS_H

struct twoVals
{
	//Variables
	int x;
	int y;
	string name;

	//Default Constructor
	twoVals();

	//Constructor
	twoVals(string, int, int);

	//Accessor Functions
	string getName();
	int getX();
	int getY();
};


#endif