#include "Classes/official.h"
#include "Classes/admin.h"
#include "Classes/accountHolder.h"
#include "driverMenu.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

void clientMenu(accountHolder currentUser, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients, financeAccounts &acc) {
    loadUsers(officials,admins,clients);

    cout << "##############" << endl;
    cout << "CLIENT MENU " << endl;
    cout << "Welcome back, " + currentUser.getFirstName() + " " + currentUser.getLastName() << endl;
    cout << "Last logged in at: " << currentUser.getLastLogin() << endl;
    time_t now = time(0);
    char* date_time = ctime(&now);
    string date(date_time);
    currentUser.setLastLogin(date.substr(0,date.length()));
    currentUser.saveClient();
    cout << "Current Accounts: " << endl;
    vector<string> accounts = currentUser.getAccounts();
    for(int i = 0; i < accounts.size(); i++) {
        cout << accounts[i] << endl;
    }
    cout << endl;
    cout << " [1] DEPOSIT INTO ACCOUNT " << endl;
    cout << " [2] WITHDRAW INTO ACCOUNT " << endl;
    cout << " [3] CLOSE ACCOUNT " << endl;
    cout << " [3] LOOK AT TRANSCATION LOGS " << endl;
    cout << " [4] CHANGE PASSWORD " << endl;
    cout << " [5] CHECK BALANCE "<< endl;
    cout << " [6] LOG-OUT " << endl; 
    cout << "##############" << endl;
    string buffer = "";
    getline(cin, buffer);
    int userSelection = stoi(buffer);
    switch(userSelection) {
        case 1: {
            cout << "Which account would you like to deposit funds into: " << endl;
            string account;
            getline(cin,account);
            if(account[0] == 'C') {
                for(int i = 0; i < acc.checkings.size(); i++) {
                    if(account == acc.checkings[i].getAccountID() && currentUser.getUserID() == acc.checkings[i].getUserID()) {
                        cout << "Current Balance: $"+ to_string(acc.checkings[i].getBalance()) << endl;
                        cout << "How much would you like to deposit?" << endl;
                        cout << "$";
                        string amount;
                        getline(cin, amount);
                        double amt = stod(amount);
                        acc.checkings[i].deposit(amt);
                        cout << endl;
                        cout << "Your new balance is: $" + to_string(acc.checkings[i].getBalance());
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }
            }else if(account[0] == 'F') {
                for(int i = 0; i < acc.savings.size(); i++) {
                    if(account == acc.savings[i].getAccountID() && currentUser.getUserID() == acc.savings[i].getUserID()) {
                        cout << "Current Balance: $"+ to_string(acc.savings[i].getBalance());
                        cout << "How much would you like to deposit?" << endl;
                        cout << "$";
                        string amount;
                        getline(cin, amount);
                        double amt = stod(amount);
                        acc.savings[i].deposit(amt);
                        cout << "Your new balance is: $" + to_string(acc.savings[i].getBalance());
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }

            }else if(account[0] == 'D') {
                cout << "You are not able to deposit money into a fixed term CD." << endl;
            }
            clientMenu(currentUser, officials, admins, clients, acc);
        }
        case 2: {

        }
        case 3: {
            cout << "Coming Soon!" << endl;
        }
        case 4: {
            cout << "Enter New Password: " << endl;
            string password;
            getline(cin, password);
            currentUser.setPassword(password);
            cout << "Password changed" << endl;
            clientMenu(currentUser, officials, admins, clients, acc);
        }
        case 5: {
            cout << "Which account would you like to see the balance of: " << endl;
            string account;
            getline(cin,account);
            if(account[0] == 'C') {
                for(int i = 0; i < acc.checkings.size(); i++) {
                    if(account == acc.checkings[i].getAccountID() && currentUser.getUserID() == acc.checkings[i].getUserID()) {
                        cout << "Current Balance: $"+ to_string(acc.checkings[i].getBalance()) << endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }
            }else if(account[0] == 'F') {
                for(int i = 0; i < acc.savings.size(); i++) {
                    if(account == acc.savings[i].getAccountID() && currentUser.getUserID() == acc.savings[i].getUserID()) {
                        cout << "Current Balance: $"+ to_string(acc.savings[i].getBalance());
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }

            }else if(account[0] == 'D') {
                for(int i = 0; i < acc.cds.size(); i++) {
                    if(account == acc.cds[i].getAccountID() && currentUser.getUserID() == acc.cds[i].getUserID()) {
                        cout << "Current Balance: $"+ to_string(acc.cds[i].getBalance());
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }
            }
            clientMenu(currentUser, officials, admins, clients, acc);
        }
        case 6: {
            main();
        }
    }
}