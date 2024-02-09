#include <iostream>
#include <string>
using namespace std;
//
class WaterBottle {
private:
    string company;
    string color;
    int capacityLiters;
    int capacityMilliliters;

public:
    
    WaterBottle(string company, string color, int capacityLiters, int capacityMilliliters)
        : company(company), color(color), capacityLiters(capacityLiters), capacityMilliliters(capacityMilliliters) {}


    string getCompany()  {
        return company;
    }
//
    void setCompany(const string& newCompany) {
        company = newCompany;
    }
//
    string getColor()  {
        return color;
    }
//
    void setColor(const string& Color) {
        color = Color;
    }
//
    int getCapacityLiters()  {
        return capacityLiters;
    }
//
    void setCapacityLiters(int CapacityLiters) {
        capacityLiters = CapacityLiters;
    }
//
    int getCapacityMilliliters()  {
        return capacityMilliliters;
    }
//
    void setCapacityMilliliters(int CapacityMilliliters) {
        capacityMilliliters = CapacityMilliliters;
    }
//  
    void consumeWater(int consumedMilliliters) {
        if (consumedMilliliters <= capacityMilliliters) {
            capacityMilliliters -= consumedMilliliters;
            cout << "Water consumed. Remaining capacity: " << capacityLiters << " liters and " << capacityMilliliters << " milliliters." << endl;
        } else {
            cout << "Not enough water in the bottle to consume." << endl;
        }
    }
//
    void CapacityFromUserInput() {
        int consumedMilliliters;
        cout << "Enter the amount of water consumed in milliliters: ";
        cin >> consumedMilliliters;

        consumeWater(consumedMilliliters);
    }//
};
//
int main() {
    WaterBottle bottle("nestle", "Blue", 3, 2000);
    cout << "Water Bottle Details:" ;
    cout << "\nCompany: " << bottle.getCompany() ;
    cout << "\nColor: " << bottle.getColor() ;
    cout << "\nCapacity: " << bottle.getCapacityLiters() << " liters and " << bottle.getCapacityMilliliters() << " milliliters." << endl;
    bottle.CapacityFromUserInput();
    cout << "\nUpdated Water Bottle Details:" ;
    cout << "\nCompany: " << bottle.getCompany() ;
    cout << "\nColor: " << bottle.getColor() ;
    cout << "\nCapacity: " << bottle.getCapacityLiters() << " liters and " << bottle.getCapacityMilliliters() << " milliliters." << endl;

    return 0;
}
 
