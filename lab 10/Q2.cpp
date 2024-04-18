/*
Name:S.Sara Ali
ID:23K-0070
*/

#include <iostream>
using namespace std;

class Num
{
	private:
		int n;
		public:
		Num(int a)
		{
			n=a;
		}
		Num operator--()//prefix
		{
			Num pro(0);
			pro.n=4*n;
			return pro;
		}
		Num operator--(int)//postfix
		{
			Num rem(0);
			rem.n=n/4;

			return rem;
		}
		void display(){
			cout<<"The value is: "<<n<<endl;
		}
};

int main()
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
  
	Num n1(16),n2(8);
	Num n3=n1--;
	Num n4=--n2;
	n3.display();//postfix
	n4.display();//prefix

	return 0;
}
