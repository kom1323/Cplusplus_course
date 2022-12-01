/*
Project by:
Omer Mualem 207685199
Daniel Omesi 207689092

*/

#include <iostream>
using namespace std;
#include "Facebook.h"


void initFacebookEntities(Facebook &facebook);
void startMenu(Facebook& facebook);


int main()
{
	Facebook facebook;
	initFacebookEntities(facebook);

	startMenu(facebook);

}