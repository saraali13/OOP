/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <string>
using namespace std;

//base class
class Employee 
{
	protected:

    	int employeeID;
    	string employeeName;

	public:

		Employee(int ID, const string& name) : employeeID(ID), employeeName(name) 
        {}

        //virtual funtions
    	virtual double calculatePay() const =0;
    	virtual void displayDetails() const 
        {
        	cout<< "Employee ID: "<<employeeID << "\nName: "<<employeeName;
    	}
};//

//derived class 1 from employee class
class FullTimeEmployee : public Employee 
{
	private:

    	double monthlySalary;

	public:
    	FullTimeEmployee(int ID, const string& name, double salary) : Employee(ID, name), monthlySalary(salary) {}

    	double calculatePay() const override 
        {
        	return monthlySalary;
    	}

    	void displayDetails() const override 
        {
            cout<<"Displaying Details of full time employee:\n";
        	Employee::displayDetails();
        	cout<<"\nType: Full-time\nMonthly Salary: "<<monthlySalary << endl;
    	}
};

//derived class 2 from employee class
class PartTimeEmployee : public Employee 
{
	private:
    	double hourlyWage;
    	double hoursWorked;
	
	public:
	
    	PartTimeEmployee(int id, const string& name, double wage, double hours) : Employee(id, name), hourlyWage(wage), hoursWorked(hours) {}

    	double calculatePay() const override 
        {
        	return hourlyWage * hoursWorked;
    	}

    	void displayDetails() const override 
        {
            cout<<"Displaying Details of part time employee:\n";
        	Employee::displayDetails();
        	cout<<"\nType: Part-time\nHourly Wage: "<< hourlyWage <<"\nHours Worked: "<<hoursWorked<<endl;
    	}
};

int main() 
{
	cout<<"Name:S.Sara Ali\nID:23k-0070\n\n";
    
    FullTimeEmployee FTE(001,"Ali",90000);
    PartTimeEmployee PTE(002,"John",56,23);

    
    FTE.displayDetails();
    cout<<endl;
    PTE.displayDetails();

    Employee *emp1=&FTE;
    Employee *emp2=&PTE;
 
    cout<<"\nCalculating pay using base class pointer:"<<endl;
    cout<<"Full-time Employee Pay: " <<emp1->calculatePay()<<endl;
    cout<<"Part-time Employee Pay: " <<emp2->calculatePay()<<endl;

    return 0;
}
