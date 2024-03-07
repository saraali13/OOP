/*
Name: S. Sara Ali
ID:23K-0070
*/

#include<iostream>
using namespace std;

class LoanHelper
{
	const float Rate;
	float Amount;	
	int MonthsLoan;		
	
	public:
		
		LoanHelper(float rate, float amount, int monthsLoan):Rate(rate), Amount(amount), MonthsLoan(monthsLoan)//parameterized constructor
		{
			if(rate<=0 || rate>=0.005)
			{
				cout<<"invalid rate\n";
			}
		}
	//function to calculate the amount that should be paid every month
		void amountToPay()
		{
			float ToPay;
			float Interest;
			float MP;
			MP = Amount/MonthsLoan;
			Interest = MP*Interest;
			ToPay=MP+Interest;
			cout<<"You have to pay "<<ToPay<<" every month for "<<MonthsLoan<<" months to repay your loan\n";
		}
};// end loanHelper class

int main()
{
	
	LoanHelper L1(0.67, 234000, 4);
	L1.amountToPay();
	
}// end main
