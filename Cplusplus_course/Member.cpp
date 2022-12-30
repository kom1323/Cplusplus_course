#include "Member.h"
using namespace std;






Member::Member(const string& newName, Date date) : name(newName), birthday(date)
{
	

}

const string Member::getName() const
{
	return this->name;
}

const Member& Member::operator=(const Member& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->birthday = other.birthday;
		this->friendsList = other.friendsList;
		this->favPagesList = other.favPagesList;
		this->statusList = other.statusList;
	}
	return *this;
}

const Member& Member::operator+=(Member& other)
{
	this->addFriend(&other);
	return *this;
}

bool Member::operator>(const Member& other)
{
	if (this->friendsList.size() > other.friendsList.size())
		return true;
	return false;
}

bool Member::operator>(const Page& other)
{
	if (this->friendsList.size() > other.getFanListSize())
		return true;
	return false;
}


bool Member::operator<(const Member& other)
{
	if (this->friendsList.size() < other.friendsList.size())
		return true;
	return false;
}

bool Member::operator<(const Page& other)
{
	if (this->friendsList.size() < other.getFanListSize())
		return true;
	return false;
}

Date Member::getBirthday() const
{
	return this->birthday;
}

const vector<Status>& Member::getStatusList() const
{
	return this->statusList;
}



const vector<Member*>& Member::getFriendsList() const
{
	return this->friendsList;
}

bool Member::addFriend(Member* newAmigo)
{
	if (isMember(newAmigo)) //to stop loop between both friends
		return false;
	else
	{
		this->friendsList.push_back(newAmigo);
		newAmigo->addFriend(this); //add this friend to his friend's friends list
		return true;
	}
}

//function that unconnects one friends from another
bool Member::removeFriend(const string& friendName)
{
	vector<Member*>::iterator mem = this->friendsList.begin();

	for (mem; mem != friendsList.end(); mem++)
	{
		if ((*mem)->getName() == friendName)
		{
			Member* tmp = *mem;
			*mem = nullptr;
			this->friendsList.erase(mem);
			tmp->removeFriend(this->name);
			return true;
		}
	}
	return false;
}

bool Member::addFavPage(Page* newPage)
{
	if (isFanPage(newPage))
		return false;

	this->favPagesList.push_back(newPage);
	newPage->addFan(this);
	return true;
}

bool Member::removeFavPage(const string pageName)
{
	vector<Page*>::iterator page = this->favPagesList.begin();

	for (page; page != favPagesList.end(); page++)
	{
		if ((*page)->getName() == pageName)
		{
			Page* temp = *page;
			*page = nullptr;
			this->favPagesList.erase(page);
			return true;
		}
	}
	return false;
}

bool Member::addStatus()
{
	this->statusList.push_back(Status());
	return true;
}

bool Member::addStatus(const string& status)
{
	this->statusList.push_back(Status(status));
	return true;
}


void Member::printAllFriends()
{
	cout << "Friends of the user: " << this->name << endl;
	cout << "-------------------------" << endl;
	if (this->friendsList.size() == 0)
	{
		cout << "This user has no friends" << endl;
		return;
	}
	for (auto& amigo : this->friendsList)
	{
		cout << amigo->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

void Member::printAllFavPages()
{
	cout << "Favorite pages of the user: " << this->name << endl;
	cout << "-------------------------" << endl;
	if (this->favPagesList.size() == 0)
	{
		cout << "This user has no fav pages" << endl;
		return;
	}
	for (auto& page : this->favPagesList)
	{
		cout << page->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

void Member::printAllStatus()
{
	cout << "Statuses of the user: " << this->name << endl;
	cout << "-------------------------" << endl;
	int count = 0;
	if (this->statusList.size() == 0)
	{
		cout << "This user has no statuses" << endl;
		return;
	}
	for (auto& status : this->statusList)
	{
		cout << count + 1 << ". " << status.getCurrStatus() << endl << "Date: " << status.getDate().getmDate() << endl;
		count++;
	}
	cout << "-------------------------" << endl;
}

void Member::printLatestStatusesOfFriends()
{
	int statusSize, count;
	cout << "The statuses of " << this->name << "'s friends: " << endl;;
	cout << "-------------------------" << endl;
	for (auto& amigo : this->friendsList)
	{
		if (amigo->statusList.size() == 0)
			cout << amigo->name << " doesn't have statuses yet" << endl;
		else
		{
			statusSize = min((int)amigo->statusList.size(), 10);
			cout << "Statuses of " << amigo->name << ": " << endl;
			count = 1;
			for (auto& status : amigo->statusList)
			{
				cout << count << ". " << status.getCurrStatus() << endl << status.getDate().getmDate() << endl << endl;
				count++;
			}
		}
		cout << "-------------------------" << endl;
	}

}

//throws if users are already friends
void Member::checkFriendship(const string& name) throw(AlreadyFriendsException)
{
	if (this->isMember(name))
		throw AlreadyFriendsException();
}

//throws if users are not friends
void Member::checkNotFriendship(const string& name) throw(NotFriendsException)
{
	if (!this->isMember(name))
		throw NotFriendsException();
}

//throw if the name belongs to this user
void Member::isMe(const string& name) throw(SelfException)
{
	if (this->name == name)
		throw SelfException();
}

//function that returns true if the users are friends
bool Member::isMember(const Member* newAmigo)
{
	return isMember(newAmigo->name);
}

//function that returns true if the users are friends
bool Member::isMember(const string& amigoName)
{
	for (auto& amigo : this->friendsList)
	{
		if (amigoName == amigo->getName())
			return true;
	}
	return false;
}

//function that returns true if the page is on this user's fav pages
bool Member::isFanPage(const Page* newPage)
{
	for (auto& page : this->favPagesList)
	{
		if (page == newPage)
			return true;
	}
	return false;
}

//function that returns true if the page is on this user's fav pages
bool Member::isFanPage(const string& pageName)
{
	for (auto& page : this->favPagesList)
	{
		if (pageName == page->getName())
			return true;
	}
	return false;
}
