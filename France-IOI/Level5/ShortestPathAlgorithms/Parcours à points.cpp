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
int dfs(int node,int time,vector<vector< array<int,2> >>&graph,vector<vector<int>>&dp){
    if (time==0){
        return 0;
    }
    if (dp[node][time]!=-1){
        return dp[node][time];
    }
    int curr=0;
    int ans=0;
    for(auto i:graph[node]){
        curr+=i[0];
        int call=dfs(i[1],time-1,graph,dp);
        ans=max(ans,curr+call);
        curr-=i[0];
    }
    return dp[node][time]=ans;
}
void solve(){
    int x,y,f,g;
    cin>>x>>y>>f>>g;
    vector<vector<int>>vis(x+1,vector<int>(g+1,-1));
    vector<vector< array<int,2> >>graph(x+1);
    for(int i=0;i<y;i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({c,b});
    }
    cout<<dfs(f,g,graph,vis)<<endl;
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