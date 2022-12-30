#include "Functions.h"


void startMenu(Facebook& facebook)
{
	string userInput, nameInput, nameInput2, statusInput;
	Page* page;
	Member* member1, * member2;
	bool isValid;
	cout << "Welcome to the amazing Facebook!" << endl << endl;
	MENU_OPTIONS  choice = MENU_OPTIONS::START_MENU;
	readValidChoice(userInput, choice, facebook);

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
			readMemberName(facebook, nameInput);
			cout << "Please enter a status: ";
			statusInput = readInputString();
			facebook.getMemberByName(nameInput)->addStatus(statusInput);
			break;

		case MENU_OPTIONS::ADD_PAGE_STATUS:
			readPageName(facebook, nameInput);
			cout << "Please enter a status: ";
			statusInput = readInputString();
			facebook.getPageByName(nameInput)->addStatus(statusInput);
			break;

		case MENU_OPTIONS::PRINT_MEMBER_STATUS:
			readMemberName(facebook, nameInput);
			facebook.getMemberByName(nameInput)->printAllStatus();
			break;

		case MENU_OPTIONS::PRINT_PAGE_STATUS:
			readPageName(facebook, nameInput);
			facebook.getPageByName(nameInput)->printAllStatus();
			break;

		case MENU_OPTIONS::PRINT_RECENT_FRIENDS_STATUS:
			readMemberName(facebook, nameInput);
			facebook.getMemberByName(nameInput)->printLatestStatusesOfFriends();
			break;

		case MENU_OPTIONS::CONNECT_MEMBERS:
			readMemberName(facebook, nameInput);
			member1 = facebook.getMemberByName(nameInput);
				if (member1->getFriendsList().size() == (facebook.getMembersList().size()-1) )
					cout << "No members available to add as friends to this user" << endl;
				else
				{
					while (!isValid)
					{
						facebook.printAvailableFriends(nameInput);
						cout << "Choose the second member from the above by typing his name: ";
						nameInput2 = readInputString();
						try
						{
							isBlank(nameInput2);
							facebook.isNotMember(nameInput2);
							member1->isMe(nameInput2);
							member2 = facebook.getMemberByName(nameInput2);
							member1->checkFriendship(nameInput2);
							isValid = true;
						}
						catch (FacebookExceptions& e)
						{
							cout << e.what() << endl;
						}
					}
					member2 = facebook.getMemberByName(nameInput2);
					*member1 += *member2;
				}
			break;

		case MENU_OPTIONS::DISCONNECT_MEMBERS:
			readMemberName(facebook, nameInput);
			member1 = facebook.getMemberByName(nameInput);
			if (member1->getFriendsList().size() == 0)
				cout << "No members available to remove from this user" << endl;
			else
			{
				while (!isValid)
				{
					facebook.printFriendListOfMember(nameInput);
					cout << "Please choose a friend to delete from the list above: ";
					nameInput2 = readInputString();
					try
					{
						isBlank(nameInput2);
						facebook.isNotMember(nameInput2);
						member1->isMe(nameInput2);
						member2 = facebook.getMemberByName(nameInput2);
						member1->checkNotFriendship(nameInput2);
						isValid = true;
					}
					catch (FacebookExceptions& e)
					{
						cout << e.what() << endl;
					}
				}
				member1->removeFriend(nameInput2);
			}
			break;

		case MENU_OPTIONS::ADD_FAN_TO_PAGE:
			readPageName(facebook, nameInput);
			page = facebook.getPageByName(nameInput);
			if (page->getFanListSize() == (facebook.getMembersList().size() - 1))
				cout << "No members available to add as fans to this page" << endl;
			else
			{
				while (!isValid)
				{
					facebook.printAvailableFans(nameInput);
					cout << "Please enter the member's name from the list above: ";
					nameInput2 = readInputString();
					try
					{
						isBlank(nameInput2);
						facebook.isNotMember(nameInput2);
						page->checkFanship(nameInput2);
						isValid = true;
					}
					catch (FacebookExceptions& e)
					{
						cout << e.what() << endl;
					}
				}
				member1 = facebook.getMemberByName(nameInput2);
				*page += *member1;
			}
			break;

		case MENU_OPTIONS::REMOVE_FAN_FROM_PAGE:
			readPageName(facebook, nameInput);
			page = facebook.getPageByName(nameInput);
			if (page->getFanListSize() == 0)
				cout << "No members available to remove from this page fan list" << endl;
			else
			{
				while (!isValid)
				{
					cout << "Fans available to delete:" << endl;
					facebook.getPageByName(nameInput)->printAllFans();
					cout << "Please enter the member's name from the list above: ";
					nameInput2 = readInputString();
					try
					{
						isBlank(nameInput2);
						facebook.isNotMember(nameInput2);
						page->checkNotFanship(nameInput2);
						isValid = true;
					}
					catch (FacebookExceptions& e)
					{
						cout << e.what() << endl;
					}
				}
				page->removeFan(nameInput2);
			}
			break;

		case MENU_OPTIONS::PRINT_ALL_ENTITIES:
			facebook.printAllEntities();
			break;

		case MENU_OPTIONS::PRINT_MEMBER_FRIENDS:
			readMemberName(facebook, nameInput);
			facebook.getMemberByName(nameInput)->printAllFriends();
			break;

		case MENU_OPTIONS::PRINT_PAGE_FANS:
			readPageName(facebook, nameInput);
			facebook.getPageByName(nameInput)->printAllFans();
			break;

		case MENU_OPTIONS::EXIT_MENU:
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}

		if (choice != MENU_OPTIONS::EXIT_MENU)
		{
			cout << "-------------------------" << endl;
			readValidChoice(userInput, choice, facebook);
		}


	}

}

void newTerminate()
{
	cout << "A problem has occured" << endl;
	exit(1);
}


void readValidChoice(string& userInput, MENU_OPTIONS& choice,Facebook& facebook)
{
	bool isValid = false;
	while (!isValid)
	{
		printMenu();
		userInput = readInputString();
		try
		{
			isBlank(userInput);
			facebook.isNumber(userInput);
			choice = (MENU_OPTIONS)stoi(userInput);
			isValid = true;
		}
		catch (FacebookExceptions& e)
		{
			cout << e.what() << endl;
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
			isBlank(nameInput);
			facebook.isNotMember(nameInput);
			isValid = true;
			
		}
		//isMember function throws an exception if and only if the member exists
		catch (FacebookExceptions& e)
		{
			cout << e.what() << endl;
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
			isBlank(nameInput);
			facebook.isNotPage(nameInput);
			isValid = true;
		}
		//isPage function throws an exception if and only if the page exists
		catch (FacebookExceptions& e)
		{
			cout << e.what() << endl;
		}
	}
}

string readInputString()
{
	string input;
	getline(cin, input);

	return input;
}


void initFacebookEntities(Facebook& facebook)
{
	Member* m1, * m2, * m3;
	Page* p1, * p2, * p3;


	Date d1("06/11/2020");
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
}

void isBlank(const string& input) throw(BlankException)
{
	if (input.size() == 0)
		throw BlankException();
}
