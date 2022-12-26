#include "Date.h"
using namespace std;

Date::Date()
{
    time_t curr_time;
    curr_time = time(NULL);

    this->mDate = ctime(&curr_time);
}

Date::Date(const string& birthDayDate) : mDate(birthDayDate)
{
}

const string& Date::getmDate() const
{
    return this->mDate;
}

