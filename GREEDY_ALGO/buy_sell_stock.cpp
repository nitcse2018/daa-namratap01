/* The following is the famous problem for buying and selling stock to maximize profit when there is a transaction fee involved.
 An array of integers is given, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee
 representing a transaction fee.
 We can complete as many transactions as we want but cannot buy more than 1 share of a stock at a time and need to pay the
 transaction fee for each transaction.
 Return the maximum profit we can make. */
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements in array:";
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++)
        cin>>price[i];

    int fee;
    cout<<"Enter the transaction fee:";
    cin>>fee;
    int maximum=0;
    int minimum=-price[0];

    for(int i=0;i<n;i++)
    {
        maximum=max(maximum,minimum+price[i]-fee);
        minimum=max(minimum,maximum-price[i]);
    }

    cout<<maximum;
}
/*
INPUT1:
7
8 2 4 10 7 1 2
2
OUTPUT: 6

INPUT2:
7
1 2 3 10 8 4 9
3
OUTPUT: 8

INPUT3:
20
7 5 4 9 7 6 1 56 44 3 29 8 7 12 19 3 9 2 29 5
5
OUTPUT: 101

*/
