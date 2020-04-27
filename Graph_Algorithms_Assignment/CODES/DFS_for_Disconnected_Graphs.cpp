#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int V;
vector<int> *vec;

void DFSnode(int node, int visited[])
{
    visited[node]=1;
    cout<<node<<" ";
    for(auto i=vec[node].begin();i!=vec[node].end();i++)
        if(visited[*i]==0)
            DFSnode(*i,visited);

}

void DFS(int initial)
{
    int visited[V]={0};
    DFSnode(initial,visited);

    for(int i=0;i<V;i++)
        if(visited[i]==0)
            DFSnode(i,visited);
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

    cout<<endl<<"The DFS traversal is : ";
    DFS(initial);
}

/*
INPUT:
Number of vertices:
10
Number of edges:
10
7 0
7 2
6 3
6 4
1 5
9 6
1 7
1 9
4 9
9 8
Initial vertex:
2

OUTPUT:
2 0 1 5 7 9 6 3 4 8

*/
