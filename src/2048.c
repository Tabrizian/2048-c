#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
int table[8][8];
int newtable[8][8];
int gameover[8][8];
int n;
int fibo[1001];
int c;
void swapTable(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void gameoverTable()
{
    int i;
    for(i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            gameover[i][j]=table[i][j];
        }
    }
}
bool tableEqu()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(table[i][j]!=newtable[i][j])
                return false;
        }
    }
    return true;
}
void shiftLeft()
{
    int i;
    int j,k;
    for(j=0;j<n;j++)
    {
        for(i=0;i<n;i++)
        {
            for(k=0;k<i;k++)
            {
                if(table[j][i]!=0&&table[j][k]==0)
                    swapTable(&table[j][i],&table[j][k]);
            }
        }
    }
}
void shiftRight()
{
    int i;
    int j,k;
    for(j=0;j<n;j++)
    {
        for(i=n-1;i>-1;i--)
        {
            for(k=n-1;k>i;k--)
            {
                if(table[j][i]!=0&&table[j][k]==0)
                    swapTable(&table[j][i],&table[j][k]);
            }
        }
    }
}
void shiftDown()
{
    int i;
    int j,k;
    for(j=n-1;j>-1;j--)
    {
        for(i=n-1;i>-1;i--)
        {
            for(k=n-1;k>i;k--)
            {
                if(table[i][j]!=0&&table[k][j]==0)
                    swapTable(&table[i][j],&table[k][j]);
            }
        }
    }
}
void shiftUp()
{
    int i;
    int j,k;
    for(j=n-1;j>-1;j--)
    {
        for(i=0;i<n;i++)
        {
            for(k=0;k<i;k++)
            {
                if(table[i][j]!=0&&table[k][j]==0)
                    swapTable(&table[i][j],&table[k][j]);
            }
        }
    }
}
void tablePrint()
{
    int i;
    for(i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            if(table[i][j]!=0)
                printf("%5d ",table[i][j]);
            else
                printf("%5c ",'-');
        }
        printf("\n");
    }
    printf("\n");
    switch (c)
    {
    case 72:
    case 'i':
        printf("Your Moved UP\n");
        break;
    case 80:
    case 'k':
        printf("Your Moved DOWN\n");
        break;
    case 75:
    case 'j':
        printf("Your Moved LEFT\n");
        break;
    case 77:
    case 'l':
        printf("Your Moved RIGHT\n");
        break;
    case 'u':
        printf("Your Moved UNDO\n");
    }
}
void mergeTableL()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(table[i][j]==table[i][j+1])
            {
                table[i][j]*=2;
                table[i][j+1]=0;
            }
        }
    }
}
void mergeTableR()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>0;j--)
        {
            if(table[i][j]==table[i][j-1])
            {
                table[i][j-1]*=2;
                table[i][j]=0;
            }
        }
    }
}
void mergeTableU()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(table[j+1][i]==table[j][i])
            {
                table[j][i]*=2;
                table[j+1][i]=0;
            }
        }
    }
}
void mergeTableD()
{
    int i,j;
    for(i=n-1;i>-1;i--)
    {
        for(j=n-2;j>-1;j--)
        {
            if(table[j+1][i]==table[j][i])
            {
                table[j+1][i]*=2;
                table[j][i]=0;
            }
        }
    }
}
void tableCpy()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            newtable[i][j]=table[i][j];
        }
    }
}
void gameoverTableReverse()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            table[i][j]=gameover[i][j];
        }
    }
}
bool gameoverCheck()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(table[i][j]!=gameover[i][j])
                return false;
        }
    }
    return true;
}
bool isOver()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(table[i][j]==0)
                return false;
        }
    }
    gameoverTable();
    mergeTableD();
    mergeTableL();
    mergeTableR();
    mergeTableU();
    if(gameoverCheck())
    {
        return true;
    }
    else
    {
        gameoverTableReverse();
        return false;
    }
    return true;
}
void tableUndo()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            table[i][j]=newtable[i][j];
        }
    }
}
void fib(int n)
{
    if(n<=2)
        fibo[n]=1;
    else
            fibo[n]=fibo[n-1]+fibo[n-2];

}
int main()
{
    int rand1,rand2;
    printf("This Table works with arrow key & l,k,j,i\n");
    printf("Enter Table Dimensions:");
    scanf("%d",&n);;
    int i,j,l;
    for(l=1;l<1000;l++)
        fib(l);
    while(!isOver())
    {
        A:
        rand1=rand()%n;
        rand2=rand()%n;
        if(table[rand1][rand2]==0)
        {
            table[rand1][rand2]=2;
        }
        else
            goto A;
        C:
        system("cls");
        tablePrint();
        B:
        c=getch();
        switch (c){
            case 72:
            case 'i':
                tableCpy();
                shiftUp();
                mergeTableU();
                shiftUp();
                if(tableEqu()&&(!isOver()))
                    goto C;
                else if(isOver())
                    goto D;
                break;
            case 'k':
            case 80:
                tableCpy();
                shiftDown();
                mergeTableD();
                shiftDown();
                if(tableEqu()&&(!isOver()))
                    goto C;
                else if(isOver())
                    goto D;
                break;
            case 75:
            case 'j':
                tableCpy();
                shiftLeft();
                mergeTableL();
                shiftLeft();
                if(tableEqu()&&(!isOver()))
                    goto C;
                else if(isOver())
                    goto D;
                break;
            case 77:
            case 'l':
                tableCpy();
                shiftRight();
                mergeTableR();
                shiftRight();
                if(tableEqu()&&(!isOver()))
                    goto C;
                else if(isOver())
                    goto D;
                break;
            case 'q':
                printf("You Quit Program!!");
                return 0;
                break;
            case 'u':
                printf("Undo Table:\n");
                tableUndo();
                goto C;
                break;
            default:
                goto B;
        }
    }
    D:
    printf("GAME OVER!!");
    return 0;
}

