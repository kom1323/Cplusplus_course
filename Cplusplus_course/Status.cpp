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

void Status::readFromFile(istream& os)
{
}

ostream& operator<<(ostream& os, const Status& status)
{
	if (typeid(status) == typeid(Status))
		os << "Status" << endl;
	else
		os << "Media Status" << endl;
	os << status.currStatus<<endl;
	os << status.date;
	status.writeToFile(os);
	return os;
}

istream& operator>>(istream& os, Status& status)
{
	getline(os, status.currStatus);
	os >> status.date;
	status.readFromFile(os);
	return os;
}
