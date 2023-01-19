#ifndef _ENTITY_H
#define _ENTITY_H

#include "Types.h"
#include "FacebookExceptions.h"


class Entity 
{
protected:

	string name;
	vector<Status*> statusList;
	vector<Entity*> followersList;
	

public:
	Entity(const string& newName);
	Entity() = default;
	virtual ~Entity();
	
	const string& getName() const;
	const vector<Status*>& getStatusList() const;
	const vector<Entity*>& getFollowersList() const;
	vector<Entity*>& setFollowersList();

	void checkFollowship(const string& name) throw(AlreadyFriendsException);
	void checkNotFollowship(const string& name) throw(NotFriendsException);
	bool addFollow(Entity* newEntity);
	bool removeMutualFollow(const string& friendName);
	bool isMutualFollowing(Entity* entity) const;
	bool isMutualFollowing(const string& name) const;
	void printAllFollowerMembers() const;

	bool isMember(const Entity* newAmigo) const;
	bool isMember(const string& amigoName) const;
	void isMe(const string& name) throw(SelfException);


	bool addStatus(const string& status);
	bool addMediaStatus(const string& status, const string& fileName);

	void printAllStatus() const;

	virtual void writeToFile(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Entity& entity);
	virtual void readFromFile(istream& os) ;
	friend istream& operator>>(istream& os, Entity& entity);
};



#endif  //! _ENTITY_H