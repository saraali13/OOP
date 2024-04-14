#include <iostream>
#include <string>
using namespace std;

//player class:base class 1
class Player 
{
protected:

    int playerID;
    string playerName;
    int health;

public:

    Player(int ID, string Name) : playerID(ID), playerName(Name), health(1000) 
	{}

    virtual void display() const 
	{
        cout << "Player ID: " << playerID;
        cout << "\nPlayer Name: " << playerName ;
        cout << "\nHealth: " << health << endl;
    }

    virtual void playGame() const = 0;
};

//weapon class:base class 2
class Weapon 
{
protected:
    string weaponsList[5] = {"Sword", "Axe", "Bow", "Staff", "Dagger"};

public:
    void use() const 
	{
        cout << "Weapon Available: ";
        for (int i = 0; i < 5; ++i) 
		{
            cout << weaponsList[i] << " ";
        }
        cout << endl;
    }
};

//character class : derived from player and weapon class
class Character : public Player, public Weapon 
{
protected:

    int Level;
    string experience;
    int points;

public:
    Character(int ID, string Name, int level, string exp) : Player(ID, Name), Level(level), experience(exp), points(0) 
	{}

//function for increasing character's level
    virtual void levelUp() 
	{
        points += 10;
        if (points >= 10) 
		{
            Level++;
            if (experience == "Beginner") 
			{
                experience = "Intermediate";
            } 
			else if (experience == "Intermediate") 
			{
                experience = "Advanced";
            } 
			else if (experience == "Advanced") 
			{
                experience = "Expert";
            }
            points = 0;
        }
    }


    void playGame() const override 
	{
        cout << playerName << " is playing the game\n";
    }

//function for displaying character's details
    void display() const override 
	{
        Player::display();
        cout << "Level: " << Level;
        cout << "\nExperience: " << experience;
        cout << "\nPoints: " << points << endl;
    }
};

//enemy class:derived from only weapon class
class Enemy : public Weapon 
{
protected:
    int Damage;

public:
    Enemy(int damage) : Damage(damage) {}

    void attack(int& targetHealth) const 
	{
        cout << "Enemy is attacking\n";
        targetHealth -= Damage;
    }
};

//main function
int main() 
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
    Character player(1, "xyz", 0, "Beginner");
    Enemy enemy(5);
    player.display();
    player.use();
    player.playGame();
    cout << endl;
    for (int i = 0; i < 3; ++i) 
	{
        player.levelUp();
        player.display();
        cout << endl;
    }
    
    return 0;
}
