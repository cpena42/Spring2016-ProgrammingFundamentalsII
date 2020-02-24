/* Annual Rainfall Report
Write a programm that displays the name of each month in a year
and its rainfall amount, sorted in order of rainfall from
highest to lowest.  The program should use an array of structures,
where each structure holds the name of a month and its rainfall
amount.  Use a constructor to set the month names.  Make the program
modular by calling on different functions to input the rainfall
amounts, to sort the data, and to display the data.

Programmer: Cesar Pena
Date: March 6, 2016
*/
#include <iostream>
#include <string>
using namespace std;

#include "Rainfall.h"		//Needed to access the header file

void inputRain();			//Function to get rain amounts from the user
void sortMonths();			//Function to sort the months in descending order
void displayMonths();		//Function to display the months after they are sorted

//Global Constant Variable
	int const SIZE = 12;	//Used to specify the size of the structure array

//Month Array from header file - Structure - set globaly to be used in functions
	Month months[SIZE] = { Month("January", 0.0), Month("February", 0.0), Month("March", 0.0), Month("April",0.0),
						   Month("May", 0.0), Month("June", 0.0), Month("July", 0.0), Month("August", 0.0),
						   Month("September", 0.0), Month("October", 0.0), Month("November", 0.0), Month("December", 0.0)};

int main()
{
	//Display Program Title
	cout << "*********************************************" << endl;
	cout << "*          Annual Rainfall Report           *" << endl;
	cout << "*           in descending order             *" << endl;
	cout << "*********************************************" << endl;

	//Get rainfall amounts
	inputRain();

	//Sort months by rainfall amount
	sortMonths();

	//Display the sorted months
	displayMonths();

	system("pause");
	return 0;
}

//Get the user to enter rain amounts for each month.
void inputRain()
{

	cout << "Enter the amount of rainfall for each month" << endl;		//Display asking user to enter rainfall amounts
	
	//For loop to get rainfall amount values for each month
	for(int a = 0; a < SIZE; a++)
	{
		cout << months[a].month << ": ";	//Display the month member value from struct array[a]
		cin >> months[a].rain;				//Sets the new input value to rain member in the struct array[a]
	}

}

/********************************************************
 *                    Bubble Sort                       *
 * This function performs a bubble sort on the Month    *
 * structure, arranging it in descending rain order.    *
 ********************************************************/

void sortMonths()
{
	Month temp;		//Holds a Month object
	bool swap;		//Used for bubble sort swap

	do
	{
		swap = false;	//Sets swap value to false
		for(int count = 0; count < (SIZE - 1); count++)		//For loop to begin comparing
		{
			if(months[count].getRain() > months[count + 1].getRain())	//If the rain value stored in the first struct is less then the 2nd run this if statement
			{
				temp = months[count];				//sets struct temp to hold the first value of months structure
				months[count] = months[count + 1];	//sets the first value of the months structure to be equal to the 2nd
				months[count + 1] = temp;			//sets the 2nd value of the structure value to the value in struct temp
				swap = true;		//Change swap to true because a swap did happen
			}
		}
	} while(swap); //While swap is true stay in the do/while loop

}

//Displays the annual rainfall
void displayMonths()
{
	cout << endl; // Extra space for readibility

	//Display the months structure array that had been previously sorted
	cout << "The annual rainfall for each month from Greatest to Least is as follows: " << endl;
	for(int a = 0; a < SIZE; a++)
		cout << months[a].month << " - " << months[a].rain << endl;
}