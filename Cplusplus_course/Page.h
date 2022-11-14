#ifndef  _PAGE
#define _PAGE

#include "Member.h"
#include "Status.h"



class Page
{
private:
	char* name;
	Member** membersList;
	int numOfMembers;
	

public:
	

	const char* getName();
	const Member** getMembersList();
	int getNumOfMembers();

	
	bool setName(const char* newName);
	bool setMembersList(const Member** newMemebersList, const int numMembers);
	bool setNumOfMembers(const int numMembers);
	void deleteMembersList();

};






#endif // ! _PAGE
