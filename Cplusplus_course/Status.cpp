#pragma warning(disable:4996)
#include <iostream>
using namespace std;

#include "Status.h"

Status::Status()
{
	cout << "Please enter a status: ";
	char* str = readInputString();
	this->currStatus = str;
	this->date = Date();
}

Status::Status(const char* status)
{
	char* temp = strdup(status);
	this->currStatus = temp;
	this->date = Date();
}

Status::~Status()
{
	delete[] this->currStatus;
}

const char* Status::getCurrStatus() const
{
	return this->currStatus;
}

Date Status::getDate() const
{
	return this->date;
}