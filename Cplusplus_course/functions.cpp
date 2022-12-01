#include <iostream>
using namespace std;
#include "Facebook.h"
#include "Date.h"
#include "Status.h"
#include "Member.h"
#include "Page.h"
#include <string>

enum class MENU_OPTIONS {ADD_MEMBER=1, ADD_FAN_PAGE, ADD_MEMBER_STATUS, ADD_PAGE_STATUS,
					PRINT_MEMBER_STATUS, PRINT_PAGE_STATUS, PRINT_RECENT_FRIENDS_STATUS,
					CONNECT_MEMBERS, DISCONNECT_MEMBERS, ADD_FAN_TO_PAGE, REMOVE_FAN_FROM_PAGE,
					PRINT_ALL_ENTITIES, PRINT_MEMBER_FRIENDS, PRINT_PAGE_FANS, EXIT_MENU, START_MENU};


const char* enumStrings[] = {"Add member", "Add fan page", "Add status to member", "Add status to page",
"Print member statuses", "Print page statuses", "Print recent statuses of a member's friends",
"Friend two members", "Unfriend two members", "Add a fan to a page", "Remove fan from page",
"Print all entities in Facebook", "Print member's friends", "Print page's Fans", "exit"};

constexpr int enumStringSize = 15;
constexpr int BUFFER_SIZE = 256;

void printMenu();

char* readInputString()
{
	char* stringFromUser = new char[BUFFER_SIZE];
	cin.getline(stringFromUser, BUFFER_SIZE, '\n');

	return stringFromUser;
}

void initFacebookEntities(Facebook& fuckbook)
{
	Member* m1,* m2,* m3;
	Page* p1, * p2, * p3;

	m1 = new Member("Daniel", "20/01/2020");
	m2 = new Member("Omer", "20/01/2020");
	m3 = new Member("Roey", "20/01/2020");
	p1 = new Page("Twitter");
	p2 = new Page("Instagram");
	p3 = new Page("Linkedin");
	
	fuckbook.addMember(m1);
	fuckbook.addMember(m2);
	fuckbook.addMember(m3);
	fuckbook.addPage(p1);
	fuckbook.addPage(p2);
	fuckbook.addPage(p3);
	
	m1->addStatus("This is Daniel's status");
	m2->addStatus("This is Omer's status");
	m2->addStatus("This is Omer's second status");
	m3->addStatus("This is Roey's status");

	p1->addStatus("This is Twitter's status");
	p2->addStatus("This is instagram's status");
	p3->addStatus("This is linkedin's status");

	m1->addFriend(m2);
	m1->addFavPage(p1);

	m3->addFriend(m2);
	m3->addFavPage(p3);

	m2->addFavPage(p2);
}


void startMenu(Facebook& fuckbook)
{
	char* userInput;
	char* nameInput, *nameInput2;
	cout << "Welcome to the amazing Facebook!" << endl<<endl;
	MENU_OPTIONS  choice = MENU_OPTIONS::START_MENU;
	printMenu();
	userInput = readInputString();
	choice = (MENU_OPTIONS)stoi(userInput);


	while (choice != MENU_OPTIONS::EXIT_MENU)
	{
		nameInput = nullptr;
		nameInput2 = nullptr;
		switch (choice)
		{
			case MENU_OPTIONS::ADD_MEMBER:
				fuckbook.addMember();
				break;

			case MENU_OPTIONS::ADD_FAN_PAGE:
				fuckbook.addPage();
				break;

			case MENU_OPTIONS::ADD_MEMBER_STATUS:
				fuckbook.printAllMembers();
				cout << "Choose 1 member of the above by typing his name: ";
				nameInput = readInputString();
				fuckbook.getMemberByName(nameInput)->addStatus();
				break;

			case MENU_OPTIONS::ADD_PAGE_STATUS:
				fuckbook.printAllPages();
				cout << "Choose 1 page of the above by typing his name: ";
				nameInput = readInputString();
				fuckbook.getPageByName(nameInput)->addStatus();
				break;

			case MENU_OPTIONS::PRINT_MEMBER_STATUS:
				fuckbook.printAllMembers();
				cout << "Choose 1 member of the above by typing his name: ";
				nameInput = readInputString();
				fuckbook.getMemberByName(nameInput)->printAllStatus();
				break;

			case MENU_OPTIONS::PRINT_PAGE_STATUS:
				fuckbook.printAllPages();
				cout << "Choose 1 page of the above by typing his name: ";
				nameInput = readInputString();
				fuckbook.getPageByName(nameInput)->printAllStatus();
				break;

			case MENU_OPTIONS::PRINT_RECENT_FRIENDS_STATUS:
				fuckbook.printAllMembers();
				cout << "Choose 1 member of the above by typing his name: ";
				nameInput = readInputString();
				fuckbook.getMemberByName(nameInput)->printLatestStatusesOfFriends();
				break;

			case MENU_OPTIONS::CONNECT_MEMBERS:
				fuckbook.printAllMembers();
				cout << "Choose the first member from the list above by typing his name: ";
				nameInput = readInputString();
				if (fuckbook.printAvailableFriends(nameInput))
				{
					cout << "Please enter the second member's name from the list above: ";
					nameInput2 = readInputString();
					fuckbook.getMemberByName(nameInput)->addFriend(fuckbook.getMemberByName(nameInput2));
				}
				else
					cout << "There are no members available to choose from" << endl;
				break;

			case MENU_OPTIONS::DISCONNECT_MEMBERS:
				fuckbook.printAllMembers();
				cout << "Choose the first member from the list above by typing his name: ";
				nameInput = readInputString();
				if (fuckbook.printFriendListOfMember(nameInput))
				{
					cout << "Please choose a friend to delete from the list above: ";
					fuckbook.getMemberByName(nameInput)->printAllFriends();
					cout << "Please enter the second member's name: ";
					nameInput2 = readInputString();
					fuckbook.getMemberByName(nameInput)->removeFriend(nameInput2);
				}
				else
					cout << "There are no members available to delete" << endl;
				break;

			case MENU_OPTIONS::ADD_FAN_TO_PAGE:
				fuckbook.printAllPages();
				cout << "Choose 1 page of the above by typing his name: ";
				nameInput = readInputString();
				if (fuckbook.printAvailableFans(nameInput))
				{
					cout << "Please enter the member's name from the list above: ";
					nameInput2 = readInputString();
					fuckbook.getPageByName(nameInput)->addFan(fuckbook.getMemberByName(nameInput2));
				}
				else
					cout << "There are no fans available to choose from" << endl;
				break;

			case MENU_OPTIONS::REMOVE_FAN_FROM_PAGE:
				fuckbook.printAllPages();
				cout << "Choose 1 page of the above by typing his name: ";
				nameInput = readInputString();
				cout << "Choose from ";
				fuckbook.getPageByName(nameInput)->printAllFans();
				cout << "Please enter the member's name: ";
				nameInput2 = readInputString();
				fuckbook.getPageByName(nameInput)->removeFan(nameInput2);
				break;

			case MENU_OPTIONS::PRINT_ALL_ENTITIES:
				fuckbook.printAllEntities();
				break;

			case MENU_OPTIONS::PRINT_MEMBER_FRIENDS:
				fuckbook.printAllMembers();
				cout << "Choose the first member from the list above by typing his name: ";
				nameInput = readInputString();
				fuckbook.getMemberByName(nameInput)->printAllFriends();
				break;

			case MENU_OPTIONS::PRINT_PAGE_FANS:
				fuckbook.printAllPages();
				cout << "Choose 1 page of the above by typing his name: ";
				nameInput = readInputString();
				fuckbook.getPageByName(nameInput)->printAllFans();
				break;

			case MENU_OPTIONS::EXIT_MENU:
				exit(1);
				break;

		}
		delete[] nameInput;
		delete[] nameInput2;
		delete[] userInput;

		if (choice != MENU_OPTIONS::EXIT_MENU)
		{
			cout << "-------------------------" << endl;
			printMenu();
			userInput = readInputString();
			choice = (MENU_OPTIONS)stoi(userInput);

		}
		

	}

}


void printMenu()
{
	cout << "Please enter desired action by number:" << endl;
	for (int i = 0; i < enumStringSize; i++)
	{
		cout << i + 1 << ". " << enumStrings[i] << endl;
	}
	cout << "Your choice: ";
}
