/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

//Base class : character class
class Character 
{
	protected:

    	int Health;
    	int Damage;

	public:

    	//parameterized Constructor 
    	Character(int health, int damage) : Health(health), Damage(damage) 
		{}

    //function for displaying the data of the character
    void display() const 
	{
        cout<<"Health: "<<Health;
        cout<<"\nDamage: "<<Damage<<endl;
    }//

};//end character class


//derived class1: Enemy class
class Enemy : public Character 
{
	public:

    	//paramerterized constructor
    	Enemy(int health, int damage) : Character(health, damage) 
		{}

    //function for displaying details of Enemy
    void display() const 
	{   
        cout<<"Type: Enemy\n";
        Character::display();
        
    }//

};// end enemy class

//derived class2: Player class
class Player : public Character 
{
	public:

    	//parameterized constructor
    	Player(int health, int damage) : Character(health, damage) 
		{}

    //function for displaying details of Player
    	void display() const 
		{   
			cout<<"Type: Player\n";
        	Character::display();
        	
    	}//

};// end player class

//sub class of player : Wizard class
class Wizard : public Player 
{
	private:

    	int magicPower;
    	string Spells;

	public:

    	//parameterized constructor
    	Wizard(int health, int damage, int magic_Power, string spells) : Player(health, damage), magicPower(magic_Power), Spells(spells) {}

    //function for displaying details of Wizard
    	void display() const 
		{
			cout<<"Wizard Details:"<<endl;
        	Player::display();
        	cout<< "Magic Power: "<<magicPower<<endl;
        	cout<<"Spells: "<<Spells<<endl;
    	}//

};// end wizard class

//main function
int main() 
{
	cout<<"Name:S.Sara Ali\nID:23k-0070\n\n";
   
    Wizard Wiz1(500,50,200, "healing spell,invisible spell");
    Wiz1.display();
    cout<<endl;
    Enemy E1(500,30);
    E1.display();
    
    return 0;
}// end main
