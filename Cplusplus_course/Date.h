#ifndef _Date
#define _Date

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