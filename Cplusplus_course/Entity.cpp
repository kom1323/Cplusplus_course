#include "Entity.h"

const string& Entity::getName() const
{
	return this->name;
}

const vector<Status>& Entity::getStatusList() const
{
	return this->statusList;
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
