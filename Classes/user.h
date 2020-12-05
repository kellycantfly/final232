#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;

class User {
    protected:
        string userID;
        string username; 
        string password;
        string log;
        string lastLogin;
        string status;

    public: 
        User() {
            
        }
        User(string ID, string user, string pass, string last, string stat, string activity) {
            userID = ID;
            username = user;
            password = pass;
            lastLogin = last;
            status = stat;
            log = activity;
        }
        void setPassword(string pass) {
            password = pass;
        }
        void setLastLogin(string date) {
            lastLogin = date;
        }
        string getUserID() {
            return userID;
        }
        string getUserName() {
            return username;
        }
        string getPassword() {
            return password;
        }
        string getLog() {
            return log;
        }
        string getLastLogin() {
            return lastLogin;
        }
        string getStatus() {
            return status;
        }
        void deleteAccount() {
                string filePath = "Data/" + userID + ".txt";
                if(remove(filePath.c_str()) != 0) {
                    cout << "The account has been deleted." << endl;
                }
                
        }
        
       

};

#endif