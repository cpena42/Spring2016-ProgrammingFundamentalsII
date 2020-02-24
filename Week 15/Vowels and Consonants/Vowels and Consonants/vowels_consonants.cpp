/* Vowels and Consonants
Write a function that accepts a C-string as its argument.  The function
should count the number of vowels appearing in the string and return
that number.
Write another function that accepts a C-string as its argument.  This
function should count the number of consonants appearing in the string
and return that number.
Demonstrate the two functions in a program that performs the following
steps:
1. The user is asked to enter a string.
2. The program displays the following menu.
A) Count the number of vowels in the string
B) Count the number of consonants in the string
C) Count both the vowels and consonants in the string
D) Enter another string
E) Exit the program
3. The program performs the operation selected by the user and repeats
   until the user selects E, to exit the program.

Programmer: Cesar Pena
Date: May 7, 2016
*/
#include<iostream>
#include<cstring>		// Required to used cstrings
#include<cctype>		// Required to use strlen, to calculate length of string
#include<stdlib.h>		// Required to use system('cls')

using namespace std;

//Function Prototypes
int vowelCount(char *);			//Will count the vowels in the string	
int consonantCount(char *);		//Will count the consonants in the string

int main()
{
	//Variables
	char sentence[300];			//C-String
	char menuChoice;			//Used for menu choice

	//Display title
	cout << "************************************************************ \n";
	cout << "                   Vowels and Consonants                     \n";
	cout << "    This program reads a string and returns the total        \n";
	cout << "       number of vowels and consonants it contains           \n";
	cout << "************************************************************ \n";
	cout << "Please enter the following: \n\n";

	//Prompt user to enter a string of 300 characters
	cout << "Enter a string of 300 characters: \n";
	cin.getline(sentence, 300);

	//do while loop for menu
	do
	{
		system("cls"); // Clear the screen

		//Display menu
		cout << "Vowel and Consonants - Main Menu \n";

		cout << "\tA) Count the number of vowels in the string\n";
		cout << "\tB) Count the number of consonants in the string\n";
		cout << "\tC) Count both the vowels and consonants in the string\n";
		cout << "\tD) Enter another string\n";
		cout << "\tE) Exit the program\n";

		//Prompt user for menu choice
		cout << endl << "Please make a selection (A-E): ";
		cin >> menuChoice;

		//Switch/case statement for menu options
		switch(menuChoice)
		{
		case 'A': case 'a':			//Display if choice was A or a,  Display the vowel count of the string
				system("cls");
				cout << "Menu Choice - Count the number of vowels in the string. \n";
				
				cout << "The string entered is: \n";
				cout << sentence << endl;

				//Send the c-string to the function vowelCount to calculate how many vowels it has
				cout << endl;
				cout << "Contains " << vowelCount(sentence) << " vowels" << endl;
				cout << endl;

				system("pause");
				break;
		
		case 'B': case 'b':			//Display if choice was B or b, Display the consonant count of the string
				system("cls");
				cout << "Menu Choice - Count the number of consonants in the string. \n";

				cout << "The string entered: \n";
				cout << sentence << endl;

				//Send the c-string to the function consonantCount to calculate how many vowels it has
				cout << endl;
				cout << "Contains " << consonantCount(sentence) << " consonants" << endl;
				cout << endl;

				system("pause");
				break;

		case 'C': case 'c':			//Display if choice was C or c, Display the vowel and consonant count of the string
				system("cls");
				cout << "Menu Choice - Count both the vowels and consonants in the string. \n";

				cout << "The string entered: \n";
				cout << sentence << endl;

				//Send the c-string to the functions vowelCount and consonantCount to get the vowels and consonants in it
				cout << endl;
				cout << "Contains " << vowelCount(sentence) << " vowels";
				cout << " and " << consonantCount(sentence) << " consonants" << endl;
				cout << endl;

				system("pause");
				break;

		case 'D': case 'd':			//Display if choice was D or d, Display the menu to enter new string into sentence c-string
				system("cls");
				cout << "Menu Choice - Enter another string. \n";

				//Prompt user for new c-string
				cout << "Enter new string: \n";
				cin.ignore();
				cin.getline(sentence, 300);

				break;

		case 'E': case 'e':			//Display if choice was E or e, Program exit
				system("cls");
				cout << "Program Terminated Successfully" << endl;

				break;
		}
	}
	while(menuChoice != 'E' && menuChoice != 'e');		//Exit the while loop if menuChoice is E or e

	
	system("pause");
	return 0;
}

//Function Definition for vowelCount - Calculates how many vowels in the c-string sent from main.
int vowelCount(char sentence[300])
{
	int vowels = 0;

	for(int i = 0; i < (unsigned)strlen(sentence); i++)
	{
		if(sentence[i] == 'A' || sentence[i] == 'a' || sentence[i] == 'E' || sentence[i] == 'e' || sentence[i] == 'I' || sentence[i] == 'i' || sentence[i] == 'O' || sentence[i] == 'o' || sentence[i] == 'U' || sentence[i] == 'u')
			vowels++;
	}
	return vowels;
}

//Function Definition for consonantCount - Calculates how many consonants in the c-string sent from main.
int consonantCount(char sentence[300])
{
	int consonants = 0;

	for(int i=0; i < (unsigned)strlen(sentence); i++)
	{
		if(sentence[i] != 'A' && sentence[i] != 'a' && sentence[i] != 'E' && sentence[i] != 'e' && sentence[i] != 'I' && sentence[i] != 'i' && sentence[i] != 'O' && sentence[i] != 'o' && sentence[i] != 'U' && sentence[i] != 'u' && sentence[i] != ' ' && sentence[i] != '.' && sentence[i] != '!' && sentence[i] != ',' && sentence[i] != '?' && sentence[i] != ';' && sentence[i] != ':')
			consonants++;
	}

	return consonants;
}
