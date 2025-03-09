#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
using namespace std;

class BankAccount {
    private:
        double balance;
        int securityPin;
        bool isFrozen;
    
    public:
        string const customerName;
        int const accountNumber;

        BankAccount(string name, int accNum, double initialBalance, int pin, bool isFrosen = true); // Actually I should not add last part but it is asked. Also id must be unique I must control it but also it is not asked

        double getBalance();
        void deposit(double amount);
        void withdraw(double amount);
        bool isAccountFrozen();
        void unFreezeAccount(int pin);
        void setBalance(double newBalance);
};

#endif