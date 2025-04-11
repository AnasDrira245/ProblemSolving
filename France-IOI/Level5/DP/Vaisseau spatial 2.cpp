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
vector<vector<int>>dp2;
vector<vector<int>>dp;
vector<vector<int>>graph;
int l,w;
bool valid(int x,int y){
    return (x>=0 && y>=0 && x<l && y<w);
}
int  dfs(int node,int level){
    if (dp[level][node]!=-1e8){
        return dp[level][node];
    }
    int ans=graph[level][node];
    int ans2;
    int call1=-1e8,call2=-1e8,call3=-1e8;
    if (valid(level-1,node-1))
        call1 = dfs(node-1,level-1);
    if (valid(level-1,node+1))
        call2 = dfs(node+1,level-1);
    if (valid(level-1,node))
        call3 = dfs(node,level-1);
    if (call1!=-1e8 || call2!=-1e8 ||call3!=-1e8 ){
         ans += max(call1,max(call2,call3));
         if (call1>=call2 && call1>=call3){
            ans2=-1;
         }
         else if (call2>=call1 && call2>=call3){
            ans2=1;
         }
        else{
            ans2=0;
        }
    }
    dp2[level][node]=ans2;
    return dp[level][node] = ans;
}
void solve(){
    int n,m,c;
    cin>>n>>m>>c;
    l=n;
    w=m;
    dp2.resize(n+1,vector<int>(m+1,0));
    dp.resize(n+1,vector<int>(m+1,-1e8));
    graph.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            graph[i].push_back(x);
        }
    }
    int x=dfs(c,n-1);
    while(n>1){
        cout<<dp2[n-1][c]<<" ";
        c+=dp2[n-1][c];
        n--;
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