#include<bits/stdc++.h>
#include<map>
using namespace std;
int V;
bool bi=true;
typedef pair<int,int> p;

class Graph{
    unordered_map<int,list<p> > graph;

public:

    void edge(int u,int v,int d){
        graph[u].push_back({v,d});
        if(bi==true)
        graph[v].push_back({u,d});
    }



    void dijsktra(int src){
        vector<int> distance(V,INT_MAX);

        distance[src]=0;

        set<p> s;
        s.insert({0,src});

        while(!s.empty())
        {
            auto init=*s.begin();
            int node=init.second;
            int dis=init.first;
            s.erase(s.begin());

            for(auto &i : graph[node]){
                if(dis+i.second < distance[i.first]){
                    int dest= i.first;
                    auto f=s.find({distance[dest],dest});
                    if(f!=s.end())
                        s.erase(f);

                    distance[dest]=dis+i.second;
                    s.insert({distance[dest],dest});
                }
            }
        }

        for(int i=0;i<V;i++)
            cout<<"  "<<i<<"\t\t"<<distance[i]<<endl;
    }

};

int main(){

    int e;
    cout<<"Number of vertices:"<<endl;
    cin>>V;
    cout<<"Number of edges:"<<endl;
    cin>>e;
    int v1,v2,d;
    Graph g;
    string val;
    cout<<"Is the graph bidirectional? (yes/no)"<<endl;
    cin>>val;
    if(val!="yes")
        bi=false;

    cout<<"Enter the edges:"<<endl;
    while(e>0)
    {
        cin>>v1>>v2>>d;
        g.edge(v1,v2,d);
        e--;
    }
    int initial;
    cout<<"Initial vertex:"<<endl;
    cin>>initial;

    cout<<"Vertex - Distance from Source"<<endl;
    g.dijsktra(initial);

}
/*
INPUT:
Number of vertices:
9
Number of edges:
14
Is the graph bidirectional? (yes/no)
yes
Enter the edges:
0 1 4
0 7 8
1 7 11
1 2 8
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
Initial vertex:
0

OUTPUT:
Vertex - Distance from Source
  0             0
  1             4
  2             12
  3             19
  4             21
  5             11
  6             9
  7             8
  8             14
*/
