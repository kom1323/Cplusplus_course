#ifndef _STATUS_H
#define _STATUS_H

#include "Types.h"
#include "Date.h"

class Status
{

private:

	char* currStatus;
	Date date;

public:
	Status();
	const char* getCurrStatus();
	Date getDate();


	bool setCurrStatus(const char* statusText);
	bool setDate(Date& d);





};



#endif // !_STATUS
