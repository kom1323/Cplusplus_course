#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Page.h"
#include "Status.h"
#include "Member.h"

constexpr int LIST_STARTING_SIZE = 1;

char* readInputString();

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

	
	delete[] this->name;

}

const char* Page::getName() const
{
	return this->name;
}

bool Page::addFan(Member* newAmigo)
{
	//check if member is alread a fan of page
	if(this->isFan(newAmigo))
	{	
		return false;
	}

	//increase membersList if necessery
	if (this->membersListLogSize == this->membersListPhySize)
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

bool Page::removeFan(const char* friendName)
{
	
	for (int i = 0; i < this->membersListLogSize; i++)
	{
		//match by name
		if (strcmp(this->membersList[i]->getName(), friendName) == 0)
		{
			//check if already removed the page from the member
			if(!this->membersList[i]->removeFavPage(this->getName()))
			{
				return true;
			}

			//minimize space
			for (int j = i; j < this->membersListLogSize - 1; j++)
			{
				this->membersList[j] = this->membersList[j + 1];
			}
			this->membersListLogSize--;
			return true;
			
		}

	}

	return false;
}

bool Page::addStatus()
{
	Status* s = new Status();

	//increase statusList if necessery
	if (this->statusListLogSize == this->statusListPhySize)
	{
		Status** temp = new Status * [this->statusListPhySize * 2];

		for (int i = 0; i < this->statusListLogSize; i++)
		{
			temp[i] = this->statusList[i];
		}
		delete[] this->statusList;

		this->statusList = temp;
	}

	//add the new status 
	this->statusList[this->statusListLogSize] = s;
	this->statusListLogSize++;
	return true;

}
bool Page::addStatus(const char* status)
{
	Status* s = new Status(status);

	//increase statusList if necessery
	if (this->statusListLogSize == this->statusListPhySize)
	{
		Status** temp = new Status * [this->statusListPhySize * 2];

		for (int i = 0; i < this->statusListLogSize; i++)
		{
			temp[i] = this->statusList[i];
		}
		delete[] this->statusList;

		this->statusList = temp;
	}

	//add the new status 
	this->statusList[this->statusListLogSize] = s;
	this->statusListLogSize++;
	return true;

}


bool Page::isFan(Member* member) const
{
	for (int i = 0; i < this->membersListLogSize; i++)
	{
		
		if (this->membersList[i] == member) {

			return true;
		}
	}
	return false;
}

bool Page::isFan(const char* name) const
{
	for (int i = 0; i < this->membersListLogSize; i++)
	{
		
		if (strcmp(this->membersList[i]->getName(),name) == 0) {

			return true;
		}
	}
	return false;
}

void Page::printAllFans()
{
	cout << "Fans of page: " << this->name << endl;
	cout << "-------------------------" << endl;

	for (int i = 0; i < this->membersListLogSize; i++)
	{
		cout << this->membersList[i]->getName() << endl;
	}
	cout << "-------------------------" << endl;


}

void Page::printAllStatus()
{

	cout << "Statuses in page: " << this->name << endl;
	cout << "-------------------------" << endl;

	for (int i = 0; i < this->statusListLogSize; i++)
	{
		cout << i + 1 << ". " << this->statusList[i]->getCurrStatus()  << endl << "Date: " << this->statusList[i]->getDate().getmDate() << endl;
	}

	cout << "-------------------------" << endl;

}
