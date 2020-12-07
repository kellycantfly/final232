#include "Classes/official.h"
#include "Classes/admin.h"
#include "Classes/accountHolder.h"
#include "driverMenu.h"
#include <iostream>
#include <iomanip>
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
    cout << " [6] MAKE NEW BANK ACCOUNT"<<endl;
    cout << " [7] LOG-OUT " << endl; 
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
                        cout << "Current Balance: $"<<setprecision(2)<<fixed<<acc.checkings[i].getBalance() << endl;
                        cout << "How much would you like to deposit?" << endl;
                        cout << "$";
                        string amount;
                        getline(cin, amount);
                        double amt = stod(amount);
                        acc.checkings[i].deposit(amt);
                        acc.checkings[i].saveAccount();
                        cout << endl;
                        cout << "Your new balance is: $" <<setprecision(2)<<fixed<<acc.checkings[i].getBalance()<<endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }
            }else if(account[0] == 'F') {
                for(int i = 0; i < acc.savings.size(); i++) {
                    if(account == acc.savings[i].getAccountID() && currentUser.getUserID() == acc.savings[i].getUserID()) {
                        cout << "Current Balance: $"<<setprecision(2)<<fixed<< acc.savings[i].getBalance()<<endl;
                        cout << "How much would you like to deposit?" << endl;
                        cout << "$";
                        string amount;
                        getline(cin, amount);
                        double amt = stod(amount);
                        acc.savings[i].deposit(amt);
                        acc.savings[i].saveAccount();
                        cout << "Your new balance is: $"<<setprecision(2)<<fixed<< acc.savings[i].getBalance()<<endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }

            }else if(account[0] == 'D') {
                cout << "You are not able to deposit money into a fixed term CD." << endl;
            }
            clientMenu(currentUser, officials, admins, clients, acc);
        }
        case 2: {
            cout << "Which account would you like to withdraw funds from: " << endl;
            string account;
            getline(cin,account);
            if(account[0] == 'C') {
                for(int i = 0; i < acc.checkings.size(); i++) {
                    if(account == acc.checkings[i].getAccountID() && currentUser.getUserID() == acc.checkings[i].getUserID()) {
                        cout << "Current Balance: $"<<setprecision(2)<<fixed<<acc.checkings[i].getBalance() << endl;
                        cout << "How much would you like to withdraw?" << endl;
                        cout << "$";
                        string amount;
                        getline(cin, amount);
                        double amt = stod(amount);
                        acc.checkings[i].withdraw(amt);
                        acc.checkings[i].saveAccount();
                        cout << endl;
                        cout << "Your balance is: $" <<setprecision(2)<<fixed<<acc.checkings[i].getBalance()<<endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }
            }else if(account[0] == 'F') {
                for(int i = 0; i < acc.savings.size(); i++) {
                    if(account == acc.savings[i].getAccountID() && currentUser.getUserID() == acc.savings[i].getUserID()) {
                        cout << "Current Balance: $"<<setprecision(2)<<fixed<<acc.savings[i].getBalance()<<endl;
                        cout << "How much would you like to withdraw?" << endl;
                        cout << "$";
                        string amount;
                        getline(cin, amount);
                        double amt = stod(amount);
                        acc.savings[i].withdraw(amt);
                        acc.savings[i].saveAccount();
                        cout << "Your new balance is: $" <<setprecision(2)<<fixed<<acc.savings[i].getBalance()<<endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }

            }else if(account[0] == 'D') {
                // include a penalty for withdrawing if the account has yet to mature....
            }
            clientMenu(currentUser, officials, admins, clients, acc);
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
                        cout << "Current Balance: $"<<setprecision(2)<<fixed<<acc.checkings[i].getBalance() << endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }
            }else if(account[0] == 'F') {
                for(int i = 0; i < acc.savings.size(); i++) {
                    if(account == acc.savings[i].getAccountID() && currentUser.getUserID() == acc.savings[i].getUserID()) {
                        cout << "Current Balance: $"<<setprecision(2)<<fixed<<acc.savings[i].getBalance()<<endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }

            }else if(account[0] == 'D') {
                for(int i = 0; i < acc.cds.size(); i++) {
                    if(account == acc.cds[i].getAccountID() && currentUser.getUserID() == acc.cds[i].getUserID()) {
                        cout << "Current Balance: $"<<setprecision(2)<<fixed<<acc.cds[i].getBalance()<<endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
                }
            }
            clientMenu(currentUser, officials, admins, clients, acc);
        }
        case 6: 
        {
            bool found = false;
                    string officialUser, officialPass;
                    cout<<" BANK OFFICIAL NEEDED TO CREATE ACCOUNT "<<endl;
                    cout<<" Enter bank officials username : ";
                    getline(cin,officialUser);
                    cout<<" Enter bank officials password : ";
                    getline(cin,officialPass);

                    for (int a =0; a<officials.size();a++)
                    {
                        if(officialUser == officials[a].getUserName() && officialPass == officials[a].getPassword())
                        {
                            found =true;
                        }
                    }
                    if (found == false)
                    {
                        cout<<"Official not found -- Account creation denied"<<endl;
                        clientMenu(currentUser, officials, admins, clients, acc);
                    }
            string input;
            cout<<"What Kind of account Would you like to open?"<<endl;
            cout<<" [1] checking"<<endl;
            cout<<" [2] savings"<<endl;
            cout<<" [3] cd"<<endl;
            getline(cin,input);
            int input2 = stoi(input);
            
            switch(input2)
            {
                case 1:
                {   
                    
                    string accid,userid,status,fee,ir,bal;
                    cout<<" what is the inital Balance : ";
                    getline(cin,bal);
                    cout<<endl<<" what is the fee for the account : ";
                    getline(cin,fee);
                    cout<<endl<<" what is the Interest Rate for the account : ";
                    getline(cin,ir);
                    status = "Active";
                    userid = currentUser.getUserID();
                    cout<<" Enter account number : ";
                    getline(cin,accid);
                    accid = "C" + accid;
                    checkingAccount tempAcc(accid,userid,status,stod(fee),stod(ir),stod(bal),"none");
                    tempAcc.saveAccount();
                    acc.checkings.emplace_back(tempAcc);
                    accounts.emplace_back(accid);
                    currentUser.setAccounts(accounts);
                    clientMenu(currentUser, officials, admins, clients, acc);
                }
                case 2:
                {
                    string accid,userid,status,fee,ir,bal;
                    cout<<" what is the inital Balance : ";
                    getline(cin,bal);
                    cout<<endl<<" what is the fee for the account : ";
                    getline(cin,fee);
                    cout<<endl<<" what is the Interest Rate for the account : ";
                    getline(cin,ir);
                    status = "Active";
                    userid = currentUser.getUserID();
                    cout<<" Enter account number : ";
                    getline(cin,accid);
                    accid = "D" + accid;
                    savingAccount tempAcc(accid,userid,status,stod(fee),stod(ir),stod(bal),"none");
                    tempAcc.saveAccount();
                    acc.savings.emplace_back(tempAcc);
                    accounts.emplace_back(accid);
                    currentUser.setAccounts(accounts);
                    clientMenu(currentUser, officials, admins, clients, acc);
                }
                case 3:
                {
                    string accid,userid,status,fee,ir,bal,term,penalty,date;
                    cout<<" what is the inital Balance : ";
                    getline(cin,bal);
                    cout<<" what is the fee for the account : ";
                    getline(cin,fee);
                    cout<<" what is the Interest Rate for the account : ";
                    getline(cin,ir);
                    status = "Active";
                    userid = currentUser.getUserID();
                    cout<<" Enter account number : ";
                    getline(cin,accid);
                    accid = "F" + accid;
                    cout<<" Enter term length : ";
                    getline(cin,term);
                    cout<<" Enter penalty for early withdraw : ";
                    getline(cin,penalty);
                    time_t currentTime = time(NULL);
                    tm* timePtr = localtime(&currentTime);
                    date = to_string((timePtr->tm_mday))+"/"+ to_string((timePtr->tm_mon)+1) +"/"+ to_string((timePtr->tm_year)+1900);
                    cdAccount tempAcc(accid,userid,status,stod(fee),stod(ir),stod(bal),date,term,stod(penalty),"none");
                    tempAcc.saveAccount();
                    acc.cds.emplace_back(tempAcc);
                    accounts.emplace_back(accid);
                    currentUser.setAccounts(accounts);
                    clientMenu(currentUser, officials, admins, clients, acc);
                }
            }
        }
        case 7: {
            main();
        }
    }
}
