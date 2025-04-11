#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int dfs(int node , vector<vector<int>>&adj)
{
    int ans=0;
    for(auto i:adj[node])
    {
        ans=max(ans,1+dfs(i,adj));
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    //level[adj[0][i]]=0;
    cout<<dfs(0,adj)<<endl;
}