#include <iostream>
using namespace std;

//DarazPersonData class: base class
class DarazPersonData 
{
private:

    string lastName;
    string firstName;
    string Address;
    string City;
    string State;
    string Zip;
    string Phone;

public:
    // Getter functions
    string getLastName() const 
	{
        return lastName;
    }

    string getFirstName() const 
	{
        return firstName;
    }

    string getAddress() const 
	{
        return Address;
    }

    string getCity() const 
	{
        return City;
    }

    string getState() const 
	{
        return State;
    }

    string getZip() const 
	{
        return Zip;
    }

    string getPhone() const 
	{
        return Phone;
    }

    // Setter functions
    void setLastName(string lastName) 
	{
        this->lastName = lastName;
    }

    void setFirstName(string firstName) 
	{
        this->firstName = firstName;
    }

    void setAddress(string Address) 
	{
        this->Address = Address;
    }

    void setCity(string City) 
	{
        this->City = City;
    }

    void setState(string State) 
	{
        this->State = State;
    }

    void setZip(string Zip) 
	{
        this->Zip = Zip;
    }

    void setPhone(string Phone) 
	{
        this->Phone = Phone;
    }
};

//DarazCustomerData class derived from DarazPersonData class
class DarazCustomerData : public DarazPersonData 
{
private:

    int customerNumber;
    int loyaltyPoints;

public:
    // Getter functions
    int getCustomerNumber() const 
	{
        return customerNumber;
    }

    int getLoyaltyPoints() const 
	{
        return loyaltyPoints;
    }

    // setter functions
    void setCustomerNumber(int customerNumber) 
	{
        this->customerNumber = customerNumber;
    }

    void setLoyaltyPoints(int loyaltyPoints) 
	{
        if (loyaltyPoints >= 0) 
		{
            this->loyaltyPoints = loyaltyPoints;
        } 
		else 
		{
            cout << "Invalid input\n";
        }
    }
};

class DarazLoyaltyProgram 
{
public:

    // Function for adding customer's loyalty points
    static void addLoyaltyPoints(DarazCustomerData& customer, int points) 
	{
        int currentPoints = customer.getLoyaltyPoints();
        customer.setLoyaltyPoints(currentPoints + points);
        cout << points << " loyalty points added for customer " << customer.getCustomerNumber() << endl;
    }

    // Function for redeeming customer's loyalty points for discounts
    static void redeemLoyaltyPoints(DarazCustomerData& customer, int points) 
	{
        int currentPoints = customer.getLoyaltyPoints();
        if (currentPoints >= points) 
		{
            customer.setLoyaltyPoints(currentPoints - points);
            cout << points << " loyalty points redeemed for customer " << customer.getCustomerNumber() << endl;
        } 
		else 
		{
            cout << "Insufficient loyalty points for redemption\n" ;
        }
    }

    // Function for displaying total loyalty points of a customer
    static void displayTotalLoyaltyPoints(const DarazCustomerData& customer) 
	{
        cout << "Total loyalty points of customer " << customer.getCustomerNumber() << "= " << customer.getLoyaltyPoints() << endl;
    }
};

int main() 
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
    DarazCustomerData customer;
    customer.setCustomerNumber(5098);
    customer.setLoyaltyPoints(400);
    DarazLoyaltyProgram::addLoyaltyPoints(customer, 70);
    DarazLoyaltyProgram::redeemLoyaltyPoints(customer, 50);
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer);

    return 0;
}//end main
