/* Movie Statistics
Write a program that can be used to gather statistical data about the number of movies
college students see in a month.  The program should ask the user how many students
were surveyed and dynamically allocate an array of that size.  The program should then
allow the user to enter the number of movies each student has seen. The program should
then calculate the average, median, and mode of the values entered.

Programmer: Cesar Pena
Date: April 3, 2016
*/
#include<iostream>
#include<iomanip>
using namespace std;

//Function Prototypes
int *getMovies(int);				//Populates the dynamic pointer array
void sortMovies(int *, int);		//Sorts the values in ascending order
double getAverage(int *, int);		//Calculates the average of the values
int getMedian(int *, int);			//Get the median value of the array
void getMode(int *, int);			//Calculates the mode - most repeated number or numbers

int main()
{
	//Variables
	int *students;		//Pointer array to hold values
	int size;			//Variable that will hold the size of the pointer array

	//Program Title
	cout << "******************************************************\n";
	cout << "*           Statistical Data - (Monthly)             *\n";
	cout << "*    Number of movies seen by college students       *\n";
	cout << "******************************************************\n";

	cout << "Please enter how many students were surveyed? ";
	cin >> size;

	//Input Validation - size of array cannot be 0 or negative
	while(size <= 0)
	{
		cout << "Error! Number of students cannot be 0 or negative \n";
		cout << "Re-enter number of students surveyed: ";
		cin >> size;
	}
	cout << endl;

	//Function call - Send size to populate the pointer array
	students = getMovies(size);

	//Function call - Sort values in ascending order
	sortMovies(students, size);

	//Display sorted array/values
	cout << "Sorted array \n";
	for(int i=0; i<size; i++)
		cout << students[i] << endl;

	cout << endl;
	cout << showpoint << fixed << setprecision(2);				//Used to display 2 decimal places for average
	cout << "Average: " << getAverage(students, size) << endl;	//Function call to calculate average
	cout << "Median: " << getMedian(students, size) << endl;	//Function call to calculate median

	getMode(students, size);			// Function call - calculate and display mode(s)

	system("pause");
	return 0;
}

//Function to populate pointer *array
int *getMovies(int size)
{
	int *array;		//Temporary pointer array

	array = new int[size];  //Dynamically allocate the user size to array
	
	cout << "Enter the number of movies seen for each student\n";
	
	//Populate data into the array
	for(int i=0; i<size; i++)
	{
		cin >> array[i];

		//Validate data - no zeros or negatives
		while(array[i] <= 0)
		{
			cout << "Error! Value cannot be 0 or less\n";
			cout << "Please try again: ";
			cin >> array[i];
		}
	}

	return array; // return temp array to be set to *students pointer array
}

//Use bubble sort to sort the values in *students pointer array
void sortMovies(int *students, int size)
{
	double temp;	//Used to hold temporary value
	bool swap;		//Used for bubble sort swap

	do
	{
		swap = false;	//Sets swap value to false
		for(int count = 0; count < (size - 1); count++)		//For loop to begin comparing
		{
			if(students[count] > students[count + 1])		//If Value in students[0] is greater than students[1] run this statement		
			{
				temp = students[count];						//Sets students[0] to temp variable
				students[count] = students[count + 1];		//Sets students[0] to students[1]
				students[count + 1] = temp;					//Sets students[1] to temp
				swap = true;					//Sets swap to true - because swap did occur
			}
		}
	} while(swap); //While swap is true stay in the do/while loop
}

//Function to calculate the average of the pointer array
double getAverage(int *students, int size)
{
	//Variables
	double total = 0.0;		//Will hold the sum of the array values 
	double average;			//Will hold the calculation average of the array

	//For loop to sum the values in the array
	for(int i=0; i<size; i++)
		total+=students[i];

	//Calculate the average
	average = total / size;

	//Returns the value in average
	return average;
}

//Calculates the Median value of the array
int getMedian(int *students, int size)
{
	int median;		//Hold temp value of median

	if((size % 2) == 0)	//If the array has no remainder - meaning its an even number - run this statement
		median = (students[size/2] + students[(size/2) - 1]) / 2;  // Median = array[size/2] + array[(size/2)-1] / 2
	else
		median = students[(size/2)];	//Median = array[size/2]

	//Returns value in median
	return median;	
}

//Calculate and Display mode
void getMode(int *students, int size)
{
	//Variables
	int number = students[0];	//sets new number variable to the first value of the array
	int mode = number;			//sets new mode variable to number
	int *pointer;				//New *pointer array to hold multiple values if multiple modes are found
	int nmode = 1;				//Variable counter - counts number of modes found
	int count = 1;				//Variable to count if a mode was found
	int countMode = 1;			//Incrementing variable to count same numbers are found

	pointer = new int[size];	//Sets pointer dynamically to the size of "size variable"

	cout << "Mode(s): ";		//Display
	//Calculations
	for (int i=1; i<size; i++)
	{
		if (students[i] == number)			//If value in second position of array is == to first run this if statement 
			{ 
				countMode++;	//Increment countMode because 2 numbers were found to be the same
					if(countMode == count)	//If countMode is == count run this statement
					{
						nmode++;			//Increment nmode - meaning multiple modes were found
						pointer[nmode-1] = number;	//Sets number value to pointer[1]
					}
					else if (countMode > count) //If countMode is greater than count run this statement
					{
						count = countMode; //Count is set to countMode - same as how many of a value were found
						mode = number;		//Sets mode to number
						nmode=1;			//Sets nmode=1, resets nmode meaning only 1 mode occurance was found
					}
			}
		else
		{ //Numbers did not match
			countMode = 1; // reset countMode for the new number
			number = students[i]; //set number variable with next position of the array
		}
	}

	if(count == 1)		// If count is = to 1 meaning no modes were found run this if statement
		cout << "No modes were found! (no repeated numbers)" << endl;		// Display that no modes were found
	else   //Run this else if count is not equal to 1 meaning modes were found
	{
		cout << mode << " ";	//Display the value stored in mode

		for(int i=1; i<nmode; i++)			//For loop to display the values stored in pointer array - multiple modes found
		{
			cout << pointer[i] << " ";
		}
		cout << endl;
	}
}