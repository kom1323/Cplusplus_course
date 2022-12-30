#include "Page.h"






Page::Page(const string& name) : name(name)
{
}


const Page& Page::operator=(const Page& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->membersList = other.membersList;
		this->statusList = other.statusList;
	}
	return *this;
}

const Page& Page::operator+=(Member& fan)
{
	this->addFan(&fan);
	return *this;
}


bool Page::operator>(const Member& other)
{
	if (this->membersList.size() > other.getFriendsList().size())
		return true;
	return false;
}

bool Page::operator>(const Page& other)
{
	if (this->membersList.size() > other.membersList.size())
		return true;
	return false;
}


bool Page::operator<(const Member& other)
{
	if (this->membersList.size() < other.getFriendsList().size())
		return true;
	return false;
}

bool Page::operator<(const Page& other)
{
	if (this->membersList.size() < other.membersList.size())
		return true;
	return false;
}

//throws exception if the user is already a fan of this page
void Page::checkFanship(const string& name) throw(AlreadyFanException)
{
	if (isFan(name))
		throw AlreadyFanException();
}

//throws exception if the user is not a fan of this page
void Page::checkNotFanship(const string& name) throw(NotFanException)
{
	if (!isFan(name))
		throw NotFanException();
}

int Page::getFanListSize() const
{
	return (int)this->membersList.size();
}

const string& Page::getName() const
{
	return this->name;
}

bool Page::addFan(Member* newAmigo)
{
	//check if member is alread a fan of page
	if (this->isFan(newAmigo))
	{
		return false;
	}

	//add the new member and update the member's favorite pages
	this->membersList.push_back(newAmigo);
	newAmigo->addFavPage(this);

	return true;
}

bool Page::removeFan(const string friendName)
{
	vector<Member*>::iterator itr = this->membersList.begin();
	for (itr; itr != this->membersList.end(); itr++)
	{
		//match by name
		if ((*itr)->getName() == friendName)
		{
			Member* tmp = *itr;
			*itr = nullptr;
			this->membersList.erase(itr);
			tmp->removeFavPage((this->name));
			return true;

		}

	}

	return false;
}

bool Page::addStatus()
{
	//add the new status 
	this->statusList.push_back(Status());
	return true;
}
bool Page::addStatus(const string status)
{

	this->statusList.push_back(Status(status));
	return true;

}


bool Page::isFan(Member* member) const
{
	for (auto& fan : this->membersList)
	{

		if (fan == member) {

			return true;
		}
	}
	return false;
}

bool Page::isFan(const string name) const
{
	for (auto& fan : this->membersList)
	{

		if (fan->getName() == name) {

			return true;
		}
	}
	return false;
}

void Page::printAllFans()
{
	cout << "Fans of page: " << this->name << endl;
	cout << "-------------------------" << endl;
	if (this->membersList.size() == 0)
	{
		cout << "This page has no fans" << endl;
		return;
	}
	for (auto& fan : this->membersList)
	{
		cout << fan->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

void Page::printAllStatus()
{

	cout << "Statuses in page: " << this->name << endl;
	cout << "-------------------------" << endl;
	int count = 0;
	if (this->statusList.size() == 0)
	{
		cout << "This page has no statuses" << endl;
		return;
	}
	for (auto& status : this->statusList)
	{
		cout << count + 1 << ". " << status.getCurrStatus() << endl << "Date: " << status.getDate().getmDate() << endl;
		count++;
	}

	cout << "-------------------------" << endl;

}
