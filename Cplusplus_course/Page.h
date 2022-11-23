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

	bool addFan(Member* newAmigo);
	bool removeFan(const char* friendName); 
	bool addStatus();
	bool isFan(Member* member) const;
	bool isFan(const char* name) const;

	void printAllFans();
	void printAllStatus();


};






#endif // ! _PAGE
