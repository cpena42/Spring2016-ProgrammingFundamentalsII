/* Rate of Inflation
The annual rate of inflation is the rate at which money loses its value.
For example, if the annual rate of inflation is 3.0%, then in one year it will
cost $1030 to buy the goods that could have been purchased for $1000 today.
Put another way, a year from now $1000 will only buy 1/1.03 * $1000, or $970.87, worth of goods.
Two years from now $1000 will only buy only 1/1.03 of $970.87, or $942.59 worth of goods.
Write a program that allows the user to enter an annual rate of inflation between 1% and 15%, and which
then reports how much $1000 today will be worth each year for the next 10 years.

Programmer: Cesar Pena
Date: January 24, 2016
*/
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	// Variables
	double money = 1000;
	double userRate, inflateAmount;

	// Display Title / Description
	cout << "************************************************************* \n";
	cout << "**    Calculates rate of inflation for $1000 in 10 years   ** \n";
	cout << "**         How much is $1000 worth for each year           ** \n";
	cout << "************************************************************* \n";
	cout << endl;

	// Ask user input for rate of inflation
	cout << "Please enter an annual rate of inflation (between 1 - 15 %): ";
	cin >> userRate;
	cout << endl;

	// If rate of inflation entered is less than 1 or more than 15 ask user to re-enter value
	while(userRate < 1 || userRate > 15)
	{
		cout << "Error! Please use a value between 1 - 15 only \n";
		cout << "Enter an annual rate of inflation (between 1 - 15 %): ";
		cin >> userRate;
		cout << endl;
	}

	cout << fixed << showpoint << setprecision(2);		// Show 2 decimal points
	for(int i=1; i <= 10; i++)							// For loop to calculate rate per year for 10 years
	{
		money = money * (1 / (1 + (userRate /100)));
		cout << "Year " << i << " = $" << money << endl;
	}


	system("pause");
	return 0;
}