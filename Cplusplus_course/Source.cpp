/*
Project by:
Omer Mualem 207685199
Daniel Omesi 207689092

*/

#include "Types.h"
#include "Facebook.h"



void startMenu(Facebook& facebook);
void newTerminate();
void saveData(Facebook& facebook);
void getData(Facebook& facebook);

int main()
{
	set_terminate(newTerminate);

	Facebook facebook;

	getData(facebook);
	
	startMenu(facebook);

	saveData(facebook);
}
