#include <iostream>
#include <ctime>
#include "Date.h"
using namespace std;

//No arg constructor which sets date valeus to current date, no inputs, no outputs
Date::Date()
{
	time_t t = time(0);
	tm * now = localtime(&t);
	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	date = now->tm_mday;
}

//Constructor which finds the date values given the secodns since unix epoch, input of seconds, no output
Date::Date(int secondsSince)
{
	time_t t = secondsSince;
	tm * now = localtime(&t);
	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	date = now->tm_mday;
}

//Constructor function for entered date values, input of year, month, and day, no ouput
Date::Date(int yr, int mnth, int day)
{
	year = yr;
	month = mnth;
	date = day;
}

//Getter function for year, no input, output of year
int Date::getYear()
{
	return year;
}

//Getter function for month, no input, output of month
int Date::getMonth()
{
	return month;
}

//Getter function for date, no input, output of date
int Date::getDay()
{
	return date;
}

//Function for setting the date given the time elapsed since last entered date in seconds
void Date::setDate(int elapseTime)
{
	int yearsSince = year - 1970;
	int daysSince = 0;
	//Findign the number of days from months using a array adn a for loop
	int daysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 0; i < month; i++)
	{
		daysSince = daysSince + (1 * daysInMonths[i]);
	}
	//Taking into account leap years by cycling through the number of years since 1970, and counting leap years accordingly
	int numberLeapDays = 0;
	for (int j = 1970; j < year; j++)
	{
		if (j% 4 == 0)
		{
			numberLeapDays++;
			if (j%4 == 0 && j%100 == 0 && j%400 != 0)
			{
				//For each year which is divisible by 4, 100, and not four hunrdered, take a way a leap year
				numberLeapDays--;
			}
		}
		
	}
	//Calculating total number of days
	daysSince = daysSince + numberLeapDays + date;
	//Calculating total number of seconds
	int secondsSince = (31536000 * yearsSince) + (60 * 60 * 24 * daysSince);
	int combinedSecs = secondsSince + elapseTime;
	//Finding date, month, and year values given new number of seconds elapsed since unix epoch
	time_t t = combinedSecs;
	tm * now = localtime(&t);
	year = now->tm_year + 1900;
	month = now->tm_mon + 1;
	date = now->tm_mday;
}