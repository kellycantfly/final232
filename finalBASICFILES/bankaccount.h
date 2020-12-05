#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    private:
        string accID; // userID + account type
        string userID; // matches accountID in User
        double balance; // TO DO
        double fee; // TO DO

    public:

        // SETTERS
        void setUserID(string ID) { userID = ID; }
        void setAccID(string ID) { accID = ID; }

        // GETTERS
        string getUserID() { return userID; }
        string getAccID() { return accID; }

        // Prints the accID and userID. Can be changed
        void print()
        {
            cout << "AccID: " << getAccID() << "User ID: " << getUserID() << endl;
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
        string creationDate;
        int termLength;
        string dateOpen;
        string dateClose;
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
