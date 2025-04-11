#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define endl "\n"
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define karr(x) cout<<(#x)<<": ";_print(x);cout<<endl;
#define F first
#define S second
#define kar trace
#define wow cout<<"YES"<<endl;
#define INF 1e18
const int N=2e5+5;

vector<vector<char>>graph;
vector<vector<int>>dp;
vector<vector<int>>ans;
vector<int>dx={0,1,0,-1};
vector<int>dy={-1,0,1,0};
vector<char>dir={'L','D','R','U'};
vector<vector<bool>>vis;
int n,m;
bool valid(int i,int j) {
    return i>=0 && j>=0 && i<n && j<m;
}
//shortest path from xa,ya to any other node
void bfs(int i,int j) {
    queue<array<int,3>>q;
    q.push({i,j,0});
    vis[i][j]=1;
    while(!q.empty()) {
        array<int,3> p = q.front();
        q.pop();
        ans[p[0]][p[1]]=p[2];
        for(int k=0;k<4;k++) {
            int ni =p[0]+dx[k];
            int nj = p[1]+dy[k];
            if( valid(ni,nj)&&  !vis[ni][nj]  &&   graph[ni][nj]=='.') {
                q.push({ni,nj ,p[2]+1});
                vis[ni][nj]=true;
            }
        }
    }
}
queue<pair<int,int>>q2;
void  bfs3() {

    while (!q2.empty()) {
        pair<int,int> p = q2.front();
        q2.pop();
        for(int k=0;k<4;k++) {
            int nx = p.first+dx[k];
            int ny = p.second+dy[k];
            if (valid(nx,ny)  ) {
                if (graph[nx][ny] != '#' && dp[nx][ny] > dp[p.first][p.second] + 1) {
                    dp[nx][ny] = dp[p.first][p.second] + 1;
                    q2.push({nx, ny});
                }
            }
        }
    }

}
string bfs2(int i,int j) {
    vector<pair<int,int>>ans2;
    queue<pair<int,int>>q;
    vector<vector<pair<int,int>>>par(n,vector<pair<int,int>>(m,{-1,-1}));
    q.push({i,j});
    vis[i][j]=1;
    pair<int,int> last={-1,-1};
    while (!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        ans2.pb(p);
        if (  graph[p.first][p.second]=='A'    ) {
            last=p;
            break;
        }
        for(int k=0;k<4;k++) {
            int ni = p.first+dx[k];
            int nj = p.second+dy[k];
            if (valid(ni,nj) && (graph[ni][nj]=='.'|| graph[ni][nj]=='A')   ) {
                if (vis[ni][nj])continue;
                q.push({ni,nj});
                par[ni][nj]=p;
                vis[ni][nj]=true;
            }
        }
    }

    pair<int,int>curr=last;
    string s2;
    while (curr!= make_pair(-1,-1)   ) {
        last = curr;
        curr=par[curr.first][curr.second];
        if (curr!=make_pair(-1,-1)) {
            int diff= curr.first-last.first;
            int diff2=curr.second-last.second;
            for (int j=0;j<4;j++) {
                if (diff==dx[j] && diff2==dy[j]) {
                    s2+=dir[j];
                }
            }
        }
    }
   // reverse(s2.begin(),s2.end());
    return s2;

}
void solve() {
    cin>>n>>m;
    graph = vector<vector<char>>(n,vector<char>(m,'.'));
    ans=vector<vector<int>>(n,vector<int>(m,1e8));
    int xa,ya;
    dp=vector<vector<int>>(n,vector<int>(m,1e8));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>graph[i][j];
            if (graph[i][j]=='A') {
                xa=i;
                ya=j;
            }
            if (graph[i][j]=='M') {
                q2.push({i,j});
                dp[i][j]=0;
            }
        }
    }
    vis=vector<vector<bool>>(n,vector<bool>(m,false));
    bfs(xa,ya);
    //vis=vector<vector<bool>>(n,vector<bool>(m,false));

    bfs3();

    vis=vector<vector<bool>>(n,vector<bool>(m,false));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (i==0 || i==n-1 || j==0 || j==m-1) {
                if ((graph[i][j]!='.' ||graph[i][j]!='A')     &&  ans[i][j]<  dp[i][j]  ) {

                    string s2 = bfs2(i,j);

                    // cout<<i<<" "<<j<<endl;
                    cout<<"YES"<<endl;
                    cout<<s2.size()<<endl;
                    cout<<s2<<endl;
                    return;


                }
            }
        }
    }
    cout<<"NO"<<endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;
    int t = 1;
    // cin>>t;

    while (t--) {
        solve();
    }
}