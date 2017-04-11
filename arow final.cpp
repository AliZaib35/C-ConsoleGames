#include <iostream>
#include <windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
void setcolor(unsigned int color) 
{                                    
    if (color >15 || color <=0)
    {
        cout <<"Error" <<endl;
        
    }
    else
    {    
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hcon,color);
    }
}
void menu()
{
	int i;
	char ch1='%',ch2=178;
	for(i=79;i>=0;i=i-1)
	{
		int color;
		gotoxy(i,0);
		cout<<ch1;
		Sleep(10);
		color= rand()%15 + 1;
		setcolor(color);
	}
	for(i=1;i<=23;i=i+1)
	{
		int color;
		gotoxy(0,i);
		cout<<ch2;
		Sleep(20);
		color= rand()%15 + 1;
		setcolor(color);
	}
	for(i=0;i<79;i=i+1)
	{
		int color;
		gotoxy(i,24);
		cout<<(ch1);
		Sleep(10);
		color= rand()%15 + 1;
		setcolor(color);
	}
	for(i=23;i>0;i=i-1)
	{
		int color;
		gotoxy(79,i);
		cout<<ch2;
		Sleep(20);
		color= rand()%15 + 1;
		setcolor(color);
	}

	for(i=1;i<24;i=i+1)
	{
		if(i%2==0)
		{
			setcolor(10);
		}
		else
		{
			setcolor(6);
		}
		gotoxy(20,i);
		cout<<"|";
		Sleep(100);
	}
}

void we(int x,int y)
{
	char ch=178,ch2=16;
	setcolor(14);

	gotoxy(x,y);
	cout<<"(";
	setcolor(10);
	cout<<",";
	setcolor(12);
	cout<<"\"";
	setcolor(14);
	cout<<")";

	gotoxy(x-1,y+1);
	cout<<"_/|";
	setcolor(9);
	cout<<ch;
	setcolor(14);
	cout<<"|>";
	setcolor(9);
	cout<<"---";
	setcolor(12);
	cout<<ch2;
	setcolor(14);
	
	gotoxy(x,y+2);
	cout<<"_| \\_"<<endl;

}
int target(int slade1)
{
	int i,slade2=slade1+1,slade3=slade2+1,slade4=slade3+1,slade5=slade4+1;
	char ch1=219,ch2=178,ch3=177,ch4=176,ch5=219;

	setcolor(6);
	for(i=0;i<9;i=i+1)
	{
		gotoxy(77,slade1);
		cout<<ch1;
		slade1=slade1+1;
	}

	setcolor(13);
	for(i=0;i<7;i=i+1)
	{
		gotoxy(76,slade2);
		cout<<ch2;
		slade2=slade2+1;
	}

	setcolor(9);
	for(i=0;i<5;i=i+1)
	{
		gotoxy(75,slade3);
		cout<<ch3;
		slade3=slade3+1;
	}

	setcolor(12);
	for(i=0;i<3;i=i+1)
	{
		gotoxy(74,slade4);
		cout<<ch4;
		slade4=slade4+1;
	}
	setcolor(14);
	gotoxy(73,slade5);
	cout<<ch5;
	return slade5;
}
void remtarget(int slade1)
{
	int i,slade2=slade1+1,slade3=slade2+1,slade4=slade3+1,slade5=slade4+1;
	for(i=0;i<9;i=i+1)
	{
		gotoxy(77,slade1);
		cout<<" ";
		slade1=slade1+1;
	}

	for(i=0;i<7;i=i+1)
	{
		gotoxy(76,slade2);
		cout<<" ";
		slade2=slade2+1;
	}

	
	for(i=0;i<5;i=i+1)
	{
		gotoxy(75,slade3);
		cout<<" ";
		slade3=slade3+1;
	}

	for(i=0;i<3;i=i+1)
	{
		gotoxy(74,slade4);
		cout<<" ";
		slade4=slade4+1;
	}
	
	gotoxy(73,slade5);
	cout<<" ";
}
int movetarget(int &i,int &flag1)
{
		int slade5;
		slade5=target(i);
		Sleep(100);
		remtarget(i);
		if(i==15)
		{
			flag1=1;
		}
		if(i==1)
		{
			flag1=0;
		}
		if(flag1==0)
		{
			i=i+1;
		}
		else
		{
			i=i-1;
		}
		return slade5;
}
void movearrow( int &i,int &flag1)
{
	int x=8;
	char ch=16,n=0;
	int slade5;
	while(n!=1)
	{
		slade5=movetarget(i,flag1);
		gotoxy(x,11);
		cout<<"    ";
		x=x+1;
		gotoxy(x,11);
		setcolor(12);
		cout<<"---";
		setcolor(9);
		cout<<ch;
		if(x==71 && slade5==11)
		{
			target(i);
			Sleep(3000);
			n=1;
		}
	
		if(x==72 && (slade5-1)==11 )
		{
			target(i);
			Sleep(3000);
			n=1;
		}
		
		if(x==72 && (slade5+1)==11 )
		{
			target(i);
			Sleep(3000);
			n=1;
		}
		
		if(x==73 && (slade5-2)==11 )
		{
			target(i);
			Sleep(3000);
			n=1;
		}
		if(x==73 && (slade5+2)==11 )
		{
			target(i);
			Sleep(3000);
			n=1;
		}
	
		if(x==74 && (slade5-3)==11 )
		{
			target(i);
			Sleep(3000);
			n=1;
		}
		
		if(x==74 && (slade5+3)==11 )
		{
			target(i);
			Sleep(3000);
			n=1;
		}
		if(x==75 && (slade5-4)==11)
		{
			target(i);
			Sleep(3000);
			n=1;
		}
		if(x==75 && (slade5+4)==11)
		{
			target(i);
			Sleep(3000);
			n=1;
		}
		if(x==76)
		{
			target(i);
			Sleep(3000);
			n=1;
		}
	}
}
int main()
{
	menu();
	we(3,10);
	we(8,3);
	we(8,16);
	we(22,1);
	we(22,21);
	int i=2,flag1=0;
	char key;
	do
	{
		while(!_kbhit())
		{
			movetarget(i,flag1);
		}
		key=_getch();	
	}
	while(key!=32);
	movearrow(i,flag1);
	
}