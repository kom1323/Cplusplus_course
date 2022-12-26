#include "Facebook.h"





Facebook::~Facebook()
{
	//deleting all members of facebook
	for (auto &member: this->allMembers) 
	{
		delete member;
	}


	//deleting all pages of facebook
	for (auto &page: this->allPages)
	{
		delete page;
	}

}



bool Facebook::addMember()
{

	cout << "Please enter the new member name: ";
	char* name = readInputString();

	//check if member is alread a member
	if (this->isMember(name))
	{
		cout << name << " is already a member" << endl;
		delete[] name;
		return false;
	}

	cout << "Please enter date of birth(dd/mm/yyyy): ";
	char* dateOfBirth = readInputString();
	
	Member* temp = new Member(name, dateOfBirth);
	
	//delete temporary strings
	delete[] name;
	delete[] dateOfBirth;
	return this->addMember(temp);
}

bool Facebook::addMember(Member* mem)
{
	//increase membersList if necessery
	if (this->membersLogSize == this->membersPhySize)
	{
		this->membersPhySize *= 2;
		Member** temp = new Member * [this->membersPhySize];

		//copy array
		for (int i = 0; i < this->membersLogSize; i++)
		{
			temp[i] = this->allMembers[i];
		}
		delete[] this->allMembers;

		this->allMembers = temp;
	}

	//add the new member
	this->allMembers[this->membersLogSize] = mem;
	this->membersLogSize++;

	return true;
}




bool Facebook::addPage()
{

	cout << "Please enter page name: ";
	char* name = readInputString();

	//check if member is alread a member
	if (this->isPage(name))
	{
		cout << name << " is already a Page in Facebook" << endl;
		delete[] name;
		return false;
	}


	Page* temp = new Page(name);
	delete[] name;

	return this->addPage(temp);
}

bool Facebook::addPage(Page* pag)
{

	//increase Pagelist if necessery
	if (this->pagesLogSize == this->pagesPhySize)
	{
		this->pagesPhySize *= 2;
		Page** temp = new Page * [this->pagesPhySize];

		//copy array
		for (int i = 0; i < this->pagesLogSize; i++)
		{
			temp[i] = this->allPages[i];
		}
		delete[] this->allPages;

		this->allPages = temp;
	}

	//add the new Page
	this->allPages[this->pagesLogSize] = pag;
	this->pagesLogSize++;

	return true;
}



bool Facebook::isMember(const char* name)
{
	for (int i = 0; i < this->membersLogSize; i++)
	{
		
		if (strcmp(this->allMembers[i]->getName(), name) == 0) {

			return true;
		}
	}
	return false;
}

bool Facebook::isPage(const char* name)
{
	for (int i = 0; i < this->pagesLogSize; i++)
	{

		if (strcmp(this->allPages[i]->getName(), name) == 0) {

			return true;
		}
	}
	return false;
}

Member* Facebook::getMemberByName(const char* name)
{
	for (int i = 0; i < this->membersLogSize; i++)
	{
		if (strcmp(this->allMembers[i]->getName(), name) == 0)
		{
			return this->allMembers[i];
		}
	}

	return nullptr;
}

Page* Facebook::getPageByName(const char* name)
{
	for (int i = 0; i < this->pagesLogSize; i++)
	{
		if (strcmp(this->allPages[i]->getName(), name) == 0)
		{
			return this->allPages[i];
		}
	}

	return nullptr;
}

void Facebook::printAllEntities()
{
	this->printAllMembers();
	this->printAllPages();
}

void Facebook::printAllMembers()
{
	cout << "All members in Facebook" << endl;
	cout << "-------------------------" << endl;

	for (int i = 0; i < this->membersLogSize; i++)
	{
		cout << this->allMembers[i]->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

void Facebook::printAllPages()
{
	cout << "All Pages in Facebook" << endl;
	cout << "-------------------------" << endl;

	for (int i = 0; i < this->pagesLogSize; i++)
	{
		cout << this->allPages[i]->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

bool Facebook::printAvailableFriends(const char* amigoName)
{
	bool isFriends=false; //to see if everyone are already his friends
	cout << "All available friends to add:" << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < this->membersLogSize; i++) 
	{
		if (this->allMembers[i]->getFriendLocationInArray(amigoName) == NOT_FOUND && (strcmp(this->allMembers[i]->getName(), amigoName)!=0))
		{
			cout << this->allMembers[i]->getName() << endl;
			isFriends = true;
		}
	}
	cout << "-------------------------" << endl;
	return isFriends;
}

bool Facebook::printFriendListOfMember(const char* name)
{
	Member* temp;
	temp = this->getMemberByName(name);
	int size = temp->getFriendListLogSize();

	if (size == 0)
		return false;
	else
	{
		cout << "All available friends to delete:" << endl;
		cout << "-------------------------" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << temp->getFriendsList()[i]->getName() << endl;
		}
		cout << "-------------------------" << endl;
	}
	return true;
}

bool Facebook::printAvailableFans(const char* pageName)
{
	bool isFan = false; //to see if everyone are already his friends
	cout << "All available friends to add:" << endl;
	cout << "-------------------------" << endl;
	for (int i = 0; i < this->pagesLogSize; i++)
	{
		if ( this->allMembers[i]->isFanPage(pageName) == false && (strcmp(this->allMembers[i]->getName(), pageName) != 0))
		{
			cout << this->allMembers[i]->getName() << endl;
			isFan = true;
		}
	}
	cout << "-------------------------" << endl;
	return isFan;
}
