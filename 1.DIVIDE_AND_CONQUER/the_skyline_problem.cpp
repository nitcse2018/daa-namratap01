/*A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance.
The following program outputs the skyline for a given input of buildings.
The geometric information of each building is represented by a triplet of integers [Li, Hi, Ri], where Li and Ri are the x coordinates
of the left and right edge of the ith building, respectively, and Hi is its height.
The output is the list of points that defines the skyline.*/

#include<bits/stdc++.h>
using namespace std;
vector<int> *v;
typedef pair<int,int> pairs;
vector<pairs> skyline;
vector<pairs> res;

void mergeskyline(int start, int ends)
{
    start=start*2;
    ends=(ends*2)+1;
    int mid=(start+ends)/2;
    int i=start,
        j=mid+1,
        h1=0,h2=0;
    while(i<=mid && j<=ends)
    {
        if (skyline[i].first < skyline[j].first )
        {
            h1=skyline[i].second;
            int maxh= max(h1,h2);
            res.push_back(make_pair(skyline[i].first,maxh));
            i++;
        }
        else
        {
            h2=skyline[j].second;
            int maxh= max(h1,h2);
            res.push_back(make_pair(skyline[j].first,maxh));
            j++;
        }
    }
        while(i<=mid)
        {
            res.push_back(skyline[i]);
            i++;
        }
        while(j<=ends)
        {
            res.push_back(skyline[j]);
            j++;
        }
        int k=0;
        for(i=start;i<=ends;i++)
        skyline[i]=res[k++];

        res.clear();

}
void getskyline(int start,int ends)
{
    if(start>=ends)
    {
        skyline.push_back(make_pair(v[start][0],v[start][1]));
        skyline.push_back(make_pair(v[start][2],0));
    }
    else
    {
        int mid=(start+ends)/2;
        getskyline(start,mid);
        getskyline(mid+1,ends);
        mergeskyline(start,ends);
    }
}

int main()
{
    int n,i,j,temp;
    cout<<"Enter number of buildings:";
    cin>>n;
    v= new vector<int>[n];
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
    {
        cin>>temp;
        v[i].push_back(temp);
    }
    sort(v,v+n);
    getskyline(0,n-1);
    int m=skyline.size();
    for(i=1;i<m;i++)
    {
        if(skyline[i].second==skyline[i-1].second)
            {skyline.erase(skyline.begin()+i);i--;m--;}
    }

    for (auto const &x : skyline) {
        cout << "(" << x.first << ", "
             << x.second << ")"
             << " ";
    }
}
