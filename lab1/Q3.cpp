/*
name:S.SaraALi
des: to write a c++ program that return indices of the two numbers such that they add up to target
*/

#include <iostream>
using namespace std;



int main() 
{
	int nums[ ] = {2, 7, 11, 15};
    int target = 9;


    for (int i=0;i<sizeof(nums)/sizeof(nums[0]);i++) 
	{
        int remainder = target- nums[i];// as target= sum of the remainder and the number present at i address in the array
        
        for (int j=i+1;j<sizeof(nums)/sizeof(nums[0]);j++) 
		{
			
            if (nums[j] == remainder) // num[i]+num[j] = targeted number
			{
            	
                cout << i << "," << j;
                
                return 0;
                
            }// end if
            
        }// end for 2
        
    }// end for 1
    
    
   //no two number's sum results the targeted number
    cout << "target not found";

    return 0;
}// end main
