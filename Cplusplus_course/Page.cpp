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

