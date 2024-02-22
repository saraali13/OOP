/*
Name:S. Sara Ali
ID:23k-0070
*/

#include <iostream>
#include <string>
using namespace std;

class weekDays 
{
	
private:
	
    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int currentDay;

public:
	
    // Default constructor
    
    weekDays() 
	{
        currentDay = 0;
    }

    // Parameterized constructor
    
    weekDays(int current_day) 
	{
        if (current_day > 6) 
		{
            currentDay = current_day % 7;
        } 
		else 
		{
            currentDay = current_day;
        }
    }
    
    
// getter functions

    string get_CurrentDay() 
	{
        return Days[currentDay];
    }

    string get_NextDay() 
	{
        return Days[(currentDay + 1) % 7];
    }

    string get_PreviousDay() 
	{
        return Days[(currentDay + 6) % 7]; 
    }

    string get_NthDayFromToday(int n) 
	{
        return Days[(currentDay + n) % 7];
    }
};// end class

// main function

int main() 
{
    int n;
    weekDays week;

    cout << "\nCurrent Day: " << week.get_CurrentDay();
    cout << "\nNext Day: " << week.get_NextDay();
    cout << "\nPrevious Day: " << week.get_PreviousDay();
    cout << "\nEnter the value of n to find the Nth day from today: ";
    cin >> n;
    cout <<n<<" Days from Today: " << week.get_NthDayFromToday(n) << endl;
    return 0;
  
}// end main function
