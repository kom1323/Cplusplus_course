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
	string name, dateOfBirth;

	this->getMember(name, dateOfBirth);
	
	Member* temp = new Member(name, dateOfBirth);
	
	this->allMembers.push_back(temp);
	return true;
}


void Facebook::getMember(string& name, string& dateOfBirth) throw(...)
{

	bool isValid = false;
	while (!isValid)
	{
		cout << "Please enter the new member name: ";
		name = readInputString();
		try
		{
			this->isNameValid(name);
			this->isMember(name);
			isValid = true;
		}
		catch (InvalidNameException& e)
		{
			cout << e.what() << endl;
		}
		catch (NameExistException& e)
		{
			cout << e.what() << endl;
		}
	}
	isValid = false;
	while (!isValid)
	{
		cout << "Please enter date of birth(dd/mm/yyyy): ";
		dateOfBirth = readInputString();
		try
		{
			this->isBirthdayValid(dateOfBirth);
			isValid = true;
		}
		catch (DateFormatException& e)
		{
			cout << e.what() << endl;
		}
	}





}

void Facebook::isNameValid(string& name) const throw(InvalidNameException)
{
	for (int i = 0; i < name.size(); i++)
	{
		if (!isalpha(name[i]))
		{
			throw InvalidNameException();
				break;
		}
	}

}

void Facebook::isBirthdayValid(const string& birthday) const throw(DateFormatException)
{
	//check that the file is in the format with legit birthday - dd/mm/yy (example: 06/11/1998)
	
	int day, month, year;
	if ((birthday.size() == 10) && (birthday[2] == '/' && birthday[5] == '/'))
	{
		day = (birthday[0] - '0') * 10 + (birthday[1] - '0');
		month= (birthday[3] - '0') * 10 + (birthday[4] - '0');
		year = (birthday[6] - '0') * 1000 + (birthday[7] - '0') * 100 + (birthday[8] - '0') * 10 + (birthday[9] - '0');
		if (!((day <= 31 && day >= 1) && (month <= 12 && month >= 1) && (year >= 0 && year <= 2022)))
			throw DateFormatException();
	}
	else
		throw DateFormatException();
		
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

bool Facebook::isMember(const string& name) throw(NameExistException)
{
	for (auto& mem : this->allMembers)
	{

		if (mem->getName() == name) {

			throw NameExistException();
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
	int size = (int)temp->getFriendsList().size();

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