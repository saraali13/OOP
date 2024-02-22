/*
Name:Muhammad Abbas
ID:23K-0068
Purpose:a program to create classes for office and pass different number of arguments
*/

#include<iostream>
#include<string>

using namespace std;

class Office 
{
private:
	
    string location;
    int seatingCapacity;
    string furniture[3];

public:
	
    // Parameterized constructor
    
    Office(string loc = "", int capacity = 0, string furn1 = "", string furn2 = "", string furn3 = "") :
        location(loc), seatingCapacity(capacity), furniture{furn1, furn2, furn3} 
		{}

    // Function to display all the office details
    
    void display() 
	{
        cout<<"Location: "<<location;
        cout<<"\nSeating Capacity: "<<seatingCapacity;
        cout<<"\nFurniture: ";
        for(int i=0;i<3;i++) 
		{
            cout<<furniture[i];
            if(i!=2)cout<<" , ";
        }
        cout<<endl;
    }
};// end class

// main function

int main() 
{
    Office office1; 
    Office office2("Building 1",49);
    Office office3("Building 2", 50, "clock","shelf", "chairs"); 
    Office office4("Building 3", 100, "desk", "chair", "pc");


// Displaying all the details of all the offices
    
    cout<<"Office 1 Info:\n";
    office1.display();
    cout<<endl;
    cout<<"Office 2 Info:\n";
    office2.display();
    cout<<endl;
    cout<<"Office 3 Info:\n";
    office3.display();
    cout<<endl;
    cout<<"Office 4 Info:\n";
    office4.display();
    cout << endl;
    return 0;
    
}// end main function
