/*
Name:S.Sara Ali
ID:23k-0070
*/

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class rollerCoaster
{
	private:
		
	    string Name;
	    float Height;
	    float Length;
	    float Speed;
	    int Capacity;
	    int CurrentRiders;
	    bool RideInProgress;
	    
	public:
		
	//default constructor
		rollerCoaster() : Name("roller coaster"), Height(300), Length(1000), Speed(20), Capacity(10), CurrentRiders(0), RideInProgress(false) 
		{}
		
	//parameterized constructor
		rollerCoaster(string name, float height, float length, float speed, int capacity, int num_riders) {
			Name=name;
			Height=height;
			Length=length;
			Speed=speed;
			
			if(capacity>3) 
			{
				if(capacity%2==0 || capacity%3==0)
				{
					Capacity=capacity;
				} else
				{
					 Capacity = ((capacity + 1) / 2) * 2;
				}
			}
			else 
			{
				cout<<"Minimum limit not reached\n";
			}
			CurrentRiders=num_riders;
		}
		
	//setter functions
	
		void setName(string name) 
		{
			Name=name;
		}
		
		void setHeight(float height) 
		{
			Height=height;
		}
		
		void setLength(float length) 
		{
			Length=length;
		}
		
		void setSpeed(float speed) 
		{
			Speed=speed;
		}
		
		void setCapacity(int capacity) 
		{
			if(capacity>3) 
			{
				if(capacity%2==0 || capacity%3==0)
				{
					Capacity=capacity;
				} 
				else
				{
					 Capacity = ((capacity + 1) / 2) * 2;;
				}
			}
			else 
			{
				cout<<"Minimum limit not yet exceeded"<<endl;
			}
		}
		
		void setCurrentRiders(int num_riders) 
		{
			CurrentRiders=num_riders;
		}
		void setFlag(bool flag) 
		{
			RideInProgress=flag;
		}
		
	//getter functions
	
		string getName() 
		{
			return Name;
		}
		
		float getHeight() 
		{
			return Height;
		}
		
		float getLength() 
		{
			return Length;
		}
		
		float getSpeed() 
		{
			return Speed;
		}
		
		int getCapacity() 
		{
			return Capacity;
		}
		
		int getCurrentRiders() 
		{
			return CurrentRiders;
		}
		
		bool getFlag() 
		{
			return RideInProgress;
		}
		
	//function for loading riders 
		int LoadRiders(int numRiders) 
		{
            if (!RideInProgress && numRiders<=(Capacity-CurrentRiders)) 
			{
                CurrentRiders=CurrentRiders+numRiders;
                return 0;
            } 
			else 
			{
                int remainingRiders = numRiders - (Capacity - CurrentRiders);              
				CurrentRiders=Capacity;
                return remainingRiders;
            }
        }
        
    //fuction for starting a ride    
        int StartRide() 
		{
            if (!RideInProgress) 
			{
                if(CurrentRiders==Capacity) 
				{
                    RideInProgress=true;
                    return 0; // ride started
                } 
				else 
				{
                    return Capacity - CurrentRiders;// no of empty seats
                }
            } 
			else 
			{
                return -1;//ride in progress
            }
        }   
  
    // function for stopping a ride    
        void StopRide() 
		{
            if (RideInProgress) 
			{
                RideInProgress = false;
                cout<<"Ride stopped\n";
            }
        }
           
    //function for unloading riders from a ride    
        void UnloadRiders() 
		{
        	if(!RideInProgress) 
			{
			    CurrentRiders = 0;
				cout<<"Ride unloaded\n"<<endl;	
			}
        }
        
    //function to accelerate the ride
        void Accelerate(int speed) 
		{
        	int num;
        	while(speed!=0) 
			{
        		num=speed%10;
        		if(num!=0) 
				{
        		    Speed=Speed+num;
        		    cout<<"Speed is accelerated to "<<speed<<endl;
        		    break;
			    } 
				else
				{
			    	speed=speed/10;
				}   
			}
		}
		
	//function for applying brake
		void Brake(int speed) 
		{
        	int num;
        	while(speed!=0) 
			{
        		num=speed%10;
        		if(num!=0) 
				{
        		    Speed=Speed-num;
        		    cout<<"Speed is slowed down to "<<speed<<endl;
        		    break;
			    } 
				else
				{
			    	speed=speed/10;
				}   
			}
		}
		
};// end class rollercoaster

//main function
int main() 
{
	cout<<"Name:S.Sara Ali\n";
	cout<<"ID:23k-0070\n\n";
	
	rollerCoaster roller_Coaster1; 
    rollerCoaster roller_Coaster2("life roll", 400, 1500, 50, 70, 60); 

    cout<<"Roller Coaster 1 Details:\n";
    cout<<"\nName: " <<roller_Coaster1.getName();
    cout<<"\nHeight: " <<roller_Coaster1.getHeight();
    cout<<"\nLength: " << roller_Coaster1.getLength();
    cout<<"\nSpeed: " << roller_Coaster1.getSpeed();
    cout<<"\nCapacity: " << roller_Coaster1.getCapacity();
    cout<<"\nCurrent riders: "<<roller_Coaster1.getCurrentRiders()<<endl;
    cout<<endl;
    cout<<"Roller Coaster 2 Details:\n";
    cout<<"\nName: " << roller_Coaster2.getName();
    cout<<"\nHeight: " << roller_Coaster2.getHeight();
    cout<<"\nLength: " << roller_Coaster2.getLength();
    cout<<"\nSpeed: " << roller_Coaster2.getSpeed();
    cout<<"\nCapacity: " << roller_Coaster2.getCapacity();
    cout<<"\nCurrent riders: "<<roller_Coaster2.getCurrentRiders()<<endl;
    cout<<endl;
    cout<<"Roller coaster # 2\n";
    if(roller_Coaster2.LoadRiders(10)==0) 
	{
    	cout<<"All riders seated\n";
	} else 
	{
		cout<<"Remaining number of riders are: "<<roller_Coaster2.LoadRiders(10)<<endl;
	}
    roller_Coaster2.LoadRiders(10);
    roller_Coaster2.StartRide();
    roller_Coaster2.Accelerate(230070);
    roller_Coaster2.Brake(230070);
    roller_Coaster2.StopRide();
    roller_Coaster2.UnloadRiders();

    return 0;
	
}//end main
