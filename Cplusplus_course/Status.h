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
	virtual ~Status() = default;
	
	bool operator==(const Status& other) const;
	bool operator!=(const Status& other) const;


	const string& getCurrStatus() const;
	Date getDate() const;
	virtual void writeToFile(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Status& status);

};
#endif // !_STATUS