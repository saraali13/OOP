/*
Name:S.Sara Ali
ID: 23k-0070
*/

#include<iostream>
using namespace std;

class Square 
{
	
	private:
		
		float sideLength;
		float Area;
		static float allAreas;
		
	public:
		
		Square() //default constructor
		{
			sideLength=0;
			Area=0;
		}
		
		Square(float sideLength) // parameterized constructor
		{
			this->sideLength=sideLength;
			Area=0;
		}
		
		void calculateArea() // function for calculating area of the square
		{
			Area= sideLength * sideLength;
			allAreas = allAreas + Area;
		}
		
		// setter and getter
		
		void setLength(int sideLength) 
		{
			this->sideLength;
		}
		
		float getsideLength() 
		{
			return sideLength;
		} 
		
		float getArea() 
		{
			return Area;
		}
		
		static float getallAreas() 
		{
			return allAreas;
		}
		
};// end square class

//static variable
float Square::allAreas=0;

int main() 
{
	Square sq1(5.9); 
    sq1.calculateArea();
    cout<<"Area of square is: " <<sq1.getArea()<<endl;
    cout<<"All areas: " << Square::getallAreas() <<endl;
    cout<<endl;
    Square sq2(4.6); 
    sq2.calculateArea();
    cout<<"Area of square is: "<<sq2.getArea()<<endl;
    cout<<"All areas: "<<Square::getallAreas() <<endl;
    cout<<endl;
    Square sq3(4.5); 
    sq3.calculateArea();
    cout<< "area of square is: " << sq3.getArea() <<endl;
    cout<< "All areas: " << Square::getallAreas() <<endl;
    cout<<endl;
    
    return 0;
}// end main
