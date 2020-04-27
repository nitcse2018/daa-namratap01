#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int V;
vector<int> *vec;
int *parent;

int findset(int x)
{
    if(parent[x]==-1)
        return x;
    else
        return findset(parent[x]);
}


int Union(int x,int y)
{
    int xset = findset(x);
    int yset = findset(y);
    if(xset != yset)
    {
        parent[xset] = yset;
    }
}

int Cycle()
{
    parent=new int[V];
    fill(parent,parent+V,-1);
    int i=0;
    while(i<V)
    {
        int x=findset(i);
        for(int j=0;j<vec[i].size();j++)
        {
            int y=findset(vec[i][j]);
            if(x==y)
                return 1;

            Union(x,y);
        }
        i++;
    }
    return 0;
}

int main()
{
    int edge;
    cout<<"Number of vertices:"<<endl;
    cin>>V;
    vec =new vector<int>[V];
    cout<<"Number of edges:"<<endl;
    cin>>edge;
    int v1,v2;
    while(edge>0)
    {
        cin>>v1>>v2;
        vec[v1].push_back(v2);
        edge--;
    }
    if(Cycle())
        cout<<"The graph has a cycle";
    else
        cout<<"The graph doesn't contain a cycle";

}
/*
6
0 1
1 2
2 3
2 5
3 5
3 4
 */
