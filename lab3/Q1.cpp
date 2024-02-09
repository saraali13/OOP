#include <iostream>
#include <string>

using namespace std;

class BoardMarker {
private:
    string Brand;
    string Shade;
    bool refillable;
    bool inkStatus;

public:

    string getBrand() const { return Brand; }
    string getShade() const { return Shade; }
    bool is_Refillable() const { return refillable; }
    bool is_InkDepleted() const { return !inkStatus; }

    void setBrand(string brand) { Brand = brand; }
    void setShade(string shade) { Shade = shade; }
    void setRefillable(bool Refillable) { refillable = Refillable; }
    void setInkStatus(bool InkStatus) { inkStatus = InkStatus; }

    void write() {
        if (inkStatus)
		{
            cout << "The board marker writes perfectly\n";
        }
	   else 
		{
            cout << "The ink of the board marker has run out\n";
        }
    }//

    void refill() {
        if (refillable) 
		{
            inkStatus = true;
            cout << "The board marker refilled\n";
        } 
		else 
		{
            cout << "This board marker cannot refilled\n";
        }
    }//
};

int main() {
    
    string brand,color; 
    BoardMarker marker;
    marker.setBrand("Dollar");
    marker.setShade("red");
    marker.setRefillable(false);
    marker.setInkStatus(true);
    brand= marker.getBrand();
    color=marker.getShade();
    cout<<"brand: "<<brand<<"\ncolor: "<<color<<endl;
    marker.refill(); 
    marker.write(); 
    return 0;
}
