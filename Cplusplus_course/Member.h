#ifndef _MEMBER_H
#define _MEMBER_H


#include "Types.h"
#include "Date.h"


class Member 
{
private:
	const char* name;
	const Date birthday;
	Member** friendsList;
	Page** favPagesList;
	Status** statusList;
	int friendsListPhySize, friendsListLogSize,
		statusListPhySize, statusListLogSize,
		pagesListPhySize, pagesListLogSize;

public:
	Member(const char* name, const Date date);
	~Member();

	const char* getName() const { return this->name; };
	Date getBirthday() const;


	bool addFriend(const Member* newAmigo);
	bool removeFriend(const char* friendName);
	bool addFavPage(const Page* newPage) { return false; };
	bool removeFavPage(const char* pageName) { return true; };
	bool addStatus();


	void printAllFriends();
	void printAllFavPages();
	void printAllStatus();
	void printLatestStatusesOfFriends();

};

#endif //_MEMBER
