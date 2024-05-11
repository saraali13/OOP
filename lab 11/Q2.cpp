/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

// Abstract base class 
class Account 
{
protected:
    int accountNumber;
    double balance;

public:
   //parameterized constructor
    Account(int accNum, double Bal) : accountNumber(accNum), balance(Bal) 
    {}

    //pure virtual functions
    virtual void deposit(double amount) = 0; 
    virtual void withdraw(double amount) = 0; 
    virtual void calculateInterest() = 0; 
    
    //getter functions
    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }
};

//subclass for Savings Account
class SavingsAccount : public Account 
{
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double Bal, double rate) : Account(accNum,Bal), interestRate(rate) 
    {}

    void deposit(double amount) 
    {
        balance += amount;
    }

    void withdraw(double amount) 
   {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient Balance \n";
    }

    void calculateInterest() 
   {
        double interest = balance * interestRate / 100;
        balance += interest;
    }
};

//subclass for Current Account
class CurrentAccount : public Account 
{
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNum, double Bal, double limit) : Account(accNum, Bal), overdraftLimit(limit) 
    {}

    void deposit(double amount) 
    {
        balance += amount;
    }

    void withdraw(double amount) 
    {
        if (balance + overdraftLimit >= amount)
            balance -= amount;
        else
            cout << "Withdrawal exceed the limit\n";
    }

    void calculateInterest() 
    {
        // Current accounts is having no interest
        cout << "No interest for current account\n";
    }
};

int main() 
{

   cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";

    SavingsAccount savings(190, 100940, 8); 
    savings.deposit(200);
    savings.withdraw(3489);
    savings.calculateInterest();
    cout << "Savings Account Balance: " << savings.getBalance() << endl;

    CurrentAccount current(987, 20009644, 1000); 
    current.deposit(890);
    current.withdraw(35647);
    current.calculateInterest();
    cout << "Current Account Balance: " << current.getBalance() << endl;

    return 0;
}

