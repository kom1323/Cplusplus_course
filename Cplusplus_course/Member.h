#ifndef _MEMBER_H
#define _MEMBER_H


#include "Types.h"
#include "Date.h"

class Member {
private:
	char* name;
	Date birthday;
	Member** friends;
	Page** favPages;
	Status** statusList;

public:

	bool setName(char* newName);
	bool setBirthday(Date newBirthday);
};

#endif //_MEMBER
