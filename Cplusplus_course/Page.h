#ifndef  _PAGE_H
#define _PAGE_H

#pragma warning(disable : 4996)
#include "Types.h"
#include "Status.h"
#include "Member.h"

class Page
{
private:
	string name;
	vector<Member*> membersList;
	vector<Status> statusList;

public:
	Page(const string& name);
	Page() = default;

	int getFanListSize() const;
	const string& getName() const;


	const Page& operator=(const Page& other);
	const Page& operator+=(Member& fan);

	bool operator>(const Member& other);
	bool operator>(const Page& other);
	bool operator<(const Member& other);
	bool operator<(const Page& other);

	bool addFan(Member* newAmigo);
	bool removeFan(const string friendName);
	bool addStatus();
	bool addStatus(const string status);
	bool isFan(Member* member) const;
	bool isFan(const string name) const;

	void printAllFans();
	void printAllStatus();
};
#endif // ! _PAGE
