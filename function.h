#include <iostream>
#include <string>
#include <vector>
#include "USER.h"
using namespace std;


void menu(int menuType, USER use);

void validateLogin(string username, string password, vector<USER> vec);

void login(vector<USER> vec);

USER* search(string username, string password, vector<USER> vec);

void badAccountCreationRequest();



