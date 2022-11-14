#include <iostream>
using namespace std;

#include "Status.h"


const char* Status::getCurrStatus()
{

	return currStatus;
}
Date Status::getDate()
{

	return date;
}


bool Status::setCurrStatus(const char* statusText)
{
	if (currStatus != nullptr)
		delete[] currStatus;

	currStatus = new char[strlen(statusText) + 1];
	strcpy(currStatus, statusText);
	return true;

}
bool Status::setDate(Date& d)
{
	date = d;
	return true;

}

