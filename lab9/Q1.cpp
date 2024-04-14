/*
Name:S.Sara Ali
ID:23k-0070
*/

#include <iostream>
using namespace std;

//constant Pi
const double Pi = 3.14159265359;

class Shape 
{
	public:

    	double Area(double radius)//circle 
		{
        	return Pi * radius * radius;
    	}

    	double Area(double length, double width)//rectangle
		{
        	return length * width;
    	}

    	double Area(float base, float height)//triangle 
		{
        	return 0.5 * base * height;
    	}

    	double Perimeter(double radius)//circle
		{
        	return 2 * Pi * radius;
    	}

    	double Perimeter(double length, double width)//rectangle 
		{
        	return 2 * (length + width);
    	}

   		double Perimeter(double side1, double side2, double side3)//triangle 
		{
        	return (side1 + side2 + side3);
    	}
};//end shape class

int main() 
{
	cout<<"Name:S.Sara Ali\nID:23k-0070\n\n";

    Shape shape;
	double radius=5;
	double length=7;
	double width=9;
	float base= 4.5;
	float height = 10.12;
	double side1=89.3, side2=83, side3=90.1;
    
  cout<<"Area of circle: " << shape.Area(radius);
	cout<<"\nPerimeter of circle: "<<shape.Perimeter(radius);

  cout<<"\n\nArea of rectangle: " << shape.Area(length,width);
	cout<<"\nPerimeter of rectangle: "<<shape.Perimeter(length,width);

  cout<<"\n\nArea of triangle: " << shape.Area(base,height);
	cout<<"\nPerimeter of triangle: "<<shape.Perimeter(side1,side2,side3);

    return 0;
}
