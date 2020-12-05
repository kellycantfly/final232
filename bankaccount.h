#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class BankAccount {
    private:
        string dateOpen;
        string dateClose;
        string accID; // userID + account type
        string userID; // matches accountID in User
        double balance; // TO DO
        double fee; // TO DO
        bool status = 0; // 0 is closed, 1 is open

    public:

        BankAccount()
        {
            time_t now = time(0);
            setDateOpen(ctime(&now));
            setStatus(1); // account is open
        }

        // SETTERS
        void setUserID(string ID) { userID = ID; }
        void setAccID(string ID) { accID = ID; }
        void setDateOpen(string date) { dateOpen = date; }
        void setDateClose(string date) { dateClose = date; }
        void setStatus(bool stat) { status = stat; }

        // GETTERS
        string getUserID() { return userID; }
        string getAccID() { return accID; }
        string getDateOpen() { return dateOpen; }
        string getDateClose() { return dateClose; }
        bool getStatus() { return status; }

        // Prints the accID and userID. Can be changed
        void print()
        {
            cout << "AccID: " << getAccID() << " User ID: " << getUserID() << endl;
        }
};

class SavingAccount : public BankAccount {
    private:
        double interestRate; // TO DO

    public:
        SavingAccount(string accountID)
        {
            setUserID(accountID);
            setAccID(accountID.insert(0, "S")); // adds S identifer to accID
        }

        // SETTERS
        void setInterestRate(double intRate) { interestRate = intRate; }


};

class CheckingAccount : public BankAccount {

    public:
        CheckingAccount(string accountID)
        {
            setUserID(accountID);
            setAccID(accountID.insert(0, "C")); // adds C identifer to accID
        }
};

class CDAccount : public BankAccount {
    private:

        // help with time functionality
        int termLength;
        int maturity;
        int interestRate; // TO DO

        public:
            CDAccount(string accountID)
            {
                setUserID(accountID);
                setAccID(accountID.insert(0, "D")); // adds D identifer to account
            }

};

#endif
