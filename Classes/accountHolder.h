#ifndef accountHolder_H
#define accountHolder_H
#include "user.h"
#include <vector>
#include <string>
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
        accountHolder(string ID, string user, string pass, string last, string stat, string first, string lastN, string phone, string addy, vector<string> acc, string activity) {
            userID = ID;
            username = user;
            password = pass;
            lastLogin = last;
            log = activity;
            firstName = first;
            lastName = lastN;
            phoneNumber = phone;
            address = addy;
            accounts = acc;

        }
        accountHolder(string ID, string user, string pass, string last, string stat, string first, string lastN, string phone, string addy) {
            userID = ID;
            username = user;
            password = pass;
            lastLogin = last;
            status = stat;
            firstName = first;
            lastName = lastN;
            phoneNumber = phone;
            address = addy;
            

        }
        void saveClient() {
            ofstream outFile;
            outFile.open("Data/"+userID + ".txt");
            outFile << userID << endl;
            outFile << encrypt(username) << endl;
            outFile << encrypt(password) << endl;
            outFile << encrypt(lastLogin) << endl;
            outFile << encrypt(status) << endl;
            outFile << encrypt(firstName) << endl;
            outFile << encrypt(lastName) << endl;
            outFile << encrypt(phoneNumber) << endl;
            outFile << encrypt(address) << endl;
            for(int i = 0; i < accounts.size(); i++) {
                outFile << encrypt(accounts[i]) + " ";
            }
            if (accounts.empty() == true) {
                outFile << "N/A";
            }
            outFile << endl;
            outFile << log << endl;
        }
        
        string getFirstName() {
            return firstName;
        } 
        string getLastName() {
            return lastName;
        }
        string getPhoneNumber() {
            return phoneNumber;
        }
        string getAddress() {
            return address;
        }
        vector<string> getAccounts() {
           return accounts;
        }
        void setAccounts(vector<string> acc){
            accounts = acc;
        }
        void deleteAccount() {
                string filePath = "Data/" + userID + ".txt";
                for(int i = 0; i < accounts.size(); i++) {
                    string filePath2 = "Accounts/" + accounts[i] + ".txt";
                    remove(filePath2.c_str());
                }
                if(remove(filePath.c_str()) != 0) {
                    cout << "The account has been deleted." << endl;
                }
              
        }
         void disableAccount(string officialID) {
            status = "Inactive " + officialID;
        }
        void enableAccount() {
            status = "Active";
        }
        void setStatus(string stat) {
            status = stat;
        }
        int listAccounts() {
            if(accounts.size() > 0) {
            for(int i = 0; i < accounts.size(); i++) {
                cout << accounts[i] << endl;
                return 1;
            }
            }else {
                return 0;
            }
            return 0;
        }
       


};
#endif
