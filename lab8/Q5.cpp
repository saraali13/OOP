/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;


//Base class : vehicle class
class Vehicle 
{
	protected:

    	string Make;
    	string Model;
    	int Year;

	public:
    	//parameterized Constructors
    	Vehicle( string make, string model, int year) : Make(make), Model(model), Year(year) 
		{}

    	//function for displaying details
    	void display() const 
		{
        	cout<<"Make: "<<Make;
			cout<<"\nModel: "<<Model;
			cout<<"\nYear: "<<Year<<endl;
    	}//
};


// Derived class1 : car class
class Car : public Vehicle 
{
	protected:

    	int numDoors;
    	double fuelEfficiency;

	public:

    	//parameterized Constructor
    	Car(string make, string model, int year, int numDoors, double fuelEfficiency) 
		: Vehicle(make, model, year), numDoors(numDoors), fuelEfficiency(fuelEfficiency) 
		{}

    	//function for displaying details
    	void display() const 
		{
        	Vehicle::display(); //initial function implementation called
        	cout<<"Number of Doors: "<<numDoors;
			cout<<"\nFuel Efficiency: "<<fuelEfficiency<<" kWh/100 km\n";
        }//
};


// Derived class from car class : electric car
class ElectricCar : public Car 
{
	protected:

    	double batteryLife;

	public:

    	//parameterized Constructor
    	ElectricCar(string make, string model, int year, int numDoors, double fuelEfficiency, double batteryLife)
        : Car(make, model, year, numDoors, fuelEfficiency), batteryLife(batteryLife) 
		{}

       //function for displaying details
    	void display() const 
		{
        	Car::display(); 
        	cout << "Battery Life: "<<batteryLife<<" miles\n";
        }//
};


int main() 
{
	cout<<"Name:S.Sara Ali\nID:23k-0070\n\n";
    ElectricCar electricCar("Audi", "e-tron GT", 2021, 4, 21.6, 20000);
    cout << "Details of Electric Car:\n";
    electricCar.display();

    return 0;
}//
