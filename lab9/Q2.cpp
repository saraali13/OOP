/*
Name:S. Sara Ali
ID:23K-0070
*/
#include <iostream>
#include <cmath>

class Shape
{
	private:
		char shape;
	public:
	Shape(char t):shape(t)
	{}
	virtual double area() const=0;
	virtual double perimeter() const=0;
	virtual void displayProperties () const=0;
};

class Circle:public Shape
{
	private:
    double radius;

public:
    Circle(double radius) : radius(radius) 
	{}

   virtual double area() const 
	{
        return (M_PI * pow(radius, 2));
    }

    virtual double perimeter() const 
	{
        return (2 * M_PI * radius);
    }

    virtual void displayProperties() const
	{
		cout<<"Displaying data of Circle:\n";
        cout << "Radius: " << radius <<endl;
        cout << "Area: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() <<endl;
    }
};

class Rectangle:public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) 
	{}

    virtual double area() const override 
	{
        return (length * width);
    }

    virtual double perimeter() const override 
	{
        return (2 * (length + width));
    }

    virtual void displayProperties() const override 
	{
		cout<<"Displaying data of Rectangle:\n";
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
}
};
class Square:public Shape
{
	private:
    double Length;

public:
    Square(double Length) : Length(Length) 
	{}

    virtual double area() const  
	{
        return pow(sideLength, 2);
    }

    virtual double perimeter() const  
	{
        return (4 * sideLength);
    }

    virtual void displayProperties() const  
	{
		cout<<"Displaying data of Square:\n";
        cout << "Side Length: " << sideLength << endl;
        cout << "Area: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
    }
};
class Triangle:public Shape
{
	protected:
    double a;
    double b;
    double c;

   public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    virtual double area() const override 
	{
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    virtual double perimeter() const  
	{
        return (a + b + c);
    }

    virtual void displayProperties() const  
	{
		cout<<"Displaying data of Triangle:\n";
        cout << "Side a: " << a <<endl;
        cout << "Side b: " << b <<endl;
        cout << "Side c: " << c <<endl;
        cout << "Area: " << this->area() <<endl;
        cout << "Perimeter: " << this->perimeter() <<endl;
    }
};
class EquilateralTriangle:public Triangle{
	public:
    EquilateralTriangle(double sideLength) : Triangle(sideLength, sideLength, sideLength) 
	{}

   virtual void displayProperties() const  
	{
	   cout<<"Displaying data of Triangle:\n";
       cout << "Equilateral Triangle" <<endl;
       cout << "Side Length: " << a <<endl;
       cout << "Area: " << this->area() <<endl;
       cout << "Perimeter: " << this->perimeter() <<endl;
    
};
int main()
{
	
}
