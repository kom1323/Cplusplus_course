#include <iostream>
using namespace std;
#include <fstream>
#include <string>
class A
{
private:
	string a="hello";
public:

};



void main()
{

	
	string* temp = new string("hello");

	int* a = (int*)temp;

	cout << *((string*)a) << endl;
}