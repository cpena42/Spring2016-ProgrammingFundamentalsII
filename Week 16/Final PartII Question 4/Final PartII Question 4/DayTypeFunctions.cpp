//dayType class function definitions
#include "DayType.h"

//Default Constructor
dayType::dayType()
{
	day = "Monday";		//Sets the day to Monday by default
}

//Constructor - with parameter (*not listed in the question)
dayType::dayType(string d)
{
	day = d;	//Sets the day to the string sent by main when the object was created
}

//Copy Constructor - used to copy one object to another
dayType::dayType(const dayType & d)
{
	day = d.day;
}

//Mutator Function - Sets the day
void dayType::setDay(int d)
{
	//If/Else to assign the day string using the sent int value by updateDay() function
	if(d == 1)
		day = "Monday";
	else if(d == 2)
		day = "Tuesday";
	else if(d == 3)
		day = "Wednesday";
	else if(d == 4)
		day = "Thursday";
	else if(d == 5)
		day = "Friday";
	else if(d == 6)
		day = "Saturday";
	else
		day = "Sunday";
}

void dayType::updateDay(int addDay)
{
	//Variables used for calculation
	int numDay, newDay;

	//If/Else statement used to translate the day string into an int for calculation
	if(day == "Monday")
		numDay = 1;
	else if(day == "Tuesday")
		numDay = 2;
	else if(day == "Wednesday")
		numDay = 3;
	else if(day == "Thursday")
		numDay = 4;
	else if(day == "Friday")
		numDay = 5;
	else if(day == "Saturday")
		numDay = 6;
	else
		numDay = 7;

	newDay = numDay + addDay;	//Adds the added number of days sent from main to the current day number variable

	if(newDay > 7)				//If the newDay variable is more than 7, divide the newDay number by 7 and get the remainder
		newDay = newDay % 7;	//Assigns the remainder to newDay

	setDay(newDay);		//Send the newDay int value to the setDay() function to translate it back to a string
}

//Prints the current day
void dayType::printDay()
{
	cout << "The current day is set to " << day << endl;
}

//Accessor Function - Returns the day
string dayType::getDay()
{
	return day;
}

//Accessor Function - Returns the next day
string dayType::getNextDay()
{
	//If/Else statement to calculate the next day and return it
	if(day == "Monday")
		return "Tuesday";
	else if(day == "Tuesday")
		return "Wednesday";
	else if(day == "Wednesday")
		return "Thursday";
	else if(day == "Thursday")
		return "Friday";
	else if(day == "Friday")
		return "Saturday";
	else if(day == "Saturday")
		return "Sunday";
	else
		return "Monday";
}

//Accessor Function - Returns the previous day
string dayType::getPreviousDay()
{
	//If/Else statement to calculate the previous day and return it
	if(day == "Monday")
		return "Sunday";
	else if(day == "Tuesday")
		return "Monday";
	else if(day == "Wednesday")
		return "Tuesday";
	else if(day == "Thursday")
		return "Wednesday";
	else if(day == "Friday")
		return "Thursday";
	else if(day == "Saturday")
		return "Friday";
	else
		return "Saturday";
}
