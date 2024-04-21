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
    	
    Shape(int l) : length(l),area(0) 
	{}

    void Area() 
	{
        area= length*length;
    }

    Shape operator+(const Shape& obj) const 
	{
        Shape totalArea(0);
        totalArea.area = this->area + obj.area;
        return totalArea.area;
    }
    
    void display() const 
	{
        cout << "The sum of both Areas: " << length << endl;
    }
};

int main() 
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
	
    Shape s1(23), s2(34);
    s1.Area();
    s2.Area();
    Shape s3=s1+s2;
    //Shape s3=s1.Area()+s2.Area();
    s3.display();

    return 0;
}
