#include <iostream>
#include "BankEmployee.h"

using namespace std;

int main() {
    // Step 1: Creating a bank account (default isFrozen = true)
    BankAccount customerAccount1{"Cedric Noctair", 123456, 500.0, 4321};
    // SUCCESS! A new "customerAccount1" object is created.

    // Step 2: Attempt deposit and withdraw
    customerAccount1.deposit(200); // ERROR: Cannot deposit!
    customerAccount1.withdraw(100); // ERROR: Cannot withdraw!

    // Step 3: Check if account is frozen
    cout << "Is account frozen? " << (customerAccount1.isAccountFrozen() ? "Yes" : "No") << endl;

    // Step 4: Attempt to unfreeze
    customerAccount1.unFreezeAccount(1234); // ERROR: Unfreezing is failed
    
    // Step 5: Attempt to unfreeze again
    customerAccount1.unFreezeAccount(4321); // SUCCESS! The account is activated
    
    // Step 6: Attempt direct balance modification
    //customerAccount1.balance = 10000; // ERROR: Balance update is failed
    
    // Step 7: Modify balance using setBalance()
    customerAccount1.setBalance(10000); // SUCCESS! New balance value is 10000.
    
    // Step 8: Perform deposit and withdraw
    customerAccount1.deposit(500); // SUCCESS! New balance value is 10500.
    customerAccount1.withdraw(300); // SUCCESS! New balance value is 10200.
    
    // Step 9: Create an employee
    BankEmployee employee1{"Isabella Ferrera", 1001, "Manager"}; // SUCCESS! A new "employee1" object is created.
    
    // Step 10: Employee tries to access account details
    employee1.accessAccount(customerAccount1); // SUCCESS! Employee can access public data.
    
    // Step 11: Create a second bank account (default isFrozen = true)
    BankAccount customerAccount2 {"Enrique Valdes", 789012, 250.0, 5678}; // SUCCESS! A new "customerAccount2" object is created.
    
    // Step 12: Employee accesses second account details
    employee1.accessAccount(customerAccount2); // SUCCESS! Employee can access public data.
    
    // Step 13: Employee unfreezes the second account
    employee1.requestUnfreeze(customerAccount2, 5678); // SUCCESS! The account is activated!
   
    // Step 14: Employee accesses second account after unfreezing
    employee1.accessAccount(customerAccount2); // SUCCESS! Employee can access public data.
    return 0;
}
    