/*
Name:S.Sara Ali
id:23k-0070
*/

#include<iostream>
using namespace std;

class Book{
	private:
	    string name;
	    string author;
	    int ISBN;
	    int totalpages;
	    int count;
	    int currentpagesread;
	    
	public:
		Book() {
			name="";
			author="";
			ISBN=0;
			totalpages=0;
			currentpagesread=0;
		}
		Book(string Name, string Author, int isbn, int Total, int read, int Count) {
			name=Name;
			author=Author;
			ISBN=isbn;
			totalpages=Total;
			count=Count;
			currentpagesread=read;
		}
		
		void UpdateRead(int pages) {
			currentpagesread+=pages;
			if(currentpagesread>=totalpages) {
				cout<<"book finished \n";
			} else {
				cout<<"pages read:"<<currentpagesread<<endl;
			}
		}
};

int main () {
	Book B1("harry potter","jk-rowling",234567,20,12,0);
	B1.UpdateRead(2);
	B1.UpdateRead(10);
	
	

	
	
	
}
