/* Binary String Search
Modify the binarySearch function presented in this chapter so it searches an
array of strings instead of an array of ints.  Test the function with a driver
program.  Use program 9-8 as a skeleton to complete. (The array must be sorted
before the binary search will work.)

Programmer: Cesar Pena
Date: March 6, 2016
*/
// Program 9.8 - used as a skeleton
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CodeMaker
{
private:
	int size;
	char codeChar[94];		//Array to hold the substitutions
							//for the 94 printable ASCII chars
	int findIt(char[], int, char);

public:
	CodeMaker();
	string encode(string);
	string decode(string);
};

// Member function implementation section

/********************************************************
 *		CodeMaker::CodeMaker - the Constructor			*
 * This method reads the substitution characters in     *
 * from a file and stores them in the codeChar array.   *
 * It also sets member variable size.                   *
 ********************************************************/
CodeMaker::CodeMaker()
{
	size = 94;
	ifstream inFile;
	inFile.open("code.dat");			// Open the file

	for (int ascii = 32; ascii < 127; ascii++)  // Read in data
		inFile >> codeChar[ascii - 32];
	inFile.close();								// Close the file
}

/*********************************************************
 *					CodeMaker::encode                    *
 * This method encodes and returns a clear text string.  *
 *********************************************************/
string CodeMaker::encode(string s)
{
	int ascii;
	char newChar;
	string newString = "";  //Will hold the encoded string

	for (unsigned pos = 0; pos < s.length(); pos++)
	{
		// Get the original character's ASCII code
		ascii = s[pos];

		// Get the new replacement character
		newChar = codeChar[ascii - 32];

		// Concatenate it onto the end of the new string
		newString += newChar;
	}
	return newString;
}

/*****************************************************
 *                    CodeMaker::decode			     *
 * This method converts an encoded string back to    *
 * clear text and returns it.						 *
 *****************************************************/
string CodeMaker::decode(string s)
{
	int index;
	char nextChar;
	char originalChar;
	string decodedText = "";

	for (unsigned pos = 0; pos < s.length(); pos++)
	{
		// Get the next character fro mthe string
		nextChar = s[pos];

		// Call findIt to find it in the array and return its index
		index = findIt(codeChar, size, nextChar);

		// Get the original character by computing its ASCII code
		originalChar = index + 32;

		// Concatenate this character onto the end of the
		// decoded text string being constructed
		decodedText += originalChar;
	}
	return decodedText;
}

/***********************************************
 *              CodeMaker::findIt			   *
 * This method performs a linear search on     *
 * a character array looking for value.		   *
 ***********************************************/
int CodeMaker::findIt (char A[], int size, char value)
{
	int index = 0;
	int position = -1;
	bool found = false;

	while(index < size && !found)
	{
		if (A[index] == value)		// If the value is found
		{  found = true;			// Set the flag
		   position = index;		// Record the value's subscript
		}
		index++;					// Go to the next element
	}
	return position;				// Return the position, or -1
}

/*******************************************************
 *                     main                            *
 * The client "program" that uses the CodeMaker class. *
 *******************************************************/
int main()
{
	string originalText, secretCode, finalText;
	CodeMaker myCoder;

	// Get text from the user
	cout << "Enter the mesage to be encoded.\n";
	getline(cin, originalText);

	//Send the text to be encoded and display the result
	secretCode = myCoder.encode(originalText);
	cout << "\nHere is the encoded message\n" << secretCode << endl;

	// Send the encoded text back to be decoded
	// and display the result
	finalText = myCoder.decode(secretCode);
	cout << "\nHere is the decoded message\n" << finalText << endl;

	system("pause");
	return 0;
}

