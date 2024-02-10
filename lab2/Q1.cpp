/*
Name:S. Sara Ali
Roll.no:23K-0070
Des: to write a c++ program to swap recursively
*/

#include<iostream>
using namespace std;

// swapping function
void recursive_Swap(int& x, int& y,int n) {
       if (n == 0) 
           return;

	 else {
		int temp = x;
        x = y;
        y = temp;
	}
	recursive_Swap(x,y,n-1);// on first call a and b will swap ,on second call there value will be the previous one again, and on 3rd call theyll be again swaped
}// end recursive swap

//main function
int main() {
	int a,b;
	cout<<"enter the value of the first variable:\n ";
	cin>>a;
	cout<<"enter the value of the second variable:\n";
    cin>>b;
    cout<<"the values before the swap:\n"<<"a="<<a<<" , b="<<b<<endl;
       if(a==b)
		cout<<"no swap required\n";
	   else
       recursive_Swap(a,b,3);
       cout<<"the values after the swap:\n"<<"a="<<a<<" , b="<<b<<endl;
    return 0;
}// end main
