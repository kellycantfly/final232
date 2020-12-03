<<<<<<< HEAD
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



=======
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



>>>>>>> 3766df0a8d8b69452f4201877bfaeec3ee7d16c6
