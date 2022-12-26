#include "Page.h"






Page::Page(const string& name) : name(name)
{
}


const Page& Page::operator=(const Page& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->membersList = other.membersList;
		this->statusList = other.statusList;
	}
	return *this;
}

const string& Page::getName() const
{
	return this->name;
}

bool Page::addFan(Member* newAmigo)
{
	//check if member is alread a fan of page
	if (this->isFan(newAmigo))
	{
		return false;
	}

	//add the new member and update the member's favorite pages
	this->membersList.push_back(newAmigo);
	newAmigo->addFavPage(this);

	return true;
}

bool Page::removeFan(const string friendName)
{
	vector<Member*>::iterator itr = this->membersList.begin();
	for (itr; itr != this->membersList.end(); itr++)
	{
		//match by name
		if ((*itr)->getName() == friendName)
		{
			//check if already removed the page from the member
			if (!(*itr)->removeFavPage(this->getName()))
			{
				return true;
			}

			this->membersList.erase(itr);
			return true;

		}

	}

	return false;
}

bool Page::addStatus()
{
	//add the new status 
	this->statusList.push_back(Status());
	return true;
}
bool Page::addStatus(const string status)
{

	this->statusList.push_back(Status(status));
	return true;

}


bool Page::isFan(Member* member) const
{
	for (auto& fan : this->membersList)
	{

		if (fan == member) {

			return true;
		}
	}
	return false;
}

bool Page::isFan(const string name) const
{
	for (auto& fan : this->membersList)
	{

		if (fan->getName() == name) {

			return true;
		}
	}
	return false;
}

void Page::printAllFans()
{
	cout << "Fans of page: " << this->name << endl;
	cout << "-------------------------" << endl;

	for (auto& fan : this->membersList)
	{
		cout << fan->getName() << endl;
	}
	cout << "-------------------------" << endl;
}

void Page::printAllStatus()
{

	cout << "Statuses in page: " << this->name << endl;
	cout << "-------------------------" << endl;
	int count = 0;
	for (auto& status : this->statusList)
	{
		cout << count + 1 << ". " << status.getCurrStatus() << endl << "Date: " << status.getDate().getmDate() << endl;
		count++;
	}

	cout << "-------------------------" << endl;

}
