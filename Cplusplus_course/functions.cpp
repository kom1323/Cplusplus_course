#include <iostream>
using namespace std;
#include "Facebook.h"
#include "Date.h"
#include "Status.h"
#include "Member.h"
#include "Page.h"


char* readInputString()
{
	char* stringFromUser = new char[30];
	cin.getline(stringFromUser, 30);

	return stringFromUser;
}

void initFacebookEntities(Facebook& fuckbook)
{
	fuckbook.addMember();
	fuckbook.addMember();
	fuckbook.addMember();
	fuckbook.addPage();
	fuckbook.addPage();
	fuckbook.addPage();





}


