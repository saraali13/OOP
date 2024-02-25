/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class Restaurant
{
	private:
		
		string Name;
		string Location;
		string MenuList[5];
		float Prices[5];
		string Coupon_Codes[5];
		static int Redeem_Coupons;
		
	public:
		
	//parameterized constructor with initializer list
		Restaurant(string name, string loc, string* menu, float* price, string* coupons) 
		{
            Name=name;
			Location = loc;
			for(int i=0 ;i<5;i++) 
			{
				MenuList[i] = menu[i];
				Prices[i] = price[i];
                Coupon_Codes[i] = coupons[i];
			}
            
        }
       
	//function for displaying menu    
		void display_menu() 
		{
			cout<<"Menu of the restaurant "<<Name<<endl;
			for(int i =0; i<5;i++) 
			{
				cout<<"Menu item "<<i+1<<" : "<<MenuList[i]<<" with the price "<<Prices[i]<<endl;
			}
			cout<<endl;
		}
		
	//function for generating bills
		void generate_bill(int* quantity) 
		{
			float sum = 0;
			cout<<"\nBill for "<<Name<<" :"<<endl;
			for(int i =0; i<5;i++) 
			{
				if(quantity[i]!=0) 
				{
					cout<<"Item name: "<<MenuList[i]<<"\tQuantity: "<<quantity[i]<<" \tPrice: $"<<Prices[i]*quantity[i]<<endl;
					sum =sum+ (Prices[i] * quantity[i]);
				}
			}
			cout<<"the total bill is: "<<sum<<endl;
		}
		
	//function for checking validity of coapon codes
		bool valid_coupon(string code) 
		{
			for(int i=0;i<5;i++) 
			{
				if(Coupon_Codes[i]==code) 
				{
					return true;
				}
			}
			return false;
		}
		
		static int getRredeem_coupons() 
		{
			return Redeem_Coupons;
		}
		
};// end class

class BOGOCoupon
{    
    public:
		string Code;
		int valid_from;
		int valid_until;
		string restaurantName;
		
	public:
		
	//parameterized constructor
	
		BOGOCoupon(string code, int from, int til, string restaurant) : Code(code), valid_from(from), valid_until(til), restaurantName(restaurant)
		 {}
        
    //function for checking coapon validity    
        bool is_valid(string restaurant, string code, int current_month) 
		{
			if(restaurantName!=restaurant) 
			{
        		cout<<"This coupon is invalid\n";
        		return false;
			}
		
			if(current_month >= valid_from && current_month <= valid_until) 
			{
				cout<<"This coupon is valid\n";
				return true;
			} 
			else 
			{
				cout<<"The coupon has expired\n";
				return false;
			}
		}		
};// end class 

class User:  public BOGOCoupon
{
	private:
		string Name;
		int Age;
		string MobileNum;
		string* Coupons;
		string* Redeem_Coupons;
		
	public:
		
	//parameterixed constructor 
	    User(string name, int age, string mobile, string code, int from, int until, string restaurant) :
        BOGOCoupon(code, from, until, restaurant), Name(name), Age(age), MobileNum(mobile) 
		{
            Coupons = new string[5];
            Redeem_Coupons = new string[5];
        }
        
        //destructor
        ~User() {
            delete[] Coupons;
            delete[] Redeem_Coupons;
        }
        
    //function for adding a coupon 
        void accumulate_coupon(string coupon) 
		{
            for (int i = 0; i < 5;i++) 
			{
                if (Coupons[i] == " ") {
                    Coupons[i] = coupon;
                    break;
                }
            }  
        }

		bool Has_valid_coupon(string code, string restaurant, int current_month) 
		{
			for(int i=0;i<5;i++) 
			{
				if(Redeem_Coupons[i]!=code) 
				{
					if (is_valid(restaurant, code, current_month)) 
					{
				            return true;
			        } 
			        return false;
		        } 
				else 
				{
		        	cout<<"coupon has already been redeemed"<<endl;
		        	return false;
				}
						
			}
		}
		
		bool redeem_coupon(string code, string restaurant, int current_month) 
		{
			
			if(!Has_valid_coupon(code, restaurant, current_month) ) 
			{
                cout<<"Coupon is not valid\n";
                return false;
            } 
			else 
			{
            	for(int i=0;i<5;i++) 
				{
            		if(Redeem_Coupons[i]=="") 
					{
            			Redeem_Coupons[i]=code;
            			cout<<"coupon redeemed\n";
            			return true;
					}
				}
			}
			cout<<"coupon not found\n";
		}
};// end class

//main function
int main() 
{
	cout<<"Name:S. Sara Ali\nID:23k-0070\n\n";
	
	string Karachi_Food_menu[5] = {"Noodles", "Fired chicken", "Buger", "Biryani","Pasta"};
    float Karachi_Food_prices[5] = {200,678 ,250,567,780};
    string Karachi_Food_coupons[5] = {"GK-12345", "","","",""};
	Restaurant Karachi_Food("Karachi Food", "Nursury", Karachi_Food_menu, Karachi_Food_prices, Karachi_Food_coupons);
    
    string Chilli_Bites_menu[5] = {"Cheesy Burger", "Karai", "Pizza", "Cheese fries","Roll"};
	float Chilli_Bites_prices[5] = {400,980,460,390,230};
    string Chilli_Bites_coupons[5] = {"HU-67890", "","","",""};
	Restaurant Chilli_Bites("Chilli Bites", "Main shaharh", Chilli_Bites_menu, Chilli_Bites_prices, Chilli_Bites_coupons);

    Karachi_Food.display_menu();
    Chilli_Bites.display_menu();
    
    BOGOCoupon coupon1("GK-12345",2,4,"Karachi Food");
    BOGOCoupon coupon2("HI-6789",3,7,"Chilli Bites");
    
    User user("Ali", 21, "6765421334","GK-12345",3,6,"Karachi Food");
    user.accumulate_coupon("GK-12345");
    user.accumulate_coupon("HU-67890");
    user.accumulate_coupon("HU-6789");

    if (user.Has_valid_coupon(coupon1.Code, coupon1.restaurantName, 3)) 
	{
        if (user.redeem_coupon(coupon1.Code, coupon1.restaurantName, 3)) 
		{
            cout << "Coupon redeemed successfully!" <<endl;
        }
    }
    
    if (user.Has_valid_coupon(coupon2.Code, coupon2.restaurantName, 3)) 
	{
        if (user.redeem_coupon(coupon2.Code, coupon2.restaurantName, 3)) 
		{
            cout << "Coupon redeemed successfully!" <<endl;
        }
    }
    
    if (user.Has_valid_coupon(coupon1.Code, coupon1.restaurantName, 3)) 
	{
        if (user.redeem_coupon(coupon1.Code, coupon1.restaurantName, 3)) 
		{
            cout << "Coupon redeemed successfully!" <<endl;
        }
    }

    int quantity[5];
	for(int i=0; i<5; i++) 
	{
    	cout<<"enter quantity for menu item "<<i+1<<endl;
    	cin>>quantity[i];
	}
	
	Karachi_Food.generate_bill(quantity);
  return 0;
	
}//end main
