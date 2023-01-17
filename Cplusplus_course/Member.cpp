#include "Member.h"
using namespace std;






Member::Member(const string& newName, Date date) : Entity(newName), birthday(date), friendsSize(0),favPagesSize(0)
{

}


const Member& Member::operator=(const Member& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->birthday = other.birthday;
		this->followersList = other.followersList;
		this->statusList = other.statusList;
	}
	return *this;
}

const Member& Member::operator+=(Member& other)
{
	this->addFollow(&other);
	return *this;
}

bool Member::operator>(const Member& other)
{
	if (this->friendsSize > other.friendsSize)
		return true;
	return false;
}

bool Member::operator>(const Page& other)
{
	if (this->friendsSize > other.getFollowersList().size())
		return true;
	return false;
}


bool Member::operator<(const Member& other)
{
	if (this->friendsSize < other.friendsSize)
		return true;
	return false;
}

bool Member::operator<(const Page& other)
{
	if (this->friendsSize < other.getFollowersList().size())
		return true;
	return false;
}

Date Member::getBirthday() const
{
	return this->birthday;
}

int Member::getFriendsSize() const
{
	return this->friendsSize;
}

int Member::getFavPagesSize() const
{
	return this->favPagesSize;
}

void Member::increaseFriendsSize(int num)
{
	(this->friendsSize)+=num;
}

void Member::increaseFavPagesSize(int num)
{
	(this->favPagesSize)+=num;
}


//bool Member::addFriend(Member* newAmigo)
//{
//	if (isMember(newAmigo)) //to stop loop between both friends
//		return false;
//	else
//	{
//		this->friendsList.push_back(newAmigo);
//		newAmigo->addFriend(this); //add this friend to his friend's friends list
//		return true;
//	}
//}

//function that unconnects one friends from another
//bool Member::removeFriend(const string& friendName)
//{
//	vector<Member*>::iterator mem = this->friendsList.begin();
//
//	for (mem; mem != friendsList.end(); mem++)
//	{
//		if ((*mem)->getName() == friendName)
//		{
//			Member* tmp = *mem;
//			*mem = nullptr;
//			this->friendsList.erase(mem);
//			tmp->removeFriend(this->name);
//			return true;
//		}
//	}
//	return false;
//}

//bool Member::addFavPage(Page* newPage)
//{
//	if (isFanPage(newPage))
//		return false;
//
//	this->favPagesList.push_back(newPage);
//	newPage->addFan(this);
//	return true;
//}

//bool Member::removeFavPage(const string pageName)
//{
//	vector<Page*>::iterator page = this->favPagesList.begin();
//
//	for (page; page != favPagesList.end(); page++)
//	{
//		if ((*page)->getName() == pageName)
//		{
//			Page* temp = *page;
//			*page = nullptr;
//			this->favPagesList.erase(page);
//			return true;
//		}
//	}
//	return false;
//}


void Member::printAllFavPages()
{
	bool hasPages = false;
	cout << "Favorite pages of the user: " << this->name << endl;
	cout << "-------------------------" << endl;
	for (auto& page : this->followersList)
	{
		if (typeid(*page) == typeid(Page))
		{
			hasPages = true;
			cout << page->getName() << endl;
		}
	}
	if (!hasPages)
		cout << "This user has no favorite pages" << endl;
	cout << "-------------------------" << endl;
}

void Member::printAllMyFriends()
{
	bool hasFriends = false;
	cout << "Friends of the user: " << this->name << endl;
	cout << "-------------------------" << endl;
	for (auto& entity : this->followersList)
	{
		if (typeid(*entity) == typeid(Member))
		{
			hasFriends = true;
			cout << entity->getName() << endl;
		}
	}
	if (!hasFriends)
		cout << "This user has no friends" << endl;
	cout << "-------------------------" << endl;
}




void Member::printLatestStatusesOfFriends()
{
	int statusSize, count;
	cout << "The statuses of " << this->name << "'s friends: " << endl;;
	cout << "-------------------------" << endl;
	for (auto& amigo : this->followersList)
	{
		if (typeid(*amigo) == typeid(Member))
		{
			Member* memPtr = (Member*)amigo;
			if (memPtr->statusList.size() == 0)
				cout << memPtr->name << " doesn't have statuses yet" << endl;
			else
			{
				statusSize = min((int)memPtr->statusList.size(), 10);
				cout << "Statuses of " << memPtr->name << ": " << endl;
				count = 1;
				for (auto& status : memPtr->statusList)
				{
					cout << count << ". " << status->getCurrStatus() << endl << status->getDate().getmDate() << endl << endl;
					count++;
				}
			}
		}

		cout << "-------------------------" << endl;
	}

}







//function that returns true if the page is on this user's fav pages
//bool Member::isFanPage(const Page* newPage)
//{
//	for (auto& page : this->favPagesList)
//	{
//		if (page == newPage)
//			return true;
//	}
//	return false;
//}

//function that returns true if the page is on this user's fav pages
//bool Member::isFanPage(const string& pageName)
//{
//	for (auto& page : this->favPagesList)
//	{
//		if (pageName == page->getName())
//			return true;
//	
//	return false;
//}
