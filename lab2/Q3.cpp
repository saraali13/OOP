/*
Name:S. Sara Ali
Roll.no:23K-0070
Des: to write a c++ program to checks if there’s a subset of the array whose elements sum up to the target sum
*/

#include<iostream>
using namespace std;


bool hasSubsetSum(int arr[], int size, int targetSum) {
    if (targetSum == 0) 
	{
        return true;
    }//subset exist
    
    if (size == 0 && targetSum != 0) 
	{
        return false;
    }//subset doesnot exist
    
    if (arr[size - 1] <= targetSum) 
	{
        return hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]) || hasSubsetSum(arr, size - 1, targetSum);
    } 
	else 
	  {
        return hasSubsetSum(arr, size - 1, targetSum);
      }
    //the resursion will cont. till the targetsum or size of an array becomes 0
}

//main function
int main() {
    int arr[] = {1, 2, 3, 4, 5,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum = 22;

    if (hasSubsetSum(arr, size, targetSum))// if true 
	 {
        cout << "a subset with sum " << targetSum <<"exists \n";
     } 
	else 
	{
        cout << "No subset with sum " << targetSum << " exists \n";
    }

    return 0;
}// end main
