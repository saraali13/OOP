/*
Name:S. Sara Ali
Roll.no:23K-0070
Des: to write a c++ program to 
1. Develop a function that enables the addition of a new product to the system. The
function should accept parameters such as product name, price, quantity, and
any other relevant details.
2. Implement a function that takes a product ID as input and displays detailed
information about the product, including its name, price, quantity in stock,
and any other relevant details.
3. Design a function that allows the update of product information. It should accept
a product ID and the new details (e.g., updated price, quantity, etc.) and modify
the existing product’s information accordingly.
*/

#include<iostream>
using namespace std;

struct Product
{
	string P_name;
	double P_price;
	int P_Quantity,P_ID;
};


//function for displaying products

void display(const string& P_name, double P_price, int P_Quantity,int P_ID)
{
	cout<<"\nProduct Name: "<<P_name;
	cout<<"\nProduct ID: "<<P_ID;
	cout<<"\nProduct Price: "<<P_price;
	cout<<"\nProduct Quantity: "<<P_Quantity<<endl;
}

//function for adding a new product

void addProduct(Product product[],int num)
{
	string P_name;
	double P_price;
	int P_Quantity,P_ID;
	
	cout<<"\nEnter new product's data:";
	cout<<"\nProduct Name:";
	getline(cin, P_name);
	cout<<"Product Price:";
	cin>>P_price;
	cout<<"Product Quantity:";
	cin>>P_Quantity;
	cout<<"Product ID: ";
	cin>>P_ID; 
	cin.ignore();
	cout<<endl;
}


//function for editing a product

void update(Product product[],int num,int product_id)
{
	bool Found=false;
		for (int i=0;i<num;i++)
	{
		if(product[i].P_ID==product_id)
		{
			cout<<"Proudct Found\n";
			display(product[i].P_name,product[i].P_price,product[i].P_Quantity,product[i].P_ID);
			Found=true;
			
		cout<<"Enter new Data of the product\n";
		cin.ignore();
		cout<<"New Name: ";
    	getline(cin, product[i].P_name);
	    cout<<"New Price: ";
	    cin>>product[i].P_price;
	    cout<<"New Quantity: ";
    	cin>>product[i].P_Quantity;
	    cout<<"New Product ID: ";
	    cin>>product[i].P_ID; 
	    cin.ignore();
    	cout<<endl;
		}
	}
	if (!Found)
    {
    	cout<<"Product not found\n";
    }
	
}


//function for finding a product

void search(Product product[],int num,int product_id)
{
	bool found=false;
	for (int i=0;i<num;i++)
	{
		if(product[i].P_ID==product_id)
		{
			cout<<"Proudct Found\n";
			display(product[i].P_name,product[i].P_price,product[i].P_Quantity,product[i].P_ID);
			found=true;
		}
	}
	if (!found)
    {
    	cout<<"Product not found\n";
    }
}

// main function
int main(){
	Product product[50];
	int num,choice,product_id;
    cout<<"number of products present\n";
    cin>>num;
    cin.ignore();
    
    cout<<"***********************************************************************\n\n"<<"Make Your Choice\n"<<"1.Display products\n"<<"2.Add a new product\n"<<"3.Edit a product\n"<<"4.Find a product ";
    cout<<"\n\n***********************************************************************\n\n";
    
    cin>>choice;
    cin.ignore();
    
    if (choice==1)
    {
      // Display all books
       cout << "Displaying the products:\n";
       for (int i=0;i<num;i++) 
	     {
          display(product[i].P_name,product[i].P_price,product[i].P_Quantity,product[i].P_ID);
         }
	}
	else if (choice==2)
	{
		addProduct(product,num);
	}
	else if (choice==3)
	{
		cout<<"Enter product ID you want to edit:\n";
		cin>>product_id;
		update(product,num,product_id);
	}
	
	else if (choice==4)
	{
	   	cout<<"Enter product ID you want to find:\n";
		cin>>product_id;
		search(product,num,product_id);	
	}
	else
	{
		cout<<"invalid input";
	}
    
	
}//end main
