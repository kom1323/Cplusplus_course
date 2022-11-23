#include <iostream>
using namespace std;
#include "Facebook.h"
#include "Date.h"
#include "Member.h"
#include "Page.h"
#include "Status.h"

void initFacebookEntities(Facebook &fuckbook);
void startMenu(Facebook& fuckbook);


int main()
{

	Facebook fuckbook;

	initFacebookEntities(fuckbook);

	startMenu(fuckbook);



}