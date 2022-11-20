#include <iostream>
using namespace std;
#include "Date.h"

bool Date::setDay(int newDay)
{
	day = newDay;
	return true;
}

bool Date::setMonth(int newMonth)
{
	month = newMonth;
	return true;
}

bool Date::setYear(int newYear)
{
	year = newYear;
	return true;
}
