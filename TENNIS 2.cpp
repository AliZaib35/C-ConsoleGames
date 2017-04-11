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
char stg[80][58],ch=219;
int countOfTiles=0,hit=0,ball[5]={10,11,12,13,14},lives=3;
void intialize1()
{
	for(int y=0;y<58;y=y+1)     // initialize
	{
		for(int x=0;x<80;x=x+1)
		{
			stg[x][y]=' ';
		}
	}
	int i,j,k;
	
	for(int n=5;n<17;n=n+2)
	{
		for(j=15;j<65;j=j+5)
		{
			k=j+4;
			
			for(i=j;i<k;i=i+1)
			{
				stg[i][n] = ch;
			}
			stg[k][n]=' ';
			countOfTiles = countOfTiles+1;		
		}
	}
}

void intialize2()
{
	for(int y=0;y<58;y=y+1)     // initialize
	{
		for(int x=0;x<80;x=x+1)
		{
			stg[x][y]=' ';
		}
	}
	int i,j,k;
	
	for(int n=5;n<20;n=n+1)
	{
		for(j=15;j<65;j=j+5)
		{
			k=j+4;
			
			for(i=j;i<k;i=i+1)
			{
				stg[i][n] = ch;
			}
			stg[k][n]=' ';
			countOfTiles=countOfTiles+1;		
		}
	}
}

void intialize3()
{
	for(int y=0;y<58;y=y+1)     // initialize
	{
		for(int x=0;x<80;x=x+1)
		{
			stg[x][y]=' ';
		}
	}
	int i,j,k[6]={10,20,30,45,55,66};
	
	for(int n=5;n<20;n=n+1)
	{
		for(j=15;j<65;j=j+5)
		{
			
			for(int x=0;x<6;x=x+1)
			{
				for(i=k[x];i<(k[x]+4);i=i+1)
				{
					stg[i][n] = ch;
				}
				stg[i][n]=' ';
				countOfTiles=countOfTiles+1;		
			}
		}
	}
}



void show1()
{
	int m=0,color[8]={6,9,10,11,12,13,14,7};
	setcolor(14);
	for(int y=0;y<=55;y=y+1)
	{
		for(int x=0;x<80;x=x+1)
		{
			if(stg[x][y]==ch)
			{
				setcolor(color[m]);
				if(stg[x+1][y]==32)
				{
					m=m+1;
					if(m==8)
					{
						m=0;
					}
				}
			
				
			}
			
			cout<<stg[x][y];
		}
		
	}		
	setcolor(14);
	gotoxy(1,10);
	cout<<"LiVeS:-";
	setcolor(12);
	gotoxy(5,12);
	cout<<lives;
}

void show2()
{
	int m=0,color[10]={9,10,6,11,12,13,14,7,10,9};
	setcolor(14);
	for(int y=0;y<=55;y=y+1)
	{
		for(int x=0;x<80;x=x+1)
		{
			if(stg[x][y]==ch)
			{
				setcolor(color[m]);
				if(stg[x+1][y]==32)
				{
					m=m+1;
					if(m==10)
					{
						m=0;
					}
				}
			
				
			}
			
			cout<<stg[x][y];
		}
		
	}		
	setcolor(14);
	gotoxy(1,10);
	cout<<"LiVeS:-";
	setcolor(12);
	gotoxy(5,12);
	cout<<lives;
}


void show3()
{
	int m=0,color[6]={9,10,11,12,13,14};
	setcolor(14);
	for(int y=0;y<=55;y=y+1)
	{
		for(int x=0;x<80;x=x+1)
		{
			if(stg[x][y]==ch)
			{
				setcolor(color[m]);
				if(stg[x+1][y]==32)
				{
					m=m+1;
					if(m==6)
					{
						m=0;
					}
				}
			
				
			}
			
			cout<<stg[x][y];
		}
		
	}		
	setcolor(14);
	gotoxy(1,10);
	cout<<"LiVeS:-";
	setcolor(12);
	gotoxy(5,12);
	cout<<lives;
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
		gotoxy(9,i);
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
void timer()
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
void remove(int xO,int yO)
{
	gotoxy(xO,yO);
	cout<<" ";
	stg[xO][yO]=' ';
	int x=xO+1;
	while(stg[x][yO]!=' ')
	{
		gotoxy(x,yO);
		cout<<" ";
		stg[x][yO]=' ';
		x=x+1;
	}
	x=xO-1;
	while(stg[x][yO]!=' ')
	{
		gotoxy(x,yO);
		cout<<" ";
		stg[x][yO]=' ';
		x=x-1;
	}
}
void win()
{
	for(int i=0;i<3;i=i+1)
	{
		setcolor(12);
		gotoxy(25,20);
		cout<<"!!!!! Y O U  W O N !!!!!";
		Sleep(500);
		gotoxy(25,20);
		cout<<"                        ";
		Sleep(500);
	}
	setcolor(14);	
	gotoxy(25,20);
	cout<<"!!!!! Y O U  W O N !!!!!";
	exit(0);
}
void over()
{
	for(int i=0;i<3;i=i+1)
	{
		setcolor(12);
		gotoxy(25,20);
		cout<<"!!!!! G A M E  O V E R !!!!!";
		Sleep(1000);
		gotoxy(25,20);
		cout<<"                            ";
		Sleep(1000);
	}
	setcolor(14);	
	gotoxy(25,20);
	cout<<"!!!!! G A M E  O V E R !!!!!";
	exit(0);
}
int main()
{
	gotoxy(30,15);
	char stage;
	setcolor(14);
	cout<<"SeLeCt tHe sTaGe .. (1-3) \n\n\t\t\t\t";
	do
	{
		stage=_getch();
	}while(stage>'3' || stage<'1');
	system("CLS");
	timer();
	gotoxy(0,0);
	switch(stage)
	{
	case '1':
		intialize1();
		show1();
		break;
	case '2':
		intialize2();
		show2();
		break;
	case '3':
		intialize3();
		show3();
		break;
	}
	
	menu();
	unsigned seed=time(0);
	int color=14,color2=14;
	char box=176,box2=219;
	srand(seed);
	int i,x1=36,y1=38;		// xy1= lower tray ;xy3 = ball; 
	int xO=x1+3,yO=y1-1;
	char flag1='u',flag2='l';
	char key='k';
	gotoxy(xO,yO);
	setcolor(6);
	cout<<"O";
	gotoxy(x1,y1);
	setcolor(color);
	cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
//	countOfTiles();		//timer
	
	while(key!=32 )
	{
		
		if(key=='l')
		{
			if(x1<62)
			{
				gotoxy(x1,y1);
				cout<<"        ";
				x1=x1+2;
				xO=x1+3,yO=y1-1;
				gotoxy(x1,y1);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			}
			
		}
		if(key=='j')
		{
			if(x1>10)
			{
				
				gotoxy(x1,y1);
				cout<<"        ";
				
				x1=x1-2;
				xO=x1+3,yO=y1-1;
				gotoxy(x1,y1);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			}
			
		}
			gotoxy(xO,yO);
			
			setcolor(color2);
			cout<<"O";
			key=_getch();
			Sleep(75);
			gotoxy(xO,yO);
			cout<<" ";
			
	}

	while(lives!=0)
	{
		
		if(key=='l')
		{
			if(x1<62)
			{
				gotoxy(x1,y1);
				cout<<"        ";
				x1=x1+2;
				gotoxy(x1,y1);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			}
			
		}
		if(key=='j')
		{
			if(x1>10)
			{
				
				gotoxy(x1,y1);
				cout<<"        ";
				
				x1=x1-2;
				gotoxy(x1,y1);
				setcolor(color);
				cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
			}
			
		}
		while(!_kbhit())
		{
			gotoxy(xO,yO);
			setcolor(color2);
			cout<<"O";
			Sleep(75);
			gotoxy(xO,yO);
			cout<<" ";
			if(xO==69)		// wall checking condition
			{
				flag2='l';
			}
			if(xO==10)
			{
				flag2='r';
			}

			if(stg[xO][yO-1]==ch)
			{
				flag1='d';
				remove(xO,yO-1);
				hit=hit+1;
			}

			if(stg[xO+1][yO]==ch)
			{
				flag2='l';
				remove(xO+1,yO);
				hit=hit+1;
		
			}

			if(stg[xO-1][yO]==ch)
			{
				flag2='r';
				remove(xO-1,yO);
				hit=hit+1;
				
			}

			if(stg[xO][yO+1]==ch)
			{
				flag1='u';
				remove(xO,yO+1);
				hit=hit+1;
			}

			if(countOfTiles==hit)
			{
				win();
			}
			
			if(flag1=='u')
			{
				yO = yO - 1;
			}
			if(flag1=='d')
			{
				yO = yO + 1;
			}
			if(flag2=='l')
			{
				xO = xO - 1;
			}
			if(flag2=='r')
			{
				xO = xO + 1;
			}
			if(yO==(y1 - 1) && xO>x1 && xO<x1+7)
			{
				color2= ball[rand()%5];
				setcolor(color2);
				flag1='u';
			}
			if(yO==(y1 - 1) && xO==x1)
			{
				color2= ball[rand()%5];
				setcolor(color2);
				flag1='u';
				flag2='l';
			}
			if(yO==(y1 - 1) && xO==x1+7)
			{
				color2= ball[rand()%5];
				setcolor(color2);
				flag1='u';
				flag2='r';
			}
			if(yO==1)
			{
				flag1='d';
			}
			if(yO==40)			//gameover condition
			{
				
				 lives=lives-1;
				 setcolor(12);
				 gotoxy(5,12);
				 cout<<lives;
				 if(lives==0)
				 {
					 over();
				 }
				 xO=x1+3;yO=y1-1;
				 flag1='u';
				 key='k';
				 Sleep(2000);
				 while(key!=32 )
		      	 {
		
					if(key=='l')
					{
						if(x1<62)
						{
							gotoxy(x1,y1);
							cout<<"        ";
							x1=x1+2;
							xO=x1+3,yO=y1-1;
							gotoxy(x1,y1);
							setcolor(color);
							cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
						}
						
					}
					if(key=='j')
					{
						if(x1>10)
						{
							
							gotoxy(x1,y1);
							cout<<"        ";
							
							x1=x1-2;
							xO=x1+3,yO=y1-1;
							gotoxy(x1,y1);
							setcolor(color);
							cout<<box2<<box<<box<<box<<box<<box<<box<<box2;
						}
						
					}
						gotoxy(xO,yO);
			
						setcolor(color2);
						cout<<"O";
						key=_getch();
						Sleep(75);
						gotoxy(xO,yO);
						cout<<" ";
			
				}
				
			}
		}
		
		key = _getch();
	}
	over();
	return 0;
}