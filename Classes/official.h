#include "user.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
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
            Log = activity;
        }
        
        void openAccount(string firstName, string lastName, string phoneNumber, string address) {
            srand((unsigned) time(0)); // random number account ID 
            string accID;
            int random;
            for(int i = 0; i < 7; i++) { // creates the digits
                random = 1 + (rand() % 9);
                accID += to_string(random);
            }
            ofstream ofs ("Data/" + accID + ".txt");
            if(ofs) {
                ofs << userID << endl;
                ofs << username << endl;
                ofs << password << endl;
                ofs << "Active" << endl;
                ofs << "No Last Login" << endl;
                ofs << firstName << endl;
                ofs << lastName << endl;
                ofs << phoneNumber << endl;
                ofs << address << endl;
            }
            // we need to reload the data structure to append this account
            
        }
        void closeAccount(string userID) {
            // ** NEED TO ACCESS DATA STRUCTURE TO CHANGE OBJECT (accountHolder.status to == "INACTIVE by this.userID")
        }

        void searchByPhoneNumber(string phone) {

        }
        void searchByAddress(string address) {

        }
        void searchByName(string first, string last) {

        }
        void searchByID(string ID) {

        }
        void depositMoney(string ID, string password) {

        }
        void withdrawMoney(string ID, string password) {

        }
};