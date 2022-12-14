#ifndef _FACEBOOK_H
#define _FACEBOOK_H

#include "Types.h"

const int LIST_STARTING_SIZE = 1;



class Facebook
{
private:

    Member** allMembers;
    Page** allPages;
    int membersLogSize, membersPhySize,
        pagesLogSize, pagesPhySize;

public:

    Facebook() {};
    ~Facebook();


    bool addMember();
    bool removeMember(const char* name);
    bool addPage();
    bool removePage(const char* name);

    void printAllEntities();




};


#endif