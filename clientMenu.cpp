#include "Classes/official.h"
#include "Classes/admin.h"
#include "Classes/accountHolder.h"
#include "driverMenu.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

void clientMenu(accountHolder currentUser, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients) {
    loadUsers(officials,admins,clients);

    cout << "##############" << endl;
    cout << "CLIENT MENU " << endl;
    cout << "Welcome back, " + currentUser.getFirstName() + " " + currentUser.getLastName() << endl;
    cout << "Last logged in at: " << currentUser.getLastLogin();
    cout << "Current Accounts: " << endl;
    vector<string> accounts = currentUser.getAccounts();
    for(int i = 0; i < accounts.size(); i++) {
        cout << accounts[i] << endl;
    }
    cout << endl;
    cout << " [1] DEPOSIT INTO ACCOUNT " << endl;
    cout << " [2] WITHDRAW INTO ACCOUNT " << endl;
    cout << " [3] CLOSE ACCOUNT " << endl;
    cout << " [3] LOOK AT TRANSCATION LOGS " << endl;
    cout << " [4] CHANGE PASSWORD " << endl;
    cout << " [5] LOG-OUT " << endl; 
    cout << "##############" << endl;
    string buffer = "";
    getline(cin, buffer);
    int userSelection = stoi(buffer);

}