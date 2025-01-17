#ifndef OFFICIAL_H
#define OFFICIAL_H
#include "user.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>
using namespace std;
class official : public User {
    public: 
        official();
        official(string ID, string user, string pass, string last, string stat, string activity) {
            userID = ID;
            username = user;
            password = pass;
            lastLogin = last;
            status = stat;
            log = activity;
        }
        official(string ID, string user, string pass) {
            userID = ID;
            username = user;
            password = pass;
            lastLogin = "None";
            status = "Active";
            log = "";
        }
        void saveOfficial() {
            ofstream outFile;
            outFile.open("Data/"+userID + ".txt");
            outFile << userID << endl;
            outFile << encrypt(username) << endl;
            outFile << encrypt(password) << endl;
            outFile << encrypt(lastLogin) << endl;
            outFile << encrypt(status) << endl;
            outFile << log << endl;
        }
        
        void disableAccount(string adminID) {
            status = "\nInactive by " + adminID;
        }
        void enableAccount() {
            status = "\nActive"; 
        }
       
};
#endif
