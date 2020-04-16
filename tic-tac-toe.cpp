#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>


//master commit!!:
//sdding comments!:
//sdding 1 more comment!
//1 more comment line please
int grid[10] = {2,2,2,2,2,2,2,2,2,2};

int turn = 1,flag = 0;
int player,comp;

void menu();
void go(int n);
void startgame();
void checkdraw();
void drawgrid();
void playerfirst();
void put(char ch,int pos);
COORD coord= {0,0}; 

int  main()
	{
		
    	system("cls");
    	menu();
    	getch();
	return 0;
	}

//menu function
void menu()
{
	int choice;
    system("cls");
    printf("\n--------MENU--------");
    printf("\n Always first player gets 'X' mark for play.");
    printf("\n1 : Play with X");
    printf("\n2 : Play with O");
    printf("\n3 : Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    turn = 1;
    switch (choice)
    {
    case 1:
        player = 1;
        comp = 0;
        playerfirst();
        break;
    case 2:
        player = 0;
        comp = 1;
        startgame();
        break;
    case 3:
        exit(1);
    default:
        menu();
    }
}
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


//added posswin comment!!!
int posswin(int p)
{
// p==1 then X   p==0  then  O
    int i;
    int check_val,pos;

    if(p == 1)
        check_val = 18;
    else
        check_val = 50;

    i = 1;
    while(i<=9)//row check
    {
        if(grid[i] * grid[i+1] * grid[i+2] == check_val)
        {
            if(grid[i] == 2)
                return i;
            if(grid[i+1] == 2)
                return i+1;
            if(grid[i+2] == 2)
                return i+2;
        }
        i+=3;
    }

    i = 1;
    while(i<=3)//column check
    {
        if(grid[i] * grid[i+3] * grid[i+6] == check_val)
        {
            if(grid[i] == 2)
                return i;
            if(grid[i+3] == 2)
                return i+3;
            if(grid[i+6] == 2)
                return i+6;
        }
        i++;
    }

    if(grid[1] * grid[5] * grid[9] == check_val)
    {
        if(grid[1] == 2)
            return 1;
        if(grid[5] == 2)
            return 5;
        if(grid[9] == 2)
            return 9;
    }

    if(grid[3] * grid[5] * grid[7] == check_val)
    {
        if(grid[3] == 2)
            return 3;
        if(grid[5] == 2)
            return 5;
        if(grid[7] == 2)
            return 7;
    }
    return 0;
}




void playerfirst()
	{
	int p;
    checkdraw();
    drawgrid();
    gotoxy(30,18);
    printf("Your Turn : ");
    scanf("%d",&p);

    if(grid[p] != 2) //if there is a choice in that cell before 
        playerfirst();
		
    if(p == posswin(player))
    {
        go(p);
        drawgrid();
        gotoxy(30,20);
        printf("Player Wins");
        getch();
        exit(0);
    }

    go(p);
    drawgrid();
    startgame();
	}

void drawgrid()
{
    int j;

    for(j=9; j<17; j++)
    {
        gotoxy(35,j);
        printf(":       :");
    }
    gotoxy(28,11);
    printf("-----------------------");
    gotoxy(28,14);
    printf("-----------------------");

    for(j=1; j<10; j++)
    {
        if(grid[j] == 3)
            put('X',j);
        else if(grid[j] == 5)
            put('O',j);
    }
}

	
	void checkdraw()
{
    if(turn > 9)
    {
        gotoxy(30,20);
        printf("Game Draw");
        getch();
        exit(0);
    }
}
	
int mostprob()
{
    if(grid[5] == 2)
        return 5;
    if(grid[2] == 2)
        return 2;
    if(grid[4] == 2)
        return 4;
    if(grid[6] == 2)
        return 6;
    if(grid[8] == 2)
        return 8;
    return 0;
}

int spanall()
{
    if(grid[1] == 2)
        return 1;
    if(grid[3] == 2)
        return 3;
    if(grid[7] == 2)
        return 7;
    if(grid[9] == 2)
        return 9;
    return 0;
}


void startgame()
{

    if(posswin(comp))
    {
        go(posswin(comp));
        flag = 1;
    }
    else if(posswin(player))
        go(posswin(player));
    else if(mostprob())
        go(mostprob());
    else
        go(spanall());
    drawgrid();

    if(flag)
    {
        gotoxy(30,20);
        
        printf("Computer wins");
        getch();
    }
    else
        playerfirst();
}


void go(int n)
{
    if(turn % 2)
        grid[n] = 3;
    else
        grid[n] = 5;
    turn++;
}


void put(char ch,int pos)
{
    int m;
    int x = 31, y = 10;
    m = pos;
    if(m > 3)
    {
        while(m > 3)
        {
            y += 3;
            m -= 3;
        }
    }
    if(pos % 3 == 0)
        x += 16;
    else
    {
        pos %= 3;
        pos--;
        while(pos)
        {
            x+=8;
            pos--;
        }
    }
    gotoxy(x,y);
    printf("%c",ch);
}
