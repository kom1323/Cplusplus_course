#ifndef _MEMBER_H
#define _MEMBER_H

#include "Types.h"


class Member
{
private:
	string name;
	Date birthday;
	vector<Member*> friendsList;
	vector<Page*> favPagesList;
	vector<Status> statusList;

public:
	Member(const string& newName, Date date);
	Member() = default;
	const Member& operator=(const Member& other);
	const string getName() const;
	Date getBirthday() const;
	const vector<Member*>& getFriendsList() const;

	bool addFriend(Member* newAmigo);
	bool removeFriend(const string& friendName);
	bool addFavPage(Page* newPage);
	bool removeFavPage(const string pageName);
	bool addStatus();
	bool addStatus(const string& status);

	void printAllFriends();
	void printAllFavPages();
	void printAllStatus();
	void printLatestStatusesOfFriends();

	bool isMember(const Member* newAmigo);
	bool isMember(const string& amigoName);
	bool isFanPage(const Page* newPage);
	bool isFanPage(const string& pageName);

};
#endif //_MEMBER