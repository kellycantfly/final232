#include <iostream>
#include "account.h"
#include "bankaccount.h"
#include <fstream>
#include <vector>
using namespace std;

int main()
{

	ofstream outFile("account.txt",ios::app);

	int userSelection = 0; // for intial menu
	BankOfficial* off = new BankOfficial; // initial BankOfficial object
	AccountHolder* hol = new AccountHolder; // initial AccountHolder object
	//SystemAdmin* admin = new SystemAdmin; // initial SystemAdmin object

	vector<AccountHolder*> accountHolderVector; // holds AccountHolders
	vector<BankOfficial*> bankOfficialVector; // holds BankOfficials
	vector<SystemAdmin*> systemAdminVector; // holds SystemAdmins

	// initial adds to subclass vectors
	bankOfficialVector.emplace_back(off);
	accountHolderVector.emplace_back(hol);
	//systemAdminVector.emplace_back(admin);

	AccountHolder* currentAccountHolder = hol; // AccountHolder is currently logged out
	BankOfficial* currentBankOfficial = off; // off is logged in. could be changed
	SystemAdmin* currentSystemAdmin = nullptr; // admin is logged in. could be changed


	do {

		try
		{
			// *** MAY INCLUDE MORE MENUS FROM ROBERT'S DRIVER AS WE MAKE THEM INTO FUNCTIONS EX. WITHDRAW/CHANGE PASSWORD
			cout << "######################" << endl;
			cout << "Welcome to Bear Bank" << endl;
			cout << "[1] Login" << endl; //
			cout << "[2] Open a Bank Account" << endl;
			cout << "[3] Create a User Account" << endl;
			cout << "[4] Logout" << endl;
			cout << "[5] Close Account" << endl;
			cout << "[6] Exit" << endl;
			cout << "######################" << endl;

			cin >> userSelection;

			if ((!cin) || (userSelection < 0) || (userSelection > 6))
			{
				throw userSelection; // jumps to error handling menu
			}

			switch (userSelection)
			{
				case 1: // Login
				{
					string name, pass;
					char type;
					int userSelection2 = 0; // 1 = Official, 2 = Admin, 3 = Holder

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
									userSelection2 = 1;
									cout << "Successful login\n";
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
									userSelection2 = 2;
									cout << "Successful login\n";
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
									userSelection2 = 3;
									cout << "Successful login\n";
								}
							}

							break;
						}
					}

					break;
				} // ***END CASE 1***
				case 2: // Open a Bank Account
				{
					if (currentAccountHolder != NULL) // checks an AccountHolder is logged in
					{
						if (currentBankOfficial != NULL) // checks a BankOfficial is logged in
						{
							// logged in BankOfficial opens an account for logged in AccountHolder
							currentBankOfficial->openAccount(currentAccountHolder);
						}
						else
						{
							cout << "Please log in a valid Bank Official\n";
						}
					}
					else
					{
						cout << "Please log in a valid Account Holder\n";

					}

					break;
				}// ***END CASE 2***
				case 3: // Create a User Account
				{
					if (currentSystemAdmin != NULL) // checks a SystemAdmin is logged in
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
				}// ***END CASE 3***
				case 4: // Logout
				{
					currentAccountHolder = NULL;
					currentBankOfficial = NULL;
					currentSystemAdmin = NULL;

					cin.clear();
					cin.ignore();
					break;
				}// ***END CASE 4***
				case 5: // Close Account
				{
					if (currentAccountHolder != NULL) // checks an AccountHolder is logged in
					{
						if (currentBankOfficial != NULL) // checks a BankOfficial is logged in
						{
							// logged in BankOfficial closes an account for logged in AccountHolder
							currentBankOfficial->closeAccount(currentAccountHolder, outFile);
						}
						else
						{
							cout << "Please log in a valid Bank Official\n";
						}
					}
					else
					{
						cout << "Please log in a valid Account Holder\n";

					}
					break;
				}
			}// ***END SWITCH STATEMENT***
		} // ***END MENU***
		catch (int) // error handling menu
		{
			cout << "Invalid input... Restarting" << endl;
			cin.clear();
			cin.ignore();
		}

	} while (userSelection != 6); // an input of 6 will close the program




	cout << "SystemAdmins: \n";
	for (int i = 0; i < systemAdminVector.size(); i++)
	{
		cout << systemAdminVector[i]->getUsername() << endl;
	}

	cout << "BankOfficials: \n";
	for (int i = 0; i < bankOfficialVector.size(); i++)
	{
		cout << bankOfficialVector[i]->getUsername() << endl;
	}

	cout << "AccountHolders: \n";
	for (int i = 0; i < accountHolderVector.size(); i++)
	{
		cout << accountHolderVector[i]->getUsername() << endl;
	}

	cout << "Goodbye!" << endl;

	delete currentAccountHolder;
	delete currentSystemAdmin;
	delete currentBankOfficial;

	return 0;
}
