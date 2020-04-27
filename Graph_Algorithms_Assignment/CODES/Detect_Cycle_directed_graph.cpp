#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V;
vector<int> *vec;
int *in_degree;

int Cycle()
{
    queue<int> myQ;
    for(int i=0;i<V;i++)
        if(in_degree[i]==0)
            myQ.push(i);

    int counts=0;

    while(!myQ.empty())
    {
        int node=myQ.front();
        myQ.pop();

        for(auto i=vec[node].begin();i!=vec[node].end();i++)
            if(--in_degree[*i]==0)
                myQ.push(*i);

        counts++;
    }
    if(counts==V)
        return 0;
    return 1;
}

int main()
{
    int edge,initial;
    cout<<"Number of vertices:"<<endl;
    cin>>V;
    in_degree=new int[V];
    fill(in_degree,in_degree+V,0);
    vec=new vector<int>[V];
    cout<<"Number of edges:"<<endl;
    cin>>edge;
    int v1,v2;
    while(edge>0)
    {
        cin>>v1>>v2;
        in_degree[v2]++;
        vec[v1].push_back(v2);
        edge--;
    }
    if(Cycle())
        cout<<"The graph has a cycle";
    else
        cout<<"The graph doesn't contain a cycle";
}
/*
INPUT:
Number of vertices:
7
Number of edges:
8
0 1
0 2
1 4
2 6
3 2
3 6
3 1
4 3

OUTPUT:
The graph has a cycle


INPUT:
Number of vertices:
7
Number of edges:
8
0 1
0 2
1 4
2 6
3 1
3 2
3 4
3 6

OUTPUT:
The graph doesn't contain a cycle
*/
