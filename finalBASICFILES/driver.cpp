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
								if ((bankOfficialVector[i]->getUsername() == name) && (bankOfficialVector[i]->getPassword() == pass))
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
								cout << accountHolderVector[i]->getUsername() << " " << accountHolderVector[i]->getAccountID() <<endl;
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
					cout << "A system administrator is required to open a new User Account\n";
					if (currentSystemAdmin != NULL) // checks a SystemAdmin is logged in
					{
						try
						{
							Account* temp = currentSystemAdmin->createUser(); // logged in SystemAdmin creates a new Account
							char c = temp->getUsername().at(0); // checks type of opened account by passing username

							if (temp == NULL) // tests for proper user creation
							{
								throw 0; // jumps to error handling creation
							}
							else
							{
								userVector.push_back(temp); // adds user to userVector

								switch (c)
								{
									case 'H':
									{
										// copies Account to AccountHolder object
										AccountHolder* newHolder = new AccountHolder(temp->getAccountID(),temp->getUsername(),temp->getPassword(),temp->getfirstName(),temp->getlastName());
										accountHolderVector.push_back(newHolder); // adds to vector
									}
									case 'A':
									{
										// copies Account to SystemAdmin object
										SystemAdmin* newAdmin = new SystemAdmin(temp->getAccountID(), temp->getUsername(), temp->getPassword(), temp->getfirstName(), temp->getlastName());
										systemAdminVector.push_back(newAdmin); // adds to vector
									}
									case 'O':
									{
										// copies Account to BankOfficial object
										BankOfficial* newOff = new BankOfficial(temp->getAccountID(), temp->getUsername(), temp->getPassword(), temp->getfirstName(), temp->getlastName());
										bankOfficialVector.push_back(newOff); // adds to vector
									}
								}

							}
							delete temp;
						}
						catch (int) // error handling creation
						{
							cout << "User creation failed" << endl;

							cin.clear();
							cin.ignore();
							break;
						}

					}
					else
					{
						cout << "Please log in a valid System Admin\n";
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

	cout << "Goodbye!" << endl;

	delete currentAccountHolder;
	delete currentSystemAdmin;
	delete currentBankOfficial;

	return 0;
}
