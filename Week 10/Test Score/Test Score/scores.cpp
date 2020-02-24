/* Test Scores #1
Write a program that dynamically allocates an array large enough to hold a user-defined
number of test scores.  Once all the scores are entered, the array should be passed to
a function that sorts them in ascending order.  Another function should be called that
calculates the average score.  The program should display the sorted list of scores and
averages with appropriate headings.  Use pointer notation rather than array notation
whenever possible.

Programmer: Cesar Pena
Date: April 3, 2016
*/
#include<iostream>
using namespace std;

//Function Prototypes
double *getScores(int);					//Populate pointer array
void sortScores(double *, int);			//Sort the array in ascending order
double averageScore(double *, int);		//Calculates the average

int main()
{
	double *s;			//Pointer array will hold test scores
	int size;			//User define size of the pointer array
	double average;		//Used to hold the calculation of average

	//Title of Program
	cout <<"****************************************************** \n";
	cout <<"*          Test Scores - Array Calculator            * \n";
	cout <<"*          Sorting(Ascending) and Average            * \n";
	cout <<"****************************************************** \n";
	cout << endl;

	//Prompt user for size of array
	cout <<"Please enter the number of scores that will be used:";
	cin >> size;

	//Input validation - no 0 or negatives for size of array
	while(size <= 0)
	{
		cout << "Error! Number of scores cannot be 0 or negative \n";
		cout << "Re-enter the number of scores \n";
		cout << "that will be used: ";
		cin >> size;
	}

	//Populate array using the getScores function
	s = getScores(size);

	//Sort scores in ascending order
	sortScores(s, size);

	//Calculate the average
	average = averageScore(s, size);

	cout <<"\nScores Sorted in Ascending Order \n";
	
	//Display sorted scores
	for(int i=0; i<size; i++)
	{
		cout << s[i] << endl;
	}
	//Display average of the scores
	cout << "Average = " << average << endl;

	system("pause");
	return 0;
}

//Populate the pointer array
double *getScores(int size)
{
	double *array;		// Temporary pointer array

	array = new double[size];	//Dynamically sets the temporary pointer array to size of user defined "size"

	//Get the scores from the user
	cout << "Please enter the " << size << " scores \n";
	for(int i=0; i<size; i++)
	{
		cin>>array[i];
	}
	
	return array;	//Returns the array to be set to *s array
}

//Use bubble sort to sort the pointer array of scores in ascending order
void sortScores(double *s, int size)
{
	double temp;	//Holds temporary value
	bool swap;		//Used for bubble sort swap

	do
	{
		swap = false;	//Sets swap value to false
		for(int count = 0; count < (size - 1); count++)		//For loop to begin comparing
		{
			if(s[count] > s[count + 1])		//If s[0] is greater than s[1] run this statement
			{
				temp = s[count];			//Sets temp variable to s[0]
				s[count] = s[count + 1];	//Sets s[0] to s[1]
				s[count + 1] = temp;		//Sets s[1] to temp variable
				swap = true;			//Sets swap to true because a swap did occur
			}
		}
	} while(swap); //While swap is true stay in the do/while loop

}

//Calculate average of scores
double averageScore(double *s, int size)
{
	double total = 0.0;		//Holds the total sum of the array of values
	double average;			//Used to hold the calculated average value
	
	//Sum the array
	for(int i=0; i<size; i++)
	{
		total += s[i];
	}
	//Calculate average
	average = total / size;

	//Returns average to main
	return average;
}