#include "Classes/official.h"
#include "Classes/admin.h"
#include "Classes/accountHolder.h"
#include "Classes/savingAccount.h"
#include "Classes/checkingAccount.h"
#include "Classes/cdAccount.h"
#include <iostream>
#include <vector>

struct financeAccounts {
    vector<cdAccount> cds;
    vector<checkingAccount> checkings;
    vector<savingAccount> savings; 
};

void adminMenu(admin currentUser, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients);
void clientMenu(accountHolder currentUser, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients, financeAccounts &acc);
void officialMenu(official currentUser, vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients);
void loadUsers(vector<official> &officials, vector<admin> &admins, vector<accountHolder> &clients);
int main();
