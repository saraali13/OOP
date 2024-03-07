#include <iostream>
#include <string>
using namespace std;

class ValidateString 
{
private:
	
    string str;

public:
	
    ValidateString(const string &st) : str(st) // parameterized constructor
	{} 

    bool isValid()// function for checking validity of the string
		{
			bool valid;
            for(char c : str) 
			{
                if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')) {
                    valid= false;
                }
                else
                   valid= true;
			}
        
        if (valid)
            cout << "Is Valid\n";
        else
            cout << "Is Invalid\n";
    }
    
};// end validate string class 

int main() 
{
    ValidateString str1("helloworld");
    ValidateString str2("0123");
    ValidateString str3("23K-0070");
    str1.isValid();
    str2.isValid();
    str3.isValid();

    return 0;
}// end main
