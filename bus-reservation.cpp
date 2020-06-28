//C++ PROJECT
#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
using namespace std;
static int p=0;

class a{
	char busn[5],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	public:
		void install();
		void empty();
		void allotment();
		void show();
		void avail();
		
}
bus[10];                   //CREATES 10 ARRAY OBJECTS NAMED 'BUS'
void vline(char ch)        //THIS FUNC IS USED TO PRINT '*' AT THE BEGGINING AND END OF DISPLAYING THE DETAILS 
{
	for(int k;k<=80;k++)
	{
		cout<<ch;
	}
}
void a:: install()         //THIS FUNC. GETS DETAILS AND STORES THIS IN ARRAY OBJECT
{
	bus[10];
	cout<<"enter bus num:";
	cin>>bus[p].busn;
	cout<<"enter driver's name:";
	cin>>bus[p].driver;
	cout<<"enter arrival  time:";
	cin>>bus[p].arrival;
	cout<<"enter departure time:";
	cin>>bus[p].depart;
	cout<<"enter from location:";
	cin>>bus[p].from;
	cout<<"enter to location:";
	cin>>bus[p].to;
	bus[p].empty();
	p++;
}
void a::empty()
{
	bus[10];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"EMPTY");
		}
	}
}
void a::allotment()         //THIS FUNC.CHECKS WHETHER USER HAS ENTERED CORRECT BUS NUM. IF SO IT ASKS FOR SEAT CONFIRMATION AND PASSENGER'S NAME
{
	char number[5];
	cout<<"enter bus number:";
	cin>>number;
	int n;
	int seat;
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,  number)==0)
		break;
	}
	while(n<=p)
    {
		cout<<"enter seat num:";
		cin>>seat;
		if(seat>32)
		{
			cout<<"only 32 seats available";
		}
		else
		{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"EMPTY")==0)
			{
				cout<<"enter passenger's name:";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
			else
			{
				cout<<"the seat is already filled";
			}
		}
    }
    if(n>p)
    {
    	cout<<"enter correct num:";
	}
}
void a::show()             //THIS FUNC DISPLAY'S THE CONFIRMED SEAT BY PASSENGER
{
	char number[5];
	cout<<"enter a num:";
	cin>>number;
	int n;
	for(int n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busn,number)==0)
		{
			break;
		}
	}
	while(n<=p)
	{
		int a=1;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				a++;
				if(strcmp(bus[n].seat[i][j],"EMPTY")!=0)
				{
					cout<<"The seat \t"<<(a-1)<<"\t is booked for\t"<<seat[i][j];
					cout<<"Other than"<<(a-1)<<"th seat,remaining seats are available ";
				}
				
			}
		}
		break;
	}
	if(n>p)
	{
		cout<<"enter correct bus num:";
	}
}

void a::avail()          //THIS FUNC. SHOWS AVAILABLE AND SEAT BOOKED BUSES 
{
	for(int n=0;n<p;n++)
	{
		vline('*');
	    cout<<"\n\nBUS NUMBER:"<<bus[n].busn<<"\t\tDRIVER'S NAME:"<<bus[n].driver
	    
		<<"\t\tARRIVAL TIME:"<<bus[n].arrival<<"\t\tDEPARTURE TIME:"<<bus[n].depart
		
		<<"\t\tFROM PLACE:"<<bus[n].from<<"\t\tTO PLACE:"<<bus[n].to<<"\n";
		
	    vline('*');
	    vline('_');
	}
	
}
int main()
{
	system("cls");       //COMMANDS OS TO CLEAR SCREEN
	int w;
	//bus[10];
	while(1)
	{
		cout<<"\n\n\n\n";
		cout<<"1.Install \n"<<"2.Reservation \n"<<"3.Show \n"<<"4.Buses Available \n"<<"5.Exit \n";
		cout<<"enter your choice";
		cin>>w;
		switch(w)
		{
			case 1:bus[p].install();
			break;
			case 2:bus[p].allotment();
			break;
			case 3:bus[0].show();
			break;
			case 4:bus[0].avail();
			break;
			case 5:exit(0);
		}
	}
	return 0;
}









