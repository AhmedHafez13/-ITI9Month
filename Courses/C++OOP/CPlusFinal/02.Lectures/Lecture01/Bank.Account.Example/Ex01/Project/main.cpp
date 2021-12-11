#include <iostream>
#include <string.h>

using namespace std;

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
            return "You don't have enough balance!";
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
};

int main() {
    cout << endl << "------------------------------------" << endl;
    cout << "Hello! This is the bank application!";
    cout << endl << "------------------------------------" << endl << endl;

    // Creating a new account
    BankAccount account1;
    account1.setupAccount(12349876, "Mohamed Ali Abdullah", "Current account");

    // Print current account info
    account1.printAccountInfo();

    // Deposit to the account (valid amount)
    char * depositMessage = account1.deposit(2000);
    cout << endl << "==> Depositing $2000, message: " << depositMessage << endl << endl;

    // Print current account info
    account1.printAccountInfo();

    // Withdraw from the account
    char * withdrawMessage = account1.withdraw(500);
    cout << endl << "==> Withdrawing $500, message: " << withdrawMessage << endl << endl;

    // Print current account info
    account1.printAccountInfo();

    // Deposit to the account (invalid amount)
    char * depositMessage2 = account1.deposit(50);
    cout << endl << "==> Depositing $50, message: " << depositMessage2 << endl << endl;

    // Print current account info
    account1.printAccountInfo();

    // Withdraw from the account (amount more than balance)
    char * withdrawMessage2 = account1.withdraw(3500);
    cout << endl << "==> Withdrawing $3500, message: " << withdrawMessage2 << endl << endl;

    // Print current account info
    account1.printAccountInfo();

    return 0;
}
