#include <iostream>
#include "account.h"
#include "bankaccount.h"
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	int userSelection = 0; // for intial menu
	BankOfficial* off = new BankOfficial; // initial BankOfficial object
	AccountHolder* hol = new AccountHolder; // initial AccountHolder object
	SystemAdmin* admin = new SystemAdmin; // initial SystemAdmin object

	vector<AccountHolder*> accountHolderVector; // holds AccountHolders
	vector<BankOfficial*> bankOfficialVector; // holds BankOfficials
	vector<SystemAdmin*> systemAdminVector; // holds SystemAdmins
	vector<Account*> userVector; // holds Users

	// initial adds to User vector
	userVector.emplace_back(off);
	userVector.emplace_back(hol);
	userVector.emplace_back(admin);

	// initial adds to subclass vectors
	bankOfficialVector.emplace_back(off);
	accountHolderVector.emplace_back(hol);
	systemAdminVector.emplace_back(admin);

	AccountHolder* currentAccountHolder = nullptr; // AccountHolder is currently logged out
	BankOfficial* currentBankOfficial = off; // off is logged in. could be changed
	SystemAdmin* currentSystemAdmin = admin; // admin is logged in. could be changed


	do{

		try
		{
			// *** MAY INCLUDE MORE MENUS FROM ROBERT'S DRIVER AS WE MAKE THEM INTO FUNCTIONS EX. WITHDRAW/CHANGE PASSWORD
			cout << "######################" << endl;
			cout << "Welcome to Bear Bank" << endl;
			cout << "[1] Login" << endl; //
			cout << "[2] Open a Bank Account" << endl;
			cout << "[3] Create a User Account" << endl;
			cout << "[4] Logout" << endl;
			cout << "[5] Exit" << endl;
			cout << "######################" << endl;

			cin >> userSelection;

			if ((!cin) || (userSelection < 0) || (userSelection > 5))
			{
				throw userSelection; // jumps to error handling menu
			}

			switch (userSelection) 
			{
				// *** CURRENTLY WORKING ON THIS. IT WORKS INITIALLY BUT NOT AFTER [3]CREATE USER ACCOUNT
				case 1: // Login
				{
					string name, pass;
					char type;

					// User prompts
					cout << "Username :";
					cin >> name;
					type = name.at(0); // checks for 'C', 'A', or 'O' to read proper subclass vector
					cout << "Password: ";
					cin >> pass;

					cin.clear();
					cin.ignore();

					switch (type)
					{
						case 'O': // Login Official
						{
							// searches existing BankOfficials
							for (int i = 0; i < bankOfficialVector.size(); i++)
							{
								if ((bankOfficialVector[i]->getUsername() == name))
								{
									currentBankOfficial = bankOfficialVector[i];
								}
								else
								{
									cout << "No matching Official\n";
									break;
								}
							}
							break;
						}
						case 'A': // Login System Admin
						{
							// searches existing SystemAdmins
							for (int i = 0; i < systemAdminVector.size(); i++)
							{
								if (systemAdminVector[i]->getUsername() == name)
								{
									currentSystemAdmin = systemAdminVector[i];
								}
								else
								{
									cout << "No matching Admin\n";
									break;
								}
							}
							break;
						}
						case 'H': // Login Account Holder
						{
							// searches existing AccountHolders
							for (int i = 0; i < accountHolderVector.size(); i++)
							{
								if (accountHolderVector[i]->getUsername() == name)
								{
									currentAccountHolder = accountHolderVector[i];
								}
								else
								{
									cout << "No matching Account Holder\n";
									break;
								}
							}

							break;
						}
					}

					break;
				}
				case 2: // Open a Bank Account
				{
					if (currentAccountHolder != NULL) // checks an AccountHolder is logged in
					{
						// logged in BankOfficial opens an account for logged in AccountHolder
						currentBankOfficial->openAccount(currentAccountHolder);
					}
					else
					{
						cout << "Please log in a valid Account Holder\n";

					}

					break;
				}
				// **** CURRENTLY WORKING ON THIS. IT ADDS TO VECTORS BUT BREAKS [1]
				case 3: // Create a User Account
				{
					if (currentSystemAdmin != NULL)
					{
						char type;
						cout << "[A]dmin, [O]fficial, [H]older" << endl;
						try
						{
							cin >> type;
							if ((!cin) && (type != 'A') && (type != 'O') && (type != 'H'))
							{
								throw type; // jumps to error handling menu
							}
							else
							{
								switch (type)
								{
									case 'A': // SystemAdmin
									{
										systemAdminVector.push_back(currentSystemAdmin->createAdmin());
										break;
									}
									case 'O': // BankOfficial
									{
										bankOfficialVector.push_back(currentSystemAdmin->createOffical());
										break;
									}
									case 'H': // AccountHolder
									{
										accountHolderVector.push_back(currentSystemAdmin->createHolder());
										break;
									}
								}
							}
						}
						catch (char) // error handling menu
						{
							cout << "Invalid user account type" << endl;
							cin.clear();
							cin.ignore();
						}
					}
					else
					{
						cout << "Only a System Admin can create a user account. Please log in Admin\n";
					}

					break;
				}
				case 4: // Logout
				{
					currentAccountHolder = NULL;
					currentBankOfficial = NULL;
					currentSystemAdmin = NULL;

					cin.clear();
					cin.ignore();
					break;
				}
			}
		}
		catch(int) // error handling menu
		{
			cout << "Invalid input... Restarting" << endl;
			cin.clear();
			cin.ignore();
		}

	} while (userSelection != 5); // an input of 5 will close the program

	cout << "All users: \n";
	for (int i = 0; i < userVector.size(); i++)
	{
		cout << userVector[i]->getAccountID() << " " << userVector[i]->getUsername() << " " << userVector[i]->getPassword() << endl;
	}

	cout << "SystemAdmins: \n";
	for (int i = 0; i < systemAdminVector.size(); i++)
	{
		cout << systemAdminVector[i]->getAccountID() << " " << systemAdminVector[i]->getUsername() << " " << systemAdminVector[i]->getPassword() << endl;
	}

	cout << "Goodbye!" << endl;

	delete currentAccountHolder;
	delete currentSystemAdmin;
	delete currentBankOfficial;

	return 0;
}
