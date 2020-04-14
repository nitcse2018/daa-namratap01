/* There is a video game consisting of L levels and N obstacles. The game allows you to cross a level only after you
have passed all the obstacles present in that particular level. Obstacles are numbered from 0 to N-1.
By mistake the game was deleted from the system. Fortunately, after installing back again, all the levels that were cleared still remain unlocked
but the player needs to pass all obstacles again before moving to the next level.
Rules:
1)As all levels are already unlocked, so we can play levels in any order.
2)For every level that we decide to play again, we have to pass all the obstacles present within it before deciding to play any other level
that has not been crossed yet. But, it is possible that we have passed some obstacles as the levels are being played in random order.
So, if we pass X new obstacles, then we incur a loss of X^m experience points in that level, where M is the player difficulty multiplier
defined by game itself and is constant for all levels. At every level, we will incur some loss of experience points that we had earned
throughout the game.

We need to find the minimum experience points that would be deducted to unlock the next level.
*/
#include<bits/stdc++.h>
using namespace std;
int levels,obs,m,*check;
int exp_point=0;
int findminlen(vector<vector<int> > obstacle)
{
    int mini=obstacle[0].size();
    int index=0;
    for(int i=1;i<obstacle.size();i++)
        if(obstacle[i].size()<mini)
        {
            mini=obstacle[i].size();
            index=i;
        }

    for(int i=0;i<mini;i++)
            check[obstacle[index][i]]=1;

    return index;
}

void deletecommon(vector<vector<int> > &obstacle)
{
    for(int j=0;j<obs;j++)
    {
        if(check[j]!=0)
        {
            for(int i=0;i<obstacle.size();i++)
            {
                vector<int>::iterator it=obstacle[i].begin();
                while(it!=obstacle[i].end())
                {
                    if(*it==j)
                    {it=obstacle[i].erase(it);
                    break;}
                    else
                        it++;
                }
            }

        }
    }
}

void findminpoints(vector<vector<int> > &obstacle)
{
    if(obstacle.size()==0)
        return;
    int index=findminlen(obstacle);
    exp_point=exp_point+pow(obstacle[index].size(),m);
    obstacle.erase(obstacle.begin()+index);
    deletecommon(obstacle);
    findminpoints(obstacle);
}

int main()
{
    cin>>levels>>obs>>m;
    check=new int[obs];
    fill(check,check+obs,0);
    vector<vector<int> > obstacle;
    for(int i=0;i<levels;i++)
    {
        int len;
        cin>>len;
        vector<int> v1;
        for(int j=0;j<len;j++)
        {
            int num;
            cin>>num;
            v1.push_back(num);
        }
        obstacle.push_back(v1);
    }
    findminpoints(obstacle);
    cout<<exp_point;

}
/*
INPUT1:
3 4 5
3 0 1 2
2 0 1
2 2 3

OUTPUT: 34

INPUT2:
20 20 2
13 1 3 4 5 6 8 9 11 14 15 17 18 19
11 0 1 2 3 4 6 11 12 13 15 19
7 0 3 6 10 11 13 16
15 0 1 2 3 5 6 7 8 9 10 11 15 16 17 18
10 4 6 8 9 11 12 14 16 17 19
10 0 1 2 3 8 10 11 16 18 19
13 1 2 4 5 9 12 13 14 15 16 17 18 19
12 0 1 2 3 4 5 7 8 13 17 18 19
12 0 1 2 3 4 9 10 14 16 17 18 19
13 0 4 5 6 7 9 10 11 12 16 17 18 19
12 0 1 2 3 6 12 13 14 15 17 18 19
9 4 6 7 8 9 13 14 15 17
10 4 6 7 9 10 13 15 17 18 19
11 0 1 2 3 4 8 9 10 13 14 17
6 4 9 13 14 17 18
8 1 3 5 7 9 15 18 19
12 1 2 3 5 6 7 9 10 13 14 16 18
11 1 4 5 10 11 12 13 15 16 17 18
10 0 1 5 7 9 11 12 13 14 15
14 0 2 3 4 5 6 7 8 11 12 16 17 18 19

OUTPUT: 72
 */
