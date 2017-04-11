#include <iostream>
#include <windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;

int delay=50,countOfTiles=1,level=1;
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

void car(int x,int y);
void remcar(int x,int y);
int cond(int xc,int yc,int xce[],int yce[]);


int cond(int xc,int yc,int xce[],int yce[])
{
	int flag=0;
	for(int i=0;i<5;i=i+1)
	{
		if( yce[i]>=18 && yce[i]<=20 && xc==xce[i])
		{
				flag=1;
				return flag;
		}
	}
}
void car(int x,int y)
{
	char ch=219,ch2=94,ch3='!';
	setcolor(12);
	gotoxy(x,y);
	cout<<"O";
	setcolor(14);
	cout<<"-";
	cout<<ch2;
	cout<<"-";
	setcolor(12);
	cout<<"O";
	setcolor(14);
	gotoxy(x,y+1);
	cout<<" |";
	setcolor(12);
	cout<<ch;
	setcolor(14);
	cout<<"|";
	gotoxy(x,y+2);
	setcolor(12);
	cout<<"O";
	setcolor(14);
	cout<<"-"<<ch3<<"-";
	setcolor(12);
	cout<<"O";
}

void car2(int x,int y)
{
	char ch=219,ch2=94,ch3='!';
	setcolor(10);
	gotoxy(x,y);
	cout<<"O";
	setcolor(9);
	cout<<"-";
	cout<<ch2;
	cout<<"-";
	setcolor(10);
	cout<<"O";
	setcolor(9);
	gotoxy(x,y+1);
	cout<<" |";
	setcolor(10);
	cout<<ch;
	setcolor(9);
	cout<<"|";
	gotoxy(x,y+2);
	setcolor(10);
	cout<<"O";
	setcolor(9);
	cout<<"-"<<ch3<<"-";
	setcolor(10);
	cout<<"O";
}

void car3(int x,int y)
{
	char ch=219,ch2=94,ch3='!';
	setcolor(7);
	gotoxy(x,y);
	cout<<"O";
	setcolor(13);
	cout<<"-";
	cout<<ch2;
	cout<<"-";
	setcolor(7);
	cout<<"O";
	setcolor(13);
	gotoxy(x,y+1);
	cout<<" |";
	setcolor(7);
	cout<<ch;
	setcolor(13);
	cout<<"|";
	gotoxy(x,y+2);
	setcolor(7);
	cout<<"O";
	setcolor(13);
	cout<<"-"<<ch3<<"-";
	setcolor(7);
	cout<<"O";
}

void car4(int x,int y)
{
	char ch=219,ch2=94,ch3='!';
	setcolor(6);
	gotoxy(x,y);
	cout<<"O";
	setcolor(14);
	cout<<"-";
	cout<<ch2;
	cout<<"-";
	setcolor(6);
	cout<<"O";
	setcolor(14);
	gotoxy(x,y+1);
	cout<<" |";
	setcolor(6);
	cout<<ch;
	setcolor(14);
	cout<<"|";
	gotoxy(x,y+2);
	setcolor(6);
	cout<<"O";
	setcolor(14);
	cout<<"-"<<ch3<<"-";
	setcolor(6);
	cout<<"O";
}

void car5(int x,int y)
{
	char ch=219,ch2=94,ch3='!';
	setcolor(13);
	gotoxy(x,y);
	cout<<"O";
	setcolor(8);
	cout<<"-";
	cout<<ch2;
	cout<<"-";
	setcolor(13);
	cout<<"O";
	setcolor(8);
	gotoxy(x,y+1);
	cout<<" |";
	setcolor(13);
	cout<<ch;
	setcolor(8);
	cout<<"|";
	gotoxy(x,y+2);
	setcolor(13);
	cout<<"O";
	setcolor(8);
	cout<<"-"<<ch3<<"-";
	setcolor(13);
	cout<<"O";
}

void car6(int x,int y)
{
	char ch=219,ch2=94,ch3='!';
	setcolor(3);
	gotoxy(x,y);
	cout<<"O";
	setcolor(9);
	cout<<"-";
	cout<<ch2;
	cout<<"-";
	setcolor(3);
	cout<<"O";
	setcolor(9);
	gotoxy(x,y+1);
	cout<<" |";
	setcolor(3);
	cout<<ch;
	setcolor(9);
	cout<<"|";
	gotoxy(x,y+2);
	setcolor(3);
	cout<<"O";
	setcolor(9);
	cout<<"-"<<ch3<<"-";
	setcolor(3);
	cout<<"O";
}


void remcar(int x,int y)
{
	gotoxy(x,y);
	cout<<"      ";
	gotoxy(x,y+1);
	cout<<"    ";
	gotoxy(x,y+2);
	cout<<"     ";
}
char track(int xc,int yc,int xce[],int yce[],int &n,int &m,int &k,int &score,char name[])
{
	unsigned seed=time(0);
	srand(seed);
	char key,ch=178;
	int i,j=1,y1=0;
	gotoxy(0,10);
	setcolor(13);
	cout<<"Player's name :-";
	gotoxy(5,12);
	setcolor(14);
	cout<<name;

	while(!_kbhit())
	{

		for(i=0;i<24;i=i+1)		//display boundary
		{
			if(i%2==0)
			{
				setcolor(14);
			}
			else
			{
				setcolor(12);
			}
			gotoxy(19,y1);
			cout<<ch;
			gotoxy(60,y1);
			cout<<ch;
			y1=y1+1;	
		}
		y1=0;
		car(xc,yc);			//display car.
		Sleep(delay);
		for(i=0;i<24;i=i+1)
		{
			if(i%2==1)
			{
				setcolor(14);
			}
			else
			{
				setcolor(12);
			}
			gotoxy(19,y1);
			cout<<ch;
			gotoxy(60,y1);
			cout<<ch;
			y1=y1+1;	
		}
		Sleep(delay);
		y1=0;
		//flags for enmey cars
		if(yce[0]==5 && n==0)	
		{
			n=1;
		}

		if(yce[1]==5 && m==0)
		{
			m=1;
		}

		if(yce[2]==5 && k==0)
		{
			k=1;
		}

							//flags for enemy cars coming again
		if(yce[0]==21)
		{
			remcar(xce[0],yce[0]);
			yce[0]=0;
			xce[0]=((rand()%8)*5)+20;
			score=score+100;
			countOfTiles=countOfTiles+1;
			if(countOfTiles%10==0)
			{
				if(delay!=10)
				{
					delay=delay-10;
					level=level+1;
				}
			}
		}
		
		if(yce[1]==21)
		{
			remcar(xce[1],yce[1]);
			yce[1]=0;
			xce[1]=((rand()%8)*5)+20;
			score=score+100;
		}

		if(yce[2]==21)
		{
			remcar(xce[2],yce[2]);
			yce[2]=0;
			xce[2]=((rand()%8)*5)+20;
			score=score+100;
		}
		
		if(yce[3]==21)
		{
			remcar(xce[3],yce[3]);
			yce[3]=0;
			xce[3]=((rand()%8)*5)+20;
			score=score+100;
		}


		if(n==1)		//enemy 2
		{
			remcar(xce[1],yce[1]);
			yce[1]=yce[1]+1;
			car3(xce[1],yce[1]);
		}

		if(m==1)		//enemy 3
		{
			remcar(xce[2],yce[2]);
			yce[2]=yce[2]+1;
			car4(xce[2],yce[2]);
		}

		if(k==1)		//enemy 4
		{
			remcar(xce[3],yce[3]);
			yce[3]=yce[3]+1;
			car5(xce[3],yce[3]);
		}

		remcar(xce[0],yce[0]);  //enemy 1
		yce[0]=yce[0]+1;
		car2(xce[0],yce[0]);
		gotoxy(0,14);
		setcolor(13);
		cout<<"Score:-";
		gotoxy(5,16);
		setcolor(14);
		cout<<score;
		setcolor(13);
		gotoxy(65,15);
		cout<<"LeveL :- ";
		gotoxy(70,17);
		setcolor(14);
		cout<<level;
		

		if((cond(xc,yc,xce,yce))==1)
		{	
				gotoxy(30,5);
				setcolor(12);
				cout<<"Name :- "<<name;
				gotoxy(30,7);
				setcolor(12);
				cout<<"Score :-"<<score;
				gotoxy(30,10);
				setcolor(14);
				Sleep(2000);
				cout<<" -: GAME OVER :-";
				exit(0);

		}
		
	}
	key=_getch();
	return key;
}
void control(int &xc,int &yc,char key)
{
	if(key=='j')
	{
		remcar(xc,yc);
		if(xc!=20)
		{
			xc=xc-5;
			car(xc,yc);
		}
	}
	if(key=='l')
	{
		remcar(xc,yc);
		if(xc!=55)
		{
			xc=xc+5;
			car(xc,yc);
		}
	}
}


int main()
{
	unsigned seed=time(0);
	srand(seed);
	char key,name[20];
	int i,xc=40,yc=20,n=0,m=0,k=0,l=0,o=0,score=0;
	int xce[5],yce[5];
	for(int j=0;j<5;j=j+1)   // intializing enmey cars array.
	{
		xce[j]=((rand()%8)*5)+20;
		yce[j]=0;
	}
	gotoxy(20,10);
	setcolor(14);
	cout<<"Enter Your name :- ";
	gotoxy(30,12);
	setcolor(12);
	cin.getline(name,20);
	system("CLS");
	while((cond(xc,yc,xce,yce))!=1)
	{
		key=track(xc,yc,xce,yce,n,m,k,score,name);
		control(xc,yc,key);	
	}
	gotoxy(30,5);
	setcolor(12);
	cout<<"Name :- "<<name;
	gotoxy(30,7);
	setcolor(12);
	cout<<"Score :-"<<score;
	gotoxy(30,10);
	setcolor(14);
	Sleep(2000);
	cout<<" -: GAME OVER :-";
}