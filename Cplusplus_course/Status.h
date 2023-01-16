#ifndef _STATUS_H
#define _STATUS_H

#pragma warning(disable : 4996)

#include "Types.h"
#include "Date.h"

class Status
{
protected:
	string currStatus;
	Date date;
public:
	Status() = default;
	Status(const string& status);
	
	bool operator==(const Status& other) const;
	bool operator!=(const Status& other) const;


	const string& getCurrStatus() const;
	Date getDate() const;

};
#endif // !_STATUS