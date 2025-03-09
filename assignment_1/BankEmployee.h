#ifndef BANKEMPLOYEE_H
#define BANKEMPLOYEE_H

#include "BankAccount.h"
#include <string>
using namespace std;

class BankEmployee {
    public:
        string const employeeName;
        int const employeeID;
        string const jobTitle;
        BankEmployee(string name, int id, string title); // I must control the id whether it is unique but it is not asked.

        void accessAccount(BankAccount& acc);
        void requestUnfreeze(BankAccount& acc, int pin);
};

#endif