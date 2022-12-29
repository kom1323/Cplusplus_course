/*
Project by:
Omer Mualem 207685199
Daniel Omesi 207689092

*/

#include "Types.h"
#include "Facebook.h"



void initFacebookEntities(Facebook &facebook);
void startMenu(Facebook& facebook);
void newTerminate();



int main()
{
	set_terminate(newTerminate);
	Facebook facebook;
	initFacebookEntities(facebook);


	startMenu(facebook);

}


/*
To do list:
Member:



(-1) program allows adding user with an invalid birth date; (-1) program allows making user a friend of themselves; (-1) runtime exception when trying to add friendship to nonexistent user (in Member::isMember)

(-1) option 8 - some users' names not listed when attempting to add user to a fan page

(-2) (option 12) runtime exception on exit in some cases (e.g after adding two users and making one a fan of a fan page)

do not submit debug folder or any other project files other than .sln and .vcxproj

- add to readme file how to execute operators testings except status
*/

/*
Exception types:
name - need to be only letters
date - need to be in format
if name is already a member
if name is already a page
if name is already a friend
if name is already a fan
if the member/page doesn't exist

*/

//we need to create a function that uses the invalid choice exception wisely