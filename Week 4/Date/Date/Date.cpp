//Function Definitions

#include "Date.h"

Date::Date()
{
	newMonth = 1;
	newDay = 1;
	newYear = 2001;
}

Date::Date(int month, int year, int day)
{
	if(month >= 1 && month <= 12)
	{
		newMonth = month;

		if(year > 0 && year <= 99)
		{
			newYear = year;

			if(day >= 1 && day <= 31)
			{
				if(newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12)
					newDay = day;
				
				else if(newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11)
				{
					if(day >= 1 && day <= 30)
						newDay = day;
					else
					{
						cout << "Invalid input for day, date has been set to 1/1/2001 (January 1, 2001) \n";
						newMonth = 1;
						newYear = 1;
						newDay = 1;
					}
				}
				else
				{
					if(day >= 1 && day <= 29)
					{
						if(day == 29)
						{
							if(year % 4 == 0)
							{
								if(year % 100 == 0)
								{
									if(year % 400 == 0)
										newDay = day;
									else
									{
										cout << "Invalid input for day, year is not a leap year, \n";
										cout << "date has been set to 1/1/2001 (January 1, 2001) \n";
										newMonth = 1;
										newYear = 1;
										newDay = 1;
									}
								}
								else
									newDay = day;
							}
							else
							{
								cout << "Invalid input for day, year is not a leap year, \n";
								cout << "date has been set to 1/1/2001 (January 1, 2001) \n";
								newMonth = 1;
								newYear = 1;
								newDay = 1;
							}
						}
						else
							newDay = day;
					}
					else
					{
						cout << "Invalid input for day, date has been set to 1/1/2001 (January 1, 2001) \n";
						newMonth = 1;
						newYear = 1;
						newDay = 1;
					}
				}
			}
			else 
			{
				cout << "Invalid input for day, date has been set to 1/1/2001 (January 1, 2001) \n";
				newMonth = 1;
				newYear = 1;
				newDay = 1;
			}
		}
		else
		{
			cout << "Invalid input for year, date has been set to 1/1/2001 (January 1, 2001) \n";
			newMonth = 1;
			newYear = 1;
			newDay = 1;
		}
	}
	else
	{
		cout << "Invalid input month, date has been set to 1/1/2001 (January 1, 2001) \n";
		newMonth = 1;
		newYear = 1;
		newDay = 1;
	}
}

int Date::getMonth() const
{
	return newMonth;
}

int Date::getYear() const
{
	return newYear;
}

int Date::getDay() const
{
	return newDay;
}

string Date::getMonthName()
{
	string monthName;

	if(newMonth == 1)
		monthName = "January";
	else if(newMonth == 2)
		monthName = "February";
	else if(newMonth == 3)
		monthName = "March";
	else if(newMonth == 4)
		monthName = "April";
	else if(newMonth == 5)
		monthName = "May";
	else if(newMonth == 6)
		monthName = "June";
	else if(newMonth == 7)
		monthName = "July";
	else if(newMonth == 8)
		monthName = "August";
	else if(newMonth == 9)
		monthName = "September";
	else if(newMonth == 10)
		monthName = "October";
	else if(newMonth == 11)
		monthName = "November";
	else
		monthName = "December";

	return monthName;
}

//Display date format 3/15/13
void Date::format1()
{
	cout << Date::getMonth() << "/" << Date::getDay() << "/";
	if(Date::getYear() <= 9)
		cout << "0" << Date::getYear() << endl;
	else
		cout << Date::getYear() << endl;
}

//Display date format March 15, 2013
void Date::format2()
{
	cout << Date::getMonthName() << " " << Date::getDay() << ", " << Date::getYear() + 2000 << endl;
}

//Display date format 15 March 2013
void Date::format3()
{
	cout << Date::getDay() << " " << Date::getMonthName() << " " << Date::getYear() + 2000 << endl;
}

Date::~Date()
{
}