#include <iostream>
#include <windows.h>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;
char scr[80][58],ch=219,chs=2,p='2',stage=2;
int e1[200],t=60,sum=0;
int n=0,countOfTiles=0,pscore=0;
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

void show(char scr[80][58])
{
	for(int y=0;y<=55;y=y+1)
	{
		for(int x=0;x<80;x=x+1)
		{
			
			if(scr[x][y]==ch)
			{
				setcolor(stage);
			}
			else if(scr[x][y]==chs)
			{
				setcolor(12);
			}
			else if(scr[x][y]=='o')
			{
				setcolor(14);
				n=n+1;
			}
			
			
			cout<<scr[x][y];
		}
		
	}		
}

void intialize1()
{	
	int i=0;
	for(int j=0;j<53;j=j+1)
	{
		e1[i]=j;
		i=i+1;
	}
	for(int j=53;j>0;j=j-1)
	{
		e1[i]=j;
		i=i+1;
	}
	
}

void intialize()
{
	int i=0;
	for(int y=0;y<58;y=y+1)     // initialize
	{
		for(int x=0;x<80;x=x+1)
		{
			if (x%4==0 && y%4==0)
			{
				scr[x][y]='o';
			}
		}
	}
	setcolor(9);				//boundary
	for(i=0;i<25;i=i+1)			//horizontal
	{
		scr[0][i]=ch;
		scr[79][i]=ch;
	}
	for(i=30;i<55;i=i+1)			
	{
		scr[0][i]=ch;
		scr[79][i]=ch;
	}
	
	for(i=0;i<80;i=i+1)		//vertical
	{
		scr[i][0]=ch;
		scr[i][55]=ch;
	}
	int x[10]={15,30,0,44};
	for(i=0;i<=10;i=i+1)		//vertical lines
	{
		scr[20][x[0]]=ch;
		scr[60][x[0]]=ch;
		scr[20][x[1]]=ch;
		scr[60][x[1]]=ch;

		scr[20][x[2]]=ch;
		scr[21][x[2]]=ch;
		scr[22][x[2]]=ch;
		scr[23][x[2]]=ch;
		scr[24][x[2]]=ch;

		scr[40][x[2]]=ch;

		scr[60][x[2]]=ch;
		scr[59][x[2]]=ch;
		scr[58][x[2]]=ch;
		scr[57][x[2]]=ch;
		scr[56][x[2]]=ch;

		scr[20][x[3]]=ch;
		scr[21][x[3]]=ch;
		scr[22][x[3]]=ch;
		scr[23][x[3]]=ch;
		scr[24][x[3]]=ch;

		scr[40][x[3]]=ch;

		scr[60][x[3]]=ch;
		scr[59][x[3]]=ch;
		scr[58][x[3]]=ch;
		scr[57][x[3]]=ch;
		scr[56][x[3]]=ch;
	
		x[0]=x[0]+1;
		x[1]=x[1]+1;
		x[2]=x[2]+1;
		x[3]=x[3]+1;

	}
	x[0]=0,x[1]=60,x[2]=30,x[3]=50;
	for(i=0;i<=20;i=i+1)
	{
		scr[x[0]][15]=ch;
		scr[x[0]][25]=ch;
		scr[x[0]][30]=ch;
		scr[x[0]][40]=ch;

		scr[x[1]][15]=ch;
		scr[x[1]][25]=ch;
		scr[x[1]][30]=ch;
		scr[x[1]][40]=ch;

		

		x[0]=x[0]+1;
		x[1]=x[1]+1;
	}
	x[0]=30,x[1]=45;
	for(i=0;i<=5;i=i+1)
	{
		scr[x[0]][25]=ch;
		scr[x[1]][25]=ch;
		x[0]=x[0]+1;
		x[1]=x[1]+1;
	}
	x[0]=15;
	for(i=0;i<25;i=i+1)
	{
		scr[30][x[0]]=ch;
		scr[50][x[0]]=ch;
		x[0]=x[0]+1;
	}

	for(i=30;i<=50;i=i+1)	//corner blocks
	{
		scr[i][10]=ch;
		scr[i][45]=ch;
	}

	for(i=6;i<15;i=i+1)		
	{
		scr[i][5]=ch;
		scr[i][50]=ch;
	}
	for(i=6;i<15;i=i+1)
	{
		scr[i][4]=ch;
		scr[i][49]=ch;
	}
	for(i=6;i<15;i=i+1)
	{
		scr[i][6]=ch;
		scr[i][51]=ch;
	}
	for(i=66;i<74;i=i+1)
	{
		scr[i][5]=ch;
		scr[i][50]=ch;
	}
	for(i=66;i<74;i=i+1)
	{
		scr[i][4]=ch;
		scr[i][49]=ch;
	}
	for(i=66;i<74;i=i+1)
	{
		scr[i][6]=ch;
		scr[i][51]=ch;
	}


	for(i=10;i<15;i=i+1)	//below upper corners
	{
		scr[10][i]=ch;
		scr[70][i]=ch;
	}
	for(i=10;i<15;i=i+1)
	{
		scr[9][i]=ch;
		scr[69][i]=ch;
	}
	for(i=10;i<15;i=i+1)
	{
		scr[8][i]=ch;
		scr[68][i]=ch;
	}
	for(i=10;i<15;i=i+1)
	{
		scr[7][i]=ch;
		scr[67][i]=ch;
	}
	for(i=10;i<15;i=i+1)
	{
		scr[6][i]=ch;
		scr[66][i]=ch;
	}

	for(i=10;i<15;i=i+1)
	{
		scr[11][i]=ch;
		scr[71][i]=ch;
	}
	for(i=10;i<15;i=i+1)
	{
		scr[12][i]=ch;
		scr[72][i]=ch;
	}
	for(i=10;i<15;i=i+1)
	{
		scr[13][i]=ch;
		scr[73][i]=ch;
	}
	for(i=10;i<15;i=i+1)
	{
		scr[14][i]=ch;
	}


	for(i=41;i<46;i=i+1)	//above loalir corner blocks
	{
		scr[10][i]=ch;
		scr[70][i]=ch;
	}
	for(i=41;i<46;i=i+1)
	{
		scr[11][i]=ch;
		scr[71][i]=ch;
	}
	for(i=41;i<46;i=i+1)
	{
		scr[12][i]=ch;
		scr[72][i]=ch;
	}
	for(i=41;i<46;i=i+1)
	{
		scr[13][i]=ch;
		scr[73][i]=ch;
	}
	for(i=41;i<46;i=i+1)
	{
		scr[14][i]=ch;
	
	}
	for(i=41;i<46;i=i+1)
	{
		scr[9][i]=ch;
		scr[69][i]=ch;
	}
	for(i=41;i<46;i=i+1)
	{
		scr[8][i]=ch;
		scr[68][i]=ch;
	}
	for(i=41;i<46;i=i+1)
	{
		scr[7][i]=ch;
		scr[67][i]=ch;
	}
	for(i=41;i<46;i=i+1)
	{
		scr[6][i]=ch;
		scr[66][i]=ch;
	}

	

	for(i=10;i<20;i=i+1)
	{
		scr[40][i]=ch;
	}
	for(i=30;i<45;i=i+1)
	{
		scr[40][i]=ch;
	}
	scr[30][5]=ch;
	scr[50][5]=ch;
	scr[30][50]=ch;
	scr[50][50]=ch;
	scr[20][11]=ch;
	scr[60][11]=ch;
	scr[20][44]=ch;
	scr[60][44]=ch;
	scr[20][29]=ch;
	scr[60][29]=ch;
	scr[59][11]=ch;
	scr[58][11]=ch;
	scr[57][11]=ch;
	scr[56][11]=ch;
	scr[21][11]=ch;
	scr[22][11]=ch;
	scr[23][11]=ch;
	scr[24][11]=ch;
	scr[30][5]=ch;
	scr[31][5]=ch;
	scr[32][5]=ch;
	scr[33][5]=ch;
	scr[34][5]=ch;

	scr[30][6]=ch;
	scr[31][6]=ch;
	scr[32][6]=ch;
	scr[33][6]=ch;
	scr[34][6]=ch;

	scr[30][4]=ch;
	scr[31][4]=ch;
	scr[32][4]=ch;
	scr[33][4]=ch;
	scr[34][4]=ch;

	scr[50][5]=ch;
	scr[49][5]=ch;
	scr[48][5]=ch;
	scr[47][5]=ch;
	scr[46][5]=ch;

	scr[50][4]=ch;
	scr[49][4]=ch;
	scr[48][4]=ch;
	scr[47][4]=ch;
	scr[46][4]=ch;

	scr[50][6]=ch;
	scr[49][6]=ch;
	scr[48][6]=ch;
	scr[47][6]=ch;
	scr[46][6]=ch;

	scr[30][49]=ch;
	scr[31][49]=ch;
	scr[32][49]=ch;
	scr[33][49]=ch;
	scr[34][49]=ch;

	scr[30][50]=ch;
	scr[31][50]=ch;
	scr[32][50]=ch;
	scr[33][50]=ch;
	scr[34][50]=ch;

	scr[30][51]=ch;
	scr[31][51]=ch;
	scr[32][51]=ch;
	scr[33][51]=ch;
	scr[34][51]=ch;

	scr[50][51]=ch;
	scr[49][51]=ch;
	scr[48][51]=ch;
	scr[47][51]=ch;
	scr[46][51]=ch;

	scr[50][50]=ch;
	scr[49][50]=ch;
	scr[48][50]=ch;
	scr[47][50]=ch;
	scr[46][50]=ch;

	scr[50][49]=ch;
	scr[49][49]=ch;
	scr[48][49]=ch;
	scr[47][49]=ch;
	scr[46][49]=ch;

	for(i=19;i>=0;i=i-1)
	{
		scr[i][29]=ch;
	}
	for(i=61;i<80;i=i+1)
	{
		scr[i][29]=ch;
	}

	for(i=29;i<45;i=i+1)
	{
		scr[39][i]=ch;
	}
	for(i=29;i<45;i=i+1)
	{
		scr[38][i]=ch;
	}
	for(i=29;i<45;i=i+1)
	{
		scr[37][i]=ch;
	}
	for(i=29;i<45;i=i+1)
	{
		scr[36][i]=ch;
	}
	for(i=29;i<45;i=i+1)
	{
		scr[41][i]=ch;
	}
	for(i=29;i<45;i=i+1)
	{
		scr[42][i]=ch;
	}
	for(i=29;i<45;i=i+1)
	{
		scr[43][i]=ch;
	}
	for(i=29;i<45;i=i+1)
	{
		scr[44][i]=ch;
	}
	scr[40][29]=ch;

	for(i=11;i<22;i=i+1)
	{
		scr[39][i]=ch;
	}
	for(i=11;i<22;i=i+1)
	{
		scr[38][i]=ch;
	}
	for(i=11;i<22;i=i+1)
	{
		scr[37][i]=ch;
	}
	for(i=11;i<22;i=i+1)
	{
		scr[36][i]=ch;
	}
	for(i=11;i<22;i=i+1)
	{
		scr[41][i]=ch;
	}
	for(i=11;i<22;i=i+1)
	{
		scr[42][i]=ch;
	}
	for(i=11;i<22;i=i+1)
	{
		scr[43][i]=ch;
	}
	for(i=11;i<22;i=i+1)
	{
		scr[44][i]=ch;
	}
	scr[40][20]=ch;
	scr[40][21]=ch;
	scr[36][25]=ch;
	scr[37][25]=ch;
	scr[43][25]=ch;
	scr[44][25]=ch;
	scr[30][14]=ch;
	scr[30][40]=ch;
	scr[30][41]=ch;

	scr[50][14]=ch;
	scr[50][40]=ch;
	scr[50][41]=ch;

	scr[16][20]=chs;
	scr[12][20]=chs;
	scr[8][20]=chs;
	scr[4][20]=chs;

	scr[16][16]=chs;
	scr[12][16]=chs;
	scr[8][16]=chs;
	scr[4][16]=chs;

	scr[16][24]=chs;
	scr[12][24]=chs;
	scr[8][24]=chs;
	scr[4][24]=chs;

	scr[16][36]=chs;
	scr[12][36]=chs;
	scr[8][36]=chs;
	scr[4][36]=chs;

	scr[16][32]=chs;
	scr[12][32]=chs;
	scr[8][32]=chs;
	scr[4][32]=chs;

	scr[64][20]=chs;
	scr[68][20]=chs;
	scr[72][20]=chs;
	scr[76][20]=chs;

	scr[64][16]=chs;
	scr[68][16]=chs;
	scr[72][16]=chs;
	scr[76][16]=chs;
	scr[64][24]=chs;
	scr[68][24]=chs;
	scr[72][24]=chs;
	scr[76][24]=chs;

	scr[64][36]=chs;
	scr[68][36]=chs;
	scr[72][36]=chs;
	scr[76][36]=chs;
	scr[64][32]=chs;
	scr[68][32]=chs;
	scr[72][32]=chs;
	scr[76][32]=chs;

	scr[0][28]=' ';
	scr[30][14]=' ';
	scr[30][41]=' ';
	scr[50][14]=' ';
	scr[50][41]=' ';

	scr[4][2]='o';
	scr[8][2]='o';
	scr[12][2]='o';
	scr[16][2]='o';
	scr[28][2]='o';
	scr[32][2]='o';
	scr[36][2]='o';
	scr[44][2]='o';
	scr[48][2]='o';
	scr[52][2]='o';
	scr[64][2]='o';
	scr[68][2]='o';
	scr[72][2]='o';
	scr[76][2]='o';
	
}

void win()
{
	if(n==countOfTiles)
	{
		gotoxy(30,30);
		setcolor(14);
		cout<<"- : YoU wON : -";
		Sleep(3000);
		exit(0);
	}
}
void score(int &x,int &y)
{
	if(scr[x][y]=='o' )
	{
		scr[x][y]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x][y+1]=='o' )
	{
		scr[x][y+1]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x][y+2]=='o' )
	{
		scr[x][y+2]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x+4][y]=='o' )
	{
		scr[x+4][y]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x+4][y+1]=='o' )
	{
		scr[x+4][y+1]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x+4][y+2]=='o' )
	{
		scr[x+4][y+2]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x+1][y]=='o')
	{
		scr[x+1][y]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	} 
	else if(scr[x+2][y]=='o')
	{
		scr[x+2][y]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x+3][y]=='o')
	{
		scr[x+3][y]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x+1][y+2]=='o')
	{
		scr[x+1][y+2]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x+2][y+2]=='o')
	{
		scr[x+2][y+2]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	else if(scr[x+3][y+2]=='o')
	{
		scr[x+3][y+2]=' ';
		countOfTiles=countOfTiles+1;
		pscore = pscore+100;
	}
	setcolor(12);
	gotoxy(30,57);
	cout<<"Score = ";
	setcolor(14);
	cout<<pscore;
}
void ali(int x,int y)
{
	char ch1=176,ch=3;
	setcolor(14);

	gotoxy(x,y);
	cout<<"(";
	setcolor(12);
	cout<<ch;
	setcolor(11);
	cout<<"_";
	setcolor(12);
	cout<<ch;
	setcolor(14);
	cout<<")";

	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(12);
	cout<<ch1;
	setcolor(14);
	cout<<"|\\";
	setcolor(14);
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void cheema(int x,int y)
{
	char ch1=2;
	setcolor(12);

	gotoxy(x,y);
	cout<<"(";
	setcolor(14);
	cout<<"^";
	setcolor(12);
	cout<<"_";
	setcolor(14);
	cout<<"^";
	setcolor(12);
	cout<<")";

	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(14);
	cout<<ch1;
	setcolor(12);
	cout<<"|\\";
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void sabir(int x,int y)
{
	char ch1=4,eye=237;
	setcolor(11);

	gotoxy(x,y);
	cout<<"(";
	setcolor(14);
	cout<<eye;
	setcolor(11);
	cout<<"_";
	setcolor(14);
	cout<<eye;
	setcolor(11);
	cout<<")";

	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(14);
	cout<<ch1;
	setcolor(11);
	cout<<"|\\";
	setcolor(11);
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void malixk(int x,int y)
{
	char ch1=5;
	setcolor(10);

	gotoxy(x,y);
	cout<<"(";
	setcolor(12);
	cout<<"#";
	setcolor(10);
	cout<<"_";
	setcolor(12);
	cout<<"#";
	setcolor(10);
	cout<<")";

	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(14);
	cout<<ch1;
	setcolor(10);
	cout<<"|\\";
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void amin(int x,int y)
{
	char ch1=15;
	setcolor(13);

	gotoxy(x,y);
	cout<<"(";
	setcolor(11);
	cout<<"$";
	setcolor(13);
	cout<<"_";
	setcolor(11);
	cout<<"$";
	setcolor(13);
	cout<<")";

	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(14);
	cout<<ch1;
	setcolor(13);
	cout<<"|\\";
	
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void amber(int x,int y)
{
	char ch1=1;
	setcolor(13);

	gotoxy(x,y);
	cout<<"(";
	setcolor(11);
	cout<<"@";
	setcolor(14);
	cout<<"_";
	setcolor(11);
	cout<<"@";
	setcolor(13);
	cout<<")";

	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(12);
	cout<<ch1;
	setcolor(13);
	cout<<"|\\";
	
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void sani(int x,int y)
{
	char ch1=14,eye=233;
	setcolor(11);

	gotoxy(x,y);
	cout<<"(";
	setcolor(14);
	cout<<eye;
	setcolor(8);
	cout<<"_";
	setcolor(14);
	cout<<eye;
	setcolor(11);
	cout<<")";

	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(12);
	cout<<ch1;
	setcolor(11);
	cout<<"|\\";
	
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void hamad(int x,int y)
{
	char ch1=6;
	setcolor(6);

	gotoxy(x,y);
	cout<<"(";
	setcolor(11);
	cout<<"~";
	setcolor(14);
	cout<<"_";
	setcolor(11);
	cout<<"~";
	setcolor(6);
	cout<<")";

	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(12);
	cout<<ch1;
	setcolor(6);
	cout<<"|\\";
	
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void maida(int x,int y)
{
	char ch1=3;
	setcolor(9);

	gotoxy(x,y);
	cout<<"(";
	setcolor(11);
	cout<<"O";
	setcolor(14);
	cout<<"_";
	setcolor(11);
	cout<<"O";
	setcolor(9);
	cout<<")";

	setcolor(2);
	gotoxy(x,y+1);
	cout<<"/|";
	setcolor(12);
	cout<<ch1;
	setcolor(2);
	cout<<"|\\";
	
	gotoxy(x,y+2);
	cout<<"_| |_"<<endl;
}

void remove(int x,int y)
{
	gotoxy(x,y);
	cout<<"     ";
	gotoxy(x,y+1);
	cout<<"     ";
	gotoxy(x,y+2);
	cout<<"     "<<endl;

}

void select(int x,int y)
{
				if (p=='1')
				{
					cheema(x,y);
				}
				else if(p=='2')
				{
					sabir(x,y);
				}
				else if(p=='3')
				{
					malixk(x,y);
				}
				else if(p=='4')
				{
					amin(x,y);
				}
				else if(p=='5')
				{
					maida(x,y);
				}
				else if(p=='9')
				{
					ali(x,y);
				}
				else if(p=='6')
				{
					amber(x,y);
				}
				else if(p=='7')
				{
					sani(x,y);
				}
				else if(p=='8')
				{
					hamad(x,y);
				}
}
void timer()
{
	if(t==0)
	{
		gotoxy(30,30);
		setcolor(12);
		cout<<"- :  gAmE OvEr  : - ";
		Sleep(3000);
		exit(0);
	}
	t=t-1;
	setcolor(14);
	gotoxy(5,57);
	cout<<" Clock :- ";
	setcolor(12);
	cout<<t;
}
char up(int &x,int &y)
{		
	char key='i';
	setcolor(14);
	while(key=='i')
	{
		while(!_kbhit())
		{
			if(scr[x][y-1]!=ch && scr[x+1][y-1]!=ch && scr[x+2][y-1]!=ch && scr[x+3][y-1]!=ch && scr[x+4][y-1]!=ch)
			{
				score(x,y);
				win();
				select(x,y);	
				Sleep(60);
				sum=sum+50;
				if(sum%1000==0)
				{
					timer();
				}
				remove(x,y);
				y=y-1;
			}
			else
			{
				select(x,y);
				sum=sum+50;
				Sleep(60);
				if(sum%1000==0)
				{
					timer();
				}
			}
		}
		key=_getch();
		if(key=='j')
		{
			if(scr[x-1][y]==ch || scr[x-1][y+1]==ch || scr[x-1][y+2]==ch)
			{
				key='i';
			}
		}
		if(key=='l')
		{
			if(scr[x+5][y]==ch || scr[x+5][y+1]==ch || scr[x+5][y+2]==ch)
			{
				key='i';
			}
		}
		if(key!='k' && key!='i' && key!='j' && key!='l')
		{
			key='i';
		}
	}
	return key;	
}

char down(int &x,int &y)
{		
	char key='k';
	setcolor(14);
	while(key=='k')
	{
		while(!_kbhit())
		{
			if(scr[x][y+3]!=ch && scr[x+1][y+3]!=ch && scr[x+2][y+3]!=ch && scr[x+3][y+3]!=ch && scr[x+4][y+3]!=ch)
			{
				score(x,y);
				win();
				select(x,y);	
				Sleep(60);
				sum=sum+50;
				if(sum%1000==0)
				{
					timer();
				}
				remove(x,y);		
				y=y+1;
			}
			else
			{
				select(x,y);
				sum=sum+50;
				Sleep(60);
				if(sum%1000==0)
				{
					timer();
				}
			}
		}
		key=_getch();
		if(key=='j')
		{
			if(scr[x-1][y]==ch || scr[x-1][y+1]==ch || scr[x-1][y+2]==ch)
			{
				key='k';
			}
		}
		if(key=='l')
		{
			if(scr[x+5][y]==ch || scr[x+5][y+1]==ch || scr[x+5][y+2]==ch)
			{
				key='k';
			}
		}
		if(key!='k' && key!='i' && key!='j' && key!='l')
		{
			key='k';
		}
	}
	return key;	
}

char frwd(int &x,int &y)
{
	char key='l';
	setcolor(14);
	while( key=='l')
	{
			while(!_kbhit())
			{
				
				if(scr[x+5][y]!=ch && scr[x+5][y+1]!=ch && scr[x+5][y+2]!=ch)
				{
					score(x,y);
					win();
					select(x,y);
					Sleep(60);
					sum=sum+50;
					if(sum%1000==0)
					{
						timer();
					}
					remove(x,y);
					x=x+1;
					if(x==75 )
					{
						x=0;
					}
				}
				else
				{
					select(x,y);
					sum=sum+50;
					Sleep(60);
					if(sum%1000==0)
					{
						timer();
					}
				}
				
				
			}
			key=_getch();
				if(key=='i')
			{
				if(scr[x][y-1]==ch || scr[x+1][y-1]==ch || scr[x+2][y-1]==ch || scr[x+3][y-1]==ch || scr[x+4][y-1]==ch)
				{
					key='l';
				}
			}
			if(key=='k')
			{
				if(scr[x][y+3]==ch || scr[x+1][y+3]==ch || scr[x+2][y+3]==ch || scr[x+3][y+3]==ch || scr[x+4][y+3]==ch)

				{
					key='l';
				}
			}
			if(key!='k' && key!='i' && key!='j' && key!='l')
			{
				key='l';
			}
	}
	return key;
}


char back(int &x,int &y)
{
	char key='j';
	setcolor(14);
	while(key=='j')
	{
		while(!_kbhit())
		{
			

			if(scr[x-1][y]!=ch && scr[x-1][y+1]!=ch && scr[x-1][y+2]!=ch)
			{
				score(x,y);
				win();
				select(x,y);	
				Sleep(60);
				sum=sum+50;
				if(sum%1000==0)
				{
					timer();
				}
				remove(x,y);	
				x=x-1;
				if(x==0)
				{
					x=75;
				}
			}
			else
			{
				select(x,y);
				sum=sum+50;
				Sleep(60);
				if(sum%1000==0)
				{
					timer();
				}
			}
			
			

		}
		key=_getch();
		if(key=='i')
			{
				if(scr[x][y-1]==ch || scr[x+1][y-1]==ch || scr[x+2][y-1]==ch || scr[x+3][y-1]==ch || scr[x+4][y-1]==ch)
				{
					key='j';
				}
			}
			if(key=='k')
			{
				if(scr[x][y+3]==ch || scr[x+1][y+3]==ch || scr[x+2][y+3]==ch || scr[x+3][y+3]==ch || scr[x+4][y+3]==ch)

				{
					key='j';
				}
			}

		if(key!='k' && key!='i' && key!='j' && key!='l')
		{
			key='j';

		}
	}
	return key;
}
void menu()
{
	gotoxy(30,5);
	cout<<" -: sEleCt yOuR pLAyEr :-   (1-9)";

	gotoxy(10,10);
	setcolor(12);
	cout<<"1 -CHEEMA :- ";
	cheema(30,10);
	Sleep(1000);

	gotoxy(10,20);
	setcolor(11);
	cout<<"2 -SABIR :- ";
	sabir(30,20);
	Sleep(1000);

	gotoxy(10,30);
	setcolor(14);
	cout<<"3 -Malixk :- ";
	malixk(30,30);
	Sleep(1000);

	gotoxy(10,40);
	setcolor(13);
	cout<<"4 -a M i N :- ";
	setcolor(12);
	amin(30,40);
	Sleep(1000);

	gotoxy(50,10);
	setcolor(12);
	cout<<"5 -MaiDa :- ";
	setcolor(9);
	maida(70,10);
	Sleep(1000);

	
	gotoxy(50,20);
	setcolor(13);
	cout<<"6 -AmBeR :- ";
	setcolor(12);
	amber(70,20);
	Sleep(1000);

	gotoxy(50,30);
	setcolor(10);
	cout<<"7 -SaNi aNgEL :- ";
	setcolor(10);
	sani(70,30);
	Sleep(1000);

	gotoxy(50,40);
	setcolor(6);
	cout<<"8 - C.M hAmMaD :- ";
	setcolor(6);
	hamad(70,40);
	Sleep(1000);

	gotoxy(30,47);
	setcolor(14);
	cout<<"9-  -: LORD ALI 007 :-";
	Sleep(200);
	setcolor(12);
	gotoxy(30,50);
	cout<<chs;
	gotoxy(30,51);
	cout<<chs;
	gotoxy(30,52);
	cout<<chs;
	Sleep(500);
	ali(39,50);
	Sleep(200);
	setcolor(12);
	gotoxy(50,50);
	cout<<"  "<<chs;
	gotoxy(50,51);
	cout<<"  "<<chs;
	gotoxy(50,52);
	cout<<"  "<<chs;
	Sleep(1000);


	do
	{	
		p =_getch();
	}while(p<'0' || p>'9');

	system("CLS");
	Sleep(1000);
	setcolor(7);
	gotoxy(30,5);
	cout<<" -: sEleCt ThE sTaGe :-    (1-6)";
	Sleep(200);

	setcolor(7);
	gotoxy(30,10);
	cout<<"* Press 1 for  :- ";
	setcolor(9);
	cout<<"wAteR wOrlD ";
	Sleep(200);

	setcolor(7);
	gotoxy(30,15);
	cout<<"* Press 2 for  :- ";
	setcolor(10);
	cout<<"jUngLE jOuRnEy ";
	Sleep(200);

	setcolor(7);
	gotoxy(30,20);
	cout<<"* Press 3 for  :- ";
	setcolor(11);
	cout<<"iCe wOrLd ";
	Sleep(200);

	setcolor(7);
	gotoxy(30,25);
	cout<<"* Press 4 for  :- ";
	setcolor(12);
	cout<<"FiRe kInGdOm  ";
	Sleep(200);

	setcolor(7);
	gotoxy(30,30);
	cout<<"* Press 5 for  :- ";
	setcolor(13);
	cout<<"FaiRy LAnd ";
	Sleep(200);

	setcolor(7);
	gotoxy(30,35);
	cout<<"* Press 6 for  :- ";
	setcolor(14);
	cout<<"sUnriSe ";
	Sleep(200);

	do
	{	
		stage =_getch();

	}while(stage<'0' || stage>'7');
	stage=stage-48;
}
int main()
{
	menu();
	system("CLS");
	intialize();
	show(scr);
	setcolor(14);
	gotoxy(5,57);
	cout<<" clock ;- ";
	setcolor(12);
	cout<<t;
	int a=38,b=23;
	char key='l';
	while(countOfTiles<=n)
	{
		if(key=='l')
		{
			key=frwd(a,b);
		}
		
		if(key=='k')
		{
			key=down(a,b);
		}

		if(key=='j')
		{
			key=back(a,b);
		}

		if(key=='i')
		{
			key=up(a,b);
		}
	}
	
}