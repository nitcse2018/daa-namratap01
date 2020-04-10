/* The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other. */
#include<iostream>
using namespace std;
int N;
char **grid;

void print()
{
    cout<<endl;
    for(int i=0;i<N;i++)
    {
         for(int j=0;j<N;j++)
            cout<< grid[i][j]<< "  " ;
        cout<<endl;
    }
}

bool isSafe(int row,int col)
{
    for(int i=0;i<row;i++)
        if(grid[i][col]=='Q')
            return false;
    int i,j;
    for(i=row,j=col;i>=0 && j>=0;)
    {
        if(grid[i--][j--]=='Q')
            return false;
    }
    for(i=row,j=col;i>=0 && j<N;)
    {
        if(grid[i--][j++]=='Q')
            return false;
    }

    return true;

}

bool findQueenpos(int row)
{
    if(row==N)
        return true;
    for(int i=0;i<N;i++)
    {
        if(isSafe(row,i))
        {
            grid[row][i]='Q';
            if(findQueenpos(row+1))
                return true;
            grid[row][i]='.';
        }
    }
    return false;
}

int main()
{
    cin>>N;
    grid=new char*[N];

    for(int i=0;i<N;i++)
    {
        grid[i]=new char[N];
        fill(&grid[i][0],&grid[i][0]+N,'.');
    }

    findQueenpos(0);
    print();

}
/*
INPUT1: 5
OUTPUT:
Q  .  .  .  .
.  .  Q  .  .
.  .  .  .  Q
.  Q  .  .  .
.  .  .  Q  .

INPUT2: 20
OUTPUT:
Q  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
.  .  Q  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
.  .  .  .  Q  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
.  Q  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
.  .  .  Q  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .  .  .  .  .  Q  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .  .  .  .  .  .  .  Q  .  .  .  .  .
.  .  .  .  .  .  .  .  .  .  .  Q  .  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  Q  .  .
.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  Q
.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  Q  .  .  .
.  .  .  .  .  .  .  .  Q  .  .  .  .  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  Q  .  .  .  .
.  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  Q  .
.  .  .  .  .  .  .  Q  .  .  .  .  .  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .  .  Q  .  .  .  .  .  .  .  .  .  .
.  .  .  .  .  .  Q  .  .  .  .  .  .  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .  .  .  .  .  .  Q  .  .  .  .  .  .
.  .  .  .  .  Q  .  .  .  .  .  .  .  .  .  .  .  .  .  .
.  .  .  .  .  .  .  .  .  .  Q  .  .  .  .  .  .  .  .  .

 */
