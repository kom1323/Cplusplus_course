#include "Member.h"



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

Date Member::getBirthday() const
{
	return this->birthday;
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

bool Member::removeFriend(const string& friendName)
{
	vector<Member*>::iterator mem = this->friendsList.begin();

	for (mem; mem != friendsList.end(); mem++)
	{
		if ((*mem)->getName() == friendName)
		{
			this->friendsList.erase(mem);
			(*mem)->removeFriend((this->name));
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
			this->favPagesList.erase(page);
			(*page)->removeFan((this->name));
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

bool Member::isMember(const Member* newAmigo)
{
	return isMember(newAmigo->name);
}

bool Member::isMember(const string& amigoName)
{
	int i;
	for (auto& amigo : this->friendsList)
	{
		if (amigoName == amigo->getName())
			return true;
	}
	return false;
}

bool Member::isFanPage(const Page* newPage)
{
	int i;
	for (auto& page : this->favPagesList)
	{
		if (page == newPage)
			return true;
	}
	return false;
}

bool Member::isFanPage(const string& pageName)
{
	int i;
	for (auto& page : this->favPagesList)
	{
		if (pageName == page->getName())
			return true;
	}
	return false;
}
