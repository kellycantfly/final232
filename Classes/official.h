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
            outFile << username << endl;
            outFile << password << endl;
            outFile << lastLogin;
            outFile << status << endl;
            outFile << log << endl;
        }
        
        void disableAccount(string adminID) {
            status = "Inactive " + adminID;
        }
        void enableAccount() {
            status = "Active";
        }
       
};
#endif