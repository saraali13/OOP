/*
Name:S.Sara Ali
ID: 23K-0070
*/

#include <iostream>
using namespace std;

class perimeter
{
    int length ;
    int breadth;
    
    public:
    perimeter(int l,int b):length(l),breadth(b)
	{}
	
    friend class printClass;
};

class printClass{
    public:
    void display(perimeter& p)
	{
        cout << "Length: " << p.length;
		cout << "\nBreadth: " << p.breadth << endl;
    }
};

int main()
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
    printClass PC1;
    perimeter per1(6,7);
    PC1.display(per1);
    return 0;

}
