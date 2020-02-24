//Final Class Function Definitions
#include "Final.h"

//Default Constructor
final::final()
{
	x = "Default";			//Set the x and y equal to Default String for easier viewing to test out Default Constructor
	y = "String";
}

//Constructor with parameters
final::final(string a, string b)
{
	x = a;
	y = b;
}

//Copy Constructor - make an object equal to another
final::final(const final & f)
{
	x = f.x;
	y = f.y;
}

//Returns the appended sum of the private data numbers
string final::sum()
{
	string sum;		//String variable that will hold the sum of both x and y

	sum = x + " " + y;	//Combine x and y strings
	
	return sum;		//Return the combined/appended strings
}

//Prints the private data
void final::print() const
{
	cout << "x: " << x << " y: " << y << endl;
}

//Destructor
final::~final()
{
}