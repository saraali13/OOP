/*
Name:S.Sara Ali
ID:23K-0070
*/

#include<iostream>
using namespace std;

//inline function for calulating batting average
inline double battingAverage(int totalRuns, int dismissed)
{
	double Avg;
	Avg = totalRuns/dismissed;
	return Avg;
}//

//inline function for calculating the strike rate
inline int strikeRate(int totalRuns, int totalBalls)
{
	int stRate;
	stRate = (totalRuns/totalBalls)*100;
	return stRate;
}//

// main function
int main()
{
	cout<<"Name:S.Sara Ali\nID:23K-0070\n\n";
	
	int Runs;//total runs
	int Balls;//total balls
	int Dis;//players dismissed
	double Average;
	int StrikeRate;
	
	cout<<"Enter total number of balls,total runs and number of players dismissed\n\n";
	cout<<"Total number of balls:";
	cin>>Balls;
	cout<<"Total number of runs:";
	cin>>Runs;
	cout<<"Total number of player dismissed:";
	cin>>Dis;

    // inline function calling
    
	Average=battingAverage(Runs,Dis);
	StrikeRate=strikeRate(Runs,Balls);
	
	cout<<"Batting average: "<<Average<<endl;
	cout<<"Strike rate: "<<StrikeRate<<endl;

    return 1;
    
}//end main
