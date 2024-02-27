#include <iostream>
using namespace std;

inline int product(int x,int y){
	return x*y;
}
class Student{

	int ID;
	string name;
//	int b=3;
	public:
	Student():ID(0),name(""){
	}
	
	Student (int ID,string name){
		this->ID=ID;
		this->name=name;
	}
	Student& gh(int a)
	{
		this->ID=a;
		return *this;
	}
    void display(){
    	cout<<"Name: "<<name;
    	cout<<"\nID: "<<ID<<endl;
	}
	
};

//int Student :: ID=2;
//int Student::a=2;

int main ()
{
	Student S1(5,"Sara");
	S1.display();
//	S2.Student(3,"Ali")
    int pro=product(9,4);
    cout<<"product is : "<<pro;

	
}
