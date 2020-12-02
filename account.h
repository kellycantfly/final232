#include <string>
#include <iostream>
using namespace std;

class Account {
    private:
        string accountID;
        string username;
        string password;
        string firstName;
        string lastName;

        bool status;
        friend class BankOfficial;
        friend class SystemAdmin;
    public:
        void setAccountID(string accID) {
            accountID = accID;
        }
        void setUsername(string user) {
            username = user;
        }
        void setPassword(string pass) {
            password = pass;
        }
        void setfirstName(string name) {
            firstName = name;
        }
        void setlastName(string name) {
            lastName = name;
        }
        string getUsername() {
            return username;
        }
};
class AccountHolder : public Account {
    private:
        string phoneNumber;
        string address;
        string dateOpened;
        string dateClosed;
        string maturity;
        string lastLogin;
        string accounts;
        string accountLog;
        friend class BankOfficial;
        friend class SystemAdmin;
    public: 
        void setPhone(string phone) {
            phoneNumber = phone;
        }
        void setAddress(string userAddress) {
            address = userAddress;
        }
        string getAddress() {
            return address;
        }
        void setDateOpened(string date) {
            dateOpened = date;
        }
        void setDateClosed(string date) {
            dateClosed = date;
        }
        
};

class BankOfficial : public Account {
    public: 
        void openAccount() {
            
        }
        void closeAccount() {

        }
        void searchAccount() { // official can search by phone, address, customer name
            
        }
        void depositToAccount(string accID, string password) {

        }
        void withdrawToAccounts(string accID, string password) {

        }
};

class SystemAdmin : public Account {
    public: 
        void createLogin() {

        }
        void disableAccount() {

        }
        void changePassword() {

        }
};

class BankAccount {
    private:
        string accID;
        string userID;
        double balance;
        double fee;
    public:
        void setAccID(string accID) {

        }
        void setUserID(string userID) {

        }
};

class SavingAccount : public BankAccount {
    private:
    double interestRate;
    public: 
        void setInterestRate(double intRate) {
            interestRate = intRate;
        }


};

class CheckingAccount : public BankAccount {

};

class CDAccount : public BankAccount {
    private:
    string creationDate;
    int termLength;
    string dateOpen;
    string dateClose;
    int maturity;
    int interestRate;

};


