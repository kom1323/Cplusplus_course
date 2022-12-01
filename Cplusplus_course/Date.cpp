#pragma warning(disable:4996)
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"


Date::Date()
{
    time_t curr_time;
    curr_time = time(NULL);

    char* tm = ctime(&curr_time);
    strcpy(this->mDate, tm);

}

Date::Date(const char* birthDayDate)
{
    strcpy(this->mDate, birthDayDate);
}

const char* Date::getmDate() const
{
    return this->mDate;
}

