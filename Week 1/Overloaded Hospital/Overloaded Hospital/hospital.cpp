/* Overloaded Hospital
Write a program that computes and displays the charges for 
a patient's hospital stay.  First, the program should ask if
the patient was admitted as an in-patient or an out-patient.
if the patient was an in-patient the following data should
be entered:
    * The number of days spent in the hospital
	* The daily rate
	* Charges for hospital services (lab tests, etc.)
	* Hospital medication charges.

	If the patient was an out-patient the following data should
be entered:
	* Charges for hospital services (lab tests, etc.)
	* Hospital medication charges.

	Use a single, separate function to validate that no input is
less than zero.  If it is, it should be reentered before
being returned.

Once the required data has been input and validated, the program
should use two overloaded functions to calculate the total
charges.  One of the functions should accept arguments for the
in-patient data, while the other function accepts arguments for
out-patient data.  Both functions should return the total
charges.

Programmer: Cesar Pena
Date: January 24, 2016
*/
#include<iostream>
#include<iomanip>
using namespace std;

// Function Prototypes
double validate(double);   
double totalCharges(int, double, double, double);   // Overloaded Function (1)
double totalCharges(double, double);				// Overloaded Function (2)

int main()
{
	// Variables
	int userChoice;    // Choice for switch statement
	double days, rate, serviceFee, medFee;  // Will hold user input

	// Display Title
	cout << "***************************************************** \n";
	cout << "**                Hospital Charges                 ** \n";
	cout << "***************************************************** \n";
	cout << endl;

	// Menu - Allows user to select if patient is an in-patient or out-patient
	cout << "Please make a selection \n";
	cout << "1. In-Patient \n";
	cout << "2. Out-Patient \n";
	cout << endl;
	cout << "Is the patient an in-patient or out-patient? ";
	cin >> userChoice;  
	cout << endl;

	while(userChoice < 1 || userChoice > 2)			// If userChoice is not 1 or 2 run this while statement until it is.
	{
		cout << "Error! Choice must be 1 or 2 \n";
		cout << "Re-enter choice: ";
		cin >> userChoice;
	}
	
	switch(userChoice)								// Switch statement for user choice
	{
	case 1: cout << "Enter days patient spent in hospital: ";		// If userChoice was 1, run this case, get user to enter
			cin >> days;											// Days, Rate, Service Fee, and Medication Fee
			days = validate(days);

			cout << "Enter daily rate: ";
			cin >> rate;
			rate = validate(rate);
			
			cout << "Enter charges for hospital services: ";
			cin >> serviceFee;
			serviceFee = validate(serviceFee);

			cout << "Enter hospital medication charges: ";
			cin >> medFee;
			medFee = validate(medFee);

			// Send days, rate, serviceFee and medFee to function to display total charges
			cout << fixed << showpoint << setprecision(2);
			cout << endl;							
			cout << "The total charges are $" << totalCharges(days, rate, serviceFee, medFee);
			cout << endl;
			break;

	case 2: cout << "Enter charges for hospital services: ";		// If userChoice was 2, run this case, get user to enter
			cin >> serviceFee;										// Service Fee and Medication Fee
			serviceFee = validate(serviceFee);

			cout << "Enter hospital medication charges: ";
			cin >> medFee;
			medFee = validate(medFee);

			// Send serviceFee and medFee to function to display total charges
			cout << fixed << showpoint << setprecision(2);
			cout << endl;
			cout << "The total charges are $" << totalCharges(serviceFee, medFee);
			cout << endl;
			break;

	}


	system("pause");
	return 0;
}

// Function to validate Data, value cannot be less than 0
double validate(double userInput)
{
	while(userInput < 0)
	{
		cout << "Error! Value cannot be less than 0! \n";
		cout << "Re-Enter value: ";
		cin >> userInput;
	}

	return userInput;
}

// Overloaded function (1) to calculate in-patient total charges
double totalCharges(int days, double rate, double serviceFee, double medFee)
{
	double total;

	total = (days * rate) + serviceFee + medFee;

	return total;
}

// Overloaded function (2) to calculate out-patient total charges
double totalCharges(double serviceFee, double medFee)
{
	double total;

	total = serviceFee + medFee;

	return total;
}

