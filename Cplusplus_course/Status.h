#ifndef _STATUS_H
#define _STATUS_H

#pragma warning(disable : 4996)

#include "Types.h"
#include "Date.h"

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