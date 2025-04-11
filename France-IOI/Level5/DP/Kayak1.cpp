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
int last;
int dfs(int node,vector<int>&dp,vector<vector<pair<int,int>>>&graph){
    if (dp[node]!=-1){
        return dp[node];
    }
    if (node==last){
        return 0;
    }
    int ans=0;
    int res=-1e7;
    for(auto i:graph[node]){
            int call1 = dfs(i.first,dp,graph);
            if (call1!=-1e7){
                res=max(res,call1 + i.second);
            }
    }
    return dp[node] = res;
}
void solve(){
    int n,e;
    cin>>n>>e;
    last=n;
    vector<vector<pair<int,int>>>graph(n+1);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    vector<int>vis(n+1,-1);
    cout<<dfs(1,vis,graph);
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