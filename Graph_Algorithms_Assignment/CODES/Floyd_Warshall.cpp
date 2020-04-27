#include<iostream>
using namespace std;
#define INF 999999
int V;
int **graph;
bool bi=true;

void floydWarshall(){

    //Floyd Warshall Algorithm
    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++)
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);

            //If any of the diagonals become negative, it means the
            //graph has a negative cycle
            if(graph[i][i]<0)
            {
                cout<<"Negative Weight Detected";
                return;
            }
        }

    cout<<"The following matrix represents distance between every pair of vertices:"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
        {   if(i==j)
            cout<<"0  ";
            else if(graph[i][j]==INF)
            {cout<<".  ";}
            else
            cout<<graph[i][j]<<"  ";
        }

        cout<<endl;
    }

}

int main(){
    cout<<"Number of vertices:"<<endl;
    cin>>V;
    graph=new int*[V];
    for(int i=0;i<V;i++){
        graph[i]=new int[V];
        fill(graph[i],graph[i]+V, INF);
    }
    int e;
    cout<<"Number of edges:"<<endl;
    cin>>e;
    string val;
    cout<<"Is the graph bidirectional? (yes/no)"<<endl;
    cin>>val;
    if(val!="yes")
        bi=false;
    int input[V][V];
    int v1,v2,w;
    cout<<"Enter the edges:"<<endl;
    while(e>0)
    {
        cin>>v1>>v2>>w;
        graph[v1][v2]=w;
        input[v1][v2]=w;
        e--;
    }

    floydWarshall();
    return 0;
}
/*
INPUT:
Number of vertices:
4
Number of edges:
4
Is the graph bidirectional? (yes/no)
no
Enter the edges:
0 1 5
0 3 10
1 2 3
2 3 1

OUTPUT:
The following matrix represents distance between every pair of vertices:
0  5  8  9
.  0  3  4
.  .  0  1
.  .  .  0


INTPUT:
Number of vertices:
4
Number of edges:
5
Is the graph bidirectional? (yes/no)
no
Enter the edges:
0 2 -2
1 0 4
1 2 -3
2 3 2
3 1 -1

OUTPUT:
Negative Weight Detected
*/
