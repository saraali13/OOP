/*
Name:S. Sara Ali
ID:23K-0070
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class StationaryShop 
{
private:
    static const int n = 100;
    string items[n];
    double prices[n];
    int Count = 0;

public:
	
//function for adding new item

    void AddItem(const string& Item, double Price) 
	{
        if (Count < n) 
		{
            items[Count] = Item;
            prices[Count] = Price;
            cout << "Item " << Item << " added of price " << Price << endl;
            Count++;
        }
        else 
		{
            cout << "Cannot add more items\n";
        }
    }

//function for displaying items

    void display() 
	{
        cout << "Displaying Items:\n";
        for (int i = 0; i < Count; i++) 
		{
            cout << "\nItem: " << items[i] << " Price: " << prices[i] << endl;
        }
    }

//dunction for modifying price

    void modify(int index, double newPrice) 
	{
        if (index >= 1 && index <= Count) 
		{
            prices[index - 1] = newPrice;
            cout << "\nPrice of " << items[index - 1] << " is updated to " << newPrice << endl;
        }
        else 
		{
            cout << "Invalid item\n";
        }
    }

//function for displaying the Bill or recipt

    void Receipt(const int purchases[], const int quantities[], int purchaseCount)
	{
        cout << "\nReceipt:\n";
        double total = 0;
        for (int i = 0; i < purchaseCount; i++) 
		{
            int index = purchases[i] - 1;
            if (index >= 0 && index < Count) 
			{
                cout << items[index] << " x " << quantities[i] << " price: " << prices[index] * quantities[i] << endl;
                total += prices[index] * quantities[i];
            }
        }
        cout << "Total Amount: " << total << endl;
    }
};

//main function

int main() 
{
    StationaryShop shop;
    int choice;
    string item;
    double price;
    int index;
    int purchases[100];
    int quantities[100];
    int purchaseCount = 0;

    cout << "Stationary Shop\n";
        cout << "\nMake Your Choice" << endl;
        cout << "\n1. Add item and price";
        cout << "\n2. Display items";
        cout << "\n3. Modify price";
        cout << "\n4. Generate receipt\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Item: ";
            cin >> item;
            cout << "Item price: ";
            cin >> price;
            shop.AddItem(item, price);
            break;
        case 2:
            shop.display();
            break;
        case 3:
            cout << "Item index to modify price: ";
            cin >> index;
            cout << "New price: ";
            cin >> price;
            shop.modify(index, price);
            break;
        case 4:
            cout << "Items purchased:\n";
            cout << "enter 0 for exiting\n";
            while (true) 
			{
                cin >> index;
                if (index == 0) 
				{
                    break;
                }
                cout << "Quantity: ";
                cin >> quantities[purchaseCount];
                purchases[purchaseCount++] = index;
            }
            shop.Receipt(purchases, quantities, purchaseCount);
            break;
        default:
            cout << "Invalid choice\n";
        }
}// end main
