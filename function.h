#include <iostream>
#include <string>
#include <vector>
#include "USER.h"
using namespace std;

void menu(int menuType, USER use);

USER* validateLogin(string username, string password, vector<USER> vec);

USER* login(vector<USER> vec);

USER* search(string username, string password, vector<USER> vec);

void badAccountCreationRequest();



