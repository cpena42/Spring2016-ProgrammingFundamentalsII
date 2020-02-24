/* Date Pg 497
Design a class called Date that has integer data members to store month, day, and year.  The class should have a three-parameter
default constructor that allows the date to be set at the time a new Date object is created.  If the user creates a Date object
without passing any arguments, or if any of the values passed are invalid, the default values of 1, 1, 2001 (i.e., January 1, 2001)
should be used.  The class should have member functions to print the date in the following formats:

3/15/13
March 15, 2013
15 March 2013

Demonstrate the class by writing a program that uses it.  Be sure your program only accepts reasonable values for month and day.  The month
should be between 1 and 12. The day should be between 1 and the number of days in the selected month.

Programmer: Cesar Pena
Date: February 13, 2016
*/
#include<iostream>

#include "Date.h"

using namespace std;

int main()
{
	int month, year, day;
	
	cout << "************************************************************ \n";
	cout << "*         Display a date in 3 different formats            * \n";
	cout << "*             using classes and objects                    * \n";
	cout << "************************************************************ \n";
	cout << "Please enter the following information: \n\n";

	cout << "Enter a month number between (1-12): "; 
	cin >> month;
	cout << "Enter a year (1 - 99; year will display in the 2000s): ";
	cin >> year;
	cout << "Enter a day number between (1-31): ";
	cin >> day;

	Date dates(month, year, day);

	cout << endl;
	cout << "The date in 3 different formats is: \n";
	dates.format1();
	dates.format2();
	dates.format3();

	system("pause");
	return 0;
}