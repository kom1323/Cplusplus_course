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

	



	


	void printAllFavPages();
	void printAllMyFriends();
	void printLatestStatusesOfFriends();

	
	
	bool isFanPage(const Page* newPage);
	bool isFanPage(const string& pageName);

};
#endif //_MEMBER