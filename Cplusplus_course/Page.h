#ifndef  _PAGE_H
#define _PAGE_H

#include "Types.h"


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




	bool addFriend(const Member* newAmigo);
	bool removeFriend(const char* friendName);
	bool addFavPage(const Page* newPage);
	bool removeFavPage(const char* pageName);
	bool addStatus();



	void printAllFans();
	void printAllStatus();


};






#endif // ! _PAGE
