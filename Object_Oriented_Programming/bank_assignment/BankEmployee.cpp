#include "BankEmployee.h"
#include <iostream>

BankEmployee::BankEmployee(string name, int id, string title)
    : employeeName(name), employeeID(id), jobTitle(title) {
        cout << "SUCCESS! A new employee is created." << endl;
    }

void BankEmployee::accessAccount(BankAccount& acc) {
    cout << "SUCCESS! Employee can access public data!!"<< endl;
    cout << "Customer name: " << acc.customerName << endl;
    cout << "Customer id: " << acc.accountNumber << endl;
    if(!acc.isAccountFrozen()) {
        cout << "Customer balance: " << acc.getBalance() << endl;
    }
}
void BankEmployee::requestUnfreeze(BankAccount& acc, int pin) {
    acc.unFreezeAccount(pin);
    if(!acc.isAccountFrozen()) {
        cout << "SUCCESS! Employee can access the account" << endl;
    }
    else {
        cout << "ERROR: Employee can not access the account" << endl;
    }
}