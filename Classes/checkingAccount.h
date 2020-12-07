#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class checkingAccount {
    protected:
        string accID;
        string userID;
        string status;
        double balance;
        double fee;
        double interestRate;
        string log;
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
            status = "Active";
            balance = 0;
            fee = 0;
            interestRate = 0;
        }
        checkingAccount(string acc, string userHolderID, string stat, double charge, double IR, double bal, string activity) {
            accID = acc;
            userID = userHolderID;
            status = stat;
            interestRate = IR;
            fee = charge;
            balance = bal;
            log = activity;

        }
        string getAccountID() {
            return accID;
        }
        string getUserID() {
            return userID;
        }
        void deposit(int amt) {
            if(amt > 0) {
                balance+=amt;
            }else {
                cout << "Invalid Amount." << endl;
            }
        }
        void withdraw(int amt) {
            if(amt < balance && amt > 0) {
                balance-=amt;
            }else {
                cout << "Invalid Amount." << endl;
            }
        }

        double getBalance() {
            return balance;
        }
        virtual void saveAccount() {
            ofstream outFile;
            outFile.open("Accounts/"+accID + ".txt");
            outFile << accID << endl;
            outFile << encrypt(userID) << endl;
            outFile << encrypt(status) << endl;
            outFile << encrypt(to_string(interestRate)) << endl;
            outFile << encrypt(to_string(fee)) << endl;
            outFile << encrypt(to_string(balance)) << endl;
        }

        string encrypt(string input)
{
    string newString = "";
    int counter = 0;
    int modifier = 1;
    while (input != "")
    {
        if (counter == 6)
        {
            counter = 0;
        }
        if (counter <=2)
        {
            modifier +=1;
        }
        if (counter <= 5 && counter >2)
        {
            modifier -=1;
        }
        counter +=1;
        char tempString;
        
        tempString = input[0];
        tempString += modifier;

        newString = newString + tempString;
        input = input.substr(1,input.length());
    }
    return newString;
}

};

#endif
