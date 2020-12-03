<<<<<<< HEAD
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "bankaccount.h"
#include <string>
#include <iostream>
using namespace std;

class Account {
private:
    string accountID;
    string username;
    string password;
    string firstName;
    string lastName;

    bool status;

    friend class BankOfficial;
    friend class SystemAdmin;

public:
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
    string getUsername() {
        return username;
    }
    string getPassword() {
        return password;
    }
    string getAccountID() {
        return accountID;
    }
};
class AccountHolder : public Account {
private:
    string phoneNumber;
    string address;
    string dateOpened;
    string dateClosed;
    string maturity;
    string lastLogin;
    string accounts;
    string accountLog;

    friend class BankOfficial;
    friend class SystemAdmin;

public:
    void setPhone(string phone) {
        phoneNumber = phone;
    }
    void setAddress(string userAddress) {
        address = userAddress;
    }
    string getAddress() {
        return address;
    }
    void setDateOpened(string date) {
        dateOpened = date;
    }
    void setDateClosed(string date) {
        dateClosed = date;
    }

};

class BankOfficial : public Account {
public:

    BankOfficial()
    {
        string name, pass;
        cout << "Enter new Official username" << endl;
        cin >> name;
        name.insert(0, "O");
        setUsername(name);

        cout << "Enter new Official password" << endl;
        cin >> pass;
        setPassword(pass);
    }

    void openAccount()
    {
        AccountHolder* holder = new AccountHolder;
        openAccount(holder);
    }
    BankAccount* openAccount(AccountHolder* holder) {
        cout << "New account menu" << endl;
        if (validateLogin())
        {
            char type;
            cout << "[C]hecking, [S]aving, C[D]" << endl;
            try
            {
                cin >> type;
                if ((!cin) && (type != 'C') && (type != 'S') && (type != 'D'))
                {
                    throw type;
                }
                else
                {
                    switch (type)
                    {
                    case 'C':
                    {
                        CheckingAccount* newChecking = new CheckingAccount;
                        newChecking->setAccID(holder->getAccountID());
                        return newChecking;
                        break;
                    }
                    case 'S':
                    {
                        SavingAccount* newSaving = new SavingAccount;
                        newSaving->setAccID(holder->getAccountID());
                        return newSaving;
                        break;
                    }
                    case 'D':
                    {
                        CDAccount* newCD = new CDAccount;
                        newCD->setAccID(holder->getAccountID());
                        return newCD;
                        break;
                    }
                    }
                }
            }
            catch (char)
            {
                cout << "Invalid account type" << endl;
                cin.clear();
                cin.ignore();
            }
        }
        else
        {
            cout << "Invalid credentials for opening account" << endl;
        }
        return NULL;
    }
    void closeAccount() {

    }
    void searchAccount() { // official can search by phone, address, customer name

    }
    void depositToAccount(string accID, string password) {

    }
    void withdrawToAccounts(string accID, string password) {

    }
    bool validateLogin()
    {
        string name, pass;

        cout << "Username: \n";
        cin >> name;
        cout << "Password: \n";
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
    void createLogin() {

    }
    void disableAccount() {

    }
    void changePassword() {

    }
};

#endif
=======
#include <string>
#include <iostream>
using namespace std;

class Account {
    private:
        string accountID;
        string username;
        string password;
        string firstName;
        string lastName;

        bool status;
        friend class BankOfficial;
        friend class SystemAdmin;
    public:
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
        string getUsername() {
            return username;
        }
};
class AccountHolder : public Account {
    private:
        string phoneNumber;
        string address;
        string dateOpened;
        string dateClosed;
        string maturity;
        string lastLogin;
        string accounts;
        string accountLog;
        friend class BankOfficial;
        friend class SystemAdmin;
    public: 
        void setPhone(string phone) {
            phoneNumber = phone;
        }
        void setAddress(string userAddress) {
            address = userAddress;
        }
        string getAddress() {
            return address;
        }
        void setDateOpened(string date) {
            dateOpened = date;
        }
        void setDateClosed(string date) {
            dateClosed = date;
        }
        
};

class BankOfficial : public Account {
    public: 
        void openAccount() {
            
        }
        void closeAccount() {

        }
        void searchAccount() { // official can search by phone, address, customer name
            
        }
        void depositToAccount(string accID, string password) {

        }
        void withdrawToAccounts(string accID, string password) {

        }
};

class SystemAdmin : public Account {
    public: 
        void createLogin() {

        }
        void disableAccount() {

        }
        void changePassword() {

        }
};

class BankAccount {
    private:
        string accID;
        string userID;
        double balance;
        double fee;
    public:
        void setAccID(string accID) {

        }
        void setUserID(string userID) {

        }
};

class SavingAccount : public BankAccount {
    private:
    double interestRate;
    public: 
        void setInterestRate(double intRate) {
            interestRate = intRate;
        }


};

class CheckingAccount : public BankAccount {

};

class CDAccount : public BankAccount {
    private:
    string creationDate;
    int termLength;
    string dateOpen;
    string dateClose;
    int maturity;
    int interestRate;

};


>>>>>>> 3766df0a8d8b69452f4201877bfaeec3ee7d16c6
