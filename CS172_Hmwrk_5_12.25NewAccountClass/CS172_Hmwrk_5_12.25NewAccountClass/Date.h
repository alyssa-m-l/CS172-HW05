#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
	//Variables for required elements of the date
	int year;
	int month;
	int date;
public:
	//No arg constructor for the date, sets date to current date
	Date();
	//Date constructor which sets the date to the date given by the number of seconds since unix epoch
	Date(int secondsSince);
	//Date consctructor which sets the date given explicit date, month, and year values
	Date(int yr, int mnth, int day);
	//Getter function for year
	int getYear();
	//Getter function for month
	int getMonth();
	//Getter function for day
	int getDay();
	//Function to reset date given time elapsed since last date in seconds
	void setDate(int elapseTime);
};

#endif
