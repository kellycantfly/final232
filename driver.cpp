#include <iostream>
#include "USER.h"
#include "account.h"
#include "CreateAccount.cpp"
#include "login.cpp"
using namespace std;


int main()
{
	for(;;) {
	cout << "######################" << endl;
	cout << "Welcome to Bear Bank" << endl;
	cout << "[1] Login" << endl;
	cout << "[2] Create an Account" << endl;
	cout << "[3[ Exit" << endl;
	cout << "######################" << endl;
	string buffer = "";
	int userSelection = 0;
	getline(cin,buffer);
	try {
		userSelection = stoi(buffer);
	}catch(...) {
		cout << "Invalid input.. Restarting..." << endl;
		main();
	}
	switch(userSelection) {
		case 1: {
			// login.cpp
			break;
		}
		case 2: {
			badAccountCreationRequest(); // an function to error because normal users cannot open accounts
			break;
		}
		case 3: {
			cout << "Goodbye!" << endl;
			exit(1);
		}
		default: {
			cout << "An error has occured, restarting" << endl;
			main();
		}
	}
	}
	return 0;
}

void menu(int menuType) {
	if(menuType == 1) {

	}
	if(menuType == 2) {

	}
	if (menuType == 3) {

	}
}