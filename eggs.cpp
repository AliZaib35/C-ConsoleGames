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
void basket(int x)
{
	setcolor(13);
	char ch=219,ch1=221;
	gotoxy(x,21);
	setcolor(12);
	cout<<"|";
	setcolor(9);
	cout<<"___";
	setcolor(12);
	cout<<"|";
	gotoxy(x+1,22);
	cout<<"|"<<ch<<"|";
	gotoxy(x,23);
	cout<<"_/,\\_";
}
void rembasket(int x)
{
	gotoxy(x,21);
	cout<<"     ";
	gotoxy(x+1,22);
	cout<<"   ";
	gotoxy(x,23);
	cout<<"     ";
}
void clock(int x)
{
	char ch=219,ch1=176;
	setcolor(11);
	gotoxy(64,6);
	cout<<"-: T I M E R :-";

	gotoxy(65,7);
	setcolor(12);
	cout<<ch;
	setcolor(14);
	cout<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1;
	setcolor(12);
	cout<<ch;
	setcolor(14);
	gotoxy(65,8);
	cout<<ch1<<"          "<<ch1;
	gotoxy(65,9);
	cout<<ch1<<"          "<<ch1;
	gotoxy(65,10);
	setcolor(14);
	cout<<ch1<<"    ";
	setcolor(12);
	cout<<x;
	setcolor(14);
	gotoxy(76,10);
	cout<<ch1;
	setcolor(14);
	gotoxy(65,11);
	cout<<ch1<<"          "<<ch1;
	gotoxy(65,12);
	cout<<ch1;
	cout<<"          "<<ch1;
	
	gotoxy(65,13);
	setcolor(12);
	cout<<ch;
	setcolor(14);
	cout<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1<<ch1;
	setcolor(12);
	cout<<ch;
}
int main()
{
	unsigned seed=time(0);
	srand(seed);
	char key,ch='O',name[20],ch1=219;
	int i,j=1,y[9],num[9],flag[8]={0,0,0,0,0,0,0},n=10,color[9],dead,q=0,w=0,score=0,time=0;
	int timer=60;
	int xO=40;
	y[0]=0;
	y[1]=0;
	y[2]=0;
	y[3]=0;
	y[4]=0;
	y[5]=0;
	y[6]=0;
	y[7]=0;
	y[8]=0;
	num[0]=(rand()%21*2) + 20;;//(rand()%7*5) + 20;
	num[1]=(rand()%21*2) + 20;
	num[2]=(rand()%21*2) + 20;
	num[3]=(rand()%21*2) + 20;
	num[4]=(rand()%21*2) + 20;
	num[5]=(rand()%21*2) + 20;
	num[6]=(rand()%21*2) + 20;
	num[7]=(rand()%21*2) + 20;
	num[8]=(rand()%21*2) + 20;
	color[0]=(rand()%14)+1;
	color[1]=(rand()%14)+1;
	color[2]=(rand()%14)+1;
	color[3]=(rand()%14)+1;
	color[4]=(rand()%14)+1;
	color[5]=(rand()%14)+1;
	color[6]=(rand()%14)+1;
	color[7]=(rand()%14)+1;
	color[8]=(rand()%14)+1;
	dead=(rand()%14)+1;

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
	basket(xO);
	while(timer!=0)
	{
		while(!_kbhit())
		{
			
			setcolor(color[0]);
			gotoxy(num[0],y[0]);
			cout<<ch;
			if(flag[0]==1)
			{
				setcolor(color[1]);
				gotoxy(num[1],y[1]);
				cout<<ch;
			}
			if(flag[1]==1)
			{
				
				setcolor(color[2]);
				gotoxy(num[2],y[2]);
				cout<<ch;
			}
			if(flag[2]==1)
			{
				
				setcolor(color[3]);
				gotoxy(num[3],y[3]);
				cout<<ch;
			}
			if(flag[3]==1)
			{
			
				setcolor(color[4]);
				gotoxy(num[4],y[4]);
				cout<<ch;
			}
			if(flag[4]==1)
			{
			
				setcolor(color[5]);
				gotoxy(num[5],y[5]);
				cout<<ch;
			}
			if(flag[5]==1)
			{
			
				setcolor(color[6]);
				gotoxy(num[6],y[6]);
				cout<<ch;
			}
			if(flag[6]==1)
			{
			
				setcolor(color[7]);
				gotoxy(num[7],y[7]);
				cout<<ch;
			}
			if(flag[7]==1)
			{
			
				setcolor(color[8]);
				gotoxy(num[8],y[8]);
				cout<<ch;
			}

			setcolor(14);
			gotoxy(2,9);
			cout<<"* Score :-";
			setcolor(12);
			gotoxy(5,11);
			cout<<score;
			clock(timer);
			if(timer==0)
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
			for(i=0;i<=24;i=i+1)		//display boundary
			{
				if(i%2==0)
				{
					setcolor(9);
				}
				else
				{
					setcolor(11);
				}
				gotoxy(19,i);
				cout<<ch1;
				gotoxy(61,i);
				cout<<ch1;	
			}
			Sleep(100);
			for(int i=20;i<61;i=i+1)
			{
				dead=(rand()%14)+1;
				setcolor(dead);
				gotoxy(i,0);
				cout<<"O";
				if(i%2==0)
				{
					setcolor(6);
				}
				else
				{
					setcolor(10);
				}
				gotoxy(i,24);
				cout<<ch1;
			}
			Sleep(100);
			time=time+200;
			if(time%1000==0)
			{
				timer=timer-1;
			}
			

			gotoxy(num[0],y[0]);
			cout<<" ";
			if(flag[0]==1)
			{
				gotoxy(num[1],y[1]);
				cout<<" ";
			}
			if(flag[1]==1)
			{
				gotoxy(num[2],y[2]);
				cout<<" ";
			}
			if(flag[2]==1)
			{
				gotoxy(num[3],y[3]);
				cout<<" ";
			}
			if(flag[3]==1)
			{
				gotoxy(num[4],y[4]);
				cout<<" ";
			}
			if(flag[4]==1)
			{
				gotoxy(num[5],y[5]);
				cout<<" ";
			}
			if(flag[5]==1)
			{
				gotoxy(num[6],y[6]);
				cout<<" ";
			}
			if(flag[6]==1)
			{
				gotoxy(num[7],y[7]);
				cout<<" ";
			}
			if(flag[7]==1)
			{
				gotoxy(num[8],y[8]);
				cout<<" ";
			}
	
	
			if(y[0]==3)
			{
				flag[0]=1;
			}

			if(y[1]==3)
			{
				flag[1]=1;
			}
			if(y[2]==3)
			{
				flag[2]=1;
			}
			if(y[3]==3)
			{
				flag[3]=1;
			}
			if(y[4]==3)
			{
				flag[4]=1;
			}
			if(y[5]==3)
			{
				flag[5]=1;
			}
			if(y[6]==3)
			{
				flag[6]=1;
			}
			if(y[7]==3)
			{
				flag[7]=1;
			}
			if(y[8]==3)
			{
				flag[8]=1;
			}


			// conditionz
			for(int i=0;i<9;i=i+1)
			{
				if(num[i]>=xO && num[i]<=(xO+5) && y[i]==21)
				{
					y[i]=23;
					score=score+100;
				}
			}



			if(y[0]==23)
			{
				y[0]=0;
				color[0]=(rand()%14)+1;
				num[0]=(rand()%21*2) + 20;
			}
	
			if(y[1]==23)
			{
				y[1]=0;
				color[1]=(rand()%14)+1;
				num[1]=(rand()%21*2) + 20;
			}
	
			if(y[2]==23)
			{
				y[2]=0;
				color[2]=(rand()%14)+1;
				num[2]=(rand()%21*2) + 20;
			}
			if(y[3]==23)
			{
				y[3]=0;
				color[3]=(rand()%14)+1;
				num[3]=(rand()%21*2) + 20;
			}
			if(y[4]==23)
			{
				y[4]=0;
				color[4]=(rand()%14)+1;
				num[4]=(rand()%21*2) + 20;
			}
			
			if(y[5]==23)
			{
				y[5]=0;
				color[5]=(rand()%14)+1;
				num[5]=(rand()%21*2) + 20;
			}
			if(y[6]==23)
			{
				y[6]=0;
				color[6]=(rand()%14)+1;
				num[6]=(rand()%21*2) + 20;
			}
			if(y[7]==23)
			{
				y[7]=0;
				color[7]=(rand()%14)+1;
				num[7]=(rand()%21*2) + 20;
			}
			if(y[8]==23)
			{
				y[8]=0;
				color[8]=(rand()%14)+1;
				num[8]=(rand()%21*2) + 20;
			}

			

			y[0]=y[0]+1;

			if(flag[0]==1)
			{
				y[1]=y[1]+1;
			}
			if(flag[1]==1)
			{
				y[2]=y[2]+1;
			}
	
			if(flag[2]==1)
			{
				y[3]=y[3]+1;
			}
			if(flag[3]==1)
			{
				y[4]=y[4]+1;
			}
			if(flag[4]==1)
			{
				y[5]=y[5]+1;
			}
			if(flag[5]==1)
			{
				y[6]=y[6]+1;
			}
			if(flag[6]==1)
			{
				y[7]=y[7]+1;
			}
			if(flag[7]==1)
			{
				y[8]=y[8]+1;
			}
		}	
		key=_getch();
		if(key=='l')
		{
			if(xO<56)
			{
				rembasket(xO);
				xO=xO+2;
				basket(xO);
			}
		}
		if(key=='j')
		{
			if(xO>20)
			{
				rembasket(xO);
				xO=xO-2;
				basket(xO);
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