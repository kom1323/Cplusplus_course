#ifndef _ENTITY_H
#define _ENTITY_H

#include "Types.h"


class Entity 
{
private:

	string name;
	vector<Status> statusList;
	vector<Entity*> followersList;

public:

	const string& getName() const;
	const vector<Status>& getStatusList() const;

	void checkFollowship(const string& name);
	void checkNotFollowship(const string& name);
	bool addFollow(Entity* newEntity);
	bool removeMutualFollow(const string& friendName);
	bool isMutualFollowing(Entity* entity) const;
	bool isMutualFollowing(const string& name) const;

	virtual bool addStatus() = 0;
	virtual bool addStatus(const string& status)= 0;

	//printallStatus() virtual
	//add isMember with implemintaion in Entity, need to use typeid
	//add isFavPage with implemintaion in Entity, need to use typeid




};



#endif  //! _ENTITY_H