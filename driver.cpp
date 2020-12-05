#include "Classes/official.h"
#include "Classes/admin.h"
#include "Classes/accountHolder.h"
#include "driverMenu.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <filesystem>
namespace fs = filesystem;

using namespace std;


bool validateLogin(string username, string password, int accType, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients);
void retryLogin(int accType, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients);
void loadUsers(vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients);
int main () {
    
    vector<official> officials;
    vector<admin> admins;
    vector<accountHolder> clients;

    for(;;) {
        loadUsers(officials, admins, clients);
        cout << "##############" << endl;
        cout << " BEAR BANK LOGIN " << endl;
        cout << " [1] LOGIN " << endl;
        cout << " [2] CREATE AN ACCOUNT " << endl;
        cout << " [3] EXIT " << endl;
        cout << "##############" << endl;
        
        string buffer;
        getline(cin, buffer);
        int userSelection = stoi(buffer);

        switch(userSelection) {
            case 1: { // LOGIN
                cout << "##############" << endl;
                cout << " [1] CUSTOMER LOGIN" << endl;
                cout << " [2] EMPLOYEE LOGIN " << endl;
                cout << " [3] EXIT " << endl;
                cout << "##############" << endl;
                buffer = "";
                getline(cin, buffer);
                userSelection = stoi(buffer);


                if(userSelection == 1) {
                cout << "##############" << endl;
                cout << " PLEASE ENTER YOUR CREDINTENALS " << endl;
                cout << "##############" << endl;
                cout << "Username: ";
                string username;
                getline(cin, username);
                cout << "Password: ";
                string password;
                getline(cin, password);
                validateLogin(username, password, userSelection, officials, admins, clients);
                }
                if(userSelection == 2) {
                    cout << "##############" << endl;
                    cout << " [1] BANK OFFICIAL" << endl;
                    cout << " [2] SYSTEM ADMIN" << endl;
                    cout << " [3] RETURN TO MAIN MENU " << endl;
                    cout << "##############" << endl;
                    buffer;
                    getline(cin, buffer);
                    userSelection = stoi(buffer);
                    if(userSelection == 3) {
                        main();
                    }
                    cout << "##############" << endl;
                    cout << " PLEASE ENTER YOUR CREDINTENALS " << endl;
                    cout << "##############" << endl;
                    cout << "Username: ";
                    string username;
                    getline(cin, username);
                    cout << "Password: ";
                    string password;
                    getline(cin, password);
                    if(userSelection == 1) {
                        userSelection = 2;
                        validateLogin(username, password, userSelection, officials, admins, clients);
                    }else if(userSelection == 2) {
                        userSelection = 3;
                        validateLogin(username, password, userSelection, officials, admins, clients);
                    }
                } else if(userSelection == 3){
                    exit(1);
                }else {
                    cout << "##############" << endl;
                    cout << "Incorrect Input... Returning to main menu" << endl;
                    cout << "##############" << endl;
                }
            }
            case 2: {
                cout << "########" << endl;
                cout << "CHANGE THIS LATER..." << endl;

            }
            case 3: { // exit condition
                cout << " GOODBYE " << endl;
                cout << "##############" << endl;
                // saveAccounts();
                exit(1);
            }
        }
        
    }
}
// load in the users into the program
void loadUsers(vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients) {
    
 
    string path = "Data/";
    vector<string> accountIDs; // USE A BST HERE!!!
    for(const auto & entry : fs::directory_iterator(path)) {
        string temp = entry.path().string();
        temp = temp.substr(5,8);
        accountIDs.push_back(temp);
    }
    for(int i = 0; i < accountIDs.size(); i++) {
        string accountID = accountIDs[i];
        if(accountID[0] == 'S') {
            // get the file 
            // create an admin 
            // push admin
            ifstream inFile;
            inFile.open("Data/"+accountID+".txt");
            string text;
            string log;
            vector<string> temp;
            while(getline(inFile, text)) {
                if(text[0] != '@') {   
                    temp.push_back(text); 
                } else {
                    log = text + log;
                }
            }
            string username = temp[1];
            string password = temp[2];
            string lastLogin = temp [3]; 
            string status = temp [4];
            if(status.length() < 5) {
                status = "Active";
            }
            admin tempAdmin(accountID, username, password, lastLogin, status, log);
            admins.push_back(tempAdmin);
            
        } else if (accountID[0] == 'O') {
            ifstream inFile;
            inFile.open("Data/"+accountID+".txt");
            string text;
            string log;
            vector<string> temp;
            while(getline(inFile, text)) {
                if(text[0] != '@') {   
                    temp.push_back(text); 
                } else {
                    log = text + log;
                }
            }
            string username = temp[1];
            string password = temp[2];
            string lastLogin = temp[3]; 
            string status = temp[4];

            if(status.length() < 5) {
                status = "Active";
            }
            
            official tempOfficial(accountID, username, password, lastLogin, status, log);
            officials.push_back(tempOfficial);
            
            
        } else if (accountID[0] == 'A') {
            ifstream inFile;
            inFile.open("Data/"+accountID+".txt");
            string text;
            string log;
            vector<string> temp;
            while(getline(inFile, text)) {
                if(text[0] != '@') {   
                    temp.push_back(text); 
                } else {
                    log = text + log;
                }
            }

            string username = temp[1];
            string password = temp[2];
            string lastLogin = temp[3]; 
            string status = temp[4];
            if(status.length() < 5) {
                status = "Active";
            }
            string firstName = temp[5];
            string lastName = temp[6];
            string phoneNumber = temp[7];
            string address = temp[8];
            vector<string> accounts;
            
            string tempString;
            stringstream ss(temp[9]);
    
            while(getline(ss, tempString, ' ')) {
                accounts.push_back(tempString);
            }

            accountHolder tempAccount(accountID, username, password, lastLogin, status, firstName, lastName, phoneNumber, address, accounts, log);
            clients.push_back(tempAccount);
        }
    }

    

}

bool validateLogin(string username, string password, int accType, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients) {
    loadUsers(officials,admins,clients);
    if(accType == 1) { // CUSTOMER
        for(int i = 0; i < clients.size(); i++) {
            if(clients[i].getUserName() == username && clients[i].getPassword() == password) {
                time_t now = time(0);
                char* date_time = ctime(&now);
                string date(date_time);
                clients[i].setLastLogin(date.substr(0,date.length()));
                clients[i].saveClient();
                clientMenu(clients[i], officials, admins, clients);
            }

        }
    }
    if(accType == 2) { // OFFICIAL
       for(int i = 0; i < admins.size(); i++) {
            if(officials[i].getUserName() == username && officials[i].getPassword() == password) {
                time_t now = time(0);
                char* date_time = ctime(&now);
                string date(date_time);
                officials[i].setLastLogin(date.substr(0,date.length()));
                officials[i].saveOfficial();
                officialMenu(officials[i], officials, admins, clients);
            }
            
        }     
    }
    if(accType == 3) {
        for(int i = 0; i < admins.size(); i++) {
            if(admins[i].getUserName() == username && admins[i].getPassword() == password) {
                time_t now = time(0);
                char* date_time = ctime(&now);
                string date(date_time);
                admins[i].setLastLogin(date.substr(0,date.length()));
                admins[i].saveAdmin();
                adminMenu(admins[i], officials, admins, clients);
            }
            
        }
        
    }
     do{
        cout << "##############" << endl;
        cout << " INCORRECT CREDINTIALS " << endl;
        cout << "##############" << endl;
        cout << "[1] Retry Login" << endl;
        cout << "[2] Return to Main Menu" << endl;
        cout << "##############" << endl;
        string buffer = "";
        getline(cin, buffer);
        int userSelection = stoi(buffer);
        if(userSelection == 1) {
            retryLogin(accType, officials, admins, clients);
        }else{ // error
            main();
        }
     }while(validateLogin(username,password, accType, officials, admins, clients) == false);   
}

void retryLogin(int accType, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients) {
    cout << "##############" << endl;
    cout << " PLEASE ENTER YOUR CREDINTENALS " << endl;
    cout << "##############" << endl;
    cout << "Username: ";
    string username;
    getline(cin, username);
    cout << "Password: ";
    string password;
    getline(cin, password);
    validateLogin(username, password, accType, officials, admins, clients);
}
