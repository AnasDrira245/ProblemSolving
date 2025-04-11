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
int n,m;
int x3,y3;
string s;
bool valid(int x,int y,vector<vector<char>>&grid){
    return x>=0 && y>=0 && x<n && y<m && grid[x][y]=='.';
}
void bfs(int x,int y,vector<vector<char>>&grid){
    int dx[4]={0,-1,0,1};
    int dy[4]={1,0,-1,0};
    map<pair<int,int>,char>mp;
    vector<vector<bool>>vis(n,vector<bool>(m));
    mp[{1,0}]='S';
    mp[{-1,0}]='N';
    mp[{0,-1}]='O';
    mp[{0,1}]='E';
    queue<vector<int>>q;
    q.push({x,y});
    vector<vector<  pair<int,int>  > >parent(n,vector<pair<int,int>>(m));
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        vis[curr[0]][curr[1]]=true;
        if (curr[0]==n-1 && curr[1]==m-2){
            int x2=curr[0];
            int y2=curr[1];
            while(x2!=1 || y2!=0){
                //cout<<x2<< " "<<y2<<endl;
                x3=parent[x2][y2].first;
                y3=parent[x2][y2].second;
                s+=mp[ {x2-x3,y2-y3}];
                x2=x3;
                y2=y3;
            }
            reverse(s.begin(),s.end());
            cout<<s.size()<<endl;
            cout<<s<<endl;
           // cout<<x2<<" "<<y2<<endl;
            return;
        }
        for(int k=0;k<4;k++){
            int x1=curr[0]+dx[k];
            int y1=curr[1]+dy[k];
            if (valid(x1,y1,grid) && !vis[x1][y1]){
                vis[x1][y1]=true;
                q.push({x1,y1}  );
                parent[x1][y1]={curr[0],curr[1]};
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    bfs(1,0,grid);
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