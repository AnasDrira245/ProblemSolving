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
vector<vector<int>>dp;
vector<vector<int>>graph;
int l;
bool valid(int x,int y){
    return (x>=0 && y>=0 && x<l && y<=x);
}
int  dfs(int node,int level){
    if (dp[level][node]!=-1){
        return dp[level][node];
    }
    int ans=graph[level][node];
    int call1=0,call2=0;
    if (valid(level+1,node))
        call1 = dfs(node,level+1);
    if (valid(level+1,node+1))
        call2 = dfs(node+1,level+1);
    ans += max(call1, call2);
    return dp[level][node] = ans;
}
void solve(){
    int n;
    cin>>n;
    l=n;
    dp.resize(n+1,vector<int>(n+1,-1));
    graph.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int x;
            cin>>x;
            graph[i].push_back(x);
        }
    }
    cout<<dfs(0,0);
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