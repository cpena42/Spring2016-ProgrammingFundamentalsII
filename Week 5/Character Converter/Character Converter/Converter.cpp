//Seperate .cpp file containing function definitions

#include "Converter.h"	//Required to access Converter class in the header file

//Default Constructor - Strings are automatically assign " " 
Converter::Converter()
{
}

//Constructor - Variables can be sent through this function from main.cpp
Converter::Converter(string line)
{
	newLine = line;  //Assigns the line variable to newLine member
}

//Accessor Function Definition
string Converter::getLine()
{
	return newLine;		//Returns the value of newLine member
}

//Mutator Function Definition
void Converter::setLine(string line)	
{
	newLine = line;		//Assign the new variable line to the member newLine
}

//Function to convert string character to all uppercase
void Converter::uppercase()		//Function Definition for uppercase
{
	for(int i = 0; i < newLine.length(); i++)		//Loop to cycle through each letter/space in the string
	{
		newLine[i] = toupper(newLine[i]);			//Apply toupper to each letter (capitalizing it)
	}
}

//Function to convert the first letter of each word to an uppercase
void Converter::properWords()    //Function Definition for properWords
{
	newLine[0] = toupper(newLine[0]);				//Change the first letter of the string to an uppercase

	for(int i = 0; i < newLine.length(); i++)		//Loop to cycle through each letter/space in the string
	{
		if(newLine[i] == ' ')						//If a space is detected run this if statement
		{
				i++;								//Choose the letter after the space
				newLine[i] = toupper(newLine[i]);	//Uppercase the letter
		}
	}
}

//Deconstructor Function Definition
Converter::~Converter()
{
}
