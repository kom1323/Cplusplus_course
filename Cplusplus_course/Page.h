#ifndef  _PAGE_H
#define _PAGE_H

#include "Types.h"
#include "Member.h"

class Page
{
private:
	const char* name;
	Member** membersList;
	Status** statusList;
	int statusListPhySize, statusListLogSize,
		membersListPhySize, membersListLogSize;
	

public:
	
	Page(const char* name);
	~Page();

	const char* getName() const;

	bool addFriend(Member* newAmigo);	// deleted const
	bool removeFriend(const char* friendName); //circular and do i need it in a page
	bool addFavPage(const Page* newPage);
	bool removeFavPage(const char* pageName);
	bool addStatus();

	void printAllFans();
	void printAllStatus();


};






#endif // ! _PAGE
