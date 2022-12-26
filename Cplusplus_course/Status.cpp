#include "Status.h"

Status::Status(const string& status) : currStatus(status), date(Date())
{
}



const string& Status::getCurrStatus() const
{
	return this->currStatus;
}

Date Status::getDate() const
{
	return this->date;
}