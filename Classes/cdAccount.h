#ifndef CDACCOUNT_H
#define CDACCOUNT_H
#include "checkingAccount.h"
#include <iostream>
#include <string>
using namespace std;

class cdAccount : public checkingAccount {
    private:
        string dateOpen;
        string term;
        string dateClose;
        double penalty;
    public: 
        cdAccount(string acc, string userHolderID, string stat, double charge, double IR, double bal, string date, string amountOfTime, double pen, string activity) {
            accID = acc;
            userID = userHolderID;
            status = stat;
            interestRate = IR;
            fee = charge;
            balance = bal;
            log = activity;
            dateOpen = date;
            penalty = pen;
            term = amountOfTime;
        }
        void saveAccount() {
            ofstream outFile;
            outFile.open("Accounts/"+accID + ".txt");
            outFile << accID << endl;
            outFile << encrypt(userID) << endl;
            outFile << encrypt(status) << endl;
            outFile << encrypt(to_string(interestRate)) << endl;
            outFile << encrypt(to_string(fee)) << endl;
            outFile << encrypt(to_string(balance)) << endl;
            outFile << encrypt(log) << endl;
            outFile << encrypt(dateOpen) << endl;
            outFile << encrypt(to_string(penalty)) << endl;
            outFile << encrypt(term) << endl;
        }

};

#endif
