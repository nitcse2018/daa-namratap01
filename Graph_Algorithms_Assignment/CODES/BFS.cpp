#include<iostream>
#include<cstdlib>
#include<queue>
using namespace std;
int V,initial;
vector<int> *vec;

void BFS()
{
    int visited[V]={0};
    queue<int> myQ;
    visited[initial]=1;
    myQ.push(initial);
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

int main()
{
    int edge;
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

    BFS();

}
/*
0 1
1 2
1 2
1 3
2 3
3 4
4 1
4 0
4 5
*/
