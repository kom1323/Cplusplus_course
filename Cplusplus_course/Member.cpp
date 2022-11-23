#include <iostream>
using namespace std;
#include "Member.h"
#include <ctime>
#include <string.h>
#pragma warning(disable : 4996)

constexpr int LIST_STARTING_SIZE = 1;
constexpr int STATUS_MAX_SIZE = 50;

Member::Member(const char* newName, Date date) : birthday(date)
{
	char* temp = new char[strlen(newName) + 1];
	strcpy(temp, newName);
	this->name = temp;

	this->friendsList = new Member * [LIST_STARTING_SIZE];
	this->friendsListLogSize = 0;
	this->friendsListPhySize = 1;

	this->statusList = new Status * [LIST_STARTING_SIZE];
	this->statusListLogSize = 0;
	this->statusListPhySize = 1;

	this->favPagesList = new Page * [LIST_STARTING_SIZE];
	this->pagesListLogSize = 0;
	this->pagesListPhySize = 1;
}

Member::~Member()
{
	delete[] this->name;
	delete[] this->friendsList;
	delete[] this->statusList;
	delete[] this->favPagesList;
}

const char* Member::getName() const
{
	return this->name;
}

Date Member::getBirthday() const
{
	return this->birthday;
}

bool Member::addFriend(Member* newAmigo)
{
	if (isMember(newAmigo)) //to stop loop between both friends
		return false;
	else
	{
			this->checkFriendsArray(); //check if array is full (if not - double it's size)
			(this->friendsList)[this->friendsListLogSize] = newAmigo;
			(this->friendsListLogSize)++;
			newAmigo->addFriend(this); //add this friend to his friend's friends list
			return true;
	}
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
	return false;
}

bool Member::addStatus()
{
	char* statusTemp = new char[STATUS_MAX_SIZE];
	cin.getline(statusTemp, STATUS_MAX_SIZE);
	char* timeTemp = this->getTime();

	Status* newStatus = new Status(statusTemp, timeTemp);
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

void Member::checkFriendsArray()
{
	if (this->friendsListLogSize == this->friendsListPhySize)
	{
		Member** temp;
		int i, newSize = (this->friendsListPhySize)*2;
		temp = new Member * [newSize];
		this->friendsListPhySize = newSize;
		for (i = 0; i < this->friendsListLogSize; i++)
		{
			temp[i] = this->friendsList[i];
		}
		delete[] this->friendsList;
		this->friendsList = temp;
	}
}

void Member::checkStatusArray()
{
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
	}
}

void Member::checkPagesArray()
{
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
	}
}

char* Member::getTime()
{
	time_t curr_time;
	curr_time = time(NULL);

	char* tm = ctime(&curr_time);
	char* temp = new char[TIME_LENGTH];
	strcpy(temp, tm);

	return temp;
}
