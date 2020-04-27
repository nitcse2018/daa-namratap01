#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int V;
vector<int> *vec;

void DFS(int initial, int visited[])
{
    visited[initial]=1;
    cout<<initial<<" ";
    for(auto i=vec[initial].begin();i!=vec[initial].end();i++)
        if(visited[*i]==0)
            DFS(*i,visited);

}

int main()
{
    int edge,initial;
    cout<<"Number of vertices:"<<endl;
    cin>>V;
    int visited[V]={0};
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

    cout<<"The DFS traversal is : ";
    DFS(initial,visited);

    cout<<endl;
    return 0;
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
1

OUTPUT:
The DFS traversal is : 1 5 7 0 2 9 6 3 4 8

 */
