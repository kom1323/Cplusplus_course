#ifndef _FacebookExceptions_H
#define _FacebookExceptions_H

#include "Types.h"

class FacebookExceptions : public std::exception
{
public:
	virtual const char* what() const override { return "Error!"; }
};

class InvalidNameException : public FacebookExceptions
{
public:
	const char* what() const override { return "This name is invalid! Name can only contain alphabetic characters"; }
};

class NameExistException : public FacebookExceptions
{
public:
	const char* what() const override { return "This name already exists!"; }
};

class DateFormatException : public FacebookExceptions
{
public:
	const char* what() const override { return "This format is wrong! Date can only be dd/mm/yyyy"; }
};

class MemberNotFoundException : public FacebookExceptions
{
public:
	const char* what() const override { return "This member is not found!"; }
};

class PageNotFoundException : public FacebookExceptions
{
public:
	const char* what() const override { return "This page is not found!"; }
};

class AlreadyFriends : public FacebookExceptions
{
public:
	const char* what() const override { return "These two members are already friends!"; }
};


#endif