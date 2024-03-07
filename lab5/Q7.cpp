#include <iostream>
#include <string>
using namespace std;

const int MAX_MENU_ITEMS = 10;  
const int MAX_ORDER_ITEMS = 10; 


class MenuItem 
{
private:
    string Name;
    double Price;
public:
    MenuItem() 
	{}  

    MenuItem(const string& name, double price) : Name(name), Price(price) {}

    string getName() const 
	{
        return Name;
    }

    double getPrice() const 
	{
        return Price;
    }

};//


class Menu 
{
private:
    MenuItem menuItems[MAX_MENU_ITEMS];
    int numItems;
public:
    
    Menu() : numItems(0) 
	{}

    void addItem(const MenuItem& item) 
	{
        if (numItems < MAX_MENU_ITEMS) 
		{
            menuItems[numItems++] = item;
        }
    }

    void removeItem(const MenuItem& item) 
	{
        
        for (int i = 0; i < numItems; ++i) 
		{
            if (menuItems[i].getName() == item.getName()) 
			{
                
                for (int j = i; j < numItems - 1; ++j) 
				{
                    menuItems[j] = menuItems[j + 1];
                }
                numItems--;
                break;
            }
        }
    }

    void displayMenu() const 
	{
        cout << "----Menu----\n";
        for (int i = 0; i < numItems; ++i) 
		{
            cout << menuItems[i].getName() << " " << menuItems[i].getPrice() << endl;
        }
    }

};//


class Payment 
{
public:
    Payment() 
	{}  

    Payment(double amount) : amount(amount) {}

    double getAmount() const 
	{
        return amount;
    }

private:
    double amount;
};//


class Order 
{
	
private:
    MenuItem orderItems[MAX_ORDER_ITEMS];
    int numItems;
    Payment payment;
public:
    Order() : numItems(0) {}  

    
    void addItem(const MenuItem& item, int quantity = 1) 
	{
        for (int i = 0; i < quantity; ++i) 
		{
            if (numItems < MAX_ORDER_ITEMS) 
			{
                orderItems[numItems++] = item;
            }
        }
    }

    void setPayment(const Payment& payment) 
	{
        this->payment = payment;
    }


    const Payment& getPayment() const 
	{
        return payment;
    }

    double totalBillGenerate() const 
	{
        double totalBill = 0;
        for (int i = 0; i < numItems; ++i) 
		{
            totalBill += orderItems[i].getPrice();
        }
        return totalBill;
    }

};//


class RestaurantOrderingSystem 
{
private:
	
    Menu* menu;
	  
public:
	
    RestaurantOrderingSystem(Menu* pMenu) : menu(pMenu) {}
	   
    void placeOrder(const Order& order) 
	{
        
        cout << "Total amount: " << order.getPayment().getAmount() << "\n";
       
        if (order.totalBillGenerate() > 0) 
		{
            cout << "Total Bill: " << order.totalBillGenerate() << "\n";
        }
    }

};//


int main() 
{
	   
    MenuItem item1("Burger", 270);
    MenuItem item2("Pizza", 500);
    MenuItem item3("Sandwitch", 260);

    Menu* menu = new Menu();
    menu->addItem(item1);
    menu->addItem(item2);
    menu->addItem(item3);
    menu->displayMenu();
    Order order;
    order.addItem(item1);
    order.addItem(item3, 2); 
    Payment orderPayment(21.97); 
    order.setPayment(orderPayment);
    RestaurantOrderingSystem restaurant(menu);
    restaurant.placeOrder(order);   
    delete menu;

    return 0;
}// end main
