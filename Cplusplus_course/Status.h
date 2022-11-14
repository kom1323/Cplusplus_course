#ifndef _STATUS
#define _STATUS

#include "Date.h"



class Status
{

private:

	char* currStatus;
	Date date;

public:

	const char* getCurrStatus();
	Date getDate();


	bool setCurrStatus(const char* statusText);
	bool setDate(Date& d);





};



#endif // !_STATUS
