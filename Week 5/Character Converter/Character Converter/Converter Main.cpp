/* Character Converter Class
Create a CharConverter class that performs various operations on strings.  It should
have the following two public member functions to start with.  Your instructor may ask
you to add additional functions to the class.

     * The uppercase member function accepts a string and returns a copy of it with all
	   lowercase letters converted to uppercase.  If a character is already uppercase, or
	   is not a letter, it should be left alone.
	 * The properWords member function accepts a string of words separated by spaces and 
	   returns a copy of it with the first letter of each word converted to uppercase.

Write a simple program that uses the class.  It should prompt the user to input a string.
Then it should call the properWords function and display the resulting string.  Finally, it
should call the uppercase function and display this resulting string.  The program should
loop to allow additional strings to be converted and displayed until the user chooses to quit.

Programmer: Cesar Pena
Date: February 21, 2016
*/
#include<iostream>
#include<string>
#include<cctype> //Needed for toupper

#include "Converter.h" //Required to access Converter class in the header file

using namespace std;


int main()
{
	//Declare Variables
	string choice;
	string line;

	//Display Program Title & Function
	cout << "*************************************************************\n";
	cout << "**              Character Converter Program                **\n";
	cout << "*************************************************************\n";
	cout << "Enter a string and I will display it by capitalizing\n";
	cout << "the first letter of each word & displaying the same string\n";
	cout << "with all uppercase characters.\n";

	//Do-While loop - Allows user to test several strings until desired
	do
	{
		//Prompt User for input - Sent input to string variable line
		cout << endl;
		cout << "Enter string: \n";
		getline(cin, line);

		//Create convert object from Converter class
		Converter convert(line);

		//Run the properWords and uppercase functions in the Converter class and display the results
		cout << endl;
		convert.properWords();
		cout << "Proper Words: " << convert.getLine();
		cout << endl;
		convert.uppercase();
		cout << "Uppercase: " << convert.getLine();
		cout << endl;

		//Give user the choice to try another string or to quit
		cout << endl;
		cout << "Do you want to try again? (Y/N) ";
		cin >> choice;

		//Choice validation - choice has to be Y, y, N, o n otherwise run this while statement to get right input
		while(choice != "Y" && choice != "y" && choice != "N" && choice != "n")
		{
			cout << "Invalid input! Try Again!\n";
			cout << "Type 'y' to try again or 'n' to quit: ";
			cin >> choice;
		}

		cin.ignore();	// Clears input buffer - Prepares for acceptance of a new string
	}
	while(choice == "Y" || choice == "y");  // If choice is Y or y keep running this while loop if not exit the loop

	//Display this message right before the program closes
	cout << endl << "Thank you for using the character converter program!\n" << endl;

	system("pause");
	return 0;
}