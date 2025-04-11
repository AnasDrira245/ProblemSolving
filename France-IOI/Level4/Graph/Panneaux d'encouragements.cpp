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
map<int,int>mp;
int n,m;
bool valid(int x,int y,vector<vector<char>>&grid){
    return x>=0 && y>=0 && x<n && y<m && grid[x][y]=='.';
}
void bfs(int x,int y,vector<vector<char>>&grid,int limit){
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    map<int,int>mp;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    queue<vector<int>>q;
    q.push({x,y,0});
    while(!q.empty()){
        auto curr=q.front();
        vis[curr[0]][curr[1]]=true;
        q.pop();
        for(int k=0;k<4;k++){
            int x1=dx[k]+curr[0];
            int y1=dy[k]+curr[1];
            if (valid(x1,y1,grid) && !vis[x1][y1] && curr[2]+1<=limit){
                q.push({x1,y1,curr[2]+1});
                vis[x1][y1]=true;
                mp[curr[2]+1]++;
            }
        }
    }
    for(auto i:mp){
        cout<<i.second<<" ";
    }
    cout<<endl;
}
void solve(){
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m,'#'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int limit;
    cin>>limit;
    bfs(n-1,m-2,grid,limit);
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