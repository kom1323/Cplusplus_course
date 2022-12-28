#include "Types.h"
#include "Facebook.h"
#include "Date.h"
#include "Status.h"
#include "Member.h"
#include "Page.h"
#include "FacebookExceptions.h"

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
void readMemberName(Facebook& facebook, string& nameInput);
void readPageName(Facebook& facebook, string& nameInput);

string readInputString()
{
	string input;
	getline(cin, input);

	return input;
}

void initFacebookEntities(Facebook& facebook)
{
	Member* m1,* m2,* m3;
	Page* p1, * p2, * p3;


	Date d1("20/01/2020");
	Date d2("30/02/2020");
	Date d3("12/01/2020");


	m1 = new Member("Daniel", d1);
	m2 = new Member("Omer", d2);
	m3 = new Member("Roey", d3);
	p1 = new Page("Twitter");
	p2 = new Page("Instagram");
	p3 = new Page("Linkedin");
	
	facebook.addMember(m1);
	facebook.addMember(m2);
	facebook.addMember(m3);
	facebook.addPage(p1);
	facebook.addPage(p2);
	facebook.addPage(p3);
	
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


	//TESTING

	if (*m2 > *m3)
		cout << "m1 > m3" << endl;
	else
		cout << "m1 <= m3" << endl;

	if (m2->getStatusList()[0] != m3->getStatusList()[0])
		cout << "m1 same status m2" << endl;

}


void startMenu(Facebook& facebook)
{
	string userInput, nameInput, nameInput2, statusInput;
	Page* page;
	Member* member1, * member2;
	bool isValid;
	cout << "Welcome to the amazing Facebook!" << endl << endl;
	MENU_OPTIONS  choice = MENU_OPTIONS::START_MENU;
	printMenu();
	userInput = readInputString();
	choice = (MENU_OPTIONS)stoi(userInput);


	while (choice != MENU_OPTIONS::EXIT_MENU)
	{
		isValid = false;
		switch (choice)
		{
		case MENU_OPTIONS::ADD_MEMBER:
			facebook.addMember();
			break;

		case MENU_OPTIONS::ADD_FAN_PAGE:
			facebook.addPage();
			break;

		case MENU_OPTIONS::ADD_MEMBER_STATUS:
			while (!isValid)
			{
				facebook.printAllMembers();
				cout << "Choose 1 member of the above by typing his name: ";
				nameInput = readInputString();
				try
				{
					facebook.isMember(nameInput);
					MemberNotFoundException e;
					cout<<e.what()<<endl;
				}
				//isMember function throws an exception if and only if the member exists
				catch (FacebookExceptions& e)
				{
					isValid = true;
				}
			}
			cout << "Please enter a status: ";
			statusInput = readInputString();
			facebook.getMemberByName(nameInput)->addStatus(statusInput);
			break;

		case MENU_OPTIONS::ADD_PAGE_STATUS:
			while (!isValid)
			{
				facebook.printAllPages();
				cout << "Choose 1 page of the above by typing his name: ";
				nameInput = readInputString();
				try
				{
					facebook.isPage(nameInput);
					PageNotFoundException e;
					cout << e.what() << endl;
				}
				//isPage function throws an exception if and only if the member exists
				catch (FacebookExceptions& e)
				{
					isValid = true;
				}
			}
			cout << "Please enter a status: ";
			statusInput = readInputString();
			facebook.getPageByName(nameInput)->addStatus(statusInput);
			break;

		case MENU_OPTIONS::PRINT_MEMBER_STATUS:
			while (!isValid)
			{
				facebook.printAllMembers();
				cout << "Choose 1 member of the above by typing his name: ";
				nameInput = readInputString();
				try
				{
					facebook.isMember(nameInput);
					MemberNotFoundException e;
					cout << e.what() << endl;
				}
				//isMember function throws an exception if and only if the member exists
				catch (FacebookExceptions& e)
				{
					isValid = true;
				}
			}
			facebook.getMemberByName(nameInput)->printAllStatus();
			break;

		case MENU_OPTIONS::PRINT_PAGE_STATUS:
			while (!isValid)
			{
				facebook.printAllPages();
				cout << "Choose 1 page of the above by typing his name: ";
				nameInput = readInputString();
				try
				{
					facebook.isPage(nameInput);
					PageNotFoundException e;
					cout << e.what() << endl;
				}
				//isPage function throws an exception if and only if the page exists
				catch (FacebookExceptions& e)
				{
					isValid = true;
				}
			}
			facebook.getPageByName(nameInput)->printAllStatus();
			break;

		case MENU_OPTIONS::PRINT_RECENT_FRIENDS_STATUS:
			while (!isValid)
			{
				facebook.printAllMembers();
				cout << "Choose 1 member of the above by typing his name: ";
				nameInput = readInputString();
				try
				{
					facebook.isMember(nameInput);
					MemberNotFoundException e;
					cout << e.what() << endl;
				}
				//isMember function throws an exception if and only if the member exists
				catch (FacebookExceptions& e)
				{
					isValid = true;
				}
			}
			facebook.getMemberByName(nameInput)->printLatestStatusesOfFriends();
			break;

		case MENU_OPTIONS::CONNECT_MEMBERS:
			while (!isValid)
			{
				facebook.printAllMembers();
				cout << "Choose 1 member of the above by typing his name: ";
				nameInput = readInputString();
				try
				{
					facebook.isMember(nameInput);
					MemberNotFoundException e;
					cout << e.what() << endl;
				}
				//isMember function throws an exception if and only if the member exists
				catch (FacebookExceptions& e)
				{
					isValid = true;
				}
			}
			if (facebook.printAvailableFriends(nameInput))
			{
				cout << "Please enter the second member's name from the list above: ";
				nameInput2 = readInputString();
				member1 = facebook.getMemberByName(nameInput);
				member2 = facebook.getMemberByName(nameInput2);
				*member1 += *member2;
			}
			else
				cout << "There are no members available to choose from" << endl;
			break;

		case MENU_OPTIONS::DISCONNECT_MEMBERS:
			facebook.printAllMembers();
			cout << "Choose the first member from the list above by typing his name: ";
			nameInput = readInputString();
			if (facebook.printFriendListOfMember(nameInput))
			{
				cout << "Please choose a friend to delete from the list above: ";
				facebook.getMemberByName(nameInput)->printAllFriends();
				cout << "Please enter the second member's name: ";
				nameInput2 = readInputString();
				facebook.getMemberByName(nameInput)->removeFriend(nameInput2);
			}
			else
				cout << "There are no members available to delete" << endl;
			break;

		case MENU_OPTIONS::ADD_FAN_TO_PAGE:
			facebook.printAllPages();
			cout << "Choose 1 page of the above by typing his name: ";
			nameInput = readInputString();
			if (facebook.printAvailableFans(nameInput))
			{
				cout << "Please enter the member's name from the list above: ";
				nameInput2 = readInputString();
				page = facebook.getPageByName(nameInput);
				member1 = facebook.getMemberByName(nameInput2);
				*page += *member1;
			}
			else
				cout << "There are no fans available to choose from" << endl;
			break;

		case MENU_OPTIONS::REMOVE_FAN_FROM_PAGE:
			facebook.printAllPages();
			cout << "Choose 1 page of the above by typing his name: ";
			nameInput = readInputString();
			cout << "Choose from ";
			facebook.getPageByName(nameInput)->printAllFans();
			cout << "Please enter the member's name: ";
			nameInput2 = readInputString();
			facebook.getPageByName(nameInput)->removeFan(nameInput2);
			break;

		case MENU_OPTIONS::PRINT_ALL_ENTITIES:
			facebook.printAllEntities();
			break;

		case MENU_OPTIONS::PRINT_MEMBER_FRIENDS:
			facebook.printAllMembers();
			cout << "Choose the first member from the list above by typing his name: ";
			nameInput = readInputString();
			facebook.getMemberByName(nameInput)->printAllFriends();
			break;

		case MENU_OPTIONS::PRINT_PAGE_FANS:
			facebook.printAllPages();
			cout << "Choose 1 page of the above by typing his name: ";
			nameInput = readInputString();
			facebook.getPageByName(nameInput)->printAllFans();
			break;

		case MENU_OPTIONS::EXIT_MENU:
			exit(1);
			break;

		}

		if (choice != MENU_OPTIONS::EXIT_MENU)
		{
			cout << "-------------------------" << endl;
			printMenu();
			userInput = readInputString();
			choice = (MENU_OPTIONS)stoi(userInput);

		}


	}

}

void newTerminate()
{
	cout << "A problem has occured" << endl;
	exit(1);
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

void readMemberName(Facebook& facebook, string& nameInput)
{
	bool isValid = false;
	while (!isValid)
	{
		facebook.printAllMembers();
		cout << "Choose 1 member of the above by typing his name: ";
		nameInput = readInputString();
		try
		{
			facebook.isMember(nameInput);
			MemberNotFoundException e;
			cout << e.what() << endl;
		}
		//isMember function throws an exception if and only if the member exists
		catch (FacebookExceptions& e)
		{
			isValid = true;
		}
	}
}

void readPageName(Facebook& facebook, string& nameInput)
{
	bool isValid = false;
	while (!isValid)
	{
		facebook.printAllPages();
		cout << "Choose 1 page of the above by typing his name: ";
		nameInput = readInputString();
		try
		{
			facebook.isPage(nameInput);
			PageNotFoundException e;
			cout << e.what() << endl;
		}
		//isPage function throws an exception if and only if the page exists
		catch (FacebookExceptions& e)
		{
			isValid = true;
		}
	}
}
