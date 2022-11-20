#ifndef  _PAGE_H
#define _PAGE_H

#include "Types.h"


class Page
{
private:
	char* name;
	Member** membersList;
	int membersListSize;
	Status** statusList;
	int statusListSize;
	

public:
	
	int getStatusListSize() const;
	Status** getStatusList() const;
	char* getName() const;
	Member** getMembersList() const;
	int getNumOfMembers() const;

	bool setName(const char* newName);
	bool setMembersList(const Member** newMemebersList, int numMembers);
	bool setNumOfMembers(int numMembers);
	bool setStatusList(const Status** newStatusList, int newStatusListSize);
	bool setStatusListSize(int newStatusListSize);

	void deleteMembersList();
	bool addStatus(Status& status);


};






#endif // ! _PAGE
