#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(string name, int accNum, double initialBalance, int pin, bool _isFrozen = true) 
    : customerName(name), accountNumber(accNum), balance(initialBalance), securityPin(pin), isFrozen(_isFrozen) {}

double BankAccount::getBalance() { 
    cout << "Current balance: " << balance << endl;
    return balance; 
}

void BankAccount::deposit(double amount) {
    if(isAccountFrozen()) {
        cout << "Account is frozen please enter the pin." << endl;
        return;
    }
    balance += amount;
    cout << "Deposit has successfully made." << endl;
}

void BankAccount::withdraw(double amount) {
    if(isAccountFrozen()) {
        cout << "Account is frozen please enter the pin." << endl;
        return;
    }
    balance -= amount;
    cout << "Withdraw has successfully made." << endl;
}

bool BankAccount::isAccountFrozen() { return isFrozen; }

void BankAccount::unFreezeAccount(int pin) {
    if(isAccountFrozen()) {
        cout << "Account is already frozen you can make transactions." << endl;
        return;
    }

    if(securityPin == pin) {
        isFrozen = false;
        cout << "Correct pin account is open." << endl;
    }
    else cout << "Incorrect pin please try again" << endl;
}
void BankAccount::setBalance(double newBalance) {
    if(isAccountFrozen()) {
        cout << "Account is frozen please enter the pin." << endl;
        return;
    }
    balance = newBalance;
}
