/*
Project by:
Omer Mualem 207685199
Daniel Omesi 207689092

*/

#include "Types.h"
#include "Facebook.h"



void initFacebookEntities(Facebook &facebook);
void startMenu(Facebook& facebook);




int main()
{
	Facebook facebook;
	initFacebookEntities(facebook);


	startMenu(facebook);

}


/*
To do list:
Member:
(-3) no copy ctor implementation for class with dynamically allocated data members (Page, Status, Facebook)

(-3) input / output should not be done in classes / modules which handle program logic (Status ctor, Facebook::addMember, ::addPage)

allocations using strdup should be freed using C-style free, not delete (in general strdup should be avoided in cpp) (Status ctor);
(-2) long functions / methods should be split into shorter ones (startMenu); (-1) avoid using exit, other control mechanisms are preferable (startMenu)

(-1) program allows adding user with an invalid birth date; (-1) program allows making user a friend of themselves; (-1) runtime exception when trying to add friendship to nonexistent user (in Member::isMember)

(-1) option 8 - some users' names not listed when attempting to add user to a fan page

(-2) (option 12) runtime exception on exit in some cases (e.g after adding two users and making one a fan of a fan page)

do not submit debug folder or any other project files other than .sln and .vcxproj

- add to readme file how to execute operators testings except status
*/