#include <iostream>
#include <string>
#include "function.h"
using namespace std;

void menu(int menuType, USER use) {
    if (menuType == 1) {
        cout << "Account holder!" << endl;
    }
    if (menuType == 2) {
        cout << "Bank official!" << endl;
        use.menu();
    }
    if (menuType == 3) {
        cout << "System admin!" << endl;
    }
}

USER* validateLogin(string username, string password, vector<USER> vec) {

    USER* use = search(username, password, vec);
    string name = use->getUsername();
    if (name.at(0) == 'O')
    {
        cout << "Bank official!" << endl;
        use->menu();
    }
    else if (name.at(0) == 'A')
    {
        cout << "System admin!" << endl;
    }
    else if (name.at(0) == 'H')
    {
        cout << "Account holder!" << endl;
    }
    else
    {
        cout << "No matching account" << endl;
    }
}

USER* login(vector<USER> vec) {
    string username;
    string password;
    cout << endl;
	cout << "######################" << endl;
    cout << "Please enter your credentials to continue." << endl;
    cout << "######################" << endl;
    cout << "Username: ";
    cin >> username;
    cin.clear();
    cout << "Password: ";
    cin >> password;

    return validateLogin(username, password, vec);
    
}


USER* search(string username, string password, vector<USER> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if((vec.at(i).getUsername() == username) && (vec.at(i).getPassword() == password))
        {
            return &vec.at(i);
        }
        else
        {
            cout << "Invalid credentials..." << endl;
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



