#include "BankEmployee.h"
#include <iostream>

BankEmployee::BankEmployee(string name, int id, string title)
    : employeeName(name), employeeID(id), jobTitle(title) {}

void BankEmployee::accessAccount(BankAccount& acc) {
    cout << "Employee can access public data!! " << acc.customerName << endl;
    cout << "Customer name: " << acc.customerName << endl;
    cout << "Customer id: " << acc.accountNumber << endl;
}
void BankEmployee::requestUnfreeze(BankAccount& acc, int pin) {
    acc.unFreezeAccount(pin);
    if(!acc.isAccountFrozen()) {
        cout << "Employee can access the account" << endl;
    }
}