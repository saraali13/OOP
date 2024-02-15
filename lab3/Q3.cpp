/*
Name:S. Sara Ali
Roll no:23K-0070
*/

#include <iostream>
#include <string>
using namespace std;


class Calender{
private:
    static const int month = 12;
    static const int days = 31;
    string arr[month][days];
    int current_Year;

public:
    
    Calender(int year) : current_Year(year) 
	{
        for(int i = 0; i < 12; i++)
		{
            for(int j = 0; j < 31; j++)
			{
                arr[i][j] = "";
            }
        }
    }// enc default constructor

//function for adding A task 
    void AddTask(string task, int month, int day)
	{
        if(month >= 1 && month <= 12 && day >= 1 && day <=31)
		{
            arr[month-1][day-1] = task;
            cout << "Task added\n";
        } 
		else 
		{
            cout << "Invalid input\n";
        }
    }// end addtask function

// function for removing stored task 
    void RemoveTask(int month, int day)
	{
        if(month >= 1 && month <= 12 && day >= 1 && day <=31)
		{
            arr[month-1][day-1] = "";
            cout << "Task deleted\n";
        } else {
            cout << "Invalid input\n";
        }
    }// end romovetask funtion

// function for displaying the tasks
    void display()
	{
        cout << " \n" ;
        for(int i = 0; i < 12; i++){
            for(int j = 0; j < 31; j++){
                string task = arr[i][j];
                if(!task.empty()){
                    cout << task << " on date " << j + 1 <<" month " << i + 1 << " year " << current_Year << endl;
                }
            }
        }
    }
};

// main function
int main()
{
    Calender calendar1(2024);
	calendar1.display();
    calendar1.AddTask("Washing clothes", 3,14);
    calendar1.AddTask("Going for picnic", 5,20);
    calendar1.AddTask("birthday",10,21);
    calendar1.RemoveTask(3,14);	
    calendar1.display();

    return 0;
}
