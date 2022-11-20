#ifndef _Date_H
#define _Date_H
#include "Types.h"

class Date {

private:

	//add time variable with "ctime" library
	int day, month, year;

public:
	bool setDay(int newDay);
	bool setMonth(int newMonth);
	bool setYear(int newYear);

};

#endif //_Date