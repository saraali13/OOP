/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class Table 
{
    private:
    	
        const int capacity;
        int occupiedSeats;
        bool clean;

    public:
    	
    //Default constructor
    
        Table() : capacity(4), occupiedSeats(0), clean(true) {}

    //Parameterized constructor
    
        Table(int Capacity) : capacity((Capacity == 8 || Capacity == 4) ? Capacity : ((Capacity + 2) / 4 * 4)), clean(true), occupiedSeats(0) 
		{}
		
	// getter for capacity
		
        int getCapacity() const 
		{
            return capacity;
        }

    //Getter for occupied Seats
    
        int getOccupiedSeats() const 
		{
            return occupiedSeats;
        }

    //Getter for clean
    
        bool isClean() const 
		{
            return clean;
        }

    //Function for using the table
    
        void useTable(int Size) 
		{
    
            if(clean && Size<=capacity) 
			{
                occupiedSeats=Size;
                cout<<"Table of capacity "<<capacity<<" is occupied by a group of "<<Size<<endl;
            } else {
                cout<<"Table cannot be used\n";
            }
        }

    //Function for having lunch on the table
        void haveLunch() 
		{
            clean=false;
            cout<<"Having lunch on the table\n";
        }

	//Function for leaving the table
        void leaveTable() 
		{
            occupiedSeats = 0;
            cout<<"Table is no longer occupied\n";
        }

    // Function for cleaning the table
    
        void cleanTable() 
		{
            if(occupiedSeats==0) 
			{
                clean=true;
                cout<<"Table cleaned\n";
            } else 
			{
                cout<<"the table cannot be cleaned,it is occupied by people\n";
            }
        }
};// end table class


//function to occupying or using a table
void OccupyTable(Table tables[], int groupSize) 
{
    for(int i=0;i<5;i++) 
	{
        if(!tables[i].isClean()) continue;//if table is free and clean

        if (groupSize <= tables[i].getCapacity()) //suggest another table with same capacity
		{
            tables[i].useTable(groupSize);
            return;
        }
    }
    cout << "Currently no suitable table is available\n";
}// end


//function to empty a table
void EmptyTable(Table tables[], int table_Number) 
{
    if (table_Number>=0 && table_Number<5) 
	{
        tables[table_Number].leaveTable();
    } else 
	{
        cout<<"Invalid number\n";
    }
}// end 

//main function
int main() 
{
	cout<<"Name:S. Sara Ali\n";
	cout<<"ID:23K-0070\n\n";
	
	cout<<"______Table management system______\n\n";
    Table tables[5] = {Table(8), Table(4), Table(4), Table(8), Table(4)};

    cout<<"table 1:\n";
    OccupyTable(tables,4);
    cout<<endl;
    cout<<"Actions on table 1\n";
    tables[0].useTable(4);
    tables[0].haveLunch();
    tables[0].leaveTable();
    tables[0].cleanTable();
    cout<<endl;
    cout<<"table 2:\n";
    OccupyTable(tables, 6);
    cout<<endl;
    cout<<"table 2\n";
    EmptyTable(tables, 1);

    return 0;
}// end main
