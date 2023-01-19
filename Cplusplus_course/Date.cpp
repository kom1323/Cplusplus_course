#include "Date.h"


Date::Date()
{
    time_t curr_time;
    curr_time = time(NULL);

    this->mDate = ctime(&curr_time);
    this->mDate[mDate.size() - 1] = '\0';
}

Date::Date(const string& birthDayDate) : mDate(birthDayDate)
{
}

const string& Date::getmDate() const
{
    return this->mDate;
}



ostream& operator<<(ostream& os, const Date& d)
{  
    os << d.mDate << endl;
    return os;
}

istream& operator>>(istream& os, Date& d)
{
    getline(os, d.mDate);
    return os;
}
