#ifndef _Date_H
#define _Date_H


#include "Types.h"

class Date
{
private:
	string mDate;

public:
	Date();
	Date(const string& birthDayDate);
	const string& getmDate() const;
	friend ostream& operator<<(ostream& os, const Date& date);
	friend istream& operator>>(istream& os, Date& d);
};

#endif //_Date