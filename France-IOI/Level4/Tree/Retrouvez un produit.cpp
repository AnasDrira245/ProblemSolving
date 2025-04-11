#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<int>>&adj)
{
    if (node!=0)
    {
    for(auto i:adj[node])
    {
        dfs(i,adj);
    }
    cout<<node<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        adj[i+1].push_back(x);
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        dfs(x,adj);
        cout<<endl;
    }
}