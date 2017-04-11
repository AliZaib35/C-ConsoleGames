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
	for(i=70;i>10;i=i-1)
	{
		int color;
		gotoxy(i,0);
		cout<<"%";
		Sleep(10);
		color= rand()%15 + 1;
		setcolor(color);
	}
	for(i=0;i<40;i=i+1)
	{
		int color;
		gotoxy(10,i);
		cout<<"$";
		Sleep(20);
		color= rand()%15 + 1;
		setcolor(color);
	}
	for(i=11;i<71;i=i+1)
	{
		int color;
		gotoxy(i,40);
		cout<<"%";
		Sleep(10);
		color= rand()%15 + 1;
		setcolor(color);
	}
	for(i=40;i>=0;i=i-1)
	{
		int color;
		gotoxy(70,i);
		cout<<"$";
		Sleep(20);
		color= rand()%15 + 1;
		setcolor(color);
	}
}
void incre(int &x1,int &x2)
{
		if(x1==10)
		{
			x1=x1+1;
		}
		if(x1==9)
		{
			x1=x1+2;
		}
		if(x1==63)
		{
			x1=x1-1;
		}
		if(x1==64)
		{
			x1=x1-2;
		}
		if(x2==10)
		{
			x2=x2+1;
		}
		if(x2==9)
		{
			x2=x2+2;
		}
		if(x2==63)
		{
			x2=x2-1;
		}
		if(x2==64)
		{
			x2=x2-2;
		}
}
void count()
{
	int i;
	setcolor(13);
	for(i=10;i>0;i=i-1)
	{
		gotoxy(38,20);
		cout<<i;
		Sleep(250);
		gotoxy(37,20);
		cout<<"   ";
	}
}
int main()
{
	menu();
	unsigned seed=time(0);
	int color=14,color2=14;
	char box=176,box2=219;
	srand(seed);
	int i,x1=36,y1=2,x2=36,y2=38;		// xy1 = upper tray ;xy2= lower tray ;xy3 = ball; 
	int x3=x2+3,y3=y2-1;
	char flag1='u',flag2='l';
	
	char key='m';
	gotoxy(x3,y3);
	setcolor(6);
	cout<<"O";
	gotoxy(x1,y1);
	setcolor(color);
	cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
	gotoxy(x2,y2);
	setcolor(color);
	cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
	count();		//timer

	while(key!=32)
	{
		
		if(key=='d')
		{
				gotoxy(x1,y1);
				cout<<"        ";
				x1=x1+2;
				
				incre(x1,x2);
				gotoxy(x1,y1);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			
		}
		if(key=='a')
		{
			
				gotoxy(x1,y1);
				cout<<"        ";
				x1=x1-2;
				
				incre(x1,x2);
				gotoxy(x1,y1);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			
		}
		
		
		if(key=='l')
		{
				gotoxy(x2,y2);
				cout<<"        ";
				x2=x2+2;
				gotoxy(x3,y3);
				cout<<" ";
				setcolor(14);
				x3=x2+3;
				incre(x1,x2);
				gotoxy(x2,y2);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			
		}
		if(key=='j')
		{
				gotoxy(x2,y2);
				cout<<"        ";
				
				x2=x2-2;
				gotoxy(x3,y3);
				cout<<" ";
				setcolor(14);
				x3=x2+3;
				incre(x1,x2);
				gotoxy(x2,y2);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			
			
		}
		gotoxy(x3,y3);
		cout<<"O";
		key=_getch();
	}

	while(key!=27)
	{
		
		if(key=='d')
		{
				gotoxy(x1,y1);
				cout<<"        ";
				x1=x1+2;
				incre(x1,x2);
				gotoxy(x1,y1);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			
		}
		if(key=='a')
		{
			
				gotoxy(x1,y1);
				cout<<"        ";
				x1=x1-2;
				incre(x1,x2);
				gotoxy(x1,y1);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			
		}
		if(key=='l')
		{
				gotoxy(x2,y2);
				cout<<"        ";
				x2=x2+2;
				incre(x1,x2);
				gotoxy(x2,y2);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			
		}
		if(key=='j')
		{
				gotoxy(x2,y2);
				cout<<"        ";
				
				x2=x2-2;
				incre(x1,x2);
				gotoxy(x2,y2);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			
			
		}
		while(!_kbhit())
		{
			gotoxy(x3,y3);
			setcolor(color2);
			cout<<"O";
			Sleep(75);
			gotoxy(x3,y3);
			cout<<" ";
			if(x3==69)		// wall checking condition
			{
				flag2='l';
			}
			if(x3==11)
			{
				flag2='r';
			}
			
			if(y3==0 || y3==40)			//gameover condition
			{
				for(i=0;i<5;i=i+1)
				{
					gotoxy(25,20);
					cout<<"!!!!! G A M E  O V E R !!!!!";
					Sleep(500);
					gotoxy(25,10);
					cout<<"                            ";
					Sleep(500);
				}
				setcolor(14);
				gotoxy(25,20);
				cout<<"!!!!! G A M E  O V E R !!!!!";
				gotoxy(30,22);
				cout<<"R e t r y ?? (y/n)"; 
				char ret;cin>>ret;
				if(ret=='y'|| ret=='Y')
				{
					system("CLS");
					main();
				}
				exit(0);
			}
			if(flag1=='u')
			{
				y3 = y3 - 1;
			}
			if(flag1=='d')
			{
				y3 = y3 + 1;
			}
			if(flag2=='l')
			{
				x3 = x3 - 1;
			}
			if(flag2=='r')
			{
				x3 = x3 + 1;
			}
			if(y3==(y1 + 1) && x3>=x1 && x3<=x1+7) //bounce back for upper tray
			{
				color2= rand()%15 + 1;
				flag1='d';
			}
			if(y3==(y2 - 1) && x3>=x2 && x3<=x2+7)   //bounce back for upper tray
			{
				color2= rand()%15 + 1;
				flag1='u';
			}
			
	
		}
		
		key = _getch();
	}
}