/*
Name:S.Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

class Shape 
{
    int length;
    double area; 
    public:
    Shape(int l) : length(l),area(0) {}

    double Area() 
	{
        return length*length;
    }

    Shape operator+(const Shape& obj) const 
	{
        Shape A_Sum;
        A_Sum.area = this->area + obj.area;
        return A_Sum;
    }

    void display() const 
	{
        cout << "The sum of both Areas: " << area << endl;
    }
};

int main() 
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
    Shape s1(23), s2(34), s3;
    s3=s1.calculateArea()+s2.calculateArea();
//    s3 = s1 + s2;
    s3.display();

    return 0;
}
