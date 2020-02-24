/* Final Exam Part II - Question 4
4. Design and implement a class dayType that implements the day of the week in a program.
The class dayType should store the day, such as Sun for Sunday.  The program should be able
to perform the following operations on objects of the type dayType:
* A default constructor (2 points)
* A copy constructor (1 points)
* Set the day (2 points)
* Print the day (2 points)
* Return the day (2 points)
* Return the next day (2 points)
* Return the previous day (3 points)
* Update the day, stored in a dayType object, by adding certain days to it.
  For example, if the day is Monday and you add 4 days, the updated day is Friday.
  Similarly, if the day is Tuesday, and you add 13 days, the updated day is Monday. (4 points)
* Write the main program to test the dayType class, you have to test all
  the functions in the class design. (5 points)

Programmer: Cesar Pena
Date: May 8, 2016
*/
#include<iostream>
using namespace std;

#include "DayType.h"	//Required to access the class dayType in the DayType.h header file 

int main()
{
	//Variables
	dayType today;	//Use the default Constructor to create class object today - Default = "Monday"
	int addDay;		//Used to prompt user how many days they would like to add to the current day

	//Title - Description of the program
	cout << "************************************************************************ \n";
	cout << "**               Final Exam - Part II - Question 4                    ** \n";
	cout << "**           Design and implement a class named dayType               ** \n";
	cout << "**             Used to calculate the day of the week                  ** \n";
	cout << "************************************************************************ \n";
	cout << "Please provide the following information: \n";
	cout << endl;

	//Create new object using the copy constructor
	dayType today2 = today;

	//Use functions from class to get the current day, next day, and previous day
	cout << "Class Object 1 created by the default constructor: \n";
	cout << "Current Day: " << today.getDay() << endl;			//Returns the day
	cout << "Next Day: " << today.getNextDay() << endl;			//Returns the next day
	cout << "Previous Day: " << today.getPreviousDay() << endl;	//Returns the previous day

	//Print current day using the function in the class void printDay()
	today.printDay();
	cout << endl;

	//Prompt user for how many days they would like to add to the current day
	cout << endl;
	cout << "How many days would you like to add? ";
	cin >> addDay;

	//Send the days entered to the updateDay function in the class to calculate the new day
	today.updateDay(addDay);

	//Display the updated/new day using the return/accessor functions
	cout << endl;
	cout << "Updated/New class object 1 - new date calculated from days entered: \n";
	cout << "Current Day: " << today.getDay() << endl;			//Returns the day
	cout << "Next Day: " << today.getNextDay() << endl;			//Returns the next day
	cout << "Previous Day: " << today.getPreviousDay() << endl;	//Returns the previous day

	//Print current day using the function in the class void printDay()
	today.printDay();
	cout << endl;

	//Display the data stored in the 2nd object that was created using the copy constructor
	cout << endl;
	cout << "Class Object 2 created by the using the copy constructor before changing it: \n";
	cout << "Current Day: " << today2.getDay() << endl;			//Returns the day
	cout << "Next Day: " << today2.getNextDay() << endl;			//Returns the next day
	cout << "Previous Day: " << today2.getPreviousDay() << endl;	//Returns the previous day

	//Print current day using the function in the class void printDay()
	today2.printDay();
	cout << endl;

	//Create new 3rd object using the constructor with parameter
	dayType today3("Tuesday");

	//Display the data stored in the 2nd object that was created using the copy constructor
	cout << endl;
	cout << "Class Object 3 created by using the class constructor with a parameter: \n";
	cout << "Current Day: " << today3.getDay() << endl;			//Returns the day
	cout << "Next Day: " << today3.getNextDay() << endl;			//Returns the next day
	cout << "Previous Day: " << today3.getPreviousDay() << endl;	//Returns the previous day

	//Print current day using the function in the class void printDay()
	today3.printDay();
	cout << endl;

	system("pause");
	return 0;
}
