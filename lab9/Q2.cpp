/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//base class:shape class
class Shape 
{
public:
    virtual ~Shape() 
    {} // Virtual destructor

    //virtual fuctions
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;
};//

//derived from shape class
class Circle : public Shape 
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) 
    {}

    double area() const override 
    {
        return M_PI * pow(radius, 2);
    }

    double perimeter() const override 
    {
        return 2 * M_PI * radius;
    }

    void displayProperties() const override 
    {
        cout << "Displaying data of Circle:\n";
        cout << "Radius: " << radius << endl;
        cout << "Area: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
    }
};//

//derived from shape class
class Rectangle : public Shape 
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) 
    {}

    double area() const override 
    {
        return length * width;
    }

    double perimeter() const override 
    {
        return 2 * (length + width);
    }

    void displayProperties() const override {
        cout << "Displaying data of Rectangle:\n";
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
    }
};//

//derived from shape class
class Square : public Shape 
{
private:
    double sideLength;

public:
    Square(double sideLength) : sideLength(sideLength) 
    {}

    double area() const override 
    {
        return pow(sideLength, 2);
    }

    double perimeter() const override 
    {
        return 4 * sideLength;
    }

    void displayProperties() const override 
    {
        cout << "Displaying data of Square:\n";
        cout << "Side Length: " << sideLength << endl;
        cout << "Area: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
    }
};

//derived from shape class
class Triangle : public Shape 
{
protected:
    double a;
    double b;
    double c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) 
    {}

    double area() const override 
    {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double perimeter() const override 
    {
        return a + b + c;
    }

    void displayProperties() const override 
    {
        cout << "Displaying data of Triangle:\n";
        cout << "Side a: " << a << endl;
        cout << "Side b: " << b << endl;
        cout << "Side c: " << c << endl;
        cout << "Area: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
    }
};//

//derived from triangle class
class EquilateralTriangle : public Triangle 
{
public:
    EquilateralTriangle(double sideLength) : Triangle(sideLength, sideLength, sideLength) 
    {}

    void displayProperties() const override 
    {
        cout << "Displaying data of Equilateral Triangle:\n";
        cout << "Side Length: " << a << endl;
        cout << "Area: " << this->area() << endl;
        cout << "Perimeter: " << this->perimeter() << endl;
    }
};//

int main() 
{
    cout<<"Name:S.Sara Ali\nID:23k-0070\n\n";
    
    string choice;
    
    do {
        cout << "Please select a shape:\n";
        cout << "1. Circle\n2. Rectangle\n3. Square\n4. Triangle\n";
        int option;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) 
        {
            case 1: 
            {
                double radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                Circle circle(radius);
                circle.displayProperties();
                break;
            }
            case 2: 
            {
                double length, width;
                cout << "Enter the length of the rectangle: ";
                cin >> length;
                cout << "Enter the width of the rectangle: ";
                cin >> width;
                Rectangle rectangle(length, width);
                rectangle.displayProperties();
                break;
            }
            case 3: 
            {
                double side;
                cout << "Enter the side length of the square: ";
                cin >> side;
                Square square(side);
                square.displayProperties();
                break;
            }
            case 4: 
            {
                double side1, side2, side3;
                cout << "Enter three side lengths of the triangle: ";
                cin >> side1 >> side2 >> side3;
                Triangle triangle(side1, side2, side3);
                triangle.displayProperties();
                break;
            }
            default:
                cout << "Invalid choice\n";
        }

        cout << "Do you want to calculate properties for another shape? (yes/no): ";
        cin >> choice;
    } while (choice == "yes");

    cout << "Signing off\n";
    
    return 0;
}

