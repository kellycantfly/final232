#include <iostream>
#include "function.h"
#include "BST.h"
#include "USER.h"
#include <fstream>
#include <vector>
using namespace std;

int main()
{

	OFFICAL o; // initial official to open/close accounts
//	HOLDER h;
	vector<USER> users; // Used to search and confirm user information

//	users.push_back(h);
	users.push_back(o);
	int userSelection = 0;

	do{

		try
		{
			cout << "######################" << endl;
			cout << "Welcome to Bear Bank" << endl;
			cout << "[1] Login" << endl;
			cout << "[2] Create an Account" << endl;
			cout << "[3] Exit" << endl;
			cout << "######################" << endl;

			cin >> userSelection;
			if ((!cin) || (userSelection < 0) || (userSelection > 3))
			{
				throw userSelection;
			}

			switch (userSelection) 
			{
				case 1:
				{
					login(users);
					break;
				}
				case 2:
				{
					break;
				}
			}
		}
		catch(int)
		{
			cout << "Invalid input... Restarting" << endl;
			cin.clear();
			cin.ignore();
		}

	} while (userSelection != 3);

	cout << "Goodbye!" << endl;

	return 0;
}

