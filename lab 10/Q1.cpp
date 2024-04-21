/*
Name:S.Sara Ali
ID: 23K-0070
*/

#include<iostream>
using namespace std;

class Logo
{
    friend class Platform;
    friend class Server;
    string logo;
public:
    Logo(string logo):logo(logo)
	{}
};

class Platform
{
public:
    void display(Logo &obj,string newLogo)
	{  
	    cout<<"Previous Logo: "<<obj.logo<<endl;
        obj.logo = newLogo;
        cout<<"Current Logo: "<<obj.logo;
    }
};

class Server
{
    
};

int main()
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
	
    Logo logo1("Blue Bird");
    Platform p1;
    cout<<"Changing Logo Of Twitter:\n\n";
    p1.display(logo1,"Doge Coin");
    return 0;
}
