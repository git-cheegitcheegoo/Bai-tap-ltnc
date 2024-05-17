#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

void move_up(int a[4][4])
{
	int i,j,xi,yi;
	for(j=0;j<4;j++)
	{
		xi=0,yi=j;
		for(i=1;i<4;i++)
		{
			if(a[i][j]!=0)
			{
				if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
				{
					if(a[xi][yi]==a[i][j])
					{
						a[xi][yi]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[xi][yi]==0)
						{
							a[xi][yi]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[++xi][yi]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else xi++;
			}
		}
	}
}

void move_down(int a[4][4])
{
	int i,j,xi,yi;
	for(j=0;j<4;j++)
	{
		xi=3,yi=j;
		for(i=2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[xi][yi]==a[i][j])
					{
						a[xi][yi]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[xi][yi]==0)
						{
							a[xi][yi]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--xi][yi]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else xi--;
			}
		}
	}
}

void move_left(int a[4][4])
{
	int i,j,xi,yi;
	for(i=0;i<4;i++)
	{
		xi=i,yi=0;
		for(j=1;j<4;j++)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[xi][yi]==a[i][j])
					{
						a[xi][yi]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[xi][yi]==0)
						{
							a[xi][yi]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[xi][++yi]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else yi++;
			}
		}
	}
}

void move_right(int a[4][4])
{
	int i,j,xi,yi;
	for(i=0;i<4;i++)
	{
		xi=i,yi=3;
		for(j=2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[xi][yi]==a[i][j])
					{
						a[xi][yi]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[xi][yi]==0)
						{
							a[xi][yi]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[xi][--yi]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else yi--;
			}
		}
	}
}

void addblock(int a[4][4])
{
	int xi,yi;
	srand(time(0));
	while(1)
	{
		xi=rand()%4;
		yi=rand()%4;
		if(a[xi][yi]==0)
		{
			a[xi][yi]=pow(2,xi%2 + 1);
			break;
		}
	}

}

void ui(int a[4][4])
{
	cout<<"\n\t\t\tPress ESC to quit the game";
	cout<<"\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t-------------------------\n\t\t\t";
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<"|     ";
			else
                if (a[i][j] < 10) cout << "|  " << a[i][j] << "  ";
                if (a[i][j] >= 10 && a[i][j] < 100) cout << "|  " << a[i][j] << " ";
                if (a[i][j] >= 100 && a[i][j] < 1000) cout << "| " << a[i][j] << " ";
                if (a[i][j] >= 1000) cout << "| " << a[i][j];

		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t------------------------\n";
}

int move_approval(int tmp[4][4],int a[4][4])
{
	int fl=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=a[i][j])
    		{
    			fl=0;
    			break;
			}
	return fl;
}

int movability_checker(int a[4][4])
{
	int fl=0,gl=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(a[i][j]==0)
    		{
    			fl=1;
				break;
			}

	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
    		{
    			gl=1;
    			break;
			}

	if(fl || gl) return 1;
	else return 0;
}

int main()
{
	cout<<"\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
	getch();
	system("cls");
	int i1,i2,i3,i4,i,j;
	int board[4][4]={0},tmp[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;
	while(1)
	{
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 && i4!=i2) break;
	}
	board[i1][i2]=2;
	board[i3][i4]=4;
	ui(board);

	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			tmp[i][j]=board[i][j];
    	ch=getch();
    	system("cls");
    	if(ch==72) move_up(board);
    	if(ch==80) move_down(board);
    	if(ch==75) move_left(board);
    	if(ch==77) move_right(board);
		if(ch==27) break;

		if(!move_approval(tmp,board))
			addblock(board);
		ui(board);

		if(!movability_checker(board))
		{
			cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}
	}
	return 0;
}
