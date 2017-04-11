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

int flag=1,arr[10];

void display(int val,int flag);
void p1_vic();
void p2_vic();
void menu()
{
	int i,x1=20,y1=2;
	
	for(i=0;i<40;i=i+1)
	{
		if(i%2==0)
		{
			setcolor(14);
		}
		else
		{
			setcolor(10);
		}
		gotoxy(x1,8);
		cout<<"-";
		gotoxy(x1,15);
		cout<<"-";
		
		if(i%2==0)
		{
			if(y1%2==0)
			{
				setcolor(14);
			}
			else
			{
				setcolor(10);
			}
			gotoxy(32,y1);
			cout<<"|";
			gotoxy(47,y1);
			cout<<"|";
			y1=y1+1;
		}

		Sleep(50);
		
		x1=x1+1;
	}
	setcolor(11);
	gotoxy(25,5);
	cout<<"1";
	gotoxy(40,5);
	cout<<"2";
	gotoxy(55,5);
	cout<<"3";

	gotoxy(25,12);
	cout<<"4";
	gotoxy(40,12);
	cout<<"5";
	gotoxy(55,12);
	cout<<"6";

	gotoxy(25,19);
	cout<<"7";
	gotoxy(40,19);
	cout<<"8";
	gotoxy(55,19);
	cout<<"9";
}
void tik(int x,int y)
{
	setcolor(12);
	gotoxy(x,y);
	cout<<" ";
	Sleep(50);
	gotoxy(x-2,y);
	cout<<"*";
	Sleep(50);
	gotoxy(x-1,y+1);
	cout<<"*";
	Sleep(50);
	gotoxy(x+1,y);
	cout<<"*";
	Sleep(50);
	gotoxy(x+3,y-1);
	cout<<"*";
	Sleep(50);
	gotoxy(x+5,y-2);
	cout<<"*";
}

void cross(int x,int y)
{
	
	setcolor(14);

	gotoxy(x-2,y-2);
	cout<<"*";
	Sleep(50);

	gotoxy(x-1,y-1);
	cout<<"*";
	Sleep(50);

	gotoxy(x,y);
	cout<<"*";
	Sleep(50);
	gotoxy(x+1,y+1);
	cout<<"*";
	Sleep(50);

	gotoxy(x+2,y+2);
	cout<<"*";
	Sleep(50);
	
	gotoxy(x+2,y-2);
	cout<<"*";
	Sleep(50);

	gotoxy(x+1,y-1);
	cout<<"*";
	Sleep(50);

	gotoxy(x-1,y+1);
	cout<<"*";
	Sleep(50);
	gotoxy(x-2,y+2);
	cout<<"*";
	Sleep(50);
}
void display(int val,int flag)
{
	int x,y;
	if(val=='1')
	{
		x=25;
		y=5;
		if(flag==1)
		{
			arr[1] = 1;
		}
		else
		{
			arr[1] = 2;
		}
	}

	if(val=='2')
	{
		x=40;
		y=5;
		if(flag==1)
		{
			arr[2] = 1;
		}
		else
		{
			arr[2] = 2;
		}
	}

	if(val=='3')
	{
		x=55;
		y=5;
		if(flag==1)
		{
			arr[3] = 1;
		}
		else
		{
			arr[3] = 2;
		}
	}

	if(val=='4')
	{
		x=25;
		y=12;
		if(flag==1)
		{
			arr[4] = 1;
		}
		else
		{
			arr[4] = 2;
		}
	}
	if(val=='5')
	{
		x=40;
		y=12;
		if(flag==1)
		{
			arr[5] = 1;
		}
		else
		{
			arr[5] = 2;
		}
	}
	if(val=='6')
	{
		x=55;
		y=12;
		if(flag==1)
		{
			arr[6] = 1;
		}
		else
		{
			arr[6] = 2;
		}
	}

	if(val=='7')
	{
		x=25;
		y=19;
		if(flag==1)
		{
			arr[7] = 1;
		}
		else
		{
			arr[7] = 2;
		}
	}
	if(val=='8')
	{
		x=40;
		y=19;
		if(flag==1)
		{
			arr[8] = 1;
		}
		else
		{
			arr[8] = 2;
		}
	}
	if(val=='9')
	{
		x=55;
		y=19;
		if(flag==1)
		{
			arr[9] = 1;
		}
		else
		{
			arr[9] = 2;
		}
	}
	if(flag==1)
	{
		tik(x,y);
	}
	else
	{
		cross(x,y);
	}

;}

void p1_vic()
{
	gotoxy(30,5);
	setcolor(12);
	cout<<"-: pLaYeR 1 wOn :-";
	Sleep(2000);
	exit(0);
}
void p2_vic()
{
	gotoxy(30,5);
	setcolor(14);
	cout<<"-: pLaYeR 2 wOn :-";
	Sleep(2000);
	exit(0);
}
void conditon()
{
	if(arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==1)
	{
			p1_vic();
	}
	else if(arr[7]==arr[8] && arr[8]==arr[9] && arr[9]==1)
	{
			p1_vic();
	}
	else if(arr[4]==arr[5] && arr[5]==arr[6] && arr[6]==1)
	{
			p1_vic();	
	}
	else if(arr[1]==arr[4] && arr[4]==arr[7] && arr[7]==1)
	{
			p1_vic();
	}
	else if(arr[2]==arr[5] && arr[5]==arr[8] && arr[8]==1)
	{
		p1_vic();
	}
	else if(arr[3]==arr[6] && arr[6]==arr[9] && arr[9]==1)
	{
			p1_vic();
	}
	else if(arr[1]==arr[5] && arr[5]==arr[9] && arr[9]==1)
	{
			p1_vic();	
	}
	else if(arr[3]==arr[5] && arr[5]==arr[7] && arr[7]==1)
	{
			p1_vic();	
	}


	if(arr[1]==arr[2] && arr[2]==arr[3] && arr[3]==2)
	{
			p2_vic();
	}
	else if(arr[7]==arr[8] && arr[8]==arr[9] && arr[9]==2)
	{
			p2_vic();
	}
	else if(arr[4]==arr[5] && arr[5]==arr[6] && arr[6]==2)
	{
			p2_vic();	
	}
	else if(arr[1]==arr[4] && arr[4]==arr[7] && arr[7]==2)
	{
			p2_vic();
	}
	else if(arr[2]==arr[5] && arr[5]==arr[8] && arr[8]==2)
	{
		p2_vic();
	}
	else if(arr[3]==arr[6] && arr[6]==arr[9] && arr[9]==2)
	{
			p2_vic();
	}
	else if(arr[1]==arr[5] && arr[5]==arr[9] && arr[9]==2)
	{
			p2_vic();	
	}
	else if(arr[3]==arr[5] && arr[5]==arr[7] && arr[7]==2)
	{
			p2_vic();	
	}
}
int main()
{
	for(int i=1;i<10;i=i+1)
	{
		arr[i]=10;
	}
	menu();
	
	char val=65,ch=178;
	for(int i=1;i<10;i=i+1)
	{	
		if(i%2==1)
		{
			setcolor(12);
			gotoxy(0,10);
			cout<<"-:  Player 1 : -"<<endl<<endl;
			setcolor(14);
			cout<<" "<<ch;
			setcolor(12);
			cout<<" Enter UR choice:-";
			gotoxy(8,14);
			Sleep(1000);
			val=_getch();
			while(arr[val]==10)	//(val>'9' || val <'0') && 
			{
				gotoxy(8,14);
				cout<<" ";
				gotoxy(8,14);
				val=_getche();
			}
				Sleep(1000);
				gotoxy(8,14);
				cout<<" ";
			flag=1;
		}
		else
		{
			setcolor(14);
			gotoxy(0,10);
			cout<<"-:  Player 2 : -"<<endl<<endl;
			setcolor(12);
			cout<<" "<<ch;
			setcolor(14);
			cout<<" Enter UR choice:-";
			gotoxy(8,14);
			Sleep(1000);
			val=_getch();
			while(arr[val]==10)
			{
				gotoxy(8,14);
				cout<<" ";
				gotoxy(8,14);
				val=_getche();
			}
				Sleep(1000);
				gotoxy(8,14);
				cout<<" ";
				flag=2;
		}
		display(val,flag);
		conditon();

			
	}

	return 0;
}
