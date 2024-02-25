/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <string>
using namespace std;

// pet class
class Pet 
{
private:
	
    string Name;
    string healthStatus;
    int hungerLevel;
    int happinessLevel;
    string specialSkills[5];
    int num;

public:
	
// parametrized constructor

    Pet(string name, string h_status = "Healthy", int h_level = 5, int hap_level = 5) :
            Name(name), healthStatus(h_status), hungerLevel(h_level), happinessLevel(hap_level), num(0) {}
    
    
//function for displaying the details of pet

    void displayPetDetails() 
	{
    	cout<<"\nDisplaying pet details";
        cout<<"\nPet Name: "<<Name;
        cout<<"\nHealth Status: "<<healthStatus;
        cout<<"\nHunger Level: "<<hungerLevel;
        cout<<"\nHappiness Level: "<<happinessLevel;
        cout<<"\nSpecial Skills: ";
        for(int i=0;i< num;i++) 
		{
            cout<<specialSkills[i]<<", ";
        }
        cout<<endl<<endl;
    }
    
//getter to access the name of the pet

    string getName() const 
	{ 
        return Name;
    }
    
    
//function  add special skills for the pets

   void addSpecialSkill(string skill) 
	{
       if (num < 5) 
	    {
          specialSkills[num++] = skill;
        }
    }


//function for undating happiness level of the pets mini max algo is used

    void updateHappiness(string action) 
	{
        if(action=="feed") {
            happinessLevel=min(happinessLevel + 1, 10);
        } else if(action=="play") {
            happinessLevel=max(happinessLevel - 1, 0);
        }
        if(hungerLevel>=8) {
            happinessLevel=max(happinessLevel - 1, 0);
        }
    }


//functions for updating health level of the pet

    void updateHealth() 
	{
        if (hungerLevel >= 8) 
		{
            healthStatus = "Sick";
        } else if (hungerLevel <= 2) 
		{
            healthStatus = "Healthy";
        }
    }
    
    void updateHunger(string action) {
        if (action == "feed") {
            hungerLevel = max(hungerLevel - 1, 0);
        } else if (action == "play") {
            hungerLevel = min(hungerLevel + 1, 10);
        }
        if (happinessLevel <= 2) {
            hungerLevel = min(hungerLevel + 1, 10);
        }
    }
};// end pet class

//Adopter class
class Adopter 
{
    private:
    	
        string adopterName;
        string adopterMobileNum;
        Pet *adoptedPetRecords[3];
        int numPets;

    public:
    	
//parameterized constructor
        Adopter(string Name, string mobileNum) : adopterName(Name), adopterMobileNum(mobileNum) ,numPets(0)
		{}


//function for adopting pet

        void adoptPet(Pet *pet) 
		{
            if (numPets < 3) 
			{
                adoptedPetRecords[numPets++] = pet;
            }
        }
       
	    
//function for returning a pet 

        void returnPet(Pet *pet) 
		{
            for(int i=0;i<numPets;i++) 
			{
                if (adoptedPetRecords[i] == pet) 
				{
                    for (int j=i;j<numPets-1;j++) 
					{
                        adoptedPetRecords[j] = adoptedPetRecords[j + 1];
                    }
                    adoptedPetRecords[numPets--] = NULL;
                    cout<<pet->getName() << " has been returned\n";
                    return;
                }
            }
        }
    
    
//function to display current adopted pets by a adopter

    void displayAdoptedPets() 
	{
        cout<<"\nAdopted Pets by: "<<adopterName<<endl;
        for(int i=0;i<numPets;i++) 
		{
            adoptedPetRecords[i]->displayPetDetails();
        }
    }
};// end adopter class

// main function
int main() 
{
	
	cout<<"Name:S. Sara Ali\n";
	cout<<"ID:23K-0070\n\n";
  
    Pet pet1("Lucy", "Healthy", 5, 4);
    Pet pet2("Fluffy", "sick", 3, 5);
    pet1.addSpecialSkill("dancing");
    pet1.addSpecialSkill("roaring");
    pet1.addSpecialSkill("eating");
    pet1.addSpecialSkill("punching");
    pet2.addSpecialSkill("fighting");
    pet2.addSpecialSkill("sleeping");
    pet2.addSpecialSkill("eating");
    pet2.addSpecialSkill("dancing");
    
    Adopter adopter1("Ali", "830830808");
    Adopter adopter2("Zara", "779793288");
    adopter1.adoptPet(&pet1);
    adopter2.adoptPet(&pet2);

    pet1.updateHappiness("feed");
    pet1.updateHealth();
    pet2.updateHunger("play");
    pet2.updateHealth();
    adopter1.displayAdoptedPets();
    adopter2.displayAdoptedPets();

    return 0;
}// end main function
