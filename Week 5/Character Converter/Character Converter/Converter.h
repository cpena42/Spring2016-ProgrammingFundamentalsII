// Header File - Includes CharConverter class - Function Declarations
#include <iostream>
#include <string>
#include <cctype> //Needed for toupper

using namespace std;

#ifndef CONVERTER_H	 //Prevents the header file from accidently being included more than once - if not define
#define CONVERTER_H  //If CONVERTER_H is not defined this line will define it

class Converter{
private:
	string newLine;

public:
	//Default Constructor Function
	Converter();

	//Constructor Function
	Converter(string);

	//Accessor Function
	string getLine();
		//Display newLine member

	//Mutator Function - Not necessary to make program work but might be useful for future alterations
	void setLine(string);
		//Change string stored in newLine member

	//uppercase & properWords Member Functions
	void uppercase();		//Converts all letters in string to uppercase
	void properWords();		//Converts the first letter of each word to uppercase

	//Deconstructor
	~Converter();
};

#endif //End of defined CONVERTER_H