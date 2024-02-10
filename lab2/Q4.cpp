/*
name:S.SaraALi
des: Your task is to implement a basic Student Registration System in C++. Define two
structures, Register and Student, where Register includes attributes courseId and
courseName, and Student inherits from Register while having additional attributes
such as studentId, firstName, lastName, cellNo, and email. Your objective is to
create an array of Student structures to store data for five students. Write a C++
program that accomplishes the following tasks:
1. Implement the Register and Student structures.
2. Inherit the Register structure in the Student structure.
3. Create an array of Student structures to store data for 5 students.
4. Take input for each student, including their courseId, courseName,
studentId, firstName, lastName, cellNo, and email.
5. Display the information for all 5 students.*/



#include <iostream>
using namespace std;

struct Register{
	double courseID;
	string courseName;
}; 
struct Student:Register{
	string studentID, first_name , last_name ,email;
	double cell_no ;
};

int main ()
{
	Student stud[5];
	
	for (int i=0;i<2;i++)
	{
		cout<<"Enter the infrormation of student no."<<i+1<<endl;
		cout << "Enter Course ID:"<<endl;
        cin >> stud[i].courseID;
        cin.ignore();
        cout << "Enter Course Name: \n";
        getline(cin, stud[i].courseName);
        cout << "Enter Student ID: \n";
        cin >> stud[i].studentID;
        cin.ignore();
        cout << "Enter First Name: \n";
        getline(cin, stud[i].first_name);
        cout << "Enter Last Name: \n";
        getline(cin, stud[i].last_name);
        cout << "Enter Cell Number: \n";
        cin >> stud[i].cell_no;
        cin.ignore();
        cout << "Enter Email: \n";
        getline(cin, stud[i].email);
        cout<<endl;
	}// end for
	
   cout << "Information for all students: \n\n";
    for (int i = 0; i < 2;i++) {
        cout << "Student no. " << i + 1 << endl;
        cout << "Course ID: " << stud[i].courseID << endl;
        cout << "Course Name: " << stud[i].courseName << endl;
        cout << "Student ID: " << stud[i].studentID << endl;
        cout << "First Name: " << stud[i].first_name << endl;
        cout << "Last Name: " << stud[i].last_name << endl;
        cout << "Cell Number: " << stud[i].cell_no << endl;
        cout << "Email: " << stud[i].email << endl;
        cout<<endl;
    }
}// end main
