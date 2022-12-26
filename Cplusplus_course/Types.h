#ifndef _TYPES_H
#define _TYPES_H
#pragma warning(disable : 4996)
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <string.h>

#include "Date.h"
#include "Page.h"
#include "Status.h"
#include "Member.h"
#include "Facebook.h"
using namespace std;

class Member;
class Page;
class Status;
class Date;
class Facebook;

constexpr int NOT_FOUND = -1;

string readInputString();


#endif