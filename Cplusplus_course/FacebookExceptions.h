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

class AlreadyFriendsException : public FacebookExceptions
{
public:
	const char* what() const override { return "These two members are already friends!"; }
};

class NotFriendsException : public FacebookExceptions
{
public:
	const char* what() const override { return "These two members are not friends!"; }
};

class SelfException : public FacebookExceptions
{
public:
	const char* what() const override { return "Please choose a different user than yourself!"; }
};

class AlreadyFanException : public FacebookExceptions
{
public:
	const char* what() const override { return "This user is already a fan of this page!"; }
};

class NotFanException : public FacebookExceptions
{
public:
	const char* what() const override { return "This user is not a fan of this page!"; }
};

class InvalidChoiceException : public FacebookExceptions
{
public:
	const char* what() const override { return "This is not a valid choice!"; }
};

#endif