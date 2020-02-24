//Structure twoVals funtion definitions
#include "twoVals.h"


//Default Constructor Definition
twoVals::twoVals()
{
	name = " ";
	x = 0;
	y = 0;
}

//Constructor definition using parameters
twoVals::twoVals(string n, int xValue, int yValue)
{
	name = n;
	x = xValue;
	y = yValue;
}

//Accessor definition - used to return the value of name to main
string twoVals::getName()
{
	return name;
}

//Accessor definition - used to return the value of x to main
int twoVals::getX()
{
	return x;
}

//Accessor definition - used to return the value of y to main
int twoVals::getY()
{
	return y;
}