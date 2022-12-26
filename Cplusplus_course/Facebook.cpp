#include "Facebook.h"



string readInputString();

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
	string name = readInputString();

	//check if member is alread a member
	if (this->isMember(name))
	{
		cout << name << " is already a member" << endl;
		return false;
	}

	cout << "Please enter date of birth(dd/mm/yyyy): ";
	string dateOfBirth = readInputString();
	
	Member* temp = new Member(name, dateOfBirth);
	
	this->allMembers.push_back(temp);
	return true;
}

bool Facebook::addMember(Member* mem)
{
	//add the new member
	this->allMembers.push_back(mem);

	return true;
}


bool Facebook::addPage()
{

	cout << "Please enter page name: ";
	string name = readInputString();

	//check if Page is alread a included
	if (this->isPage(name))
	{
		cout << name << " is already a Page in Facebook" << endl;
		return false;
	}


	Page* temp = new Page(name);
	this->allPages.push_back(temp);
	return true;
}

bool Facebook::addPage(Page* pag)
{

	//add the new Page
	this->allPages.push_back(pag);

	return true;
}

bool Facebook::isMember(const string& name)
{
	for (auto& mem : this->allMembers)
	{

		if (mem->getName() == name) {

			return true;
		}
	}
	return false;
}

bool Facebook::isPage(const string& name)
{
	for (auto& pag : this->allPages)
	{

		if (pag->getName() == name) {

			return true;
		}
	}
	return false;
}

Member* Facebook::getMemberByName(const string& name)
{
	for (auto& mem : this->allMembers)
	{
		if (name == mem->getName())
		{
			return mem;
		}
	}

	return nullptr;
}

Page* Facebook::getPageByName(const string& name)
{
	for (auto& page : this->allPages)
	{
		if (page->getName() == name)
		{
			return page;
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

	for (auto& mem : this->allMembers)
	{
		cout << mem->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

void Facebook::printAllPages()
{
	cout << "All Pages in Facebook" << endl;
	cout << "-------------------------" << endl;

	for (auto& pag : this->allPages)
	{
		cout << pag->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

bool Facebook::printAvailableFriends(const string& amigoName)
{
	bool isFriends = false; //to see if everyone are already his friends
	cout << "All available friends to add:" << endl;
	cout << "-------------------------" << endl;
	for (auto& mem : this->allMembers)
	{
		if ((!mem->isMember(amigoName)) && ((mem->getName() != amigoName)))
		{
			cout << mem->getName() << endl;
			isFriends = true;
		}
	}
	cout << "-------------------------" << endl;
	return isFriends;
}

bool Facebook::printFriendListOfMember(const string& name)
{
	Member* temp;
	temp = this->getMemberByName(name);
	int size = temp->getFriendsList().size();

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

bool Facebook::printAvailableFans(const string& pageName)
{
	bool isFan = false; //to see if everyone are already his friends
	cout << "All available friends to add:" << endl;
	cout << "-------------------------" << endl;
	for (auto& mem : this->allMembers)
	{
		if (mem->isFanPage(pageName) == false)
		{
			cout << mem->getName() << endl;
			isFan = true;
		}
	}
	cout << "-------------------------" << endl;
	return isFan;
}