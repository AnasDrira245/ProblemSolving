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
bool valid(int x,int y,int n,int e){
    return x>=0 && y>=0 && x<n && y<e;
}
void bfs(int x,int y,vector<vector<char>>&graph,int n,int e){
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    vector<vector<int>>distance(n,vector<int>(e,1e7));
    vector<vector<bool>>vis(n,vector<bool>(e));
    distance[1][0]=0;
    q.push({distance[1][0],1,0});
    while(!q.empty()){
        auto curr=q.top();
        q.pop();
        if (vis[curr[1]][curr[2]]){
            continue;
        }
        vis[curr[1]][curr[2]]=true;
        for(int k=0;k<4;k++){
            int x1=curr[1]+dx[k];
            int y1=curr[2]+dy[k];
            if (!valid(x1,y1,n,e) || graph[x1][y1]=='#'){
                continue;
            }
            if (vis[x1][y1]){
                continue;
            }
            int cost=graph[x1][y1]=='.'?0:(graph[x1][y1]-'0');
            if (distance[x1][y1]> distance[curr[1]][curr[2]]+cost){
                distance[x1][y1]=distance[curr[1]][curr[2]]+cost;
            }
            q.push({distance[x1][y1],x1,y1});
        }
    }
    cout<<distance[n-1][e-2]<<endl;
}
void solve(){
    int x,y;
    cin>>x>>y;
    vector<vector<char>>graph(x,vector<char>(y));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>graph[i][j];
        }
    }
    bfs(1,0,graph,x,y);
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