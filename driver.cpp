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
	AccountHolder* hol = new AccountHolder;

	vector<AccountHolder*> accountHolderVector;
	vector<BankOfficial*> bankOfficialVector;
	vector<SystemAdmin*> systemAdminVector;
	vector<Account*> userVector;

	userVector.emplace_back(off);
	//userVector.emplace_back(hol);
	bankOfficialVector.emplace_back(off);
	accountHolderVector.emplace_back(hol);
	
	AccountHolder* currentAccountHolder = nullptr;
	BankOfficial* currentBankOfficial = nullptr;
	SystemAdmin* currentAdministrator = nullptr;

	//currentAccountHolder = hol;

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
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                           ACCOUNT HOLDER
//////////////////////////////////////////////////////////////////////////////////////////////////////
						case 1:
						{
							string input;
							bool ifFound = false;
							cout<< "Enter Account UserName"<< endl;
							cin>>input;
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
									int accountHolderSelection = 0;
									do
									{	
									try
									{
										cout << "######################" << endl;
										cout << "[1] Change Password" << endl;
										cout << "[2] View Accounts Information" << endl;
										cout << "[3] View Account Transaction History" << endl;
										cout << "[4] logout" << endl;
										cout << "######################" << endl;

										cin >> accountHolderSelection;
										if ((!cin) || (accountHolderSelection < 0) || (accountHolderSelection > 4))
										{
											throw accountHolderSelection;
										}
										switch(accountHolderSelection)
										{
											case 1:
											{
												string input;
												cout<<"Please Enter New Password"<<endl;
												cin>>input;
												currentAccountHolder->setPassword(input);
												cout<<"Password Has Been Set Too : "<<currentAccountHolder->getPassword()<<endl;;
												break;
											}
											case 2:
											{
//veiw account Information
											}

											case 3:
											{
//veiw account transaction
											}
										}
									}
									catch(int)
									{
										cout << "Invalid input... Restarting" << endl;
										cin.clear();
										cin.ignore();
									}
									}	while (accountHolderSelection != 4 );
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//              BANK OFFICIALS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
									int bankOfficialSelection = 0;
									do
									{	
									try
									{
										cout << "######################" << endl;
										cout << "[1] open BankAccount" << endl;
										cout << "[2] close BankAccount" << endl;
										cout << "[3] deposit" << endl;
										cout << "[4] withdraw" << endl;
										cout << "[5] Search for account" << endl;
										cout << "[6] logout" << endl;
										cout << "######################" << endl;

										cin >> bankOfficialSelection;
										if ((!cin) || (bankOfficialSelection < 0) || (bankOfficialSelection > 6))
										{
											throw bankOfficialSelection;
										}
										switch(bankOfficialSelection)
										{
											case 1:
											{
												AccountHolder* newUser = currentBankOfficial->openAccount();
												accountHolderVector.emplace_back(newUser);
												break;
											}
											case 2:
											{
//close bank account
											}

											case 3:
											{
												string input;
												bool ifFound = false;
												cout<< "Enter Account Of Deposit UserName"<< endl;
												cin>>input;
												for (int a= 0; a<accountHolderVector.size(); a+=1)
												{

													if (accountHolderVector[a]->getUsername() == input)
													{
														ifFound = true;
														currentAccountHolder = accountHolderVector[a];
													}	
												}
												if (ifFound == true)
												{
													cout<<"Enter Account Password"<<endl;
													cin>>input;
													if (currentBankOfficial->getPassword() == input)
													{
														cout<<"Account SUCCESFULLY LOGGED-IN"<<endl;
// deposite stuff
// currentAccountHolder set to person who wants to make deposit
// still need the specific account of that user to make transactio in

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

											case 4:
											{
												string input;
												bool ifFound = false;
												cout<< "Enter Account Of Withdraw UserName"<< endl;
												cin>>input;
												for (int a= 0; a<accountHolderVector.size(); a+=1)
												{

													if (accountHolderVector[a]->getUsername() == input)
													{
														ifFound = true;
														currentAccountHolder = accountHolderVector[a];
													}	
												}
												if (ifFound == true)
												{
													cout<<"Enter Account Password"<<endl;
													cin>>input;
													if (currentBankOfficial->getPassword() == input)
													{
														cout<<"Account SUCCESFULLY LOGGED-IN"<<endl;
// Withdraw stuff 
// currentAccountHolder set to person who wants to make withdraw
// still need the specific account of that user to make transaction in

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

											case 5:
											{

//search for account
// maybe another jump meanu with search by;
// phonenumber, username, address, name...

											}
										}
									}
									catch(int)
									{
										cout << "Invalid input... Restarting" << endl;
										cin.clear();
										cin.ignore();
									}
									}	while (bankOfficialSelection != 6);

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
////////////////////////////////////////////////////////////////////////////////////////////////////
//                  SYSTEM ADMIN
///////////////////////////////////////////////////////////////////////////////////////////////////
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
									int administratorSelection = 0;
									do
									{	
									try
									{
										cout << "######################" << endl;
										cout << "[1] Create Bank Official" << endl;
										cout << "[2] Disable Bank Official" << endl;
										cout << "[3] Modiffy Bank Account types" << endl;
										cout << "[4] Reteive User login ID" << endl;
										cout << "[5] Change User Password" << endl;
										cout << "[6] Logout" << endl;
										cout << "######################" << endl;

										cin >> administratorSelection;
										if ((!cin) || (administratorSelection < 0) || (administratorSelection > 6))
										{
											throw administratorSelection;
										}
										switch(administratorSelection)
										{
											case 1:
											{
												BankOfficial* newOfficial  = new BankOfficial;
												bankOfficialVector.emplace_back(newOfficial);
												break;
											}
											case 2:
											{
//disable BankOfficial
											}

											case 3:
											{
//modify bank Account types
											}

											case 4:
											{
												cout<< "Enter First Name Account Is Held Under"<<endl;
// retreive user login ID
											}

											case 5:
											{
//chnage user password
											}
										}
									}
									catch(int)
									{
										cout << "Invalid input... Restarting" << endl;
										cin.clear();
										cin.ignore();
									}
									}	while (administratorSelection != 6);

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

