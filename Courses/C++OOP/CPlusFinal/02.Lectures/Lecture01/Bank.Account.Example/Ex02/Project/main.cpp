#include <iostream>
#include <string.h>

using namespace std;

/**
    ## The goal of the project: Encapsulate (deposit, withdraw and transfer)
       functions to add some restrictions
    1. Create an array to store accounts data
    2. Create two accounts
    3. Deposit amount for every account (3500 and 1000)
    4. Print accounts info
    5. Transfer a valid amount ($500) from the first account the the second one
    6. Print accounts info again to see the new balance ($3000 and $1500)
    7. Transfer an invalid amount from the second account to the first one
    8. Print accounts info, accounts balance should not be changed ($3000 and $1500)
*/

class BankAccount {
    int accountNumber;
    char depositorName[30];
    char type[20];
    int balance;

public:
    void setupAccount(int _accountNumber, char * _depositorName, char * _type) {
        accountNumber = _accountNumber;
        strcpy(depositorName, _depositorName);
        strcpy(type, _type);
        balance = 0;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    char * getDepositorName() {
        return depositorName;
    }

    char * getType() {
        return type;
    }

    int getBalance() {
        return balance;
    }

    char * deposit(int amount) {
        if (amount < 100 || amount > 5000) {
            return "This amount is not valid, deposit amount between $100 and $5000";
        } else {
            balance += amount;
        }
        return "Deposited successfully";
    }

    char * withdraw(int amount) {
        if (amount < 100) {
            return "This amount is not valid, you can't withdraw less than $100";
        } else if (balance < amount) {
            return "You don't have enough balance to withdraw!";
        } else {
            balance -= amount;
        }
        return "Withdrawn successfully";
    }

    void printAccountInfo() {
        cout << "\nAccount Information" << "\n-----------------------"
             << "\nAccount No.: " << accountNumber
             << "\nDepositor Name: " << depositorName
             << "\nAccount Type: " << type
             << "\nBalance: $" << balance << endl;
    }

    char * transfer(int amount, BankAccount& transToAccount) {
        if (amount < 100 or amount > 3000) {
            return "This amount is not valid, transfer amount between $100 and $3000";
        } else if (balance < amount){
            return "You don't have enough balance to transfer!";
        } else {
            // Withdraw from this account
            withdraw(amount);
            // Deposit the amount to the target account
            transToAccount.deposit(amount);
        }
        return "Transfered successfully";
    }
};

int main() {
    cout << endl << "------------------------------------" << endl;
    cout << "Hello! This is the bank application!";
    cout << endl << "------------------------------------" << endl << endl;

    // The accounts array
    BankAccount accounts[5];

    // Creating a new account of id 0
    accounts[0].setupAccount(0, "Mohamed Ali Abdullah", "Current account");
    accounts[0].deposit(3500);

    // Creating another new account of id 1
    accounts[1].setupAccount(1, "Sarah Ibrahim Ahmed", "Salary account");
    accounts[1].deposit(1000);

    // Print current account info after initializing
    accounts[0].printAccountInfo();
    accounts[1].printAccountInfo();

    // Transfer $500 (a valid amount) from the first account to the second one
    // First account (3500 - 500 = 3000), the second (1000 + 500 = 1500)
    char * message1 = accounts[0].transfer(500, accounts[1]);
    cout << endl << "==> Transfer $500, message: " << message1 << endl << endl;

    // Print current account info after valid transfer
    accounts[0].printAccountInfo();
    accounts[1].printAccountInfo();

    // Transfer $8000 (an invalid amount) from the second account to the first one
    // This should give an error message, balance of both accounts should not change
    char * message2 = accounts[1].transfer(8000, accounts[0]);
    cout << endl << "==> Transfer $8000, message: " << message2 << endl << endl;

    // Print current account info after invalid transfer
    accounts[0].printAccountInfo();
    accounts[1].printAccountInfo();

    return 0;
}
