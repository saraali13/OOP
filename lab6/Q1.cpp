/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class BankAccount
{

    int accountId;
    double balance;
    int *transactionHistory;
    int numTransaction;

    public:

    BankAccount(int accountId,double balance,int *transactionHistory ,int numTransaction)//parameterized constructor for initiallization
    {
    	
        this->accountId=accountId;
        this->balance=balance;
        this->numTransaction=numTransaction;
        this->transactionHistory=new int [numTransaction];//DMA
        
        for(int i=0;i<numTransaction;i++)
        {
          this->transactionHistory[i]=transactionHistory[i];
        }
        
    }//end
    
    //copy constructor
    
    BankAccount(const BankAccount & Account):accountId(Account.accountId),balance(Account.balance),numTransaction(Account.numTransaction)
    {
    	
       this->transactionHistory=new int [numTransaction];//DMA
       
       for (size_t i = 0; i < numTransaction; i++)
       {
         this->transactionHistory[i]=Account.transactionHistory[i];
       }
       
    }// end
    
    //destrutor
    
    ~BankAccount()
    {
    	
       delete[] transactionHistory;
       
    }//end
    
    //function for displaying bank account details
	 
    void Display()
    {
    	
       cout<<"Account ID: "<< accountId;
       cout<<"\nAccount Balance: "<<balance;
       cout<<"\nTransaction History:\n";
       
       for (int i=0;i<numTransaction;i++)
       {
           cout<<transactionHistory[i]<<" ,";
       }
       
       cout<<endl;
       
    }
    
    //function for updating transaction history
    
    void updateTransactionHistory(int *newTrans,int new_numTransaction)
    {
    	
      int * new_transactionHistory= new int [new_numTransaction];//DMA
      
       for ( int i = 0; i < new_numTransaction; i++)
       {
          new_transactionHistory[i]=newTrans[i];
       }
       
       delete[] transactionHistory;//delete previous history 
       numTransaction=new_numTransaction;
       transactionHistory=new_transactionHistory;
       
    }// end
    
};//end class

//main function

int main ()
{
  cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
  
  int Transaction[]={300,40,-98,79};
  int numTrans= sizeof(Transaction)/sizeof(Transaction[0]);
  
  BankAccount Acc1(234,1290.45,Transaction,numTrans);
  BankAccount Acc2=Acc1;

  cout<<"Details of Orignal Account: \n";
  Acc1.Display();

  cout<<"\nDetails of Copied Account: \n";
  Acc2.Display();

  int newTransaction[]={678,-59,49};
  int newNumTrans=sizeof(newTransaction)/sizeof(newTransaction[0]);
  Acc1.updateTransactionHistory(newTransaction,newNumTrans);

  cout<<"\nDetails of Upated Orignal Account: \n";
  Acc1.Display();

  return 0;
}// end main
