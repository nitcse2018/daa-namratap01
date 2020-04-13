/* The following is the Shortest Superstring Problem.
Given a set of n strings arr[], we need to find the smallest string that contains each string in the given set as substring. */
#include<bits/stdc++.h>
using namespace std;
vector<string> data;

int findoverlap(string s1,string s2,string &temp)
{
    int mx=-1;
    int len1=s1.length();
    int len2=s2.length();

    if(len1<len2 && s2.find(s1,0)<len2)
    {
        temp=s2;
        return len2;
    }
    else if(s1.find(s2,0)<len1)
    {
        temp=s1;
        return len1;
    }
    else
    {
        for(int i=0;i<=min(len1,len2);i++)
        {
            if(s1.compare(0,i,s2,len2-i,i)==0)
                if(mx<i)
                {
                    mx=i;
                    temp=s2+s1.substr(i);
                }
        }
        for(int i=0;i<=min(len1,len2);i++)
        {
            if(s2.compare(0,i,s1,len1-i,i)==0)
                if(mx<i)
                {
                    mx=i;
                    temp=s1+s2.substr(i);
                }
        }
        return mx;
    }
}

void shortestsuperstring()
{
    int n=data.size(),l,r;
    while(n!=1)
    {
        int mx=-1;
        string res;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            string temp;
            int max_len=findoverlap(data[i],data[j],temp);

            if(mx<max_len)
            {
                mx=max_len;
                l=i;r=j;
                res.assign(temp);
            }
        }
        n--;

        if(mx==-1)
            data[0]+=data[n];
        else
        {
            data[l]=res;
            data[r]=data[n];
        }

    }
}

int main()
{

    string temp,word;
    getline(cin,temp);
    istringstream ss(temp);
    while(ss >> word)
        data.push_back(word);

    shortestsuperstring();
    cout<<data[0];
}

/*
INPUT1:
catgc ctaagt gcta ttca atgcatc
OUTPUT:
gctaagttcatgcatc

INPUT2:
the terrorist definitely made some heavy error
OUTPUT:
madefinitelysometerroristheavy
 */
