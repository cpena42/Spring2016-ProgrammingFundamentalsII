/* Sentence Capitalizer
Write a function that accepts a C-string as an argument and capitalizes
the first character of each sentence in the string.  For instance, if
the string argument is "hello. my name is Joe. what is your name?" the
function should manipulate the string so it contains "Hello. My name is
Joe. What is your name?" Demonstrate the function in a program that asks
the user to input a string and then passes it to the function.  The
modified string should be displayed on the screen.

Programmer: Cesar Pena
Date May 7, 2016
*/
#include<iostream>
#include<cstring>		//Required to use c-strings
#include<cctype>		//Required to use strlen - calculate the length of a c-string
using namespace std;

//Function Prototype
char *capitalizer(char *);

int main()
{
	//Variables
	char userString[300];

	//Program Title
	cout << "*************************************************************** \n";
	cout << "**                  Sentence Capitalizer                     ** \n";
	cout << "**   This program capitalizes the first word of a sentence.  ** \n";
	cout << "*************************************************************** \n";
	cout << "Please enter the following information: \n";
	cout << endl;

	//Prompt User to enter a string of not more than 300 characters.
	cout << "Enter a string with no more than 300 characters: \n";
	cin.getline(userString, 300);

	//Display the c-string
	cout << endl << "You entered: \n";
	cout << userString << endl;

	//Send the c-string to capitalizer function to capitalize the first letter of each new sentence.
	cout << endl;
	cout << "The modified string with capitalization is: \n";
	cout << capitalizer(userString) << endl;

	system("pause");
	return 0;
}

//Function Definition - goes through the userString c-string to find the beginning of each sentence and capitalize the first word
char *capitalizer(char userString[300])
{
	userString[0] = toupper(userString[0]);

	for(int i=1; i<(unsigned)strlen(userString); i++)
	{
			if(userString[i] == '.' || userString[i] == '?' || userString[i] == '!')
			{
				int s = i;
				s++;
				if(userString[s] == ' ' || userString == NULL || userString == '\0')
				{
					s++;
					userString[s] = toupper(userString[s]);
				}
			}

	}

	return userString;
}