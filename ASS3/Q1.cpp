/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <string>
using namespace std;

//Medicine class:base class
class Medicine 
{
protected:
    string name;
    string formula;
    double retailPrice;
    string manufactureDate;
    string expirationDate;

public:
    // constructor with initiallizer list
    Medicine(string name,string formula,double retailPrice,string manufactureDate,string expirationDate): name(name), formula(formula), retailPrice(retailPrice),manufactureDate(manufactureDate), expirationDate(expirationDate)
    {}

    // Setter functions

    void setName(string name) 
    {
         this->name = name; 
    }
    void setFormula(string formula) 
    {
         this->formula = formula; 
    }
    void setRetailPrice(double retailPrice) 
    { 
        this->retailPrice = retailPrice; 
    }
    void setManufactureDate(string manufactureDate)
    { 
        this->manufactureDate = manufactureDate; 
    }
    void setExpirationDate(string expirationDate) 
    { 
        this->expirationDate = expirationDate; 
    }
    
    //Getter functions
    string getName() 
    { 
        return name; 
    }
   string getFormula()  
   { 
      return formula;    
   }
  double getRetailPrice()  
  { 
     return retailPrice; 
  }
  string getManufactureDate() 
  { 
     return manufactureDate;
  }
  string getExpirationDate() 
  { 
     return expirationDate; 
  }

// Virtual function for printing medicine details
    virtual void printDetails()
    {
        cout << "Name: " << name;
        cout << "\nFormula: " << formula;
        cout << "\nRetail Price: " << retailPrice;
        cout << "\nManufacture Date: " << manufactureDate;
        cout << "\nExpiration Date: " << expirationDate <<endl;
    }

};//end of medicine class

//drived class from medicine class
class Tablet : public Medicine 
{
private:
    double sucroseLevel;

public:
//parameterized constructor
    Tablet(string name,string formula,double retailPrice,string manufactureDate,string expirationDate, double sucroseLevel): Medicine(name, formula, retailPrice, manufactureDate, expirationDate),sucroseLevel(sucroseLevel) 
    {}

    // Overriding printDetails function for printing tablet details
    void printDetails()
    {
        Medicine::printDetails();
        cout << "Sucrose Level: " << sucroseLevel <<endl;
    }

};//end of tablet class

//Derived class from medicine class
class Capsule : public Medicine 
{
private:
    int absorptionPercentage;

public:
//parameterized constructor
    Capsule(string name,string formula,double retailPrice,string manufactureDate,string expirationDate, int absorptionPercentage): Medicine(name, formula, retailPrice, manufactureDate, expirationDate),absorptionPercentage(absorptionPercentage) 
    {}

    // Overridding printDEtails function for printing capsule details
    void printDetails()  
    {
        Medicine::printDetails();
        cout << "Absorption Percentage: " << absorptionPercentage <<endl;
    }
};

class Syrup : public Medicine 
{
public:
//parameterized constructor
    Syrup(string name,string formula,double retailPrice,string manufactureDate,string expirationDate): Medicine(name, formula, retailPrice, manufactureDate, expirationDate)
     {}

    // Overridding printDetails function for printing syrup details
    void printDetails()  
    {
        Medicine::printDetails();
    }
};

class Pharmacist 
{
public:
    void searchMedicine(string formula)
    {
        
        cout << "Searching medicine by formula: " << formula << endl;
    }
};

class Counter 
{
public:
    void searchMedicine(string name)
    {
        cout << "Searching medicine by name: " << name << endl;
    }

    void updateRevenue(double amount) 
    {
        cout << "Updating revenue by: " << amount <<endl;
    }
};

// Overloading "==" operator to compare expiration years of diffrent medicines
bool operator==(Medicine med1, Medicine med2) 
{
    return med1.getExpirationDate().substr(0, 4) == med2.getExpirationDate().substr(0, 4);
}


int main() 
{
	cout<<"Name:S. Sara Ali\nID:23K-0070\n\n";
    //object of diffrent classes inherting medicine class
    Tablet tablet("Panadol", "C8H9NO2", 190.99, "2022-04-15", "2024-04-15", 0.29);
    Capsule capsule("Dan D", "C19H24N2S3", 240.49, "2023-01-10", "2024-01-10", 80);
    Syrup syrup("Brufin","C12H9O5",200.9,"2023-12-4","2026-13-6");
    Counter C1;
    Pharmacist P1;

//printing details of medicines through overrodden functions
    tablet.printDetails();
    cout<<endl;
    capsule.printDetails();
    cout<<endl;
    syrup.printDetails();
    cout<<endl;
    
//searching medicies
   C1.searchMedicine("Panadol");
   C1.updateRevenue(450.5);
   P1.searchMedicine("C19H24N2S3");
   cout<<endl;
   
//comparing expairing date of diffrent medicines through operator overridding (==)
    if (tablet == capsule) 
    {
        cout << "Both medicines (tablet and capsule) expire in the same year\n";
    } 
	else 
    {
        cout << "Medicines expire (tablet and capsule) in different years\n";
    }
    
    if(syrup==tablet) 
	{
        cout << "Both medicines (tablet and syrup) expire in the same year\n";
    } 
	else 
    {
        cout << "Medicines expire (tablet and syrup) in different years\n";
    }

    return 0;
}
