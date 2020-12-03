#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

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

#endif
