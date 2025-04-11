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
int distance(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
vector<int>res;
int dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
    int cnt=1;
    vis[node]=1;
    for(auto i:adj[node]){
        if (!vis[i]){
            cnt+=dfs(i,adj,vis);
        }
    }
    return cnt;
}
void solve(){
    int n,m;
    cin>>n>>m;
    res.resize(n);
    vector<vector<int>>coord;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        coord.push_back({x,y,z});
    }
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i!=j && distance(coord[i][0],coord[i][1],coord[j][0],coord[j][1])<= coord[i][2]*coord[i][2]){
                adj[i].push_back(j);
            }
        }
    }
    for(int i=0;i<m;i++){
        vector<bool>vis(n);
        int x;
        cin>>x;
        cout<<dfs(x,adj,vis)<<endl;
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