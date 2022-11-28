#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "Status.h"



Status::Status()
{
	cout << "Please enter a status: " << endl;
	char* str = readInputString();
	char* temp = new char[strlen(str) + 1];
	strcpy(temp, str);
	delete[] str;
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