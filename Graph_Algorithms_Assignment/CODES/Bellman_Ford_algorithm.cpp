#include<bits/stdc++.h>
#include<map>
using namespace std;
int V,e;
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



    void bellmanFord(int src){
        vector<int> distance;

        for(int i=0;i<V;i++)
            distance.push_back(INT_MAX);

        distance[src]=0;
            for(int i=0;i<V-1;i++)
            {
                bool update=false;
                for(auto i : graph){
                    int u=i.first;
                    for(auto j : i.second){
                        int v=j.first;
                        int dis=j.second;
                        if(distance[u] != INT_MAX && dis+distance[u] < distance[v])
                            {update=true;distance[v]=dis+distance[u];}
                    }
                }

                if(update==false)
                    break;
            }

            for(int i=0;i<e;i++){
                for(auto i : graph){
                    int u=i.first;
                    for(auto j : i.second){
                        int v=j.first;
                        int dis=j.second;
                        if(distance[u] != INT_MAX && dis+distance[u] < distance[v])
                            {cout<<"Negative Cycle Detected!!"<<endl;
                            return;}
                    }
                }
            }

        cout<<"Vertex - Distance from Source"<<endl;
        for(int i=0;i<V;i++)
            cout<<"  "<<i<<"\t\t"<<distance[i]<<endl;
    }

};

int main(){

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

    g.bellmanFord(initial);

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

INPUT:
Number of vertices:
5
Number of edges:
8
Is the graph bidirectional? (yes/no)
no
Enter the edges:
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
Initial vertex:
0

OUTPUT:
Vertex - Distance from Source
  0             0
  1             -1
  2             2
  3             -2
  4             1
*/
