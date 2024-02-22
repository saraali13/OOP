/*
Name:S. Sara Ali
ID:23K-0070
*/

#include<iostream>
#include<string>
using namespace std;

class office 
{
private:
	
    string location;
    int seatingCapacity;
    string* furniture;

public:
	
// Parameterized constructor
    
    office(string loc = "", int cap = 0, int furniture_num=3) :
        location(loc), seatingCapacity(cap) 
		{
        	furniture= new string[furniture_num]; 
		}

//destructor

    ~office() 
	{
        delete[] furniture;
    }
    
    
//function to set furniture in the array

    void set_furniture(int index, const string& item) 
	{
    	furniture[index]=item;
	}
    
    
// Function to display office details

    void display() 
	{
        cout<<"Location: "<<location;
        cout<<"\nSeating Capacity: "<<seatingCapacity;
        cout<<"\nFurniture: ";
        for(int i=0;i<3;i++) 
		{
            cout<<furniture[i]<<" , ";
        }
        cout<<endl;
    }
};// end class

// main function

int main() 
{
	
	office* Office1 = new office ("highway",110,3);
	Office1->set_furniture(0,"chair");
	Office1->set_furniture(1,"wall clock");
	Office1->set_furniture(2,"PC"); 
    cout<<"Office Info: \n";
    Office1->display();
    cout<<endl;
    delete Office1;

    return 0;
}// end main
