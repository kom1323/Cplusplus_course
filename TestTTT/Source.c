#include <iostream>
using namespace std;

#include <string>

class A
{
private:
	int a;
public:
	A()
	{
		a = 3;
		cout << "In A's constructor" << endl;
	}
};

class B : public A
{
private:
	int b;
public:
	B()
	{
		b = 5;
		cout << "In B's constructor" << endl;
	}


};

void main()
{
	int * const a = new int;
	int b = 8;

	*a = 8;
	cout << *a << endl;
}