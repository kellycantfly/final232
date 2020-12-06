#include "Classes/official.h"
#include "Classes/admin.h"
#include "Classes/accountHolder.h"
#include "driverMenu.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

official createOfficial();
accountHolder lookUpClient(vector<accountHolder> &clients);
admin lookUpAdmin(vector<admin> &admin);
official lookUpOfficial(vector<official> &official);


void adminMenu(admin currentUser, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients) {
        loadUsers(officials,admins,clients);
        cout << "##############" << endl;
        cout << " ADMIN MENU " << endl;
        cout << " [1] CREATE BANK OFFICIAL LOGIN " << endl;
        cout << " [2] DISABLE/RE-ENABLE A BANK OFFICIAL'S LOGIN " << endl;
        cout << " [3] DELETE ACCOUNT(S) " << endl;
        cout << " [4] RETRIEVE A USER'S LOGIN INFORMATION / CHANGE USER PASSWORD" << endl;
        cout << " [5] CREATE ANOTHER ADMINISTRATOR LOGIN " << endl;
        cout << " [6] LOG-OUT " << endl; 
        cout << "##############" << endl;
        string buffer = "";
        getline(cin, buffer);
        int userSelection = stoi(buffer);
        switch(userSelection) {
            case 1: {
                officials.push_back(createOfficial());
                adminMenu(currentUser, officials, admins, clients);
            }
            case 2: {
                cout << "Enter the Bank Official's username: " << endl;
                string buffer = "";
                getline(cin, buffer);
                string username = buffer;
                for(int i = 0; i < officials.size(); i++) {
                    if(officials[i].getUserName() == username) {
                        string status = officials[i].getStatus();
                        if(status.length() <= 7) {
                            cout << "##############" << endl;
                            cout << "User: " << username << endl;
                            cout << "Status: Enabled" << endl;
                            cout << "[1] Disable Account Login" << endl;
                            cout << "[2] Return To Menu" << endl;
                            cout << "##############" << endl;
                            string buffer = "";
                            getline(cin, buffer);
                            int userSelection = stoi(buffer);
                            if(userSelection == 1) {
                                officials[i].disableAccount(currentUser.getUserID());
                                officials[i].saveOfficial();
                                adminMenu(currentUser, officials, admins, clients);
                            } else {
                                adminMenu(currentUser, officials, admins, clients);
                            }
                            
                        }else {
                            cout << "##############" << endl;
                            cout << "User: " << username << endl;
                            cout << "Status: Disabled by " << status.substr(9, status.length()) << endl;
                            cout << "[1] Enable Account Login" << endl;
                            cout << "[2] Return To Menu" << endl;
                            cout << "##############" << endl;
                            string buffer = "";
                            getline(cin, buffer);
                            int userSelection = stoi(buffer);
                            if(userSelection == 1) {
                                officials[i].enableAccount();
                                officials[i].saveOfficial();
                                adminMenu(currentUser, officials, admins, clients);
                            } else {
                                adminMenu(currentUser, officials, admins, clients);
                            }
                        }
                        
                    } else {
                        cout << "##############" << endl;
                        cout << "No Bank Official with that username was found." << endl;
                        cout << "Returning you to Administrator Menu." << endl;
                        cout << "##############" << endl;
                        adminMenu(currentUser, officials, admins, clients);
                    }
                }
            }
            case 3: {
                cout << "##############" << endl;
                cout << "What type of account would you like to delete?" << endl;
                cout << "[1] Client Account" << endl;
                cout << "[2] Bank Official Account" << endl;
                cout << "[3] Adminstrator Account" << endl;
                cout << "[4] Return To Admin Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                switch(userSelection) {
                    case 1: {
                        cout << "Enter username: " << endl;
                        string username = "";
                        getline(cin, username);
                        for(int i = 0; i < clients.size(); i++) {
                            if(clients[i].getUserName() == username) {
                                cout << "##############" << endl;
                                cout << "Please confirm before you DELETE this client's account" << endl;
                                cout << "------------------------" << endl;
                                cout << clients[i].getFirstName();
                                cout << " " + clients[i].getLastName() << endl;
                                cout << clients[i].getUserID() << endl;
                                cout << clients[i].getUserName() << endl;
                                cout << "------------------------" << endl;
                                cout << "Please Type: CONFIRM to delete" << endl;
                                cout << "Otherwise: Enter anything else to return to Admin Menu" << endl;
                                cout << "##############" << endl;
                                string buffer;
                                getline(cin, buffer);
                                if(buffer == "CONFIRM") {
                                    clients[i].deleteAccount();
                                    adminMenu(currentUser, officials, admins, clients);
                                } else {
                                    adminMenu(currentUser, officials, admins, clients);
                                }
                                

                            }
                        }
                        cout << "##############" << endl;
                        cout << "No user found.. Returning to admin menu" << endl;
                        cout << "##############" << endl;
                        adminMenu(currentUser, officials, admins, clients);
                        
                        
                    }
                    case 2: {
                        cout << "Enter username: " << endl;
                        string username = "";
                        getline(cin, username);
                        for(int i = 0; i < officials.size(); i++) {
                            if(officials[i].getUserName() == username) {
                                cout << "##############" << endl;
                                cout << "Please confirm before you DELETE this official's account" << endl;
                                cout << "------------------------" << endl;
                                cout << officials[i].getUserID() << endl;
                                cout << officials[i].getUserName() << endl;
                                cout << "------------------------" << endl;
                                cout << "Please Type: CONFIRM to delete" << endl;
                                cout << "Otherwise: Enter anything else to return to Admin Menu" << endl;
                                cout << "##############" << endl;
                                string buffer;
                                getline(cin, buffer);
                                if(buffer == "CONFIRM") {
                                    officials[i].deleteAccount();
                                    adminMenu(currentUser, officials, admins, clients);
                                } else {
                                    adminMenu(currentUser, officials, admins, clients);
                                }
                                

                            }
                        }
                        cout << "##############" << endl;
                        cout << "No user found.. Returning to admin menu" << endl;
                        cout << "##############" << endl;
                        adminMenu(currentUser, officials, admins, clients);

                    }
                    case 3: {
                        cout << "Enter username: " << endl;
                        string username = "";
                        getline(cin, username);
                        for(int i = 0; i < admins.size(); i++) {
                            if(admins[i].getUserName() == username) {
                                cout << "##############" << endl;
                                cout << "Please confirm before you DELETE this official's account" << endl;
                                cout << "------------------------" << endl;
                                cout << admins[i].getUserID() << endl;
                                cout << admins[i].getUserName() << endl;
                                cout << "------------------------" << endl;
                                cout << "Please Type: CONFIRM to delete" << endl;
                                cout << "Otherwise: Enter anything else to return to Admin Menu" << endl;
                                cout << "##############" << endl;
                                string buffer;
                                getline(cin, buffer);
                                if(buffer == "CONFIRM") {
                                    admins[i].deleteAccount();
                                    adminMenu(currentUser, officials, admins, clients);
                                } else {
                                    adminMenu(currentUser, officials, admins, clients);
                                }
                                

                            }
                        }
                        cout << "##############" << endl;
                        cout << "No user found.. Returning to admin menu" << endl;
                        cout << "##############" << endl;
                        adminMenu(currentUser, officials, admins, clients);
                        

                    }
                    case 4: {
                        adminMenu(currentUser, officials, admins, clients);
                    }
                }
                
            }
            case 4: {
                cout << "##############" << endl;
                cout << "What type of account information are you looking for?" << endl;
                cout << "[1] Client Account" << endl;
                cout << "[2] Bank Official Account" << endl;
                cout << "[3] Adminstrator Account" << endl;
                cout << "[4] Return To Admin Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                switch(userSelection) {
                    case 1: {
                      accountHolder temp = lookUpClient(clients);
                      temp.saveClient();
                      adminMenu(currentUser, officials, admins, clients);
                    }
                    case 2: {
                      official temp = lookUpOfficial(officials);
                      temp.saveOfficial();
                      adminMenu(currentUser, officials, admins, clients);
                        
                    }
                    case 3: {
                      admin temp = lookUpAdmin(admins);
                      temp.saveAdmin();
                      adminMenu(currentUser, officials, admins, clients);
                                
                    }
                    case 4: {
                      adminMenu(currentUser, officials, admins, clients);
                    }
                }
                
            }
            case 5: {
                cout << "##############" << endl;
                cout << "Please enter the following to make an adminstrator account: " << endl;
                cout << "Username: ";
                string username;
                getline(cin, username);
                cout << "Password: ";
                string password;
                getline(cin, password);
                srand((unsigned) time(0));
                string accID;
                int random;
                for(int i = 0; i < 7; i++) {
                    random = 1 + (rand() % 9);
                    accID += to_string(random);
                }
                accID = "S" + accID;
                cout << "##############" << endl;
                cout << "New Admin Account Generated with ID: " + accID << endl;
                cout << "##############" << endl;
                admin temp(accID, username, password, "None", "Active", "");
                temp.saveAdmin();
                admins.push_back(temp);
                adminMenu(currentUser, officials, admins, clients);
            }
            case 6: {
                main();
            }
            default: {
                cout << "Invalid Input..." << endl;
                adminMenu(currentUser, officials, admins, clients);
            }
        }
}

official createOfficial() {
    srand((unsigned) time(0));
    string accID;
    int random;
    for(int i = 0; i < 7; i++) {
        random = 1 + (rand() % 9);
        accID += to_string(random);
    }
    
    cout << "##############" << endl;
    cout << "Auto-Generated UserID: " << accID << endl;
    cout << "Enter Username: ";
     string buffer = "";
     getline(cin, buffer);
     string username = buffer;
    cout << "Enter Password: ";
      buffer = "";
     getline(cin, buffer);
     string password = buffer;
     cout << endl;
     official temp("O"+accID, username, password);
     temp.saveOfficial();
     return temp;
}

accountHolder lookUpClient(vector<accountHolder> &clients) {
    cout << "##############" << endl;
    cout << "Retrieve Information By Entering Either Account ID or Username" << endl;
    cout << "##############" << endl;
    string buffer;
    getline(cin, buffer);
    cout << buffer.length() << endl;
    cout << buffer[0] << endl;
    if (buffer.length() == 8 && buffer[0] == 'A' && isdigit(buffer[2]))
    {

        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].getUserID() == buffer)
            {
                cout << "##############" << endl;
                cout << "Account ID: " << clients[i].getUserID() << endl;
                cout << "Name: " << clients[i].getFirstName() + " " + clients[i].getLastName() << endl;
                cout << "Username: " << clients[i].getUserName() << endl;
                cout << "Last Logined: " << clients[i].getLastLogin() << endl;
                cout << "Status: " << clients[i].getStatus() << endl;
                cout << "[1] Change The Account Password" << endl;
                cout << "[2] Return to Admin Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                if (userSelection == 1)
                {
                    cout << "##############" << endl;
                    cout << "Enter the new password for the account: " << endl;
                    cout << "##############" << endl;
                    string buffer = "";
                    getline(cin, buffer);
                    clients[i].setPassword(buffer);
                    clients[i].saveClient();
                    cout << "##############" << endl;
                    cout << "You have changed the password for " + clients[i].getFirstName() + " " + clients[i].getLastName() << endl;
                    cout << "##############" << endl;
                    return clients[i];
                }
                else
                {
                    return clients[i];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].getUserName() == buffer)
            {
                cout << "##############" << endl;
                cout << "Account ID: " << clients[i].getUserID() << endl;
                cout << "Name: " << clients[i].getFirstName() + " " + clients[i].getLastName() << endl;
                cout << "Username: " << clients[i].getUserName() << endl;
                cout << "Last Logined: " << clients[i].getLastLogin() << endl;
                cout << "Status: " << clients[i].getStatus() << endl;
                cout << "[1] Change The Account Password" << endl;
                cout << "[2] Return to Admin Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                if (userSelection == 1)
                {
                    cout << "##############" << endl;
                    cout << "Enter the new password for the account: " << endl;
                    cout << "##############" << endl;
                    string buffer = "";
                    getline(cin, buffer);
                    clients[i].setPassword(buffer);
                    cout << "##############" << endl;
                    cout << "You have changed the password for " + clients[i].getFirstName() + " " + clients[i].getLastName() << endl;
                    cout << "##############" << endl;
                    return clients[i];
                }
                else
                {
                    return clients[i];
                }
            }
                        
        }
         cout << "##############" << endl;
         cout << "No user found.. Returning to admin menu" << endl;
         cout << "##############" << endl;
        return clients[0];
    }
    return clients[0];
}

official lookUpOfficial(vector<official> &officials) {
    cout << "##############" << endl;
    cout << "Retrieve Information By Entering Either Account ID or Username" << endl;
    cout << "##############" << endl;
    string buffer;
    getline(cin, buffer);
    cout << buffer.length() << endl;
    cout << buffer[0] << endl;
    if (buffer.length() == 8 && buffer[0] == 'O' && isdigit(buffer[2]))
    {

        for (int i = 0; i < officials.size(); i++)
        {
            if (officials[i].getUserID() == buffer)
            {
                cout << "##############" << endl;
                cout << "Account ID: " << officials[i].getUserID() << endl;
                cout << "Username: " << officials[i].getUserName() << endl;
                cout << "Last Logined: " << officials[i].getLastLogin() << endl;
                cout << "Status: " << officials[i].getStatus() << endl;
                cout << "[1] Change The Account Password" << endl;
                cout << "[2] Return to Admin Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                if (userSelection == 1)
                {
                    cout << "##############" << endl;
                    cout << "Enter the new password for the account: " << endl;
                    cout << "##############" << endl;
                    string buffer = "";
                    getline(cin, buffer);
                    officials[i].setPassword(buffer);
                    officials[i].saveOfficial();
                    cout << "##############" << endl;
                    cout << "You have changed the password for " + officials[i].getUserName() << endl;
                    cout << "##############" << endl;
                    return officials[i];
                }
                else
                {
                    return officials[i];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < officials.size(); i++)
        {
            if (officials[i].getUserName() == buffer)
            {
                cout << "##############" << endl;
                cout << "Account ID: " << officials[i].getUserID() << endl;
                cout << "Username: " << officials[i].getUserName() << endl;
                cout << "Last Logined: " << officials[i].getLastLogin() << endl;
                cout << "Status: " << officials[i].getStatus() << endl;
                cout << "[1] Change The Account Password" << endl;
                cout << "[2] Return to Admin Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                if (userSelection == 1)
                {
                    cout << "##############" << endl;
                    cout << "Enter the new password for the account: " << endl;
                    cout << "##############" << endl;
                    string buffer = "";
                    getline(cin, buffer);
                    officials[i].setPassword(buffer);
                    cout << "##############" << endl;
                    cout << "You have changed the password for " + officials[i].getUserName() << endl;
                    cout << "##############" << endl;
                    return officials[i];
                }
                else
                {
                    return officials[i];
                }
            }
        }
    } 
    cout << "##############" << endl;
    cout << "No user found.. Returning to admin menu" << endl;
    cout << "##############" << endl;
    return officials[0];
}

admin lookUpAdmin(vector<admin> &admins) {
    cout << "##############" << endl;
    cout << "Retrieve Information By Entering Either Account ID or Username" << endl;
    cout << "##############" << endl;
    string buffer;
    getline(cin, buffer);
    cout << buffer.length() << endl;
    cout << buffer[0] << endl;
    if (buffer.length() == 8 && buffer[0] == 'S' && isdigit(buffer[2]))
    {

        for (int i = 0; i < admins.size(); i++)
        {
            if (admins[i].getUserID() == buffer)
            {
                cout << "##############" << endl;
                cout << "Account ID: " << admins[i].getUserID() << endl;
                cout << "Username: " << admins[i].getUserName() << endl;
                cout << "Last Logined: " << admins[i].getLastLogin() << endl;
                cout << "Status: " << admins[i].getStatus() << endl;
                cout << "[1] Change The Account Password" << endl;
                cout << "[2] Return to Admin Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                if (userSelection == 1)
                {
                    cout << "##############" << endl;
                    cout << "Enter the new password for the account: " << endl;
                    cout << "##############" << endl;
                    string buffer = "";
                    getline(cin, buffer);
                    admins[i].setPassword(buffer);
                    admins[i].saveAdmin();
                    cout << "##############" << endl;
                    cout << "You have changed the password for " + admins[i].getUserName() << endl;
                    cout << "##############" << endl;
                    return admins[i];
                }
                else
                {
                    return admins[i];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < admins.size(); i++)
        {
            if (admins[i].getUserName() == buffer)
            {
                cout << "##############" << endl;
                cout << "Account ID: " << admins[i].getUserID() << endl;
                cout << "Username: " << admins[i].getUserName() << endl;
                cout << "Last Logined: " << admins[i].getLastLogin() << endl;
                cout << "Status: " << admins[i].getStatus() << endl;
                cout << "[1] Change The Account Password" << endl;
                cout << "[2] Return to Admin Menu" << endl;
                cout << "##############" << endl;
                string buffer = "";
                getline(cin, buffer);
                int userSelection = stoi(buffer);
                if (userSelection == 1)
                {
                    cout << "##############" << endl;
                    cout << "Enter the new password for the account: " << endl;
                    cout << "##############" << endl;
                    string buffer = "";
                    getline(cin, buffer);
                    admins[i].setPassword(buffer);
                    cout << "##############" << endl;
                    cout << "You have changed the password for " + admins[i].getUserName() << endl;
                    cout << "##############" << endl;
                    return admins[i];
                }
                else
                {
                    return admins[i];
                }
            }
        }
    }
    cout << "##############" << endl;
    cout << "No user found.. Returning to admin menu" << endl;
    cout << "##############" << endl;
    return admins[0];
}