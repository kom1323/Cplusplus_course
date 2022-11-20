#include <iostream>
using namespace std;
#include "Page.h"
#include "Status.h"
#include "Date.h"
#include "Member.h"

void** addItemToDynamicArray(void** arr, int& arrLogicalSize, int arrPhysicalSize, int itemSize, void* newItem);

int main()
{

	Page p;
	Status s1, s2;
	int size = 1;

	cout << s1.getCurrStatus() << endl;
	cout << s2.getCurrStatus() << endl;

	Status** arr = new Status*[1];

	arr[0] = &s1;
	cout << size << endl;
	cout << arr[0]->getCurrStatus() << endl;

	void** temp = addItemToDynamicArray((void**)arr, size, 1, sizeof(Status*), &s2);
	arr = (Status**)temp;

	cout << size << endl;
	cout << arr[0]->getCurrStatus() << endl;
	cout << arr[1]->getCurrStatus() << endl;



	






}