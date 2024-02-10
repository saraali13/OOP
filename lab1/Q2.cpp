/*
name:S.SaraALi
des: to write a c++ program to manage student marks by taking inputs from user and providing final grade as output
*/

#include <iostream>
using namespace std;

//function to calculate grade 
char Grade(float avg)
{
    if (avg >= 90)
	   {
        return 'A';
       }// end if 
	else if (avg >= 80)
	   {
        return 'B';
       }// end else if
	else if (avg >= 70)
	   {
        return 'C';
       }// end else if 
	else if (avg >= 60)
	   {
        return 'D';
       } // end else if
    else
	  {
        return 'F';
      }// end else 
}// end grade function

int main() {
    int numSt;

    cout << "Enter the total number of students: ";
    cin >> numSt;

    float math[numSt];
    float english[numSt];
    float science[numSt];

    // for loop for taking inputs from user
    for (int i = 0; i < numSt;i++)
	 {
        cout << "\nEnter marks for student " << i + 1 << ":\n";
        cout << "Mathematics: ";
        cin >> math[i];
        cout << "English: ";
        cin >> english[i];
        cout << "Science: \n";
    }// end for loop

    // for loop for printing outputs
    for (int i = 0; i < numSt; ++i) 
	{
        float total = math[i] + english[i] + science[i];
        float avg = total / 3.0;

        cout << "Student " << i + 1 << ":\n";
        cout << "Mathematics: " << math[i] << "\n";
        cout << "English: " << english[i] << "\n";
        cout << "Science: " << science[i] << "\n";
        cout << "Total: " << total << "\n";
        cout << "Average: " << avg << "\n";
        cout << "Grade: " << Grade(avg) << "\n";
    }// end for loop 

    return 0;
}// end main
