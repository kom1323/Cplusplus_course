#ifndef _MEMBER_H
#define _MEMBER_H


#include "Types.h"
#include "Date.h"
#include "Page.h"
#include "Status.h"

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
	Member(const char* newName, const Date date);
	~Member();

	const char* getName() const;
	Date getBirthday() const;


	bool addFriend(Member* newAmigo);
	bool removeFriend(const char* friendName);
	bool addFavPage(Page* newPage);
	bool removeFavPage(const char* pageName);
	bool addStatus();


	void printAllFriends();
	void printAllFavPages();
	void printAllStatus();
	void printLatestStatusesOfFriends();

	bool isMember(const Member* newAmigo);
	bool isFanPage(const Page* newPage);
	void checkFriendsArray();
	void checkStatusArray();
	void checkPagesArray();
	int getFriendLocationInArray(const char* friendName);
	int getPageLocationInArray(const char* pageName);
};

#endif //_MEMBER