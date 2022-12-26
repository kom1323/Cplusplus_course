#include <iostream>
using namespace std;

class Page {

public:
	int* a;
	Page(int x) { a = new int(x); };
	/*Page(const Page& other);
	Page(Page&& other);
	*/
	~Page();


};

//Page::Page(const Page& other)
//{
//	
//}
//Page::Page(Page&& other)
//{
//
//}
//
Page::~Page()
{
	if (a)
		cout << "Deleting " << *(this->a) << endl;
	else
		cout << "Deleting Null pointer" << endl;
	delete this->a;
}

int& foo(int &y) {

	
	return ++y;
}

int main()
{
	int* c = new int();
	int a = 3;
	a = foo(a);

	cout << "a: " << a << endl;

	cin >> *c;
	return 1;
}