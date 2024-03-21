/*
Name:S.Sara Ali
ID:23K-0070
*/

#include<iostream>
using namespace std;

//Course class
class Courses
{
    string code;
    string name;
    int creditHours;
    
public:
//parameterized constructor
    Courses(string code, string name, int creditHours) : code(code), name(name), creditHours(creditHours) 
	{}

//getter functions
    int getCreditHours() const 
	{
        return creditHours;
    }
    
    string getCourseCode() const 
	{
        return code;
    }   
    string getCourseName() const 
	{
	   return name;
	}
	
	
};// end course class


//student class
class Student 
{
    string ID;
    string name;
    int numCourses = 0;
    Courses* courses[10];//aggregation
    
public:
    Student(string ID, string newName) //parameterized constructor
	{
        this->ID = ID;
        this->name = newName;
    }//
    
    void enroll(Courses& course) //function for enrolling a course
	{
        courses[numCourses] = &course;
        numCourses++;
    }//
    
    void drop(Courses& course) //function for dropping a course
	{
        bool found = false;
        for (int i = 0; i < numCourses; ++i) 
		{
            if (courses[i]->getCourseCode() == course.getCourseCode()) 
			{
                delete courses[i];
                for (int j = i; j < numCourses - 1; j++)
                    {
						courses[j] = courses[j + 1];
					}

                numCourses--;
                found = true;
                break;
            }
        }
        if (!found) 
		{
            cout << "Invalid Course\n";
        }
    }//
    
    
	//function for calculating total credit hours
    int getTotalCreditHours() 
	{
        int total = 0;
        for (int i = 0; i < numCourses; i++)
           {
			 total += courses[i]->getCreditHours();
		   }
        return total;
    }//
    
    
	//function for displaying all the detaols of Student
    void displayEnrolledCourses() const 
	{
        cout<<"Enrolled Courses of Student; ID: "<<ID<<", Name: "<<name<<":\n\n";
        for (int i = 0; i < numCourses; i++) {
            cout<<"Course Code: "<<courses[i]->getCourseCode()<<endl;
			cout<<"Course Name: "<<courses[i]->getCourseName()<<endl;
            cout<<"Credit Hours: "<< courses[i]->getCreditHours()<<endl;
        }
    }//
    
    ~Student() //destructor
	{
        for (int i = 0; i < numCourses; i++)
            delete courses[i];
    }//
    
};// end Student class


//main function
int main() 
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
	
	int creditHr;
	
    Courses C1("EW", "el1002", 2);
    Courses C2("DLD", "ap3203", 3);
    Courses C3("oop-lab", "cs11919", 1);
    Student S1("23k-0070", "Sara");
    
    S1.enroll(C1);
    S1.enroll(C2);
    S1.enroll(C3);
    S1.displayEnrolledCourses();
	creditHr=S1.getTotalCreditHours();
	cout<<"Total Credit Hour: "<<creditHr;
    cout<<"\n\n";
    
    S1.drop(C1);
    S1.displayEnrolledCourses();//After droping a course
    creditHr=S1.getTotalCreditHours();
	cout<<"Total Credit Hour: "<<creditHr;
	
    return 0;
    
}// end main
