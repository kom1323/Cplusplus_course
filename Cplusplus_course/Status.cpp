#include "Status.h"
using namespace std;




Status::Status(const string& status) : currStatus(status), date(Date())
{
}

bool Status::operator==(const Status& other) const
{
	if (this->currStatus == other.currStatus)
		return true;
	return false;
}

bool Status::operator!=(const Status& other) const
{
	return !(*this == other);
}



const string& Status::getCurrStatus() const
{
	return this->currStatus;
}

Date Status::getDate() const
{
	return this->date;
}

void Status::writeToFile(ostream& os) const
{
}

ostream& operator<<(ostream& os, const Status& status)
{
	if (typeid(status) == typeid(Status))
		os << "Media Status" << endl;
	else
		os << "Status" << endl;
	os << status.currStatus<<endl;
	os << status.date;
	status.writeToFile(os);
	return os;
}