/*
Name:S. Sara Ali
ID:23K-0070
*/

#include<iostream>
using namespace std;


class SmartPhone 
{

	private:
	    string Brand;
	    string Model;
	    int Resolution;
	    int Ram;
	    int Rom;
	    int Storage;
	    
	public:

// setter functions
		void setBrand(string brand) 
		{
			Brand=brand;
		}
		void setModel(string model) 
		{
			Model=model;
		}
		void setResolution(int resolution) 
		{
			Resolution=resolution;
		}
		void setRam(int ram)
		{
			Ram=ram;
		}
		void setRom(int rom) 
		{
			Rom=rom;
		}
		void setStorage(int storage) 
		{
			Storage=storage;
		}
		
// getter funtions
		string getBrand() 
		{
			return Brand;
		}
		string getModel() 
		{
			return Model;
		}
		int getResolution() 
		{
			return Resolution;
		}
		int getRam() 
		{
			return Ram;
		}
		int getRom() 
		{
			return Rom;
		}
		int getStorage() 
		{
			return Storage;
		}
		
		void call(string Cont_num) 
		{
			cout<<"\ndialing call to: "<<Cont_num;
		}
		
		void message(string Cont_name) 
		{
			cout<<"\nsendig message to: "<<Cont_name;
		}
		
		void WIFI(string network) {
			cout<<"\nconnecting to wifi: "<<network;
		}
		
		void internet(string search) {
			cout<<"\nbrowsing the internet for the webpage: "<<search<<endl;
		}
		
};

int main() 
{
	
	SmartPhone Phone;
//setting values 
	Phone.setBrand("SamSung");
	Phone.setModel("S24 ultra");
	Phone.setResolution(3456);
	Phone.setRam(12);
	Phone.setRom(256);
	Phone.setStorage(512);
	
//getting the data 
	cout<<"the data of the phone:\n";
	cout<<"\nBrand: ";
	cout<<Phone.getBrand();
	cout<<"\nModel: ";
	cout<<Phone.getModel();
	cout<<"\nResolution: ";
	cout<<Phone.getResolution();
	cout<<"\nRAM: ";
	cout<<Phone.getRam();
	cout<<"\nROM: ";
	cout<<Phone.getRom();
	cout<<"\nStorage: ";
	cout<<Phone.getStorage()<<endl;
//
	Phone.call("098876554");
	Phone.message("Sakina");
	Phone.WIFI("Internet");
	Phone.internet("Instagram");
	
}// end main function
