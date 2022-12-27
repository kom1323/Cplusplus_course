#include <iostream>
using namespace std;

class Father {

public:
	int* a;
	Father(int x) { a = new int(x); };
	Father() = default;
	virtual void print()
	{
		cout << "I am father";
	};
};


class Son : public Father
{
public:
	void print()
	{
		cout<<"I am son";
	};
};


int main()
{
	Father* p= new Son();
	p->print();
}