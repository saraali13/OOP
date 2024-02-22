/*
Name:S. Sara Ali
ID:23k-0070
*/

#include<iostream>
using namespace std;

class Book
{
	private:
	    string name;
	    string author;
	    string ISBN;
	    int totalpages;
	    int currentpagesread;
	    
	public:
		//default constructor
		book() 
		{
			name="";
			author="";
			ISBN="";
			totalpages=1300;
			currentpagesread=0;
		}
		
		
	//setter functions
		
		void setName(string Name)
		{
			name=Name;
		}
		
		void setAuthor(string Author)
		{
			author=Author;
		}
		
		void setIsbn(string isbn) 
		{
		
		
			ISBN=isbn;
		}
		
		
	//function to update the number of pages read and to check if the book is finished
	
		void UpdateRead() 
		{
			if(currentpagesread<=totalpages) 
			{
				currentpagesread++;
				cout<<"you have read the page "<< currentpagesread<<endl;
			} 
			else 
			{
				cout<<"book is finished\n";
			}
		}// end update read
		
		
	//function to display all the details of the books
	
		void showInfo() 
		{   cout<<"\n\nDisplaying the all the details of the book \n";
            cout<<"\nName: "<<name;
            cout<<"\nAuthor: "<<author;
            cout<<"\nISBN: "<<ISBN;
            cout<<"\nTotal Pages: "<<totalpages;
            cout<<"\nPages Read: "<<currentpagesread<<endl;
        }// end show info
};
//end class


//main function

int main () 
{
	Book book1;
	
	book1.setName("Harry-potter");
	book1.setAuthor("robert browning");
	book1.setIsbn("17784567");
	
	book1.UpdateRead();
	book1.UpdateRead();
	book1.showInfo();	
}// end main
