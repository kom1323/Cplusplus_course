#ifndef _FACEBOOK_H
#define _FACEBOOK_H

#include "Types.h"
#include "Page.h"
#include "Member.h"
#include <list>
#include "FacebookExceptions.h"

class Facebook
{
private:
    list<Member*> allMembers;
    list<Page*> allPages;

    void isBirthdayValid(const string& birthday) const throw(DateFormatException);
    void isNameValid(string& name) const throw(InvalidNameException);
public:
    Facebook() = default;
    ~Facebook();

    bool addMember(Member* mem);
    bool addMember();
    bool addPage();
    bool addPage(Page* pag);

    void getMember(string& name, string& dateOfBirth);
    bool isMember(const string& name) throw(NameExistException);
    bool isPage(const string& name);
    Member* getMemberByName(const string& name);
    Page* getPageByName(const string& name);

    void printAllEntities();
    void printAllMembers();
    void printAllPages();
    bool printAvailableFriends(const string& amigoName);
    bool printFriendListOfMember(const string& name);
    bool printAvailableFans(const string& fanName);
};
#endif