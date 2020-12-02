#include <iostream>
#include "USER.h"
#include "function.h"
#include "BST.h"
#include <fstream>
#include <vector>
using namespace std;

int main()
{

	BST tree; // tree object
	vector<Account> accounts;

	ofstream outFile; // file to write to

	//tree.readFile("accounts.txt"); // reads from accounts.txt at beginning
	outFile.open("accounts.txt"); // writes to accounts.txt at end

	for(;;) {
	cout << "######################" << endl;
	cout << "Welcome to Bear Bank" << endl;
	cout << "[1] Login" << endl;
	cout << "[2] Create an Account" << endl;
	cout << "[3] Exit" << endl;
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
			//login();
			Account newAcc;
			accounts.push_back(newAcc); // inserts new account into accounts vector
			cout << count << endl;
			break;
		}
		case 2: {
			//badAccountCreationRequest(); // an function to error because normal users cannot open accounts
			break;
		}
		case 3: {
			//tree.upload(outFile); // rewrites accounts.txt with information from session
			for (int i = 0; i < accounts.size(); i++) // Inserts account vector into BST
			{
				tree.insert(accounts[i]);
			}
			tree.print(); // testing print function
			outFile.close();
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

