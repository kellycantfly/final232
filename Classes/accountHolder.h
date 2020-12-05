#ifndef accountHolder_H
#define accountHolder_H
#include "user.h"
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
            outFile << username << endl;
            outFile << password << endl;
            outFile << lastLogin;
            outFile << status << endl;
            outFile << firstName << endl;
            outFile << lastName << endl;
            outFile << phoneNumber << endl;
            outFile << address << endl;
            for(int i = 0; i < accounts.size(); i++) {
                outFile << accounts[i] + " ";
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
        void deleteAccount() {
                string filePath = "Data/" + userID + ".txt";
                if(remove(filePath.c_str()) != 0) {
                    cout << "The account has been deleted." << endl;
                }
              // rememmber to delete the checking accounts and such here too  
        }
         void disableAccount(string officialID) {
            status = "Inactive " + officialID;
        }
        void enableAccount() {
            status = "Active";
        }
       


};
#endif