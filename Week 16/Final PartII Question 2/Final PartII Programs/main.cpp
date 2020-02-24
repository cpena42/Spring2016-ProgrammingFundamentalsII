/* Final Exam Part II - Question 2
2. Consider the following definition of struct
struct twoVals
{
	int x;
	int y;
	string name;
};
	a) Write test a testing program to have an array of twoVals.  The program
	should read and store information for each twoVals.  It should then sum up
	all the x and all the y in alla of the twoVals. (5 points)
	b) The testing program should sort the array of twoVals. It places twoVals in
	ascending order by their x value. (5 points)
	c) The testing program should have a search method with it. (5 points)

Programmer: Cesar Pena
Date: May 8, 2016
*/
#include<iostream>
#include<string>
using namespace std;

//Header File
#include "twoVals.h"		//Required to access the structure twoVals in the header file

//twoVals Function Prototypes
void sortValueArray(twoVals *, int);			//Sorts the structure array by x value in ascending order
void sortValueArrayByName(twoVals *, int);		//Sorts the structure array by name - used to properly search the array by name
int sumOfX(twoVals *, int);						//Used to return the sum of all the x values
int sumOfY(twoVals *, int);						//Used to return the sum of all the y values
int searchValueArray(twoVals *, int, string);	//Used to return the position of the searched name
void displayValueArray(twoVals *, int);			//Display the structure array in table format after it has been sorted by x value


int main ()
{
	//Variables
	twoVals *valueArray;		//Create structure array
	int SIZE, x, y;				//SIZE will hold dynamic size of array and x and y temp values entered by user
	string name;				//Will hold temp name entered by user
	string searchName;			//Used to search the array
	int searchResult;			//Holds the position of the searched name

	//Title
	cout << "************************************************************************ \n";
	cout << "**               Final Exam - Part II - Question 2                    ** \n";
	cout << "**                 using structure array twoVals                      ** \n";
	cout << "************************************************************************ \n";
	cout << "Please provide the following information: \n";
	cout << endl;

	//Prompt User for Dynamic Size of Structure Array
	cout << "Please enter how many array values would you like to use: ";
	cin >> SIZE;

	//Sets the new size to valueArray
	valueArray = new twoVals[SIZE];

	//Prompt User for the name, x and y values for each Structure Array element
	cout << "Enter the name with x and y for the " << SIZE << " elements in the array. \n";
			for(int i = 0; i<SIZE; i++)
			{
				cout <<  i+1 << " Name: ";
				cin >> name;
				cout << i+1 << " X value: ";
				cin >> x;
				cout << i+1 << " Y value: ";
				cin >> y;

				valueArray[i] = twoVals(name, x, y);	//Use constructor to set values for element of the structure array
				cout << endl;
			}

	sortValueArray(valueArray, SIZE);		//Sorts structure array by x values in ascending order
	displayValueArray(valueArray, SIZE);	//Displays table of sorted structure array by x value

	sortValueArrayByName(valueArray, SIZE);	//Resorts the structure array by name - required to search array by name

	//Prompt user to enter the name to be searched
	cout << endl;
	cout << "Enter the name you would like to search: ";
	cin >> searchName;

	//Send searchName to function to find if name was is in the structure array and assign its element # to searchResult
	searchResult = searchValueArray(valueArray, SIZE, searchName);

	if (searchResult == -1)			// if result equals to -1 run this if statement
		cout << "Name not found in the list.\n";	// Display that name was not found on the list
	//if searchResult is anything other than -1 run this else
	else
	{
		cout << valueArray[searchResult].getName() << " was found in the object structure array.\n";
		cout << "It has an x value of " << valueArray[searchResult].getX() << " and a y value of " << valueArray[searchResult].getY() << endl;
	}
	system("pause");
	return 0;
}

//************************************************
//**  Function Definition - Bubble Sort Array   **
//**      sort the array by the x value         **
//************************************************
void sortValueArray(twoVals *valueArray, int SIZE)
{
	twoVals temp;	//Holds a valueArray object
	bool swap;		//Used for bubble sort swap

	do
	{
		swap = false;	//Sets swap value to false
		for(int count = 0; count < (SIZE - 1); count++)		//For loop to begin comparing
		{
			if(valueArray[count].getX() > valueArray[count + 1].getX())	//If the test score value stored in the first object's x is less than the second run this statement
			{
				temp = valueArray[count];				//sets struct temp to hold the first value of twoVals structure
				valueArray[count] = valueArray[count + 1];	//sets the first value of the twoVals structure to be equal to the 2nd
				valueArray[count + 1] = temp;			//sets the 2nd value of the structure value to the value in struct temp
				swap = true;		//Change swap to true because a swap did happen
			}
		}
	} while(swap); //While swap is true stay in the do/while loop

}

//***************************************************
//**    Function Definition - Sum of all x values  **
//***************************************************
int sumOfX(twoVals *valueArray, int SIZE)
{
	int sum = 0;	//Variable to hold the sum of x values

	for(int i = 0; i < SIZE; i++)
		sum += valueArray[i].getX();	//sum = sum + x values

	return sum;	//returns the sum
}

//***************************************************
//**    Function Definition - Sum of all y values  **
//***************************************************
int sumOfY(twoVals *valueArray, int SIZE)
{
	int sum = 0;	//Variable to hold the sum of y values

	for(int i = 0; i < SIZE; i++)		
		sum += valueArray[i].getY();	//sum = sum + y values

	return sum;	//returns the sum
}

//****************************************************
//**  Function Definition - Search Structure Array  **
//**               search by name                   **
//****************************************************
int searchValueArray(twoVals *valueArray, int SIZE, string n)
{
	int first = 0,							// First element of the array
		last = SIZE - 1,					// Last element of the array
		middle,								// Will hold middle position of the array search
		position = -1;						// Position of search value
	bool found = false;						// Bool value for executing while loop

	while (!found && first <= last)			// While found is not false and first element is less than or equal to last - run this while loop
	{
		middle = (first + last) / 2; 		// Calculation to find middle of search
		if (valueArray[middle].getName() == n)		// If value is found in the middle element run this if statement
		{
			found = true;					// Assign true to bool found variable
			position = middle;				// Assign middle as the new position variable
		}
		else if (valueArray[middle].getName() > n) // If value is in lower half of the search
			last = middle - 1;				// Last is now one element below the previous middle
		else
			first = middle + 1;			// If value is in upper half of the search - First is not one element above the previous middle
	}
	return position;

}

//***********************************************
//**   Function Definition - Display Table     **
//**        twoVals Structure Array            **
//***********************************************
void displayValueArray(twoVals *valueArray, int SIZE)
{
	//For loop to begin looping through the structure array and display its elements
	for(int i = 0; i < SIZE; i++)
	{
		cout << valueArray[i].getName() << "\tx value: " << valueArray[i].getX() << "\ty Value: " << valueArray[i].getY() << endl;
	}

	cout << endl;
	cout << "Total of all x values: " << sumOfX(valueArray, SIZE) << endl;		//Call the sumOfX function to get the sum of all the x values
	cout << "Total of all y values: " << sumOfY(valueArray, SIZE) << endl;		//Call the sumOfY function to get the sum of all the y values
}

//************************************************
//**  Function Definition - Bubble Sort Array   **
//**         sort the array by name             **
//**    needed to search the array by name      **
//************************************************
void sortValueArrayByName(twoVals *valueArray, int SIZE)
{
	twoVals temp;	//Holds a valueArray object
	bool swap;		//Used for bubble sort swap

	do
	{
		swap = false;	//Sets swap value to false
		for(int count = 0; count < (SIZE - 1); count++)		//For loop to begin comparing
		{
			if(valueArray[count].getName() > valueArray[count + 1].getName())	//If the test score value stored in the first object's x is less than the second run this statement
			{
				temp = valueArray[count];				//sets struct temp to hold the first value of twoVals structure
				valueArray[count] = valueArray[count + 1];	//sets the first value of the twoVals structure to be equal to the 2nd
				valueArray[count + 1] = temp;			//sets the 2nd value of the structure value to the value in struct temp
				swap = true;		//Change swap to true because a swap did happen
			}
		}
	} while(swap); //While swap is true stay in the do/while loop

}