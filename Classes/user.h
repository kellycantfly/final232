#include <iostream>
#include <iostream>
#include <string>
using namespace std;

class User {
    protected:
        string userID;
        string username; 
        string password;
        string Log;
        string lastLogin;
        string status;

    public: 
        User();
        User(string ID, string user, string pass, string last, string stat, string activity) {
            userID = ID;
            username = user;
            password = pass;
            lastLogin = last;
            status = stat;
            Log = activity;
        }
};