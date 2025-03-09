#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(string name, int accNum, double initialBalance, int pin, bool _isFrozen) 
    : customerName(name), accountNumber(accNum), balance(initialBalance), securityPin(pin), isFrozen(_isFrozen) {
    cout << "SUCCESS! A new account is created." << endl;
}

double BankAccount::getBalance() {
    if(isAccountFrozen()) {
        cout << "ERROR: Can not show balance, account is frozen, please enter the pin." << endl;
        return -1;
    }
    return balance; 
}

void BankAccount::deposit(double amount) {
    if(isAccountFrozen()) {
        cout << "ERROR: Can not deposit, account is frozen, please enter the pin." << endl;
        return;
    }
    balance += amount;
    cout << "SUCCESS! Deposit has successfully made." << endl;
    cout << "Current balance: " << balance << endl;
}

void BankAccount::withdraw(double amount) {
    if(isAccountFrozen()) {
        cout << "ERROR: Can not withdraw, account is frozen, please enter the pin." << endl;
        return;
    }
    balance -= amount;
    cout << "SUCCESS! Withdraw has successfully made." << endl;
    cout << "Current balance: " << balance << endl;
}

bool BankAccount::isAccountFrozen() { return isFrozen; }

void BankAccount::unFreezeAccount(int pin) {
    if(!isAccountFrozen()) {
        cout << "ERROR: Account is already open you can make transactions." << endl;
        return;
    }

    if(securityPin == pin) {
        isFrozen = false;
        cout << "SUCCESS! Correct pin account is open." << endl;
    }
    else cout << "ERROR: Incorrect pin please try again" << endl;
}
void BankAccount::setBalance(double newBalance) {
    if(isAccountFrozen()) {
        cout << "ERROR: Account is frozen please enter the pin." << endl;
        return;
    }
    balance = newBalance;
    cout << "SUCCESS! Current balance: " << balance << endl;
}
