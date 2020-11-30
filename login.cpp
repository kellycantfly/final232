#include "driver.cpp"
#include "CreateAccount.cpp"
#include <iostream>
#include <string>
using namespace std;

int validateLogin(string username, string password);
void menu(int menuType);

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

int validateLogin(string username, string password) {
   if(username[0] == 'A') {
       // validate against account holders
   }
    else if(username[0] == 'O') {
       // validate against offical logins

   } else if(username[0] == 'S') {
       //validate against system admins login

   }
   return 0;
}



