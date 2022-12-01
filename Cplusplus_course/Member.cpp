#include <iostream>
using namespace std;
#include "Member.h"
#include <ctime>
#include <string.h>
#pragma warning(disable : 4996)

constexpr int LIST_STARTING_SIZE = 1;
constexpr int STATUS_MAX_SIZE = 50;
constexpr int NOT_FOUND = -1;

Member::Member(const char* newName, Date date) : birthday(date)
{
	char* temp = new char[strlen(newName) + 1];
	strcpy(temp, newName);
	this->name = temp;

	this->friendsList = new Member * [LIST_STARTING_SIZE];
	this->friendsListLogSize = 0;
	this->friendsListPhySize = LIST_STARTING_SIZE;

	this->statusList = new Status * [LIST_STARTING_SIZE];
	this->statusListLogSize = 0;
	this->statusListPhySize = LIST_STARTING_SIZE;

	this->favPagesList = new Page * [LIST_STARTING_SIZE];
	this->pagesListLogSize = 0;
	this->pagesListPhySize = LIST_STARTING_SIZE;
}

Member::~Member()
{
	int i;

	//deleting the member from all the friends lists of his friends
	for (i = 0; i< this->friendsListLogSize; i++)
		this->friendsList[i]->removeFriend(this->name);

	delete[] this->friendsList;

	//deleting the member from all the fans lists of his fav pages
	for (i = 0; i < this->pagesListLogSize; i++)
		this->favPagesList[i]->removeFan(this->name);

	delete[] this->favPagesList;

	//deleting all his statuses
	for (i = 0; i < this->statusListLogSize; i++)
		delete this->statusList[i];

	delete[] this->statusList;

	delete[] this->name;
	
}

const char* Member::getName() const
{
	return this->name;
}

Date Member::getBirthday() const
{
	return this->birthday;
}

int Member::getFriendListLogSize() const
{
	return this->friendsListLogSize;
}

Member** Member::getFriendsList() const
{
	return this->friendsList;
}

bool Member::addFriend(Member* newAmigo)
{
	if (isMember(newAmigo)) //to stop loop between both friends
		return false;
	else
	{
		this->checkFriendsArray(); //check if array is full (if not - double its size)
		(this->friendsList)[this->friendsListLogSize] = newAmigo;
		(this->friendsListLogSize)++;
		newAmigo->addFriend(this); //add this friend to his friend's friends list
		return true;
	}
}

bool Member::removeFriend(const char* friendName)
{
	int friendsLoc;
	friendsLoc = getFriendLocationInArray(friendName);
	//not in array
	if (friendsLoc == NOT_FOUND) 
		return false;
	//if the member exists in his friends list
	else
	{
		Member* memberToDelete = this->friendsList[friendsLoc];
		//if the member's location in the friends list is the last - just delete it
		if (friendsLoc == friendsListLogSize - 1)
			this->friendsList[friendsLoc] = nullptr;
		//if it is not in the edge of the array, switch it with the last and then delete the last
		else
		{
			this->friendsList[friendsLoc] = this->friendsList[friendsListLogSize - 1];
			this->friendsList[friendsListLogSize - 1] = nullptr;
		}
		(this->friendsListLogSize)--;
		memberToDelete->removeFriend(this->name);
	}
	return true;
}

bool Member::addFavPage(Page* newPage)
{
	if (isFanPage(newPage))
		return false;

	this->checkPagesArray();
	this->favPagesList[this->pagesListLogSize] = newPage;
	(this->pagesListLogSize)++;
	newPage->addFan(this);
	return true;
}

bool Member::removeFavPage(const char* pageName)
{
	int pageLoc;
	pageLoc = getPageLocationInArray(pageName);
	//not in array
	if (pageLoc == NOT_FOUND) 
		return false;
	//if the page exists in his pages list
	else
	{
		Page* pageToDelete = this->favPagesList[pageLoc];
		//if the page's location in the pages list is the last - just delete it
		if (pageLoc == pagesListLogSize - 1)
			this->favPagesList[pageLoc] = nullptr;
		//if it is not in the edge of the array, switch it with the last and then delete the last
		else
		{
			this->favPagesList[pagesListLogSize] = this->favPagesList[pagesListLogSize - 1];
			this->favPagesList[pagesListLogSize - 1] = nullptr;
		}
		(this->pagesListLogSize)--;
		pageToDelete->removeFan(this->name);
	}
	return true;
}

bool Member::addStatus()
{
	Status* newStatus = new Status();
	this->checkStatusArray();
	this->statusList[this->statusListLogSize] = newStatus;
	(this->statusListLogSize)++;
	return true;
}

bool Member::addStatus(const char* status)
{
	Status* newStatus = new Status(status);
	this->checkStatusArray();
	this->statusList[this->statusListLogSize] = newStatus;
	(this->statusListLogSize)++;
	return true;
}


void Member::printAllFriends()
{
	cout << "Friends of the user: " << this->name << endl;
	cout << "-------------------------" << endl;

	for (int i = 0; i < this->friendsListLogSize; i++)
	{
		cout << this->friendsList[i]->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

void Member::printAllFavPages()
{
	cout << "Favorite pages of the user: " << this->name << endl;
	cout << "-------------------------" << endl;

	for (int i = 0; i < this->pagesListLogSize; i++)
	{
		cout << this->favPagesList[i]->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

void Member::printAllStatus()
{
	cout << "Statuses of the user: " << this->name << endl;
	cout << "-------------------------" << endl;

	for (int i = 0; i < this->statusListLogSize; i++)
	{
		cout << i + 1 << ". " << this->statusList[i]->getCurrStatus() << endl <<  "Date: " << this->statusList[i]->getDate().getmDate() << endl;
	}
	cout << "-------------------------" << endl;
}

void Member::printLatestStatusesOfFriends()
{
	int statusSize;
	cout << "The statuses of " << this->name << "'s friends: " << endl;;
	cout << "-------------------------" << endl;
	for (int i = 0; i < this->friendsListLogSize; i++)
	{
		if (this->friendsList[i]->statusListLogSize == 0)
			cout << this->friendsList[i]->name << " doesn't have statuses yet" << endl;
		else
		{
			statusSize = min(this->friendsList[i]->statusListLogSize, 10);
			cout << "Statuses of " << this->friendsList[i]->name << ": " << endl;
			for (int j = 0; j < statusSize; j++)
			{
				cout << j + 1 << ". " << this->friendsList[i]->statusList[j]->getCurrStatus() << endl << this->friendsList[i]->statusList[j]->getDate().getmDate() << endl << endl;
			}
		}
		cout << "-------------------------" << endl;
	}

}

bool Member::isMember(const Member* newAmigo)
{
	int i;
	for (i = 0; i < this->friendsListLogSize; i++)
	{
		if (newAmigo == this->friendsList[i])
			return true;
	}
	return false;
}

bool Member::isFanPage(const Page* newPage)
{
	int i;
	for (i = 0; i < this->pagesListLogSize; i++)
	{
		if (this->favPagesList[i] == newPage)
			return true;
	}
	return false;
}

bool Member::isFanPage(const char* pageName)
{
	int i;
	for (i = 0; i < this->pagesListLogSize; i++)
	{
		if (strcmp(this->favPagesList[i]->getName(), pageName)==0)
			return true;
	}
	return false;
}

void Member::checkFriendsArray()
{
	//if needed a bigger array, creating a new array (with doubled size) and copying all data from old to new
	if (this->friendsListLogSize == this->friendsListPhySize)
	{
		int i, newSize = (this->friendsListPhySize) * 2;
		Member** temp = new Member * [10];
		this->friendsListPhySize = newSize;
		for (i = 0; i < this->friendsListLogSize; i++)
		{
			temp[i] = this->friendsList[i];
		}
		delete[] this->friendsList;
		this->friendsList = temp;
		this->friendsListPhySize = newSize;
	}
}

void Member::checkStatusArray()
{
	//if needed a bigger array, creating a new array (with doubled size) and copying all data from old to new
	if (this->statusListLogSize == this->statusListPhySize)
	{
		Status** temp;
		int i, newSize = (this->statusListPhySize) * 2;
		temp = new Status * [newSize];
		this->statusListPhySize = newSize;
		for (i = 0; i < this->statusListLogSize; i++)
		{
			temp[i] = this->statusList[i];
		}
		delete[] this->statusList;
		this->statusList = temp;
		this->statusListPhySize = newSize;
	}
}

void Member::checkPagesArray()
{
	//if needed a bigger array, creating a new array (with doubled size) and copying all data from old to new
	if (this->pagesListLogSize == this->pagesListPhySize)
	{
		Page** temp;
		int i, newSize = (this->pagesListPhySize) * 2;
		temp = new Page * [newSize];
		this->pagesListPhySize = newSize;
		for (i = 0; i < this->pagesListLogSize; i++)
		{
			temp[i] = this->favPagesList[i];
		}
		delete[] this->favPagesList;
		this->favPagesList = temp;
		this->pagesListPhySize = newSize;
	}
}


int Member::getFriendLocationInArray(const char* friendName)
{
	int i, res;
	for (i = 0; i < this->friendsListLogSize; i++)
	{
		if ((strcmp(this->friendsList[i]->name, friendName) == 0)) //if name is found
			return i;
	}
	return NOT_FOUND;
}

int Member::getPageLocationInArray(const char* pageName)
{
	int i, res;
	for (i = 0; i < this->pagesListLogSize; i++)
	{
		if ((strcmp(this->favPagesList[i]->getName(), pageName) == 0)) //if name is found
			return i;
	}
	return NOT_FOUND;
}

