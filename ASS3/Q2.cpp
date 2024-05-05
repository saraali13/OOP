/*
Name:S. Sara Ali
ID:23K-0070
*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>// Base Pet class template
class Pet //pet class:base class
{
protected:
    string name;
    int age;

public:
//parameterized consturctor
    Pet(string name, int age) : name(name), age(age)
     {}

// Pure virtual function for diffrent pet's sound
    virtual void makeSound() = 0;

    // Setter functions
    void setName(string name)
    {
        this->name=name;
    }
    void setAge(int age)
    {
        this->age;
    }

    //Getter functions
    string getName()
    { 
        return name; 
    }

    int getAge()
    { 
        return age; 
    }

};// end of pet class

//cat class derived from pet class
class Cat : public Pet<string> 
{
public:
//parameterized consturctor
    Cat(string name, int age) : Pet<string>(name, age) 
    {}

//Overridding makeSound function for Cat
    void makeSound()
    {
        cout << "Makes sound Meow Meow\n";
    }
};

class Dog : public Pet<string> 
{
public:
//parameterized consturctor
    Dog(string name, int age) : Pet<string>(name, age) 
    {}

//Overridding makeSound function for Dog
    void makeSound()
    {
        cout << "Makes sound Bhao bhao\n";
    }
};

class Bird : public Pet<string> 
{
public:
//parameterized consturctor
    Bird(string name, int age) : Pet<string>(name, age) 
    {}

//Overridding makeSound function for Bird
    void makeSound()
    {
        cout << "Makes sound Chee Chee\n";
    }
};

int main() 
{
    cout<<"Name:S. Sara Ali\nID:23K-0070\n\n";

    //Objects of diffrent classes inheriting pet class
    Cat cat("Kitty", 6);
    Dog dog("Wasooli", 3);
    Bird bird("Chichi", 2);

    Pet<string>* pets[3] = { &cat, &dog, &bird };
    for (int i = 0; i < 3; ++i) 
    {
        cout << "Pet name: " << pets[i]->getName() << "\nAge: " << pets[i]->getAge() <<endl;
        pets[i]->makeSound();
    }

    return 0;
}
