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
            outFile << userID << endl;
            outFile << status << endl;
            outFile << interestRate << endl;
            outFile << fee << endl;
            outFile << balance << endl;
            outFile << log << endl;
            outFile << dateOpen << endl;
            outFile << penalty << endl;
            outFile << term << endl;
        }

};

#endif