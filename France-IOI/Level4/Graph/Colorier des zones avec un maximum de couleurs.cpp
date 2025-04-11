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
char grid[1000][1000];
int ans=0;
int n,m;
bool valid(int i,int j,vector<vector<bool>>&vis){
    return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && grid[i][j]=='.';
}
void dfs(int i,int j,vector<vector<bool>>&vis){
    if (!valid(i,j,vis))
        return;
    vis[i][j]=true;
    ans++;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for(int k=0;k<4;k++){
        dfs(i+dx[k],j+dy[k],vis);
    }
}
void solve(){
    cin>>n>>m;
  //  int x=-1,y=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (!vis[i][j] && grid[i][j]=='.')
                {
                    dfs(i,j,vis);
                    cnt++;
                }
        }
    }
    cout<<cnt<<endl;
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