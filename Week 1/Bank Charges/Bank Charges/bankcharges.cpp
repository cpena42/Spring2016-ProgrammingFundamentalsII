/* A bank charges $10 per month plus the following check fees for a commercial checking account:

	$.10 each for fewer than 20 checks
	$.08 each for 20-39 checks
	$.06 each for 40-59 checks
	$.04 each for 60 or more checks

Write a program that asks for the number of checks written during the past month, then computes
and displays the bank's fees for the month.

	Input Validation: Decide how the program should handle an input of less than 0.

Programmer: Cesar Pena
Date: January 22, 2016

*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Declare Constants
	const double BANKFEE = 10.00,
			CHECKS1 = .10,
			CHECKS2 = .08,
			CHECKS3 = .06,
			CHECKS4 = .04;

	// Declare Variables
	double numChecks, totalFees;

	// Display program title and Prompt User for Input
	cout << "***************************************************** \n";
	cout << "      Calculate monthly fees for a bank account       \n";
	cout << "***************************************************** \n";
	cout << "Please provide the following information \n\n";

	cout << "How many checks were written during the past month? ";
	cin >> numChecks;
	cout << endl;
	
	// Calculations
	while (numChecks < 0)
		{
		system ("clear");

		cout << "***************************************************** \n";
		cout << "      Calculate monthly fees for a bank account       \n";
		cout << "***************************************************** \n";
		cout << "Please provide the following information \n\n";

		cout << "TRY AGAIN! Please enter a positive number!!! ";
		cout << endl;
		cout << "How many checks were written during the past month? ";
		cin >> numChecks;
		}
	
	cout << endl;
	cout << "You entered : " << numChecks << " checks.\n";
	cout << endl;

	if (numChecks >= 1 && numChecks <= 19)
		totalFees = (numChecks * CHECKS1) + BANKFEE;

	else if (numChecks >= 20 && numChecks <= 39)
		totalFees = (numChecks * CHECKS2) + BANKFEE;

	else if (numChecks >= 40 && numChecks <= 59)
		totalFees = (numChecks * CHECKS3) + BANKFEE;
		
	else if (numChecks >= 60)
		totalFees = (numChecks * CHECKS4) + BANKFEE;
	
	else
		totalFees = BANKFEE;
		

	//Display Results
	cout << fixed << showpoint << setprecision(2);
	cout << "The total bank fees for this month are : $" << totalFees << endl;

	system("pause");
	return 0;
}