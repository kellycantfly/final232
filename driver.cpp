#include <iostream>
#include "account.h"
#include "bankaccount.h"
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	int userSelection = 0;
	BankOfficial off;

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
					break;
				}
				case 2:
				{
					off.openAccount();
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

