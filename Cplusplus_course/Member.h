#ifndef _MEMBER_H
#define _MEMBER_H

#include "Types.h"
#include "Date.h"
#include "Page.h"
#include "Status.h"
#include "Entity.h"
#include "FacebookExceptions.h"


class Member : public Entity
{
private:
	Date birthday;
	int friendsSize, favPagesSize;

public:
	Member(const string& newName, Date date);
	Member() = default;
	
	const Member& operator=(const Member& other);
	const Member& operator+=(Member& other);

	bool operator>(const Member& other);
	bool operator>(const Page& other);
	bool operator<(const Member& other);
	bool operator<(const Page& other);

	Date getBirthday() const;
	int getFriendsSize() const;
	int getFavPagesSize() const;

	//adds num to the size, corresponding to logical size
	void increaseFriendsSize(int num);
	void increaseFavPagesSize(int num);

	
	


	bool addFriend(Member* newAmigo);
	bool removeFriend(const string& friendName);
	bool addFavPage(Page* newPage);
	bool removeFavPage(const string pageName);
	

	//use typeid to count the number of members in followersList
	int getMembersSize() const;

	void printAllFavPages();
	void printLatestStatusesOfFriends();

	
	
	bool isFanPage(const Page* newPage);
	bool isFanPage(const string& pageName);

};
#endif //_MEMBER