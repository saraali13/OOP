/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <string>
using namespace std;


// Base class for unit conversion
class Convert 
{
protected:
    double val1; 
    double val2; 

public:

    virtual void compute() = 0; // Virtual function for conversion
    
    //getter funtion for value 2
   double getVal2()
   {
      return val2;
   }
   
};

// Derived class :converting from liters to gallons
class L_to_G : public Convert 
{
public:
    L_to_G(double liters) //constructor
    {
        val1 = liters;
    }

    void compute() override //overriding virtual funtion
    {
        val2 = val1 * 0.264172; // 1 liter = 0.264172 gallons
    }
};

// Derived class: converting Fahrenheit to Celsius
class F_to_C : public Convert 
{
public:
    F_to_C(double fahrenheit) //constructor
    {
        val1 = fahrenheit;
    }

    void compute() override //overriding virtual funtion
    {
        val2 = (val1 - 32) * 5 / 9; // Fahrenheit to Celsius conversion formula
    }
};

int main() 
{
   cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";

   //liters to gallons conversion
    Convert* conv1 = new L_to_G(5);
    conv1->compute();
    cout << "5 liters is equal to " << conv1->getVal2() << " gallons\n";
    delete conv1;

    //Fahrenheit to Celsius conversion
    Convert* conv2 = new F_to_C(70);
    conv2->compute();
    cout << "70 Fahrenheit is equal to " << conv2->getVal2()<< " Celsius\n";
    delete conv2;

    return 0;
}

