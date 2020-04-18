/* The following is the famous Job Assignment Problem using Branch and Bound
 Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may
 vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to
 each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.
*/
#include<bits/stdc++.h>
using namespace std;

int N;
int **a;

class node
{
    public:
        node* parent;
        int pathCost;
        int cost;
        int workerID;
        int jobID;
        bool *assigned=new bool[N];

    node(int wid,int jid, bool assigned[],node* parent)
    {
        for(int i=0;i<N;i++)
            this->assigned[i]=assigned[i];

        this->assigned[jid]=true;

        this->parent=parent;
        this->workerID=wid;
        this->jobID=jid;

    }
};


int calculateCost(int x,int y,bool assigned[])
{
    int cost=0;

    bool available[N]={true};

    for(int i=x+1;i<N;i++)
    {
        int mini=INT_MAX,minIndex=-1;

        for(int j=0;j<N;j++)
        {
            if(!assigned[j] && available[j] && a[i][j]<mini)
            {
                minIndex=j;
                mini=a[i][j];
            }
        }

        cost+=mini;

        available[minIndex]=false;
    }
    return cost;
}

struct compare
{
    bool operator()(const node* ln,const node* rn) const
    {
        return ln->cost > rn->cost;
    }
};

void printres(node* mini)
{
    if(mini->parent==NULL)
        return;

    printres(mini->parent);
    cout<<"Assigned Job "<<mini->jobID+1<<" to Worker "<< char(mini->workerID + 'A')<<endl;
}

int findMinimumCost()
{
    priority_queue<node*,std::vector<node*>,compare> Q;
    bool assigned[N]={false};
    node* root= new node(-1,-1,assigned,NULL);
    root->cost=0;
    root->pathCost=0;
    root->workerID=-1;

    Q.push(root);

    while(!Q.empty())
    {
        node* mini=Q.top();

        Q.pop();

        int id=mini->workerID+1;

        if(id==N)
        {
            printres(mini);
            return mini->cost;
        }

        for(int i=0;i<N;i++)
        {
            if(!mini->assigned[i])
            {
                node* child = new node(id,i,mini->assigned,mini);

                child->pathCost= mini->pathCost+a[id][i];

                child->cost = child->pathCost + calculateCost(id,i,child->assigned);

                Q.push(child);
            }
        }
    }
}

int main(){
    cout<<"Enter the number of workers and jobs:";
    cin>>N;
    a=new int*[N];
    for(int i=0;i<N;i++)
    {
        a[i]=new int[N];
        for(int j=0;j<N;j++)
            cin>>a[i][j];
    }

    cout<<"Optimal Cost = "<<findMinimumCost();
}
/*
INPUT1:
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

OUTPUT:
Assigned Job 2 to Worker A
Assigned Job 1 to Worker B
Assigned Job 3 to Worker C
Assigned Job 4 to Worker D
Optimal Cost = 13


INPUT2:
5
90 75 75 80 92
30 85 55 65 92
125 95 90 105 86
45 110 95 115 23
80 9 98 23 55

OUTPUT:
Assigned Job 4 to Worker A
Assigned Job 1 to Worker B
Assigned Job 3 to Worker C
Assigned Job 5 to Worker D
Assigned Job 2 to Worker E
Optimal Cost = 232

*/
