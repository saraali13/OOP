/*
name:S.SaraALi
des: to write a c++ program to find whether the entered number is prime or not
*/

#include<iostream>
using namespace std;

int main ()
{    
    int n;
    int count=0;
	cout<<"Enter a number:" ;
	cin>>n;
	for (int i=2;i<=n;i++)
    {
		if (n%i==0)
		{
			
		 count++;// from how many numbers it is divisible
		 
		}// end if
		
	}// end for loop
	
	if (count==1)// as prime number will only be divisible by its self
	{
		
	cout<<"prime number";
	
    }// end if
    
    else 
	{
		
		cout<<"not prime number";
		
	}// end else
	
	return 0;
	
}// end main
