/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <cmath>
#include<cstdlib>
using namespace std;

//Drone class:base class
class Drone 
{
    protected:
    float latitude;
    float longitude;
    float altitude;
    float speed;

    public:
//paramerterized constructor
    Drone(float latitude, float longitude, float altitude, float speed) : latitude(latitude), longitude(longitude), altitude(altitude), speed(speed) 
    {}

//function for adjustig altitude
    float adjustAltitude(float altitude) 
    {
        this->altitude = altitude;
        return altitude;
    }

//function for adjusting speed
    float setSpeed(float speed) 
    {
        this->speed = speed;
        return speed;
    }

};

//Flyable class:abstract base class : interface
class Flyable 
{
    public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;

};

//Scannable class:abstract base class: interface
class Scannable 
{
    public:
    virtual void scanArea(float radius) = 0;

};

//ReconDrone class:derived from Drone,Flyable,and Scannable class
class ReconDrone : public Drone, public Flyable, public Scannable 
{
    private:
    float cameraResolution;
    float maxFlightTime;

    public:
// parameterized constructor    
    ReconDrone(float latitude, float longitude, float altitude, float speed, float Resolution, float flightTime):Drone(latitude, longitude, altitude, speed), cameraResolution(Resolution), maxFlightTime(flightTime) 
    {}

//overriding takeoff funtion
    void takeoff()
    {
        cout << "Drone is Taking off\n";
    }

//overriding land function
    void land()
    {
        cout << "Drone is Landing\n";
    }

//overriding navigate to function
    void navigateTo(float lt, float lg, float at) 
    {
        float X = (lt - longitude) * cos((latitude + lt) / 2);
        float Y = lt - latitude;
        float distance = sqrt(X * X + Y * Y) * 111.0f; 
        float time = distance / speed;

        cout << "Time until arrival estimate: " << time<< endl;

        latitude = lt;
        longitude = lg;
        altitude = at;
        
    }//end navigateto function

//overriding scan area function
    void scanArea(float radius)
    {
        int objectsDetected = rand() % 10; 
        cout << objectsDetected << " objects detected:\n";

        for (int i = 0; i < objectsDetected; ++i) {
            float objectLat = latitude + static_cast<float>(rand() % 100) / 1000.0f;
            float objectLon = longitude + static_cast<float>(rand() % 100) / 1000.0f;
            cout << "Object " << i + 1 << " at (" << objectLat << ", " << objectLon << ")\n";
            
        }
        
    }//end scanarea function
    
};//end class

int main() {
	cout<<"Name:S. Sara Ali\nID:23K-0070\n\n";
	//object of drone
    ReconDrone drone(2.11, 2.31, 50.01, 500, 7, 8);
    
    drone.takeoff();
    drone.navigateTo(3.4, 4.2, 100);
    drone.scanArea(700);
    drone.land();

    return 0;
}

