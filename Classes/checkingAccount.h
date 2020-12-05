#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class checkingAccount {
    protected:
        string userID;
        double balance;
        double fee;
        double interestRate;
    public: 
        checkingAccount() {
            srand(time(0));
            string accID;
            int random;
            for(int i = 0; i < 7; i++) {
                random = 1 + (rand() % 9);
                accID += to_string(random);
            }
            accID = "C" + userID;
            balance = 0;
            fee = 0;
            interestRate = 0;
        }
        void deposit(int amt) {
            if(amt > 0) {
                balance+=amt;
            }
        }
        void withdraw(int amt) {
            if(amt < balance && amt > 0) {
                balance-+amt;
            }
        }

        double getBalance() {
            return balance;
        }
       

};

#endif