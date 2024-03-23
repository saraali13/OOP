/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;


//base class : Book class
class Book 
{
	protected:

    	string Title;
    	string Author;
    	string Publisher;

	public:

    //parameterized constructor
    Book(string Title, string Author, string Publisher)
        : Title(Title), Author(Author), Publisher(Publisher) 
		{}

    //function for displaying the data of the book
    void display() const
	{
    	cout<<"Data of the book\n";
        cout<<"Title: "<<Title;
        cout<<"\nAuthor: "<<Author;
        cout<<"\nPublisher: "<<Publisher<<endl;
    }//

};// end book class

//derived class : Fiction book class
class FictionBook : public Book //inherited in public mode
{
	private:

    	string Genre;
    	string Protagonist;

	public:

    	//parameterized constructor
    	FictionBook(string Title, string Author, string Publisher, string Genre, string Protagonist)
        : Book(Title, Author, Publisher), Genre(Genre), Protagonist(Protagonist) {}

    //function for displaying previous data + new data of the book fictional book
    void display() const 
	{
        Book::display();//for displaying previous data
        cout<<"Genre: "<<Genre<<endl;
        cout<<"Protagonist: "<<Protagonist<<endl;
    }//
    
};// end finction book class

// main function
int main() 
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
	
    FictionBook book("The Kite Runner", "Khaled Hosseini", "Riverhead Books", "Bildungsromans", "Amir");
    book.display();

    return 0;
}
