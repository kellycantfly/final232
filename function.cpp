#include <iostream>
#include <string>
#include "function.h"
using namespace std;

void menu(int menuType) {
    if (menuType == 1) {

    }
    if (menuType == 2) {

    }
    if (menuType == 3) {

    }
}

int validateLogin(string username, string password) {
    if (username[0] == 'A') {
        // validate against account holders
        return 1;
    }
    else if (username[0] == 'O') {
        // validate against offical logins
        return 2;

    }
    else if (username[0] == 'S') {
        //validate against system admins login
        return 3;

    }
    return 0;
}

void login() {
    string username;
    string password;
    cout << endl;
	cout << "######################" << endl;
    cout << "Please enter your credintals to continue." << endl;
    cout << "######################" << endl;
    cout << "Username: ";
    getline(cin,username);
    cout << endl;
    cout << "Password: ";
    getline(cin,password);

    switch(validateLogin(username, password)) {
        case 1: { // account holder
            menu(1);
            break;
        }
        case 2: { // bank official
            menu(2);
            break;
        }
        case 3: { // system administrator
            menu(3);
            break;
        }
        default: {
            cout << "Invalid credintals..." << endl;
            login();
        }
    }
    
}


void badAccountCreationRequest() {
    cout << endl;
    cout << "######################" << endl;
    cout << "Only Bank Officials may open an account. Please see a bank official to create an account." << endl;
    cout << "######################" << endl;
    cout << endl;
    return;
}



