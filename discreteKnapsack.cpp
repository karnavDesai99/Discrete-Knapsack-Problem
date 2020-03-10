#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack(int weights[10],int values[10],int W,int n)
{
    int ks[n+1][W+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)
                ks[i][j]=0;
            else if(weights[i-1]<=j)
                ks[i][j]=max(values[i-1]+ks[i-1][j-weights[i-1]],ks[i-1][j]);
            else
                ks[i][j]=ks[i-1][j];
        }
    }
    return ks[n][W];
}

int main()
{
    int n,val[10],wt[10],W;
    cout<<"Enter total no. of elements: ";
    cin>>n;
    cout<<"Enter total weight of knapsack: ";
    cin>>W;
    cout<<"Enter values of elements: ";
    for(int i=0;i<n;i++)
        cin>>val[i];
    cout<<"Enter the weights: ";
    for(int j=0;j<n;j++)
        cin>>wt[j];
    cout<<"Max value that can be packed: "<<knapsack(wt,val,W,n);
    return 0;
}
