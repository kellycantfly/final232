#ifndef CDACCOUNT_H
#define CDACCOUNT_H
#include "checkingAccount.h"
#include <iostream>
#include <string>
using namespace std;

class cdAccount : public checkingAccount {
    private:
        string dateOpen;
        string dateClose;
        int penalty;
    public: 
        
       

};

#endif