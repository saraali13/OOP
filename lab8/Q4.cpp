/*
Name:S.Sara Ali
ID:23K-0070
*/


#include <iostream>
using namespace std;

//Base class : person class
class Person 
{
	protected:

    	string Name;
    	int Age;

	public:

    	//parameterized Constructor
    	Person(string name, int age) : Name(name), Age(age) 
		{}

       //function for displaying details of a person
    	void display() const 
		{
        	cout<<"Name: "<<Name<<endl;
			cout<<"Age: "<<Age<<endl;;
    	}//

};

//derived class1 : Student class
class Student : public Person 
{
	protected:

    	string studentID;
    	int gradeLevel;

	public:

    	//parameterized Constructor
    	Student(string& name, int age, string studentID, int gradeLevel) : Person(name, age), studentID(studentID), gradeLevel(gradeLevel) 
		{}

        //function for displaying student's detail
    	void display() const 
		{
        	Person::display(); 
        	cout <<"Student ID: "<<studentID<<endl;
			cout<<"Grade Level: "<<gradeLevel<<endl;
    	}//

};

//derived class2 : teacher class
class Teacher : public Person 
{
	protected:

    	string Subject;
    	int roomNumber;

	public:
	   //parameterized Constructor
    	Teacher(string name, int age, string subject, int RoomNumber) : Person(name, age), Subject(subject), roomNumber(RoomNumber) 
		{}

    	//function for displaying details of the teacher
    	void display() const {
        	Person::display();
        	cout<<"Subject: "<<Subject<<endl;
			cout<<"Room Number: "<<roomNumber<<endl;
        }//

};

//derived class from student and teacher classes : graduate student
class GraduateStudent : public Student, public Teacher 
{
	public:
		//parameterized Constructor
    	GraduateStudent( string name, int age, string studentID, int gradeLevel, string subject, int RoomNumber)
        : Student(name, age, studentID, gradeLevel), Teacher(name, age, subject, RoomNumber) 
		{}

       //function for displaying details of graduate student
    	void display() const 
		{
        	Student::display();
        	cout<<"Teaching Subject: "<<Subject<<endl;
			cout<<"Teaching Room Number: "<<roomNumber<<endl;
        }//

};

int main() 
{
	cout<<"Name:S.Sara Ali\nID:23k-0070\n\n";

    GraduateStudent gradStudent("Ali", 20, "45-00", 10, "AI",320);
    cout << "Details of Graduate Student:\n";
    gradStudent.display();

    return 0;
}
