#ifndef _FACEBOOK_H
#define _FACEBOOK_H

#include "Types.h"
#include "Page.h"
#include "Member.h"
#include <list>


class Facebook
{
private:
    list<Member*> allMembers;
    list<Page*> allPages;
public:
    Facebook() = default;
    ~Facebook();

    bool addMember(Member* mem);
    bool addMember();
    bool addPage();
    bool addPage(Page* pag);

    bool isMember(const string& name);
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