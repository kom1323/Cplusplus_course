#ifndef _MEMBER
#define _MEMBER

#include <iostream>
#include "Page.h"
#include "Status.h"
#include "Date.h"

class Member {
private:
	char* name;
	Date birthday;
	Member** friends;
	Page** favPages;
	Status** statusList;

	bool setName(char* newName);
	bool setBirthday(Date newBirthday);
};

#endif //_MEMBER
