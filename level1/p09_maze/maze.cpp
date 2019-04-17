#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char maze[16][16]={ {"$$$$$$$$$$$$$$$"},      //地图 
		  			{"$  $  $ $$ $$ $"},
		  			{"$$ $ $$     $ $"},
		  			{"$  $    $$$ $ $"},
		  			{"$ $$$ $$$     $"},
		  			{"$         $$$ $"},
		  			{"$$$$$$$ $   $ $"},
		  			{"$  $    $ $$$ $"},
		  			{"$$ $ $$$$$$ $ $"},
		  			{"$$ $ $$     $$$"},
		  			{"$       $$    $"},
		  			{"$ $$$$$$$   $ $"},
		  			{"$     $ $ $$$$$"},
		  			{"$ $ $   $     $"},
		  			{"$$$$$$$$$$$$$$$"}};
#define flagX 13                  //目标位置 
#define flagY 13
int Nowx, Nowy;
void printmaze();
void move(char get);

int main()
{
	system("color 74");
	char ch;
	Nowx=1;
	Nowy=1;

	printmaze();
	while(1)
	{
		if(kbhit())
		{
			ch = getch();
			move(ch);
			system("cls");
			printmaze();
			if(Nowx==flagX && Nowy==flagY)	break;
		}
	}
	printf("Victory!!!");
	return 0;
}

void printmaze()          //打印迷宫 
{
	for(int i=0; i<=14; i++)
	{
		for(int j=0; j<=14; j++)
		{
			if( maze[i][j] == '$' && ( i!=Nowx || j!=Nowy))          printf("$");
			else if( maze[i][j] == ' ' && ( i==Nowx && j==Nowy) )    printf("P");
			else if( maze[i][j] == ' ' && ( i==flagX && j==flagY) )  printf("!");
			else                 								   printf(" ");
		}
		printf("\n");
	}
}

void move(char get)        //记录人物移动 
{
	char ch=get;
	if(ch==72 && maze[Nowx-1][Nowy]!='$')		Nowx--;
	if(ch==80 && maze[Nowx+1][Nowy]!='$')		Nowx++;
	if(ch==75 && maze[Nowx][Nowy-1]!='$')		Nowy--;
	if(ch==77 && maze[Nowx][Nowy+1]!='$')		Nowy++;
}





