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
            Log = activity;
        }
        
        void openOfficialAccount() {

        }
        void disableOfficialAccount(string ID) {
            
        }
        void findPassword(string ID) {

        }

       
};