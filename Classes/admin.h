#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include <iostream>
#include <string>
using namespace std;
class admin : public User {
    public: 
        admin();
        admin(string ID, string user, string pass, string last, string stat, string activity) {
            userID = ID;
            username = user;
            password = pass;
            lastLogin = last;
            status = stat;
            log = activity;
        }
        void deleteAccount() {
                string filePath = "Data/" + userID + ".txt";
                if(remove(filePath.c_str()) != 0) {
                    cout << "The account has been deleted." << endl;
                }
              // rememmber to delete the checking accounts and such here too  
        }
        void saveAdmin() {
            ofstream outFile;
            outFile.open("Data/"+userID + ".txt");
            outFile << userID << endl;
            outFile << username << endl;
            outFile << password << endl;
            outFile << lastLogin;
            outFile << status << endl;
            outFile << log << endl;
        }
       

       
};
#endif