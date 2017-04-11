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
int color=0,n=3,t_x=0,t_y=0,x[100]={30,29,28},y[100]={10,10,10},score=0,life=1,delay=100;
char ch='%',key='l';
void boundary()
{
	int x=1;
	gotoxy(0,0);
	char ch1=219,ch2=177;
	setcolor(12);
	for(int i=0;i<80;i=i+1)
	{
		if(i%2==0)
		{
			setcolor(12);

		}
		else
		{
			setcolor(14);
		}
		Sleep(10);
		cout<<ch1;
	}
	setcolor(14);
	while(x<=20) 
	{
		if(x%2==0)
		{
			setcolor(14);
		}
		else
		{
			setcolor(12);
		}
		gotoxy(0,x);
		Sleep(20);
		cout<<ch1;
		gotoxy(79,x);
		cout<<ch1<<endl;
		x=x+1;
	}
	gotoxy(0,20);
	setcolor(12);
	for(int i=0;i<80;i=i+1)
	{
		if(i%2==0)
		{
			setcolor(14);
		}
		else
		{
			setcolor(12);
		}
		Sleep(10);
		cout<<ch1;
	}
}
void incre()
{
	if(x[0]==t_x && y[0]==t_y)
	{
		n=n+1;
		gotoxy(30,22);
		setcolor(14);
		cout<<"* ScOrE = "<<score;
		int flag=1;
		do
		{
			t_x =(rand()%59)+11;
			t_y =(rand()%19)+1;
			for(int i=0;i<n;i=i+1)
			{
				if(t_x==x[i] && t_y==y[i])
				{
					flag=0;
					break;
				}
			}
		}while(flag==0);
		color=rand()%6;
		switch(color)
		{
			case 0:
			setcolor(12);
			gotoxy(t_x,t_y);
			cout<<"@";
			score=score+10;
			break;

			case 1:
			setcolor(9);
			gotoxy(t_x,t_y);
			cout<<"*";
			score=score+30;
			break;

			case 2:
			setcolor(11);
			gotoxy(t_x,t_y);
			cout<<"#";
			score=score+50;
			break;

			case 3:
			setcolor(14);
			gotoxy(t_x,t_y);
			cout<<"$";
			score=score+100;
			break;

			case 4:
			setcolor(13);
			gotoxy(t_x,t_y);
			cout<<"%";
			score=score+20;
			break;

			case 5:
			setcolor(10);
			gotoxy(t_x,t_y);
			cout<<"O";
			score=score+70;
			break;
		}

		
	}
}
void cond()
{
	for(int i=0;i<n;i=i+1)
	{
		if(x[i]==79)
		{		
			x[i]=1;
		}
		if(x[i]==0)
		{		
			x[i]=78;
		}
		
		if(y[i]==20)
		{		
			y[i]=1;
		}
		if(y[i]==0)
		{		
			y[i]=19;
		}
	}

}
void dead()
{
	for(int i=1;i<n;i=i+1)
	{
		if(x[0]==x[i] && y[0]==y[i])
		{
			setcolor(14);
			gotoxy(30,10);
			life=life-1;
			
			setcolor(12);
			gotoxy(50,22);
			cout<<"Life : "<<life;
			for(int i=1;i<n;i=i+1)
			{
				gotoxy(x[i],y[i]);
				cout<<" ";
			}
			n=3;x[0]=40;y[0]=10;
			_getch();
			if(life==0)
			{
				gotoxy(30,10);
				setcolor(14);
				cout<<"--:G A M E  O V E R :--"<<endl;
				Sleep(2000);
				_getch();
				exit(0);
			}
		}
	}
}
char up()
{		
	setcolor(14);
	while(key=='i')
	{
		while(!_kbhit())
		{
			dead();
			incre();
			setcolor(14);
			gotoxy(x[0],y[0]);
			cout<<"O";
			
			Sleep(delay);
			gotoxy(x[n-1],y[n-1]);
			cout<<" ";
			
			
			for(int i=n;i>0;i=i-1)
			{
				y[i]=y[i-1];
				x[i]=x[i-1];
			}
			y[0]=y[0]-1;
			cond();
		}
		key=_getch();
		if(key!='j'&& key!='l')
		{
			key='i';
		}
	}
	return key;	
}

char down()
{		
	
	setcolor(14);
	while(key=='k')
	{
		while(!_kbhit())
		{
			dead();
			incre();
			setcolor(14);
			gotoxy(x[0],y[0]);
			cout<<"O";
			
			Sleep(delay);
			gotoxy(x[n-1],y[n-1]);
			cout<<" ";
			
			
			for(int i=n;i>0;i=i-1)
			{
				y[i]=y[i-1];
				x[i]=x[i-1];
			}
			y[0]=y[0]+1;
			cond();
		}
		key=_getch();
		if(key!='j'&& key!='l')
		{
			key='k';
		}
	}
	return key;	
}

char frwd()
{
	
	setcolor(14);
	while( key=='l')
	{
			while(!_kbhit())
			{
				dead();
				incre();
				setcolor(14);
				gotoxy(x[0],y[0]);
				cout<<"O";
			
				Sleep(delay);
				gotoxy(x[n-1],y[n-1]);
				cout<<" ";
				for(int i=n;i>0;i=i-1)
				{
					x[i]=x[i-1];
					y[i]=y[i-1];
				}
				x[0]=x[0]+1;
				cond();
			}
			key=_getch();
			if(key!='k' && key!='i')
			{
				key='l';
			}
	}
	return key;
}


char back()
{
	
	setcolor(14);
	while(key=='j')
	{
		while(!_kbhit())
		{
			dead();
			incre();
			setcolor(14);
			gotoxy(x[0],y[0]);
			cout<<"O";
			
			Sleep(delay);
			gotoxy(x[n-1],y[n-1]);
			cout<<" ";
			
			for(int i=n;i>0;i=i-1)
			{
				x[i]=x[i-1];
				y[i]=y[i-1];
			}
			x[0]=x[0]-1;
			cond();
		}
		key=_getch();
		if(key!='k' && key!='i')
		{
			key='j';
		}
	}
	return key;

}
int main()
{
	setcolor(14);
	gotoxy(30,15);
	char level;
	setcolor(14);
	cout<<"SeLeCt tHe level .. (1-3) \n\n\t\t\t\t";
	do
	{
		level=_getch();
	}while(level>'3' || level<'1');
	switch(level)
	{
	case '1':
		delay=100;
		break;
	case '2':
		delay=70;	
		break;
	case '3':
		delay=40;
		break;
	}
	system("CLS");
	boundary();
	unsigned seed=time(0);
	srand(seed);
	setcolor(12);
	gotoxy(50,22);	
	cout<<"Life : "<<life;
	setcolor(14);
	gotoxy(30,22);
	cout<<"* ScOrE = "<<score;
	t_x =(rand()%59)+11;
	t_y =(rand()%19)+1;
	color=14;
	gotoxy(t_x,t_y);
	setcolor(color);
	cout<<"@";
	setcolor(14);
	for(int i=0;i<3;i=i+1)
	{
		gotoxy(x[i],y[i]);
		cout<<"O";
	}
	char key='l';
	while(life!=0)
	{
		if(key=='l')
		{
			key=frwd();
		}
		
		if(key=='k')
		{
			key=down();
		}

		if(key=='j')
		{
			key=back();
		}

		if(key=='i')
		{
			key=up();
		}
	}

}