#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int V;
typedef pair<int,int> edges;

class Disjointset
{
    int *parent;
    public:
    Disjointset(int n)
    {
        parent=new int[V];
        for(int i=0;i<V;i++)
            parent[i]=i;
    }

    int findset(int x)
    {
        if(parent[x]==x)
            return x;
        else
            return findset(parent[x]);


    }

    int Union(int x,int y)
    {
        int xset = findset(x);
        int yset = findset(y);
        if(xset != yset)
            parent[xset] = yset;
    }
};


int kruskalMST(vector<pair<int,edges> > vec)
{
    int weight=0;
    sort(vec.begin(),vec.end());

    Disjointset d(V);

    for(auto i=vec.begin();i!=vec.end();i++)
    {
        int set_u=d.findset(i->second.first);
        int set_v=d.findset(i->second.second);

        if(set_u!=set_v)
        {
            cout<<i->second.first<<" - "<<i->second.second<<"  Weight: " <<i->first<<endl;
            weight+=i->first;
            d.Union(set_u,set_v);
        }
    }

    return weight;

}


int main()
{
    int e;
    cout<<"Number of vertices:"<<endl;
    cin>>V;
    vector<pair<int,edges> > vec;
    cout<<"Number of edges:"<<endl;
    cin>>e;
    int v1,v2,w;
    while(e>0)
    {
        cin>>v1>>v2>>w;
        vec.push_back({w,{v1,v2}});
        e--;

    }
    cout<<"The selected edges are: "<<endl;
    cout<<"The total weight of the minimum spanning tree is: "<<kruskalMST(vec);
}
/*
INPUT:
Number of vertices:
9
Number of edges:
14
0 1 4
1 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

OUTPUT:
The selected edges are:
6 - 7  Weight: 1
2 - 8  Weight: 2
5 - 6  Weight: 2
0 - 1  Weight: 4
2 - 5  Weight: 4
2 - 3  Weight: 7
1 - 2  Weight: 8
3 - 4  Weight: 9
The total weight of the minimum spanning tree is: 37

*/
