/* Binary String Search
Modify the binarySearch function presented in this chapter so it searches
an array of strings instead of an array of ints.  Test the function with a driver
program.  Use Program 9-8 as a skeleton to complete. (The array must be sorted
before the binary search will work.)

Programmer: Cesar Pena
Date: March 6, 2016
*/
#include<iostream>
#include<string>		// Required for using string variables
using namespace std;

//Function Prototypes
void arraySort(string[], int);			// Function used to sort the name array in ascending order - requires string array and size of array to be passed
int searchArray(string[], int, string);	// Function to search array, requires string array, size of array, and search name to be passed

int main()
{
	//Constant Variable
	int const SIZE = 20;		// Size of Array

	//Modified from program 9-2, using strings instead of integers
	string name[SIZE] = {"Garza, Juan", "Alaniz, Jose", "Hernandez, Adan", "Cortez, Belinda",
						 "Benitez, Alex", "Jimenez, Sandra", "Sanchez, Melissa", "Martinez, Jorge",
					   	 "Salinas, Susana", "Garcia, Maria", "Lopez, Maria", "Rivera, Joana",
						 "Montalvo, Beatriz", "Perkins, Melba", "Torres, Lily", "Rodriguez, Rosa",
						 "Garcia, Jose", "Pena, Rene", "Juarez, Manuel", "Garza, Cindy"};

	// Variables
	string nameSearch;		// Hold the name to be searched for
	int result;				// Hold the result of the search

	// Sorting
	arraySort(name, SIZE);		// Send the string array name to arraySort function to sort it in ascending order

	// Display Program Title
	cout << "*******************************************************" << endl;
	cout << "*        This program uses BINARY SEARCH to           *" << endl;
	cout << "*             search an array of names                *" << endl;
	cout << "*******************************************************" << endl;
	cout << "Please use the format (Last, First) including\n";
	cout << "the , when searching for a name. \n";
	cout << endl;
	// Promp user for what name they want to search for
	cout << "Enter the name you wish to search for: ";
	getline(cin, nameSearch);

	result = searchArray(name, SIZE, nameSearch);	// Assign the position in the array the name was found to variable result - if not found -1 will be assigned

	if (result == -1)			// if result equals to -1 run this if statement
		cout << "Name not found in the list.\n";	// Display that name was not found on the list
	else
		cout << name[result] << " was found in element #" << result << " of the array.\n"; // Any other value in result run this else statement and display the
																						   // name searched for the the location in the array it was found.

	cout << endl;  // Extra space for readibility

	system("pause");
	return 0;
}

//Use of sorting method - Selection sort - to sort names in name[] array
void arraySort(string name[], int SIZE)		// Received name array and array size
{
	int startSort, minIndex;		// Variables used for sorting, startSort beginning of array, minIndex is location of minimum value found
	string minValue;				// Variable that hold the string value of the minimum name found

	for (int startSort = 0; startSort < (SIZE - 1); startSort++)  // For loop to begin sorting, each increment of startSort is a an entire pass of the array
	{
		minIndex = startSort;				// Assume the first value of the array to be the minimum
		minValue = name[startSort];			// Assign the string value in the first element to minValue variable
		for (int index = startSort + 1; index < SIZE; index++)		// For loop to start testing unsorted values beginning with the second element
		{
			if (name[index] < minValue)		// If value found in the second element of testing is less than minValue run this if statement
			{
				minValue = name[index];		// Assign minValue with the new minimum string value found
				minIndex = index;			// Assign minIndex with the new location of the minimum value
			}
		}
		//Swapping Values
		name[minIndex] = name[startSort];   // Assign the value in name[0] to the location where minimum was found
		name[startSort] = minValue;			// Assign the new minimum to the beginning of the unsorted array
	}
}

// Function uses binary search method to look for the name that was inputed by the user
int searchArray(string name[], int size, string nameSearch)
{
	int first = 0,							// First element of the array
		last = size - 1,					// Last element of the array
		middle,								// Will hold middle position of the array search
		position = -1;						// Position of search value
	bool found = false;						// Bool value for executing while loop

	while (!found && first <= last)			// While found is not false and first element is less than or equal to last - run this while loop
	{
		middle = (first + last) / 2; 		// Calculation to find middle of search
		if (name[middle] == nameSearch)		// If value is found in the middle element run this if statement
		{
			found = true;					// Assign true to bool found variable
			position = middle;				// Assign middle as the new position variable
		}
		else if (name[middle] > nameSearch) // If value is in lower half of the search
			last = middle - 1;				// Last is now one element below the previous middle
		else
			first = middle + 1;			// If value is in upper half of the search - First is not one element above the previous middle
	}
	return position;	
}
