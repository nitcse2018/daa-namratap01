/* The following program solves a 9*9 input sudoku using back tracking.
Enter '.' for blank spaces*/
#include<iostream>
using namespace std;
#define N 9
char grid[N][N];

void print()
{
    cout<<endl;
    for(auto &i : grid)
    {
         for(auto &j : i)
            cout<< j-'0'<< "  " ;
        cout<<endl;
    }
}

bool isSafe(int row,int col,char num)
{
    for(int i=0;i<N;i++)
    {
        if(grid[row][i]==num || grid[i][col]==num)
            return false;
    }

    int boxrow=row-(row%3);
    int boxcol=col-(col%3);
    for(int i=0;i<3;i++)
        if(grid[boxrow+i][boxcol+i]==num || grid[boxrow+i][boxcol]==num || grid[boxrow][boxcol+i]==num)
            return false;

    return true;

}

bool solveSudoku(int ind)
{
    int row=ind/9,
        col=ind%9;
    if(row==9)
        return true;
    if (grid[row][col]!='.')
        return solveSudoku(ind+1);
    for(char num='1';num<='9';num++)
    {
        if(isSafe(row,col,num))
        {
            grid[row][col]=num;
            if(solveSudoku(ind+1))
                return true;
            grid[row][col]='.';
        }
    }
    return false;
}

int main()
{
    cout<<"Enter a sudoku puzzle to solve:";
    for(auto &i : grid)
        for(auto &j : i)
            cin>> j;

    if (solveSudoku(0)==true)
        print();
    else
        cout<<"This puzzle doesn't have a solution!";
}
/*
INPUT1:
3 . 6 5 . 8 4 . .
5 2 . . . . . . .
. 8 7 . . . . 3 1
. . 3 . 1 . . 8 .
9 . . 8 6 3 . . 5
. 5 . . 9 . 6 . .
1 3 . . . . 2 5 .
. . . . . . . 7 4
. . 5 2 . 6 3 . .

OUTPUT:
3  1  6  5  7  8  4  9  2
5  2  9  1  3  4  7  6  8
4  8  7  6  2  9  5  3  1
2  6  3  4  1  5  9  8  7
9  7  4  8  6  3  1  2  5
8  5  1  7  9  2  6  4  3
1  3  8  9  4  7  2  5  6
6  9  2  3  5  1  8  7  4
7  4  5  2  8  6  3  1  9

INPUT2:
. . 4 . . . . . .
. . . . . . . . .
. . . . . . . . .
. . . . . . . . .
. 4 . . . . . . .
. . . . . . . . .
5 . . . . . . . .
. . . . . . . . .
. . . . . 4 . . .

OUTPUT:
1  2  4  3  5  6  7  8  9
3  5  6  7  8  9  1  2  4
7  8  9  1  4  2  3  5  6
2  1  3  4  6  5  8  9  7
6  4  5  8  9  7  2  1  3
8  9  7  2  1  3  4  6  5
5  3  1  6  7  8  9  4  2
4  6  2  9  3  1  5  7  8
9  7  8  5  2  4  6  3  1

*/
