/*
Name:S. Sara Ali
Roll.no:23K-0070
Des: to write a c++ program to handle a library’s book inventory
*/


#include <iostream>
#include <string>
using namespace std;

//structure for books
struct Book 
   {
    string title;
    string author;
    int year;
    string genre;
    };


//function for displaying the data of the book

   void display(const string& title, const string& author, int year, const string& genre) 
   {
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nYear: " << year;
        cout << "\nGenre: " << genre <<endl;
    }


//function for adding data of a new book

void addBook(Book books[],int& num_books) 
   {
   	
    string title, author, genre;
    int year;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book year of publication: ";
    cin >> year;
    cin.ignore();
    cout << "Enter book genre: ";
    getline(cin, genre);

  }

// function for editing data of a book

void editBook(Book books[], int num_books, const string& name_1) 
   {
       bool Found = false;
       
    for (int i = 0; i < num_books; ++i) 
	  {
        if (books[i].title == name_1) 
		    {
                cout << "Enter new title:\n";
                getline(cin, books[i].title);
                cout << "Enter new author:\n";
                getline(cin, books[i].author);
                cout << "Enter new year:\n";
                cin >> books[i].year;
                cin.ignore();
                cout << "Enter new genre:\n";
                getline(cin, books[i].genre);

            }
      }
    if (!Found) 
		{
        cout << "Book not found" << endl;
        }
  }
  
  
//function for finding a book

void findBook(const Book book[], int size, const string& name_2) 
   {
       bool found = false;
       
       for (int i = 0; i < size; ++i) 
	    {
         if (book[i].title == name_2 || book[i].author == name_2) {
            display(book[i].title, book[i].author, book[i].year, book[i].genre);
            found = true;
            }
        }
        if (!found) 
		{
        cout << "Book not found" << endl;
        }
  }
  
// main function

int main() {
	
	Book books[100];
    int num_books,choice;
    cout<<"number of books present\n";
    cin>>num_books;
    cin.ignore();
    
    cout<<"***********************************************************************\n\n"<<"Make Your Choice\n"<<"1.Display books\n"<<"2.Add a book\n"<<"3.Edit a book\n"<<"4.Find a book ";
    cout<<"\n\n***********************************************************************\n\n";
    
    cin>>choice;
    cin.ignore();
    
if (choice==1)
   {
     // Display all books
      cout << "Displaying the books:\n";
      for (int i=0;i<num_books;i++) 
	     {
          display(books[i].title, books[i].author,books[i].year, books[i].genre);
         }
   }
else if (choice==2)
   {    
     //Adding a book
   	    addBook(books,num_books);
   }
else if (choice==3)
{      
    //editing a book
	   string name_1;
       cout << "\nEnter book's title you want to edit ";
       getline(cin, name_1);
       editBook(books, num_books, name_1);
}
else if (choice==4)
    {
       // Finding a book
       string name_2;
       cout << "\nEnter title or author to search: ";
       getline(cin, name_2);
       findBook(books, num_books, name_2);
    }

else 
    {
	cout<<"invalid input";
    }
    return 0;
}// end main
