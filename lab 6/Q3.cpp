/*
Name:S.Sara Ali
ID:23k-0070
*/

#include <iostream>
using namespace std;

class Appointment
{   
//private members

	static int total_appointments;
	static double total_earning;
    string app_type;
    
// public functions
	
	public:
		
		Appointment(string app,double cost)//constructor 
		{
			this->app_type=app;
			total_earning+=cost;
			total_appointments++;	
		}
		
		static float Avg_Cost()// function for calculating average cost
		{    
		    float avg_cost;
		    
		    if(total_appointments==0)
		    return 0;
		    
			avg_cost=total_earning/total_appointments;
			return avg_cost;
		}
		
		 void change_app(string app)// function for changing appointment type
		{
			this->app_type=app;
		}
};

int Appointment::total_appointments=0;
double Appointment::total_earning=0;

int main()
{
	Appointment App1("hair wash",3040);
	Appointment App2("hair dye",565);
	
	cout<<"Avrage Cost is "<<Appointment::Avg_Cost()<<endl;
	
	return 0;
}// end main 
