#ifndef _Date_H
#define _Date_H
#include "Types.h"

constexpr int DATE_LENGTH = 30;


class Date 
{
private:
	char mDate[DATE_LENGTH];

public:
	Date();
	Date(const char* birthDayDate);
	const char* getmDate() const;
};

#endif //_Date