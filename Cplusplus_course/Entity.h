#ifndef _ENTITY_H
#define _ENTITY_H

#include "Types.h"

class Entity 
{
protected:

	string name;
	vector<Status*> statusList;
	vector<Entity*> followersList;
	

public:
	Entity(const string& newName);
	virtual ~Entity();
	
	const string& getName() const;
	const vector<Status*>& getStatusList() const;
	const vector<Entity*>& getFollowersList() const;

	void checkFollowship(const string& name);
	void checkNotFollowship(const string& name);
	bool addFollow(Entity* newEntity);
	bool removeMutualFollow(const string& friendName);
	bool isMutualFollowing(Entity* entity) const;
	bool isMutualFollowing(const string& name) const;
	void printAllFollowerMembers() const;

	bool isMember(const Entity* newAmigo) const;
	bool isMember(const string& amigoName) const;
	void isMe(const string& name);


	bool addStatus(const string& status);
	bool addMediaStatus(const string& status, const string& fileName);

	void printAllStatus() const;

	virtual void writeToFile(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Entity& entity);

};



#endif  //! _ENTITY_H