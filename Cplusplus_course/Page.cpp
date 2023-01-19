#include "Page.h"




Page::Page(const string& name) : Entity(name)
{
}


const Page& Page::operator=(const Page& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->followersList = other.followersList;
		this->statusList = other.statusList;
	}
	return *this;
}

Page& Page::operator+=(Member& fan)
{
	this->addFollow(&fan);
	return *this;
}


bool Page::operator>(const Member& other)
{
	if (this->getFollowersList().size() > other.getFriendsSize())
		return true;
	return false;
}

bool Page::operator>(const Page& other)
{
	if (this->getFollowersList().size() > other.getFollowersList().size())
		return true;
	return false;
}


bool Page::operator<(const Member& other)
{
	if (this->getFollowersList().size() < other.getFriendsSize())
		return true;
	return false;
}

bool Page::operator<(const Page& other)
{
	if (this->getFollowersList().size() < other.getFollowersList().size())
		return true;
	return false;
}

void Page::writeToFile(ostream& os) const
{
	os << endl;
}










