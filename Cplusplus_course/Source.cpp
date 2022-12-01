#include <iostream>
using namespace std;
#include "Facebook.h"


void initFacebookEntities(Facebook &fuckbook);
void startMenu(Facebook& fuckbook);




int main()
{


	Facebook fuckbook;
	initFacebookEntities(fuckbook);

	startMenu(fuckbook);

	//go over all destructors
	//check if copy and move constructos is needed




}