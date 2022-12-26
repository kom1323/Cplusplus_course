#ifndef _STATUS_H
#define _STATUS_H

#include "Types.h"



class Status
{
private:
	string currStatus;
	Date date;
public:
	Status() = default;
	Status(const string& status);
	const string& getCurrStatus() const;
	Date getDate() const;
};
#endif // !_STATUS