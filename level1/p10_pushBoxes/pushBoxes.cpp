#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char map[11][11];
int Nowx, Nowy;
void READMAP(int i);
int move(char get);
void printmap();
int check();
void Addscore(int k,int n);

int main()
{
	char ch,c;
	printf("Welcome to push boxes!\nPlease press enter to begin.");
	while(1)
	{
		if(kbhit())
		{
			c = getch();
			if(c==13)
			{
				system("cls");
				break;
			}
		}
	}     
	for(int i=1; i<=3; i++)
	{
		READMAP(i);
		printmap();
		int n=0, flag;
		while(1)
		{
			if(kbhit())
			{
				ch = getch();
				n = move(ch);
				system("cls");
				printmap();
				flag = check();
				if(flag == 0)
				{
					printf("You took %d steps\n.", n);
					printf("Please press any key to the next level.");
					if(kbhit())
					{
						break;
					}
				}
			}
		}
		Addscore(i,n);
		system("cls");			
	}
	return 0;
}

int move(char get)        //记录人物和箱子移动 
{
	char ch=get;
	int pace=0;
	if(ch==72 && map[Nowx-1][Nowy]!='$')              //向左移动 
	{
		if(map[Nowx-1][Nowy]=='2' || map[Nowx-1][Nowy]=='1')
		{
			Nowx--;
			pace++;
			return pace;
		}
		if(map[Nowx-1][Nowy]=='0' && (map[Nowx-2][Nowy]=='2' || map[Nowx-2][Nowy]=='1'))
		{
			map[Nowx-2][Nowy]='0';
			map[Nowx-1][Nowy]='2';
			Nowx--;
			pace++;
			return pace;
		}
	}
	if(ch==80 && map[Nowx+1][Nowy]!='$')             //向右移动 
	{
		if(map[Nowx+1][Nowy]=='2' || map[Nowx+1][Nowy]=='1')
		{
			Nowx++;
			pace++;
			return pace;
		}
		if(map[Nowx+1][Nowy]=='0' && (map[Nowx+2][Nowy]=='2' || map[Nowx+2][Nowy]=='1'))
		{
			map[Nowx+2][Nowy]='0';
			map[Nowx+1][Nowy]='2';
			Nowx++;
			pace++;
			return pace;
		}
	}
	if(ch==75 && map[Nowx][Nowy-1]!='$')            //向上移动 
	{
		if(map[Nowx][Nowy-1]=='2' || map[Nowx][Nowy-1]=='1')
		{
			Nowy--;
			pace++;
			return pace;
		}
		if(map[Nowx][Nowy-1]=='0' && (map[Nowx][Nowy-2]=='2' || map[Nowx][Nowy-2]=='1'))
		{
			map[Nowx][Nowy-2]='0';
			map[Nowx][Nowy-1]='2';
			Nowy--;
			pace++;
			return pace;
		}
	}
	if(ch==77 && map[Nowx][Nowy+1]!='$')            //向下移动 
	{
		if(map[Nowx][Nowy+1]=='2' || map[Nowx][Nowy+1]=='1')
		{
			Nowy++;
			pace++;
			return pace;
		}
		if(map[Nowx][Nowy+1]=='0' && (map[Nowx][Nowy+2]=='2' || map[Nowx][Nowy+2]=='1'))
		{
			map[Nowx][Nowy+2]='0';
			map[Nowx][Nowy+1]='2';
			Nowy++;
			pace++;
			return pace;
		}
	}
}

void READMAP(int k)              //读取地图 
{
	FILE *fp;
	const char *myfile;
	switch(k)
	{
		case 1:	{	myfile = "D:\\maps\\map1.txt";
			   		fp = fopen("D:\\maps\\map1.txt", "r");
											break;
				}	
		case 2: {	myfile = "D:\\maps\\map2.txt";
		  	   		fp = fopen("D:\\maps\\map2.txt", "r");
											break;
		        }		
		case 3:	{	myfile = "D:\\maps\\map3.txt";
			   		fp = fopen("D:\\maps\\map3.txt", "r");
											break;
		   		}		
	}
	
	if( fp == NULL )
	{
		printf("Cannot find %s", myfile);
	}
	else
	{
		for(int i=0; i<=10; i++)
		{
			for(int j=0; j<=10; j++)
			{
				map[i][j] = fgetc(fp);
				if( map[i][j] == 'P')
				{
					Nowx = i;
					Nowy = j;
					map[i][j] = '2';
				}
			}
		}
	}
	fclose(fp);
}

void printmap()                       //打印地图 
{
	for(int i=0; i<=10; i++)
	{
		for(int j=0; j<=10; j++)
		{
			if(i == Nowx && j == Nowy)
			{
				printf("P");
			}
			else if(map[i][j] == '2')
			{
				printf(" ");
			}
			else if(map[i][j] == '1')
			{
				printf("!");
			}
			else
			{
				printf("%c", map[i][j]);
			}
		}
	}
}

int check()               //检查是否完成目标 
{
	int flag = 0;
	int i, j;
	for(i=0; i<=10; i++)
	{
		for(j=0; j<=10; j++)
		{
			if( map[i][j] == '1');
			{
				flag = 1;
				break;
			}
		}
	}
	return flag;
}

void Addscore(int k,int n)
{
	FILE *fp;
	const char *myfile;
	switch(k)
	{
		case 1:	{	myfile = "D:\\maps\\map1.txt";
			   		fp = fopen("D:\\maps\\map1.txt", "a");
											break;
				}	
		case 2: {	myfile = "D:\\maps\\map2.txt";
		  	   		fp = fopen("D:\\maps\\map2.txt", "a");
											break;
		        }		
		case 3:	{	myfile = "D:\\maps\\map3.txt";
			   		fp = fopen("D:\\maps\\map3.txt", "a");
											break;
		   		}		
	}
	
	fprintf(fp, "%d", n);
	fclose(fp);
}














