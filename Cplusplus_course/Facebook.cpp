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
	string name, dateOfBirth;

	this->getMember(name, dateOfBirth);
	
	Member* temp = new Member(name, dateOfBirth);
	
	this->allMembers.push_back(temp);
	return true;
}

//function that receives the data and validates it
void Facebook::getMember(string& name, string& dateOfBirth) 
{

	bool isValid = false;
	while (!isValid)
	{
		cout << "Please enter the new member name: ";
		name = readInputString();
		try
		{
			isBlank(name);
			this->isNameValid(name);
			this->isMember(name);
			isValid = true;
		}
		catch (FacebookExceptions& e)
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
			isBlank(dateOfBirth);
			this->isBirthdayValid(dateOfBirth);
			isValid = true;
		}
		catch (FacebookExceptions& e)
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
	string name;
	this->getPage(name);

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

//function that receives the data and validates it
void Facebook::getPage(string& name)
{
	bool isValid = false;
	while (!isValid)
	{
		cout << "Please enter the new page name: ";
		name = readInputString();
		try
		{
			isBlank(name);
			this->isNameValid(name);
			this->isPage(name);
			isValid = true;
		}
		catch (FacebookExceptions& e)
		{
			cout << e.what() << endl;
		}
	}
}

//throws if a member with this name is not found
bool Facebook::isNotMember(const string& name) throw(MemberNotFoundException)
{
	for (auto& mem : this->allMembers)
	{

		if (mem->getName() == name) {

			return false;
		}
	}
	throw MemberNotFoundException();

}

//throws if a member with this name is found
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

bool Facebook::isPage(const string& name) throw(NameExistException)
{
	for (auto& pag : this->allPages)
	{

		if (pag->getName() == name) {

			throw NameExistException();
		}
	}
	return false;
}

bool Facebook::isNotPage(const string& name) throw(PageNotFoundException)
{
	for (auto& pag : this->allPages)
	{

		if (pag->getName() == name) {

			return false;
		}
	}
	throw PageNotFoundException();
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

const list<Member*>& Facebook::getMembersList() const
{
	return this->allMembers;
}

//function to check if the input in the menu is valid, if not it throws
void Facebook::isNumber(const string& input) throw(InvalidChoiceException)
{
	if (input.size() >= 3)
		throw InvalidChoiceException();
	if (input.size()==2 &&( !isdigit(input[0]) || !isdigit(input[1]) || input[0] == '0'|| stoi(input)>MAXIMUM_CHOICE || stoi(input)< MINIMUM_CHOICE))
		throw InvalidChoiceException();
	if (input.size() == 1 && (!isdigit(input[0]) || input[0]=='0'))
		throw InvalidChoiceException();
	if (input.size() ==0)
		throw InvalidChoiceException();
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
	int size = (int)temp->getFriendsSize();

	if (size == 0)
		return false;
	else
	{
		cout << "All available friends to delete:" << endl;
		cout << "-------------------------" << endl;
		for (int i = 0; i < size; i++)
		{
			if (typeid(temp->getFollowersList()[i])==typeid(Member*))
				cout << temp->getFollowersList()[i]->getName() << endl;
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

