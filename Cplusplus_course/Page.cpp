#include <iostream>
using namespace std;

#include "Page.h"
#include "Member.h"


const char* Page::getName()
{
	return name;

}
const Member** Page::getMembersList()
{

	return membersList;
}

int Page::getNumOfMembers()
{
	return numOfMembers;

}
bool Page::setName(const char* newName)
{

	if (name != nullptr)
		delete[] name;
	
	name = new char[strlen(newName) + 1];	
	strcpy(name, newName);
	return true;

}
bool Page::setMembersList(const Member** newMembersList, const int numMembers)
{
	deleteMembersList();

	membersList = new Member * [numMembers];

	//create each member and copy the new
	for (int i = 0; i < numMembers; i++)
	{
		membersList[i] = new Member;
		*membersList[i] = *newMembersList[i];
	}

	numOfMembers = numMembers;

	return true;

}

bool Page::setNumOfMembers(const int numMembers)
{
	numOfMembers = numMembers;
	return true;

}

//deletes the members list
void Page::deleteMembersList()
{
	if (membersList != nullptr) {

		for (int i = 0; i < numOfMembers; i++)
		{
			delete membersList[i];
		}
	}

	delete[] membersList;
}
