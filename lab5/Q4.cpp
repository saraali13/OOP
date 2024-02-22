/*
Name:S. SARA ALI
ID:23K-0070
*/


#include <iostream>
#include <string>
using namespace std;


class BankAccount 
{
	
private:
	
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(int accountNumber,string accountHolderName, double balance)
	 {
	 	//initiallization using this pointer
	 	this->accountNumber=accountNumber;
	 	this->accountHolderName=accountHolderName;
	 	this->balance=balance;
	 	
	 }// end 


    // function for Depositing money
    
    void deposit(double amount) 
	{
		
        if (amount > 0) 
		{
        	
            balance += amount;
            cout << "Amount deposited-New balance is " << balance <<endl;
        } 
		else 
		{
            cout << "Invalid deposit amount\n";// if amount is less than 0
        }
        
    }// end


    // function for withdrawing money
    
    void withdraw(double amount) 
	{
        if (amount > 0 && amount <= balance) 
		{
			
            balance -= amount;
            cout << "Amount withdrawn-New balance is " << balance << endl;
        } 
		else 
		{
			
            cout << "Invalid withdrawal amount\n";// if amount is less than 0 or greater than the acc current balance
        }
        
    }// end


    // function for displaying all the details of the bank 
    
    void display() const 
	{

        cout << "Account Number: " << accountNumber;
        cout << "\nAccount Holder Name: " << accountHolderName ;
        cout << "\nBalance: " << balance << endl;
        
    }// end 
    
    
};// end of the class

// main function

int main() 
{
    BankAccount accounts[3] = 
   	{
        BankAccount(75554, "John", 0),
        BankAccount(98755, "Ali", 65643),
        BankAccount(78765, "Jane", 56543),
     };// array of bank accounts

   for (int i=0;i<3;i++) // calling the functions for every account 
    {
        		
    	cout<<"\nDisplaying the details of account "<<i+1<<endl;
        accounts[i].deposit(0);
        accounts[i].withdraw(3458);
        accounts[i].display();
        cout<<endl;
   }

    return 0;
}
// end main 
