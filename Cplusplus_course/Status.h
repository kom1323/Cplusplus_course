#ifndef _STATUS_H
#define _STATUS_H

#include "Types.h"
#include "Date.h"
char* readInputString();


class Status
{

private:

	const char* currStatus;
	Date date;

public:
	Status();
	~Status();
	
	const char* getCurrStatus() const;
	Date getDate() const;

};



#endif // !_STATUS
