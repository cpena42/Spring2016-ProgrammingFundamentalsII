/* Final Exam Part II - Question 3
3. Consider the definition of the following class:
class final
{
public:
	string sum();	//returns the appended sum of the private data numbers
	void print(); const; //prints the private data
	final(); //default constructor
	final(string a, string b); //constructor with parameters
	final(const final & f); //copy constructor

private:
	string x;
	string y;
};
	a) Write the definitions of the member functions as described in the definition
	of the class final. (5 points)
	b) Write a test program to test the various operations of the class final. (5 points)
	c) Make sure to separate solutions into header file, implementation file and test file
	and make sure to document and format code in a consistent manner, including comments (5 points)

Programmer: Cesar Pena
Date: May 8, 2016
*/
#include<iostream>
#include<string>		// Required to use strings
using namespace std;

#include "Final.h"		//Required to access the header file containing the class final

int main()
{
	//Variables
	string x, y;

	//Title - Description of the program
	cout << "************************************************************************ \n";
	cout << "**               Final Exam - Part II - Question 3                    ** \n";
	cout << "**     Use the class final and write its function definitions         ** \n";
	cout << "**                     Adding Two Strings                             ** \n";
	cout << "************************************************************************ \n";
	cout << "Please provide the following information: \n";
	cout << endl;

	//Prompt user for input
	cout << "Enter a first name: ";
	cin >> x;
	cout << "Enter a last name: ";
	cin >> y;
	cout << endl;

	//Create fullName object from final class with x and y parameters
	final fullName(x, y);

	//Print the values of the x and y in the fullName object
	cout << "Use of constructor with parameters: \n";
	fullName.print();

	//Display the sum of both x and y using the class function sum();
	cout << "The sum of both strings is: \n";
	cout << fullName.sum();
	cout << endl;

	//Create a 2nd class object equal to the first by using the class copy constructor
	final fullName2 = fullName;

	cout << endl;	//Extra line for readability 

	//Print the values of the x and y in the fullName2 object (2nd object)
	cout << "Use of copy constructor: \n";
	fullName2.print();

	//Display the sum of both x and y in 2nd object using the class function sum();
	cout << "The sum of both strings is: \n";
	cout << fullName2.sum();
	cout << endl;

	//Create a 3rd class object using the default constructor
	final fullName3;

	cout << endl;	//Extra line for readability

	//Prints the values of the x and y in the 3rd class object fullName3
	cout << "Use of the default constructor: \n";
	fullName3.print();

	//Display the sum of both x and y in the 3rd object using the class function sum();
	cout << "The sum of both strings is: \n";
	cout << fullName3.sum();
	cout << endl << endl;

	system("pause");
	return 0;
}