#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "Status.h"
#include "Date.h"


int x = 1;

Status::Status()
{
	currStatus = new char[7];
	strcpy(currStatus,"hello");
	currStatus[5] = x;
	currStatus[6] = '\0';
	x++;


}



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

