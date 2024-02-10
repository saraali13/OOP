/*
Name:S. Sara Ali
Roll.no:23K-0070
Des: to write a c++ program to calculate the GCD and LCM of 2 numbers using recursion
*/

#include <iostream>
using namespace std;

//function to calculate GCD of two numbers
int calculateGCD(int a, int b)
    {
     if (b==0) {
         return a;
    } 
	else 
	{
        return calculateGCD(b,a%b);
    }
}

//function for calculating LCM of 2 numbers using 
int calculateLCM(int x,int y) 
   {   
       int gcd;
       gcd=calculateGCD(x,y);
       return (x*y) /gcd ;//finding LCM using GDC by above function
   }

//main function
int main() {
    int n1,n2;
    int GCD,LCM;
    cout<<"Enter first number: ";
    cin>>n1;
    cout<<"Enter second number: ";
    cin>>n2;
    GCD=calculateGCD(n1,n2);
    LCM=calculateLCM(n1,n2);
    cout<<"GCD: "<<GCD<<endl;
    cout<<"LCM: "<<LCM<<endl;

    return 0;
}//end main
