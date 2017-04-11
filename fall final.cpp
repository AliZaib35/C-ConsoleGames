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
int main()
{
	unsigned seed=time(0);
	srand(seed);
	char key,ch=219,name[20];
	int i,j=1,y[5],num[5],flag[4]={0,0,0,0},n=10,color[5],dead,q=0,w=0,score=100,time=0,lives=3,delay=100,level=0;
	y[0]=23;
	y[1]=23;
	y[2]=23;
	y[3]=23;
	y[4]=23;
	num[0]=(rand()%7*5) + 20;
	num[1]=(rand()%7*5) + 20;
	num[2]=(rand()%7*5) + 20;
	num[3]=(rand()%7*5) + 20;
	num[4]=(rand()%7*5) + 20;
	color[0]=(rand()%14)+1;
	color[1]=(rand()%14)+1;
	color[2]=(rand()%14)+1;
	color[3]=(rand()%14)+1;
	color[4]=(rand()%14)+1;
	dead=(rand()%14)+1;

	int xO=40,yO=1;
	setcolor(12);
	gotoxy(30,10);
	cout<<"Enter your name :-  ";
	gotoxy(30,12);
	cout<<"\t\t\t";
	setcolor(14);
	cin>>name;
	system("CLS");
	gotoxy(2,5);
	setcolor(14);
	cout<<"* Player :-";
	gotoxy(5,7);
	setcolor(12);
	cout<<name;
	gotoxy(2,10);
	setcolor(14);
	cout<<"* Lives :-";
	gotoxy(5,12);
	setcolor(12);
	cout<<lives;
	setcolor(14);
	gotoxy(65,10);
	cout<<"* LeVeL :-";
	setcolor(12);
	gotoxy(72,12);
	cout<<level;

	while(lives!=0)
	{
		
		while(!_kbhit())
		{
			setcolor(12);
			gotoxy(xO,yO);
			cout<<"O";
			setcolor(color[0]);
			gotoxy(num[0],y[0]);
			cout<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch;
			if(flag[0]==1)
			{
			
				setcolor(color[1]);
				gotoxy(num[1],y[1]);
				cout<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch;
			}
			if(flag[1]==1)
			{
				
				setcolor(color[2]);
				gotoxy(num[2],y[2]);
				cout<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch;
			}
			if(flag[2]==1)
			{
				
				setcolor(color[3]);
				gotoxy(num[3],y[3]);
				cout<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch;
			}
			if(flag[3]==1)
			{
			
				setcolor(color[4]);
				gotoxy(num[4],y[4]);
				cout<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch<<ch;
			}
			setcolor(14);
			gotoxy(65,5);
			cout<<"* Score :-";
			setcolor(12);
			gotoxy(72,7);
			cout<<score;
			for(i=0;i<=24;i=i+1)		//display boundary
			{
				if(i%2==0)
				{
					setcolor(11);
				}
				else
				{
					setcolor(9);
				}
				gotoxy(19,i);
				cout<<ch;
				gotoxy(60,i);
				cout<<ch;	
			}
			Sleep(delay);
			for(int i=20;i<60;i=i+1)
			{
				dead=(rand()%14)+1;
				setcolor(dead);
				gotoxy(i,0);
				cout<<"%";

				gotoxy(i,24);
				cout<<"%";
			}
			for(i=0;i<=24;i=i+1)
			{
				if(i%2==1)
				{
					setcolor(11);
				}
				else
				{
					setcolor(9);
				}
				gotoxy(19,i);
				cout<<ch;
				gotoxy(60,i);
				cout<<ch;
			}
			Sleep(delay);
			time=time+100;
			if(time%1000==0)
			{
				score=score+100;
			}
			if(time%10000==0)
			{
				if(delay!=40)
				{
					delay=delay-10;
					level=level+1;
					setcolor(14);
					gotoxy(65,10);
					cout<<"* LeVeL :-";
					setcolor(12);
					gotoxy(72,12);
					cout<<level;

				}
			}
			gotoxy(num[0],y[0]);
			cout<<"          ";
			if(flag[0]==1)
			{
				gotoxy(num[1],y[1]);
				cout<<"          ";
			}
			if(flag[1]==1)
			{
				gotoxy(num[2],y[2]);
				cout<<"          ";
			}
			if(flag[2]==1)
			{
				gotoxy(num[3],y[3]);
				cout<<"          ";
			}
			if(flag[3]==1)
			{
				gotoxy(num[4],y[4]);
				cout<<"          ";
			}
			gotoxy(xO,yO);
			cout<<" ";
	
	
			if(y[0]==20)
			{
				flag[0]=1;
			}

			if(y[1]==20)
			{
				flag[1]=1;
			}
			if(y[2]==20)
			{
				flag[2]=1;
			}
			if(y[3]==20)
			{
				flag[3]=1;
			}
	

			if(y[0]==1)
			{
				y[0]=23;
				color[0]=(rand()%14)+1;
				num[0]=(rand()%7*5) + 20;
			}
	
			if(y[1]==1)
			{
				y[1]=23;
				color[1]=(rand()%14)+1;
				num[1]=(rand()%7*5) + 20;
			}
	
			if(y[2]==1)
			{
				y[2]=23;
				color[2]=(rand()%14)+1;
				num[2]=(rand()%7*5) + 20;
			}
			if(y[3]==1)
			{
				y[3]=23;
				color[3]=(rand()%14)+1;
				num[3]=(rand()%7*5) + 20;
			}
			if(y[4]==1)
			{
				y[4]=23;
				color[4]=(rand()%14)+1;
				num[4]=(rand()%7*5) + 20;
			}
	
			if(yO==24 || yO==0)
			{
				lives=lives-1;

				yO=3;
				gotoxy(5,12);
				setcolor(12);
				cout<<lives;
							}
			if(lives==0)
			{
				gotoxy(30,10);
				setcolor(12);
				cout<<"- : G A M E  O V E R : -";
				gotoxy(33,12);
				setcolor(14);
				cout<<"* Name : "<<name;
				gotoxy(33,14);
				setcolor(11);
				cout<<"* Score : "<<score;
				Sleep(5000);
				exit(0);
			}

			y[0]=y[0]-1;

			if(flag[0]==1)
			{
				y[1]=y[1]-1;
			}
			if(flag[1]==1)
			{
				y[2]=y[2]-1;
			}
	
			if(flag[2]==1)
			{
				y[3]=y[3]-1;
			}
			if(flag[3]==1)
			{
				y[4]=y[4]-1;
			}


			if(yO==(y[0]-1) || yO==y[0] && num[0]<=xO && xO<=num[0]+10)
			{
				n=0;
				q=1,w=1;
			}
			if(n==0)
			{
				if(!(num[0]<=xO && xO<=num[0]+10))
				{
					n=10;
					w=0;
				}
			}

			if(yO==(y[1]-1) || yO==y[1] && num[1]<=xO && xO<=num[1]+10)
			{
				n=1;
			}
			if(n==1)
			{
				if(!(num[1]<=xO && xO<=num[1]+10))
				{
					n=10;
				}
			}


			if(yO==(y[2]-1) || yO==y[2] && num[2]<=xO && xO<=num[2]+10)
			{
				n=2;
			}
			if(n==2)
			{
				if(!(num[2]<=xO && xO<=num[2]+10))
				{
					n=10;
				}
			}

			if(yO==(y[3]-1) || yO==y[3] && num[3]<=xO && xO<=num[3]+10)
			{
				n=3;
			}
			if(n==3)
			{
				if(!(num[3]<=xO && xO<=num[3]+10))
				{
					n=10;
				}
			}
			if(yO==(y[4]-1) || yO==y[4] && num[4]<=xO && xO<=num[4]+10)
			{
				n=4;
			}
			if(n==4)
			{
				if(!(num[4]<=xO && xO<=num[4]+10))
				{
					n=10;
				}
			}

			switch(n)
			{
				case 0:
				yO=y[0]-1;
				break;
			
				case 1:
				yO=y[1]-1;
				break;
				case 2:
				yO=y[2]-1;
				break;
			
				case 3:
				yO=y[3]-1;
				break;
			
				case 4:
				yO=y[4]-1;
				break;

				case 10:
				yO=yO+1;
				break;
			}
		}	
		key=_getch();
		if(key=='l')
		{
			if(xO<59)
			{
				xO=xO+1;
				if(level>3)
				{
					xO=xO+1;
				}
			}
		}
		if(key=='j')
		{
			if(xO>20)
			{
				xO=xO-1;
				if(level>3)
				{
					xO=xO-1;
				}
			}
		}
	}
				gotoxy(30,10);
				setcolor(12);
				cout<<"- : G A M E  O V E R : -";
				gotoxy(33,12);
				setcolor(14);
				cout<<"* Name : "<<name;
				gotoxy(33,14);
				setcolor(11);
				cout<<"* Score : "<<score;
				Sleep(5000);
				exit(0);
		return 0;
}