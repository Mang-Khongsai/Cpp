/*
You need to design a class hierarchy for a banking system where 
different types of accounts are managed. We will have a base class 
BankAccount and multiple derived classes such as SavingsAccount, 
CheckingAccount, and BusinessAccount. Each account has the ability 
to calculate the interest or fees, and we need to dynamically 
calculate these values depending on the type of account.
*/

#include <iostream>
#include <string>
using namespace std;

// Base class: BankAccount
class BankAccount {
protected:
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(const string& name, double initialBalance)
        : accountHolderName(name), balance(initialBalance) {}

    // Virtual destructor
    virtual ~BankAccount() {}

    // Virtual method to calculate interest or fees
    virtual void calculate() = 0; // Pure virtual function

    // Display account details
    virtual void display() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: Rs." << balance << endl;
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited Rs." << amount << ". New Balance: Rs." << balance << endl;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew Rs." << amount << ". New Balance: Rs." << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate; // Interest rate as a percentage

public:
    SavingsAccount(const string& name, double initialBalance, double rate)
        : BankAccount(name, initialBalance), interestRate(rate) {}

    void calculate() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest of Rs." << interest << " added. New Balance: Rs." << balance << endl;
    }

    void display() const override {
        cout << "Savings Account:" << endl;
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class: CheckingAccount
class CheckingAccount : public BankAccount {
private:
    double fee; // Monthly maintenance fee

public:
    CheckingAccount(const string& name, double initialBalance, double feeAmount)
        : BankAccount(name, initialBalance), fee(feeAmount) {}

    void calculate() override {
        balance -= fee;
        cout << "Monthly fee of Rs." << fee << " deducted. New Balance: Rs." << balance << endl;
    }

    void display() const override {
        cout << "Checking Account:" << endl;
        BankAccount::display();
        cout << "Monthly Fee: Rs." << fee << endl;
    }
};

// Derived class: BusinessAccount
class BusinessAccount : public BankAccount {
private:
    double transactionFee; // Fee per transaction
    int numberOfTransactions;

public:
    BusinessAccount(const string& name, double initialBalance, double feePerTransaction, int transactions)
        : BankAccount(name, initialBalance), transactionFee(feePerTransaction), numberOfTransactions(transactions) {}

    void calculate() override {
        double totalFees = transactionFee * numberOfTransactions;
        balance -= totalFees;
        cout << numberOfTransactions << " transactions processed. Total fees of Rs." << totalFees
             << " deducted. New Balance: Rs" << balance << endl;
    }

    void display() const override {
        cout << "Business Account:" << endl;
        BankAccount::display();
        cout << "Transaction Fee: Rs." << transactionFee << " per transaction" << endl;
        cout << "Number of Transactions: " << numberOfTransactions << endl;
    }
};

// Main function
int main() {
    // Create accounts
    BankAccount* accounts[3];

    accounts[0] = new SavingsAccount("Alice", 1000.0, 2.0); // 2% interest rate
    accounts[1] = new CheckingAccount("Bob", 2000.0, 15.0); // $15 monthly fee
    accounts[2] = new BusinessAccount("Charlie", 5000.0, 2.0, 10); // $2 per transaction, 10 transactions

    // Display and calculate for each account
    for (int i = 0; i < 3; ++i) {
        accounts[i]->display();
        accounts[i]->calculate();
        cout << "-----------------------------" << endl;
    }

    // Clean up
    for (int i = 0; i < 3; ++i) {
        delete accounts[i];
    }

    return 0;
}
