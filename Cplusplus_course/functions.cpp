#include <iostream>
using namespace std;



void** addItemToDynamicArray(void** arr, int& arrLogicalSize, int &arrPhysicalSize,int itemSize, void* newItem)
{

	if (arrPhysicalSize == arrLogicalSize)
	{
		void** newArr = new void* [arrPhysicalSize * 2];
		arrPhysicalSize *= 2;

		for (int i = 0; i < arrLogicalSize; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}

	arr[arrLogicalSize] = newItem;
	

	arrLogicalSize++;

	return arr;

}