#include "Member.h"

bool Member::setName(char* newName)
{
	name = new char[strlen(newName)];

	return true;
}

bool Member::setBirthday(Date newBirthday)
{
	birthday = newBirthday;
}






