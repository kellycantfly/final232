#include <iostream>
#include "account.h"
#include "bankaccount.h"
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	int userSelection = 0;
	BankOfficial* off  = new BankOfficial;

	vector<AccountHolder*> accountHolderVector;
	vector<BankOfficial*> bankOfficialVector;
	vector<SystemAdmin*> systemAdminVector;

	bankOfficialVector.emplace_back(off);
	
	AccountHolder* currentAccountHolder = nullptr;
	BankOfficial* currentBankOfficial = nullptr;
	SystemAdmin* currentAdministrator = nullptr;

	
	//currentBankOfficial = off;

	do{

		try
		{
			cout << "######################" << endl;
			cout << "Welcome to Bear Bank" << endl;
			cout << "[1] Login" << endl;
			cout << "[2] Exit" << endl;
			cout << "######################" << endl;

			cin >> userSelection;
			if ((!cin) || (userSelection < 0) || (userSelection > 2))
			{
				throw userSelection;
			}

			switch (userSelection) 
			{
				case 1:
				{
					try
					{
					int userSelection2 = 0;
					cout << "######################" << endl;
					cout << "Welcome to Bear Bank" << endl;
					cout << "[1] AccountHolder" << endl;
					cout << "[2] BankOfficial" << endl;
					cout << "[3] Admin" << endl;
					cout << "######################" << endl;
					cin >> userSelection2;

					if ((!cin) || (userSelection2 < 0) || (userSelection2 > 3))
					{
						throw userSelection2;
					}

					switch (userSelection2) 
					{
						case 1:
						{
							string input;
							bool ifFound = false;
							cout<< " Enter Account UserName"<< endl;
							getline(cin,input);
							for (int a= 0; a<accountHolderVector.size(); a+=1)
							{
								if (accountHolderVector[a]->getUsername() == input);
								{
									ifFound = true;
									currentAccountHolder = accountHolderVector[a];
								}
							}

							if (ifFound == true)
							{
								cout<<"Enter Account Password"<<endl;
								cin>>input;
								if (currentAccountHolder->getPassword() == input)
								{
									cout<<" SUCCESFUL LOGIN"<<endl;
								}

								else
								{
									cout<<"INVALID PASSWORD"<<endl;
								}
							}

							else
							{
								cout<< "INVALID USERNAME"<<endl;
							}
							break;

						}

						case 2:
						{
							string input;
							bool ifFound = false;
							cout<< "Enter Account UserName"<< endl;
							cin>>input;
							for (int a= 0; a<bankOfficialVector.size(); a+=1)
							{

								if (bankOfficialVector[a]->getUsername() == input)
								{
									ifFound = true;
									currentBankOfficial = bankOfficialVector[a];
								}
							}

							if (ifFound == true)
							{
								cout<<"Enter Account Password"<<endl;
								cin>>input;
								if (currentBankOfficial->getPassword() == input)
								{
									cout<<" SUCCESFUL LOGIN"<<endl;
								}
								else
								{
									cout<<"INVALID PASSWORD"<<endl;
								}
							}
							else
							{
								cout<< "INVALID USERNAME"<<endl;
							}
							break;
						}

						case 3:
						{
							string input;
							bool ifFound = false;
							cout<< "Enter Account UserName"<< endl;
							cin>>input;
							for (int a= 0; a<systemAdminVector.size(); a+=1)
							{

								if (systemAdminVector[a]->getUsername() == input)
								{
									ifFound = true;
									currentAdministrator = systemAdminVector[a];
								}
							}

							if (ifFound == true)
							{
								cout<<"Enter Account Password"<<endl;
								cin>>input;
								if (currentAdministrator->getPassword() == input)
								{
									cout<<" SUCCESFUL LOGIN"<<endl;
								}
								else
							{
								cout<< "INVALID PASSWORD"<<endl;
							}
							}
							else
							{
								cout<< "INVALID USERNAME"<<endl;
							}
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

					break;
				}
				/*case 2:
				{
					if (currentBankOfficial != nullptr)
					{
						accountHolderVector.emplace_back(currentBankOfficial->openAccount());
					}
					else
					{
						cout<< " A Bank Official must be logged in to Open a new Account"<<endl;
					}
					break;
				}*/
			}
		}
		catch(int)
		{
			cout << "Invalid input... Restarting" << endl;
			cin.clear();
			cin.ignore();
		}

	} while (userSelection != 2);

	cout << "Goodbye!" << endl;
;
	return 0;
}

