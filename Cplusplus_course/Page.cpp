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

const Page& Page::operator+=(Member& fan)
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









//void Page::printAllFans()
//{
//	cout << "Fans of page: " << this->name << endl;
//	cout << "-------------------------" << endl;
//	if (this->membersList.size() == 0)
//	{
//		cout << "This page has no fans" << endl;
//		return;
//	}
//	for (auto& fan : this->membersList)
//	{
//		cout << fan->getName() << endl;
//	}
//	cout << "-------------------------" << endl;
//}

