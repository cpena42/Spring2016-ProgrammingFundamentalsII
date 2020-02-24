#include<iostream>
#include<string>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date{
private:
	int newMonth;
	int newYear;
	int newDay;

public:
	//Default Constructor
	Date();

	//Overloaded Constructor
	Date(int, int, int);

	//Accessor Functions
	int getMonth() const;
	int getYear() const;
	int getDay() const;
	string getMonthName();
	
	//Display Functions
	void format1();
	void format2();
	void format3();

	//Destructor
	~Date();

};

#endif