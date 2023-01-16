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

	//initializing data
	initFacebookEntities(facebook);

	startMenu(facebook);
}


//we stopped at case MENU_OPTIONS::ADD_FAN_TO_PAGE: