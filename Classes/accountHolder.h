#include "user.h"
#include "official.h"
#include <vector>
using namespace std;
class accountHolder : public User {
    private:
        string firstName;
        string lastName;
        string phoneNumber;
        string address;
        vector<string> accounts;
        friend class official;   
    public: 
        accountHolder();
        accountHolder(string ID, string user, string pass, string last, string activity) {
            userID = ID;
            username = user;
            password = pass;
            lastLogin = last;
            Log = activity;
        }
        void accountHolderFill(string first, string last, string phone, string addy, vector<string> acc) {
            firstName = first;
            lastName = last;
            phoneNumber = phone;
            address = addy;
            accounts = acc;
        }

};