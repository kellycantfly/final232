#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include "checkingAccount.h"
#include <iostream>
#include <string>
using namespace std;

class savingAccount : public checkingAccount {
    public:
        savingAccount(string acc, string userHolderID, string stat, double charge, double IR, double bal, string activity) {
            accID = acc;
            userID = userHolderID;
            status = stat;
            interestRate = IR;
            fee = charge;
            balance = bal;
            log = activity;

        }
        virtual void deposit(int amt) {
            if(amt > 0) {
                balance+=amt;
            }
        }
        virtual void withdraw(int amt) {
            if(amt < balance && amt > 0) {
                balance-+amt;
            }
        }
        virtual void setInterestRate(double IR) {
            interestRate = IR;
        }

        double getBalance() {
            return balance;
        }
       

};

#endif