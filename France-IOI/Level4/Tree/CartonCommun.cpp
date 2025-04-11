#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll MOD = 1e9+7  ;
// const int MOD = 998244353  ;
const int N = 505 ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll prime = 1000003;
//const ll prime2 = 101 ;
int  dfs(int node,vector<vector<int>>&adj , int x,int y)
{
    if (node==x || node == y )
        return node;
    int root = -1;
    int cnt=0;
    for(auto i:adj[node])
    {
        int currRoot = dfs(i,adj,x,y);
        if (currRoot!=-1)
        {
            cnt++;
            root=currRoot;
        }
    }
    if (cnt==2)
        return node;
    return root;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    int r;
    cin>>r;
    while(r--)
    {
        int x,y;
        cin>>x>>y;
        int root = dfs(0,adj,x,y);
        if (root !=-1)
            cout<<root<<endl;
        else
            cout<<0<<endl;
    }
}
int main()
{
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
      FAST ;
      int t = 1  ;
            //cin>> t;
            while( t--) {
                        solve();
            }
}
/* stuff you should look for
* int overflow, array bounds
* special cases (n=1?)
* do smth instead of nothing and stay organized
* WRITE STUFF DOWN
* DON'T GET STUCK ON ONE APPROACH
* think backwards
*/