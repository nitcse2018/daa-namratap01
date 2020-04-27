#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
int V,initial;
vector<int> *vec;

void BFSnode(int nodei,int visited[])
{

    queue<int> myQ;
    visited[nodei]=1;
    myQ.push(nodei);
    while(!myQ.empty())
    {
        int node=myQ.front();
        myQ.pop();
        cout<<node<<" ";
        for(auto i=vec[node].begin();i!=vec[node].end();i++)
            if(visited[*i]==0)
            {
                visited[*i]=1;
                myQ.push(*i);
            }
    }
}

void BFS(int initial)
{
    int visited[V]={0};
    BFSnode(initial,visited);
    for(int i=0;i<V;i++)
        if(visited[i]==0)
            BFSnode(i,visited);
}

int main()
{

    int edge,initial;
    cout<<"Number of vertices:"<<endl;
    cin>>V;
    vec=new vector<int>[V];
    cout<<"Number of edges:"<<endl;
    cin>>edge;
    int v1,v2;
    while(edge>0)
    {
        cin>>v1>>v2;
        vec[v1].push_back(v2);
        edge--;
    }
    cout<<"Initial vertex:"<<endl;
    cin>>initial;
    cout<<endl<<"The corresponding BFS Traversal is : ";
    BFS(initial);

    cout<<endl;
}
/*
INPUT:
Number of vertices:
5
Number of edges:
6
0 4
1 2
1 3
1 4
2 3
3 4
Initial vertex:
2

OUTPUT:
2 3 4 0 1

*/
