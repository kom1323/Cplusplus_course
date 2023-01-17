#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "Types.h"
#include "Facebook.h"
#include "Date.h"
#include "Status.h"
#include "Member.h"
#include "Page.h"
#include "FacebookExceptions.h"

enum class MENU_OPTIONS {
	ADD_MEMBER = 1, ADD_FAN_PAGE, ADD_MEMBER_STATUS, ADD_PAGE_STATUS,
	PRINT_MEMBER_STATUS, PRINT_PAGE_STATUS, PRINT_RECENT_FRIENDS_STATUS,
	CONNECT_MEMBERS, DISCONNECT_MEMBERS, ADD_FAN_TO_PAGE, REMOVE_FAN_FROM_PAGE,
	PRINT_ALL_ENTITIES, PRINT_MEMBER_FRIENDS, PRINT_PAGE_FANS, EXIT_MENU, START_MENU
};


const char* enumStrings[] = { "Add member", "Add fan page", "Add status to member", "Add status to page",
"Print member statuses", "Print page statuses", "Print recent statuses of a member's friends",
"Friend two members", "Unfriend two members", "Add a fan to a page", "Remove fan from page",
"Print all entities in Facebook", "Print member's friends", "Print page's Fans", "exit" };

constexpr int enumStringSize = 15;
constexpr int BUFFER_SIZE = 256;

void printMenu();
void readMemberName(Facebook& facebook, string& nameInput);
void readPageName(Facebook& facebook, string& nameInput);
void readValidChoice(string& userInput, MENU_OPTIONS& choice, Facebook& facebook);
string readInputString();
void initFacebookEntities(Facebook& facebook);
void newTerminate();
void startMenu(Facebook& facebook);
void isBlank(const string& input) throw(BlankException);
bool getMedia(string& mediaFile);

#endif // !_FUNCTIONS_H

