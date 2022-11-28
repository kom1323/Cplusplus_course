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


	fuckbook.printAllEntities();

	//startMenu(fuckbook);

	/*Page p("hello");
	Member* m = new Member();

	p.printAllFans();
	p.addFan(m);
	p.printAllFans();
	p.addStatus();
	p.printAllStatus();*/


	/*Date d;
	cout << d.getmDate() << endl;
	Date e("Fab");
	cout << e.getmDate() << endl;*/

	int x;
	cin >> x;

}