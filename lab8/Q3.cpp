/*
Name:S.Sara Ali
ID:23K-0070
*/


#include <iostream>
using namespace std;

//base class1 : position class
class Position 
{
	protected:

    	float x;
    	float y;
    	float z;

	public:

    	//parameterized Constructor
    	Position(double x, double y, double z) : x(x), y(y), z(z) 
		{}

    	//function for displaying position of the character
    	void displayPosition() const 
		{
        	cout<<"Position: ("<<x<<", "<<y<<", "<<z<<")\n";
    	}//
};

//base class2 : health class
class Health 
{
	protected:

    	int health;

	public:

		//parameterized Constructor
    	Health(int ahealth) : health(ahealth) 
		{}

   //function for displaying health of the character
    void displayHealth() const 
	{
        cout<<"Health: "<<health<< endl;
    }//
};

//derived class from position and health class : character class
class Character : public Position, public Health 
{
	private:
    	string name;
    	int level;

	public:
    	//parameterized Constructor
    Character(double x, double y, double z, int health,string name, int level) : Position(x, y, z), Health(health), name(name), level(level) 
	{}

    //function for displaying the data of the character
    void displayCharacter() const 
	{
        cout<<"Character Name: "<<name<<endl;
        cout<<"Character Level: "<<level<<endl;
		displayPosition(); 
        displayHealth();   
    }//
};

int main() 
{
	cout<<"Name:S.Sara Ali\nID:23k-0070\n\n";
	
    Character C1(11.7, 9.6, 6.2, 300, "bla bla", 5);
    C1.displayCharacter();

    return 0;
}//
