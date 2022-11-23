#ifndef _Date_H
#define _Date_H
#include "Types.h"

const int DATE_LENGTH = 11;
const int TIME_LENGTH = 11;

class Date 
{

private:

	//add time variable with "ctime" library
	
	const char date[DATE_LENGTH];
	const char time[TIME_LENGTH];

public:
	
	
	Date();
	Date(const char* birthDayDate);
	const char* getDate() const;
	const char* getTime() const;

};

#endif //_Date