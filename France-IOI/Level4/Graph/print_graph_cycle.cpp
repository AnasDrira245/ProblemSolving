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
vector<int>ans;
bool dfs(int node,vector<bool>&vis,vector<bool>par,vector<vector<int>>&adj){
    vis[node]=true;
    par[node]=true;
    for(auto i:adj[node]){
        if (vis[i] && par[i]){
            return true;
        }
        if (!vis[i] && dfs(i,vis,par,adj)){
            return true;
        }
    }
    par[node]=false;
    ans.push_back(node);
    return false;
}
void solve(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj(n);
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    vector<bool>vis(n,0);
    vector<bool>par(n,0);
    for(int i=0;i<n;i++){
        if (!vis[i] && dfs(i,vis,par,adj)){
                cout<<-1<<endl;
                return;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans){
        cout<<i+1<<" ";
    }
}
int main()
{
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
      FAST ;
      int t = 1  ;
           // cin>> t;
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