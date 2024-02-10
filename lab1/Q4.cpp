/*
name:S.SaraALi
des: to write a c++ program to Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
*/


#include <iostream>

using namespace std;


// function for calculating max area
int Max_Area(int height[], int n) { 
	int max_Water = 0;
    
    for (int i= 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            //min function to find smallest value
			int h = min(height[i], height[j]);
			//calculating the width
            int w = j - i;
            //max function to find bigest value
            max_Water = max(max_Water, h * w);
        }// end for 
    }//end for

    return max_Water;
}// end maxArea function

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height) / sizeof(height[0]);// number of elements in the array
    int result = Max_Area(height, n);

    cout << "Max Water: " << result <<endl;

    return 0;
}
