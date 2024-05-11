/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <string>

using namespace std;

// Abstract base class
class Vehicle 
{
protected:
    string make;
    string model;
    int speed;

public:
    Vehicle(string make, string model, int speed) : make(make), model(model), speed(speed)
     {}

    // Pure virtual functions
    virtual void accelerate() = 0; 
    virtual void brake() = 0; 
    virtual void calculateFuelEfficiency() = 0; 

   //getter functions
    string getMake()
    {
        return make;
    }

    string getModel()
    {
        return model;
    }

    int getSpeed()
    {
        return speed;
    }

};

//subclass for Car
class Car : public Vehicle 
{
private:
    double fuelCapacity;

public:
    Car(string make,string model, int speed, double fuelCapacity) : Vehicle(make, model, speed), fuelCapacity(fuelCapacity) 
    {}

    void accelerate()
    {
        speed += 10; 
    }

    void brake() 
    {
        speed -= 5; 
    }

    void calculateFuelEfficiency()
    {
        cout << "Fuel efficiency of the car calculated is based on fuel capacity and speed\n";
    }
};

//subclass for Truck
class Truck : public Vehicle 
{
private:
    int cargoCapacity;

public:
    Truck(string make,string model, int speed, int cargoCapacity) : Vehicle(make, model, speed), cargoCapacity(cargoCapacity) {}

    void accelerate()
    {
        speed += 5;
    }

    void brake()
    {
        speed -= 3; 
    }

    void calculateFuelEfficiency()
    {
        cout << "Fuel efficiency of the truck calculated is based on cargo capacity and speed\n";
    }
};

int main() 
{
   cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";

    Car car("Toyota", "Corolla", 679, 67);
    car.accelerate();
    cout << "Speed of the car: " << car.getSpeed() << endl;
    car.brake();
    cout << "Speed of the car after braking: " << car.getSpeed() << endl;
    car.calculateFuelEfficiency();

    Truck truck("Ford", "F-1590", 567,94);
    truck.accelerate();
    cout << "Speed of the truck: " << truck.getSpeed() << endl;
    truck.brake();
    cout << "Speed of the truck after braking: " << truck.getSpeed() << endl;
    truck.calculateFuelEfficiency();

    return 0;
}

