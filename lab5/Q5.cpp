#include<iostream>
#include<string>
using namespace std;

//engine class
class Engine 
{
private:
    string Name;

public:
	
    Engine(string name) : Name(name)
    {}
    
    void startEngine() 
	{
        cout << "Engine started\n";
    }
};// end engine class


//wheel class
class Wheels 
{
private:
	
    int Count;

public:
	
    Wheels(int count) : Count(count) 
	{}
    
    void rotate() 
	{
        cout << "Wheels are rotating\n";
    }
};// end wheel class

// headlight class
class Headlights 
{
private:
	
    int Count;
    
public:
	
    Headlights(int num) : Count(num) 
	{}
	
    void turnOn() 
	{
        cout << "Headlights are turning on\n";
    }
};//end headlight class

// steering class
class Steering 
{
private:
	
    string type;
    
public:
	
    Steering(string name) : type(name) 
	{
      cout<<"streeing of type "<<type<<" is turning\n";
    }
};// end steering class

// car class
class Car 
{
private:
    Engine* engine;
    Steering* steering;
    Wheels wheels;
    Headlights headlights;
public:
    Car(int wheelCount, int headlightCount, Engine* enginePtr, Steering* steeringPtr)
        : wheels(wheelCount), headlights(headlightCount), engine(enginePtr), steering(steeringPtr) 
		{}

    void start() 
	{
        if (engine) 
		{
            engine->startEngine();
        }
    }
    
    void drive() 
	{
        wheels.rotate();
        headlights.turnOn();
      
    }
};// end car class


int main() 
{
    Engine engine("Engine123");
    Car car(3, 4, &engine, &steering);
    car.start();
    car.drive();
    Steering steering("Steering678");

    return 0;
}// end main
