#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H
#include "checkingAccount.h"
#include <iostream>
#include <string>
using namespace std;

class savingAccount : public checkingAccount {
    public:
        savingAccount(double IR) {
            
            balance = 0;
            interestRate = IR;
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

        virtual double getBalance() {
            return balance;
        }
       

};

#endif