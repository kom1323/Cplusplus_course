#ifndef _FACEBOOK_H
#define _FACEBOOK_H

#include "Types.h"


class Facebook
{
private:
    list<Member*> allMembers;
    list<Page*> allPages;
public:
    Facebook() = default;
    ~Facebook();

    bool addMember();
    bool addMember(Member* mem);
    bool addPage();
    bool addPage(Page* pag);
    bool isMember(const char* name);
    bool isPage(const char* name);
    Member* getMemberByName(const char* name);
    Page* getPageByName(const char* name);

    void printAllEntities();
    void printAllMembers();
    void printAllPages();
    bool printAvailableFriends(const char* amigoName);
    bool printFriendListOfMember(const char* name);
    bool printAvailableFans(const char* fanName);
};
#endif