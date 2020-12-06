#include "Classes/official.h"
#include "Classes/admin.h"
#include "Classes/accountHolder.h"
#include "driverMenu.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

accountHolder createAccount();
void officialMenu(official currentUser, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients) {
    loadUsers(officials,admins,clients);
    cout << "##############" << endl;
    cout << " OFFICIAL MENU " << endl;
    cout << " [1] OPEN ACCOUNT " << endl;
    cout << " [2] CLOSE OR RE-OPEN AN ACCOUNT  " << endl;
    cout << " [3] SEARCH ACCOUNTS " << endl;
    cout << " [4] DEPOSIT OR WITHDRAW FROM CLIENT ACCOUNTS" << endl;
    cout << " [5] LOG-OUT " << endl; 
    cout << "##############" << endl;
    string buffer = "";
    getline(cin, buffer);
    int userSelection = stoi(buffer);
    switch(userSelection) {
        case 1: {
           clients.push_back(createAccount());
           officialMenu(currentUser, officials, admins, clients);
        }
        case 2: {
             cout << "Enter the Account Holder's username: " << endl;
                string buffer = "";
                getline(cin, buffer);
                string username = buffer;
                for(int i = 0; i < clients.size(); i++) {
                    if(clients[i].getUserName() == username) {
                        string status = clients[i].getStatus();
                        cout << clients[i].getStatus() << endl;
                        if(status.length() <= 7) {
                            cout << "##############" << endl;
                            cout << "User: " << username << endl;
                            cout << "Status: Open" << endl;
                            cout << "[1] Close Account " << endl;
                            cout << "[2] Return To Menu" << endl;
                            cout << "##############" << endl;
                            string buffer = "";
                            getline(cin, buffer);
                            int userSelection = stoi(buffer);
                            if(userSelection == 1) {
                                clients[i].disableAccount(currentUser.getUserID());
                                clients[i].saveClient();
                                officialMenu(currentUser, officials, admins, clients);
                            } else {
                                officialMenu(currentUser, officials, admins, clients);
                            }
                            
                        }else {
                            cout << "##############" << endl;
                            cout << "User: " << username << endl;
                            cout << "Status: Closed by " << status.substr(9, status.length()) << endl;
                            cout << "[1] Re-Open Account" << endl;
                            cout << "[2] Return To Menu" << endl;
                            cout << "##############" << endl;
                            string buffer = "";
                            getline(cin, buffer);
                            int userSelection = stoi(buffer);
                            if(userSelection == 1) {
                                clients[i].enableAccount();
                                clients[i].saveClient();
                                officialMenu(currentUser, officials, admins, clients);
                            } else {
                                officialMenu(currentUser, officials, admins, clients);
                            }
                        }
                        
                    } else {
                        cout << "##############" << endl;
                        cout << "No Account Holder with that username was found." << endl;
                        cout << "Returning you to the Official Menu." << endl;
                        cout << "##############" << endl;
                        officialMenu(currentUser, officials, admins, clients);
                    }
                }
        }
        case 3: {
                cout << "##############" << endl;
                cout << "Search Customer Accounts using the following:" << endl;
                cout << "[1] Account ID" << endl;
                cout << "[2] Customer Name" << endl;
                cout << "[3] Customer Phone Number" << endl;
                cout << "[4] Return To Official Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                switch(userSelection) {
                    case 1: {
                        cout << "##############" << endl;
                        cout << "Enter Account ID: " << endl;
                        cout << "##############" << endl;
                        string accountID;
                        getline(cin,accountID);
                        for(int i = 0; i < clients.size(); i++) {
                            if(clients[i].getUserID() == accountID) {
                                cout << "##############" << endl;
                                cout << "Account ID: " + clients[i].getUserID() << endl;
                                cout << "Customer Name: " + clients[i].getFirstName() + " " + clients[i].getLastName() << endl;
                                cout << "Username: " + clients[i].getUserName() << endl;
                                cout << "Last Login: " + clients[i].getLastLogin() << endl;
                                cout << "Address: " + clients[i].getAddress() << endl;
                                cout << "Phone Number: " + clients[i].getPhoneNumber() << endl;
                                vector<string> accounts = clients[i].getAccounts();
                                string savingAccounts;
                                string checkingAccounts;
                                string cdAccounts;
                                for(int i = 0; i < accounts.size(); i++) {
                                    string account = accounts[i];
                                    if(account[0] == 'F') {
                                        savingAccounts = savingAccounts + " " + account;
                                    }else if (account[0] == 'C') {
                                        checkingAccounts = checkingAccounts + " " + account;

                                    }else if (account[0] == 'D') {
                                        cdAccounts = cdAccounts + " " + account;
                                    }
                                    
                                }
                                cout << "Saving Accounts:" + savingAccounts << endl;
                                cout << "Checking Accounts: " + checkingAccounts << endl;
                                cout << "CD Accounts: " + cdAccounts << endl;
                                cout << "[Enter] Return to Main Menu" << endl;
                                string buffer;
                                getline(cin, buffer);
                                officialMenu(currentUser, officials, admins, clients);
                            }
                        }
                        cout << "##############" << endl;
                        cout << "No Account Found with that Information" << endl;
                        cout << "Returning you to official Menu" << endl;
                        cout << "##############" << endl;
                        officialMenu(currentUser, officials, admins, clients);
                    }
                    case 2: {
                        cout << "##############" << endl;
                        cout << "Enter Account Name (First & Last): " << endl;
                        cout << "##############" << endl;
                        string name;
                        getline(cin,name);
                        for(int i = 0; i < clients.size(); i++) {
                            if(clients[i].getFirstName() + " " + clients[i].getLastName() == name) {
                                cout << "##############" << endl;
                                cout << "Account ID: " + clients[i].getUserID() << endl;
                                cout << "Customer Name: " + clients[i].getFirstName() + " " + clients[i].getLastName() << endl;
                                cout << "Username: " + clients[i].getUserName() << endl;
                                cout << "Last Login: " + clients[i].getLastLogin() << endl;
                                cout << "Address: " + clients[i].getAddress() << endl;
                                cout << "Phone Number: " + clients[i].getPhoneNumber() << endl;
                                vector<string> accounts = clients[i].getAccounts();
                                string savingAccounts;
                                string checkingAccounts;
                                string cdAccounts;
                                for(int i = 0; i < accounts.size(); i++) {
                                    string account = accounts[i];
                                    if(account[0] == 'X') {
                                        savingAccounts = savingAccounts + " " + account;
                                    }else if (account[0] == 'C') {
                                        checkingAccounts = checkingAccounts + " " + account;

                                    }else if (account[0] == 'D') {
                                        cdAccounts = cdAccounts + " " + account;
                                    }
                                    
                                }
                                cout << "Saving Accounts:" + savingAccounts << endl;
                                cout << "Checking Accounts: " + checkingAccounts << endl;
                                cout << "CD Accounts: " + cdAccounts << endl;
                                cout << "[Enter] Return to Main Menu" << endl;
                                string buffer;
                                getline(cin, buffer);
                                officialMenu(currentUser, officials, admins, clients);
                            }
                        }
                        cout << "##############" << endl;
                        cout << "No Account Found with that Information" << endl;
                        cout << "Returning you to official Menu" << endl;
                        cout << "##############" << endl;
                        officialMenu(currentUser, officials, admins, clients);
                        
                    }
                    case 3: {
                        cout << "##############" << endl;
                        cout << "Enter PhoneNumer (###-###-####): " << endl;
                        cout << "##############" << endl;
                        string phoneNumber;
                        getline(cin,phoneNumber);
                        for(int i = 0; i < clients.size(); i++) {
                            if(clients[i].getPhoneNumber() == phoneNumber) {
                                cout << "##############" << endl;
                                cout << "Account ID: " + clients[i].getUserID() << endl;
                                cout << "Customer Name: " + clients[i].getFirstName() + " " + clients[i].getLastName() << endl;
                                cout << "Username: " + clients[i].getUserName() << endl;
                                cout << "Last Login: " + clients[i].getLastLogin() << endl;
                                cout << "Address: " + clients[i].getAddress() << endl;
                                cout << "Phone Number: " + clients[i].getPhoneNumber() << endl;
                                vector<string> accounts = clients[i].getAccounts();
                                string savingAccounts;
                                string checkingAccounts;
                                string cdAccounts;
                                for(int i = 0; i < accounts.size(); i++) {
                                    string account = accounts[i];
                                    if(account[0] == 'X') {
                                        savingAccounts = savingAccounts + " " + account;
                                    }else if (account[0] == 'C') {
                                        checkingAccounts = checkingAccounts + " " + account;

                                    }else if (account[0] == 'D') {
                                        cdAccounts = cdAccounts + " " + account;
                                    }
                                    
                                }
                                cout << "Saving Accounts:" + savingAccounts << endl;
                                cout << "Checking Accounts: " + checkingAccounts << endl;
                                cout << "CD Accounts: " + cdAccounts << endl;
                                cout << "[Enter] Return to Main Menu" << endl;
                                string buffer;
                                getline(cin, buffer);
                                officialMenu(currentUser, officials, admins, clients);
                            }
                        }
                        cout << "##############" << endl;
                        cout << "No Account Found with that Information" << endl;
                        cout << "Returning you to official Menu" << endl;
                        cout << "##############" << endl;
                        officialMenu(currentUser, officials, admins, clients);
 
                                
                    }
                    case 4: {
                         officialMenu(currentUser, officials, admins, clients);

                    }
                }
                   
        } 
        case 4: {

        }
        case 5: {
            main();
        }

    }

}

accountHolder createAccount() {
    srand(time(0));
    string accID;
    int random;
    for(int i = 0; i < 7; i++) {
        random = 1 + (rand() % 9);
        accID += to_string(random);
    }
    cout << "##############" << endl;
    cout << "Auto-Generated UserID: " << accID << endl;
    cout << "Enter First Name: ";
    string firstName;
    getline(cin, firstName);
    cout << "Enter Last Name:";
    string lastName;
    getline(cin, lastName);
    cout << "Enter Address: ";
    string address;
    getline(cin, address);
    cout << "Enter Phone Number: ";
    string phoneNumber;
    getline(cin, phoneNumber);
    cout << "Enter Username: ";
    string username;
    getline(cin, username);
    cout << "Enter Password: ";
    string password;
    getline(cin, password);
    cout << endl;
    accountHolder temp("A"+accID, username, password, "None", "Active", firstName, lastName, phoneNumber, address);
    temp.saveClient();
    return temp;
}

