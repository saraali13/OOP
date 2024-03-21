/*
Name:S.Sara Ali
ID:23K-0070
*/

#include<iostream>
using namespace std;

//image class
class Image{
	private:
		int width;
		int height;
		int* imgData;
		
	public:
		Image(double width, double height, int* imgData)//parameterized constructor
		{
			this->width = width;
			this->height =height;
			
			int size = width*height;
			this->imgData = new int[size];//DMA
			for(int i =0; i<size; i++)
			{
				this->imgData[i] = imgData[i];
			}
		}//
		
		//copy constructor
		Image(Image& Img)
		{
			this->width = Img.width;
			this->height = Img.height;
			
			int size = width*height;
			imgData = new int[size];
			
			for(int i =0; i<size; i++)
			{
				imgData[i] = Img.imgData[i];			
			}
		}//
		
		~Image()//destructor
		{
			delete[] imgData;
		}//
		
		void display()//Function for displaying image data
		{
			cout<<"Image Data: \n";
			for(int i =0; i<width*height; i++)
			{
				cout<<imgData[i]<<" ,";
				if((i+1)%width==0)
				{
					cout<<endl;
				}
			}
		}//end display
		
		void updateData()//Function for updating image data
		{
			for(int i =0; i<width*height; i++)
			{
				if(imgData[i]<=0)
				{
					imgData[i]=rand()%255+1;
				}
			}
		}//end update
		
};// end class

//main function
int main()
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
	int imgData[] = {10,56,63,28};
	Image Img1(4,2 ,imgData);
	Image Img2 = Img1;
	//orignal data
	cout<<"Data of Original Image:\n";
	Img1.display();
	cout<<"\nDataof Copied image:\n";
	Img2.display();
	//updated data
	Img2.updateData();
	cout<<"\nUpdated data of original image:\n";
	Img1.display();
	cout<<"\nUpdated data of copyied image:\n";
	Img2.display();
	
	return 0;
}// end
