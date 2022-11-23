#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Page.h"

Page::Page(const char* name)
{
	char* temp = new char[strlen(name) + 1];
	strcpy(temp, name);
	this->name = temp;

	this->membersList = new Member * [LIST_STARTING_SIZE];
	this->membersListLogSize = 0;
	this->membersListPhySize = 1;
	
	this->statusList = new Status * [LIST_STARTING_SIZE];
	this->statusListLogSize = 0;
	this->statusListPhySize = 1;


}

Page::~Page()
{
	
	for (int i = 0; i < statusListLogSize; i++)
	{
		delete statusList[i];
	}
	delete[] statusList;

	for (int i = 0; i < membersListLogSize; i++)
	{
		membersList[i]->removeFavPage(this->name);
	}
	delete[] membersList;

	//cout << "Killed " << this->name << endl;
	delete[] this->name;

}

const char* Page::getName() const
{
	return this->name;
}

bool Page::addFriend(Member* newAmigo)
{
	//check if member is alread a fan of page
	for (int i = 0; i < this->membersListLogSize; i++)
	{
		if (this->membersList[i] == newAmigo) {

			cout << "Member " << newAmigo->getName() << "is already a fan" << endl;
			return false;
		}
	}

	//increase membersList if necessery
	if (membersListLogSize == membersListPhySize)
	{
		Member** temp = new Member * [this->membersListPhySize * 2];

		for (int i = 0; i < this->membersListLogSize; i++)
		{
			temp[i] = this->membersList[i];
		}
		delete[] this->membersList;

		this->membersList = temp;
	}

	//add the new member and update the member's favorite pages
	this->membersList[this->membersListLogSize] = newAmigo;
	this->membersListLogSize++;
	newAmigo->addFavPage(this);

	return true;
}

bool Page::removeFriend(const char* friendName)
{
	return false;
}
