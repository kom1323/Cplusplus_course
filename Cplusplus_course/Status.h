#ifndef _STATUS_H
#define _STATUS_H

#include "Types.h"
#include "Date.h"

class Status
{

private:

	const char* currStatus;
	const Date date;

public:
	Status(const char* currStatus, const Date date);
	~Status();
	
	const char* getCurrStatus() const;
	Date getDate() const;

};



#endif // !_STATUS
