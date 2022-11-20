#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "Page.h"
#include "Member.h"
#include "Status.h"


void** addItemToDynamicArray(void** arr, int& arrLogicalSize, int arrPhysicalSize, int itemSize, void* newItem);

char* Page::getName() const
{
	return name;

}
Member** Page::getMembersList() const
{

	return membersList;
}

int Page::getNumOfMembers() const
{
	return membersListSize;

}


int Page::getStatusListSize() const
{
	return statusListSize;
}

Status** Page::getStatusList() const
{

	return statusList;

}


bool Page::setName(const char* newName)
{

	if (name != nullptr)
		delete[] name;
	
	name = new char[strlen(newName) + 1];	
	strcpy(name, newName);
	return true;

}
bool Page::setMembersList(const Member** newMembersList, int numMembers)
{
	deleteMembersList();

	membersList = new Member * [numMembers];

	//create each member and copy the new
	for (int i = 0; i < numMembers; i++)
	{
		membersList[i] = new Member;
		*membersList[i] = *newMembersList[i];
	}

	membersListSize = numMembers;

	return true;

}

bool Page::setNumOfMembers(int numMembers)
{
	membersListSize = numMembers;
	return true;

}



// ---------------------------------test---------------------------------------------------
bool Page::addStatus(Status& status)
{

	Status* newStatus = new Status(status);


	void ** temp = addItemToDynamicArray((void**)statusList, statusListSize, 1, sizeof(Status*), newStatus);
	statusList = (Status**)temp;

	return true;

}



//deletes the members list
void Page::deleteMembersList()
{
	if (membersList != nullptr) {

		for (int i = 0; i < membersListSize; i++)
		{
			delete membersList[i];
		}
	}

	delete[] membersList;
}
