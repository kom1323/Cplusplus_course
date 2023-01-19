#include "Entity.h"
#include "Status.h"
#include "MediaStatus.h"
#include "Member.h"



Entity::Entity(const string& newName) :name(newName)
{
}

Entity::~Entity()
{
	//delete all statuses dynamic allocations
	for (auto &status: this->statusList)
	{
		delete status;
	}
}

const string& Entity::getName() const
{
	return this->name;
}

const vector<Status*>& Entity::getStatusList() const
{
	return this->statusList;
}

const vector<Entity*>& Entity::getFollowersList() const
{
	return this->followersList;
}

vector<Entity*>& Entity::setFollowersList()
{
	return this->followersList;
}

bool Entity::addStatus(const string& status)
{
	this->statusList.push_back(new Status(status));
	return true;

}

bool Entity::addMediaStatus(const string& status,const string& fileName)
{

	this->statusList.push_back(new MediaStatus(status,fileName));
	return true;

}

void Entity::printAllStatus() const
{
	cout << "Statuses of: " << this->name << endl;
	cout << "-------------------------" << endl;
	int count = 0;
	if (this->statusList.size() == 0)
	{
		cout << "This user has no statuses" << endl;
		return;
	}

	for (auto& status : this->statusList)
	{
		cout << count + 1 << ". " << status->getCurrStatus() << endl << "Date: " << status->getDate().getmDate() << endl<<endl;
		count++;

		if (typeid(*status) == typeid(MediaStatus))
		{
			MediaStatus* tmp = (MediaStatus*)status;
			tmp->playMedia();
		}
			

	}
	cout << "-------------------------" << endl;
}

void Entity::writeToFile(ostream& os) const
{
}

void Entity::readFromFile(istream& os)
{
}


bool Entity::addFollow(Entity* newEntity)
{
	//check if member is alread a fan of page
	if (this->isMutualFollowing(newEntity))
	{
		return false;
	}

	//add the new member and update the member's favorite pages
	this->followersList.push_back(newEntity);
	if (typeid(*this) == typeid(Member))
	{
		Member* temp = (Member*)this;
		if (typeid(*newEntity) == typeid(Member))
			temp->increaseFriendsSize(1);
		else
			temp->increaseFavPagesSize(1);
	}
	newEntity->addFollow(this);

	return true;
}

bool Entity::removeMutualFollow(const string& friendName)
{
	vector<Entity*>::iterator entityItr = this->followersList.begin();

	for (entityItr; entityItr != followersList.end(); entityItr++)
	{
		if ((*entityItr)->getName() == friendName)
		{
			Entity* tmp = *entityItr;
			*entityItr = nullptr;
			this->followersList.erase(entityItr);
			if (typeid(*this) == typeid(Member))
			{
				Member* memPtr = (Member*)this;
				if (typeid(*(*entityItr)) == typeid(Member))
					memPtr->increaseFriendsSize(-1);
				else
					memPtr->increaseFavPagesSize(-1);
			}
			
			tmp->removeMutualFollow(this->name);
			return true;
		}
	}
	return false;
}

bool Entity::isMutualFollowing(Entity* entity) const
{
	return isMutualFollowing(entity->name);
}

bool Entity::isMutualFollowing(const string& name) const
{
	for (auto& follower : this->followersList)
	{
		if (name ==follower->getName())
			return true;
	}
	return false;
}

//throw if the name belongs to this entity
void Entity::isMe(const string& name) throw(SelfException)
{
	if (this->name == name)
		throw SelfException();
}

//function that returns true if the users are friends
bool Entity::isMember(const Entity* newAmigo) const
{
	return isMember(newAmigo->name);
}

//function that returns true if the users are friends
bool Entity::isMember(const string& amigoName) const
{
	for (auto& amigo : this->followersList)
	{
		//add if amigo is member
		if ( typeid(*amigo)==typeid(Member) && amigoName == amigo->getName() )
			return true;
	}
	return false;
}

void Entity::printAllFollowerMembers() const
{
	bool hasFriends = false;
	if (typeid(*this) == typeid(Member))
		cout << "Friends";
	else
		cout << "Fans" ;
	cout << "of: " << this->name << endl;
	cout << "-------------------------" << endl;

	for (auto& amigo : this->followersList)
	{
		if (typeid(*amigo) == typeid(Member))
		{
			hasFriends = true;
			cout << amigo->getName() << endl;
		}
	}
	if (!hasFriends)
	{
		if (typeid(*this) == typeid(Member))
			cout << "This user doesn't have any friends!";
		else
			cout << "This page doesn't have any fans!";
	}
	cout << "-------------------------" << endl;
}


//throws if users are already friends
void Entity::checkFollowship(const string& name) throw(AlreadyFriendsException)
{
	if (this->isMember(name))
		throw AlreadyFriendsException();
}

//throws if users are not friends
void Entity::checkNotFollowship(const string& name) throw(NotFriendsException)
{
	if (!this->isMember(name))
		throw NotFriendsException();
}

ostream& operator<<(ostream& os, const Entity& entity)
{
	if (typeid(entity) == typeid(Member))
		os << "Member" << endl;
	else
		os << "Page" << endl;
	os << entity.name << endl;
	os << entity.followersList.size() << endl;
	for (auto& follower: entity.followersList)
	{
		os << follower->name << endl;
	}
	os << entity.statusList.size() << endl;
	for (auto& status : entity.statusList)
	{
		os << *status;
	}
	entity.writeToFile(os);
	return os;
}

istream& operator>>(istream& os, Entity& entity)
{
	int i,followersSize, statusSize;
	string* temp, statusChecker,size;
	Status* statusTmp;
	getline(os, entity.name);
	getline(os, size);
	followersSize = std::stoi(size);
	for (i = 0; i < followersSize; i++)
	{
		temp = new string;
		getline(os, *temp);
		entity.followersList.push_back((Entity*)temp);
	}
	getline(os, size);
	statusSize = std::stoi(size);
	for (i = 0; i < statusSize; i++)
	{
		getline(os, statusChecker);
		if (statusChecker == "Media Status")
			statusTmp = new MediaStatus();
		else
			statusTmp = new Status();
		os >> *statusTmp;
		entity.statusList.push_back(statusTmp);
	}
	entity.readFromFile(os);
	return os;
}
