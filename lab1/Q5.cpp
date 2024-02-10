/*
name:S.SaraALi
des: to write a c++ to Design a Event Management System
*/

#include<iostream>
#include<string.h>
using namespace std;

struct Event{
	char name[50];
	char date[50];
	char venue[50];
	char organizer[50];
};

// function for displaying events 
void display(const Event& event)
{
	
	cout<<"Event name: "<<event.name<<"\n";
	cout<<"Event date: "<<event.date<<"\n";
	cout<<"Event venue: "<<event.venue<<"\n";
	cout<<"Event organizer: "<<event.organizer<<"\n\n";
	
}// end display


int main()
{
	
	int total_events;
	cout<<"Enter the total number of events to be managed: "<<endl;
	cin>>total_events;
	Event* events = new Event[total_events];
	
	// taking details of the event as an input from user
	for(int i =0;i<total_events;i++)
	{
		
		cout<<"Enter the details for "<<i+1<<" event : "<<endl;
		cout<<"Event name: \n";
		cin.ignore();
		cin.getline(events[i].name, sizeof(events[i].name));
		cout<<"Event date: \n";
		cin.getline(events[i].date, sizeof(events[i].date));
		cout<<"Evnet venue: \n";
		cin.ignore();
		cin.getline(events[i].venue, sizeof(events[i].venue));
		cout<<"Event organizer: \n";
		cin.ignore();
		cin.getline(events[i].organizer, sizeof(events[i].organizer));
		cout<<endl;
	}// end for loop
	
	
	//loop for displaying all the events 	
	
	for(int j=0;j<total_events;j++)
	{
		
		cout<<"Displaying the details for event no. "<<j+1<<": "<<endl;
		display(events[j]);	
		
	}// end for loop
	
	//searching events for a particular date
	char search_date[20];
	cout<<"Enter the date to search event:"<<endl;
	cin>>search_date;
	cout<<"Event on "<<search_date<<" : "<<endl;
	bool found = false;
	
	//loop to check the event on a particular date
	for(int k =0;k<total_events;k++)
	{
		if(strcmp(events[k].date, search_date)==0)
		{
			display(events[k]);
			found = true;
		}//end if
	}// end for loop
	
	if(!found)//if found remains false
	{
		cout<<"No event found on "<<search_date<<endl;
	}// end if
	
	delete[] events;
	
	return 0;
}// end main
