#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "bankaccount.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;


class Account {
    private:
        string accountID; // matches userID in BankAccount
        string username; // user input
        string password; // user input

        // add to constructor
        string firstName;
        string lastName;

        friend class BankOfficial;
        friend class SystemAdmin;

    public:
        int counter = rand() % 500 + 1;

        Account()
        {
            setAccountID(to_string(counter));
            setfirstName("");
            setlastName("");
        }

        // SETTERS
        void setAccountID(string accID) {
            accountID = accID;
        }
        void setUsername(string user) {
            username = user;
        }
        void setPassword(string pass) {
            password = pass;
        }
        void setfirstName(string name) {
            firstName = name;
        }
        void setlastName(string name) {
            lastName = name;
        }

        // GETTERS
        string getUsername() {
            return username;
        }
        string getPassword() {
            return password;
        }
        string getAccountID() {
            return accountID;
        }
        string getfirstName() {
            return firstName;
        }
        string getlastName() {
            return lastName;
        }
};


class AccountHolder : public Account {
    private:

        // add to constructor
        string phoneNumber;
        string address;

        // help add time functionality
        string dateOpened; 
        string dateClosed;
        string maturity;
        string lastLogin;
        string accountLog; // could be a file or vector


        CheckingAccount* check = NULL; // this AccountHolder's CheckingAccount
        SavingAccount* save = NULL; // this AccountHolder's SavingAccount
        CDAccount* CD = NULL; // this AccountHolder's CDAccount

        friend class BankOfficial;
        friend class SystemAdmin;

    public:
        AccountHolder()
        {
            string name, pass;
            cout << "Enter new Account Holder username" << endl;
            cin >> name;
            name.insert(0, "H"); // adds H identifer to username
            setUsername(name);

            cout << "Enter new password" << endl;
            cin >> pass;
            setPassword(pass);

            setAccountID(to_string(counter));
            cout << getUsername() <<" "<< getAccountID() << endl; // displays new account to user
        }

        // Copy constructor for [3] Account Creation
        AccountHolder(string acc, string name, string pass, string first, string last)
        {
            setAccountID(acc);
            setUsername(name);
            setPassword(pass);
            setfirstName(first);
            setlastName(last);
        }

        // SETTERS
        void setChecking(CheckingAccount* c) { check = c; }
        void setSaving(SavingAccount* s) { save = s; }
        void setCD(CDAccount* d) { CD = d; }
        void setPhone(string phone) { phoneNumber = phone; }
        void setAddress(string userAddress) { address = userAddress; }
        void setDateOpened(string date) { dateOpened = date; }
        void setDateClosed(string date) { dateClosed = date; }

        // GETTERS
        string getAddress() { return address; }
        CheckingAccount* getChecking() { return check; }
        SavingAccount* getSaving() { return save; }
        CDAccount* getCD() { return CD; }

};

class BankOfficial : public Account {
    public:

        BankOfficial()
        {
            string name, pass;
            cout << "Enter new Official username" << endl;
            cin >> name;
            name.insert(0, "O"); // adds O identifier to username
            setUsername(name);

            cout << "Enter new password" << endl;
            cin >> pass;
            setPassword(pass);

            setAccountID(to_string(counter));

            cout << getUsername() << " " << getAccountID() << endl; // displays new account to user
        }

        // Copy constructor for [3] Account Creation
        BankOfficial(string acc, string name, string pass, string first, string last)
        {
            setAccountID(acc);
            setUsername(name);
            setPassword(pass);
            setfirstName(first);
            setlastName(last);
        }

        void closeAccount(AccountHolder* holder, ofstream& outFile)
        {
            char type;
            time_t now = time(0);
            cout << "[C]hecking, [S]aving, C[D]" << endl;
            try
            {
                cin >> type; // prompts user input. Must be the capital letter
                if ((!cin) && (type != 'C') && (type != 'S') && (type != 'D'))
                {
                    throw type; // jumps to error handling menu
                }
                else
                {
                    switch (type)
                    {
                        case 'C': // CheckingAccount
                        {
                            if (holder->getChecking() != NULL)
                            {
                                holder->getChecking()->setDateClose(ctime(&now));
                                outFile << holder->getChecking()->getAccID() << " "
                                    << holder->getAccountID() << " "
                                    << holder->getUsername() << " "
                                    << holder->getfirstName() << " "
                                    << holder->getlastName() << " "
                                    << holder->getAddress() << " "
                                    << holder->getChecking()->getDateOpen() << " "
                                    << holder->getChecking()->getDateClose() << endl;
                                holder->getChecking()->setStatus(0);
                                holder->setChecking(NULL);
                                cout << "Checking account closed\n";
                            }
                            else
                                cout << "User has no checking account\n";

                            break;
                        }
                        case 'S': // SavingAccount
                        {
                            if (holder->getSaving() != NULL)
                            {
                                holder->getSaving()->setDateClose(ctime(&now));
                                outFile << holder->getSaving()->getAccID() << " "
                                    << holder->getAccountID() << " "
                                    << holder->getUsername() << " "
                                    << holder->getfirstName() << " "
                                    << holder->getlastName() << " "
                                    << holder->getAddress() << " "
                                    << holder->getSaving()->getDateOpen() << " "
                                    << holder->getSaving()->getDateClose() << endl;
                                holder->getSaving()->setStatus(0);
                                holder->setSaving(NULL);
                                cout << "Saving account closed\n";
                            }
                            else
                                cout << "User has no saving account\n";
                            break;
                        }
                        case 'D': // CDAccount
                        {
                            if (holder->getCD() != NULL)
                            {
                                holder->getCD()->setDateClose(ctime(&now));
                                outFile << holder->getCD()->getAccID() << " "
                                    << holder->getAccountID() << " "
                                    << holder->getUsername() << " "
                                    << holder->getfirstName() << " "
                                    << holder->getlastName() << " "
                                    << holder->getAddress() << " "
                                    << holder->getCD()->getDateOpen() << " "
                                    << holder->getCD()->getDateClose() << endl;
                                holder->getCD()->setStatus(0);
                                holder->setCD(NULL);
                                cout << "CD account closed\n";
                            }
                            else
                                cout << "User has no CD account\n";
                            break;
                        }
                    }
                }

            }
            catch (char) // error handling menu
            {
                cout << "Invalid bank account type" << endl;
                cin.clear();
                cin.ignore();
            }
        }

        // openAccount allows a BankOfficial to take an AccountHolder parameter, create a new BankAccount, and assign
        // it to that AccountHolder's pointer members depending on the type
        BankAccount* openAccount(AccountHolder* holder) {
            cout << "New bank account menu" << endl;
            char type;
            cout << "[C]hecking, [S]aving, C[D]" << endl;
            try
            {
                cin >> type; // prompts user input. Must be the capital letter
                if ((!cin) && (type != 'C') && (type != 'S') && (type != 'D'))
                {
                    throw type; // jumps to error handling menu
                }
                else
                {
                    switch (type)
                    {
                    case 'C': // CheckingAccount
                    {
                        if (holder->getChecking() == NULL) // checks for existing CheckingAccount
                        {
                            CheckingAccount* newChecking = new CheckingAccount(holder->getAccountID()); // makes a new CheckingAccount
                            holder->setChecking(newChecking); // assigns the AccountHolder this CheckingAccount
                            holder->check->print(); // test print to check userID matches accountID
                            return newChecking;
                        }
                        else
                            cout << "User already has a checking account\n";
                        break;
                    }
                    case 'S': // SavingAccount
                    {
                        if (holder->getSaving() == NULL) // checks for existing SavingAccount
                        {
                            SavingAccount* newSaving = new SavingAccount(holder->getAccountID());
                            holder->setSaving(newSaving);
                            holder->save->print(); // test print
                            return newSaving;
                        }
                        else
                            cout << "User already has a saving account\n";
                        break;
                    }
                    case 'D': // CDAccount
                    {
                        if (holder->getCD() == NULL) // checks for existing CDAccount
                        {
                            CDAccount* newCD = new CDAccount(holder->getAccountID());
                            holder->setCD(newCD);
                            holder->CD->print(); // test print
                            return newCD;
                        }
                        else
                            cout << "User already has a CD account\n";
                        break;
                    }
                    }
                }
            }
            catch (char) // error handling menu
            {
                cout << "Invalid bank account type" << endl;
                cin.clear();
                cin.ignore();
            }
            return NULL;
        }

        // TO DO
        void searchAccount() { // official can search by phone, address, customer name

        }
         // TO DO
        void depositToAccount(string accID, string password) {

        }

        // TO DO
        void withdrawToAccounts(string accID, string password) {

        }

        // Checks user is properly logged in
        bool validateLogin()
        {
            string name, pass;

            cout << "Official's Username: \n";
            cin >> name;
            cout << "Official's Password: \n";
            cin >> pass;

            if ((getUsername() == name) && (getPassword() == pass))
            {
                return true;
            }
            else
                return false;

        }
};

class SystemAdmin : public Account {
    public:
        SystemAdmin()
        {
            string name, pass;
            cout << "Enter new System Admin username" << endl;
            cin >> name;
            name.insert(0, "A");
            setUsername(name);

            cout << "Enter new password" << endl;
            cin >> pass;
            setPassword(pass);

            setAccountID(to_string(counter));
            cout << getUsername() << " " << getAccountID() << endl;
        }

        // Copy constructor for [3] Account Creation
        SystemAdmin(string acc, string name, string pass, string first, string last)
        {
            setAccountID(acc);
            setUsername(name);
            setPassword(pass);
            setfirstName(first);
            setlastName(last);
        }

        // TO DO
        void disableAccount() {

        }

        // TO DO
        void changePassword() {

        }

        // Checks user is properly logged in
        bool validateLogin()
        {
            string name, pass;

            cout << "Admin's Username: \n";
            cin >> name;
            cout << "Admin's Password: \n";
            cin >> pass;

            if ((getUsername() == name) && (getPassword() == pass))
            {
                return true;
            }
            else
                return false;

        }

        SystemAdmin* createAdmin()
        {
            SystemAdmin* newAdmin = new SystemAdmin;
            return newAdmin;
        }

        BankOfficial* createOffical()
        {
            BankOfficial* newOfficial = new BankOfficial;
            return newOfficial;
        }

        AccountHolder* createHolder()
        {
            AccountHolder* newHolder = new AccountHolder;
            return newHolder;
        }
};

#endif