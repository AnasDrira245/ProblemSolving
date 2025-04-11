#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
#define pb push_back
using namespace std;
const ll MOD = 1e9+7  ;
// const int MOD = 998244353  ;
const int N = 505 ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll prime = 1000003;
//const ll prime2 = 101 ;
bool op(pair<int,int>p1,pair<int,int>p2){
    if (p1.first==p2.first){
        return p1.second<p2.second;
    }
    else{
        return p1.first>p2.first;
    }
}
void bfs(int node,vector<vector< pair<int,int> > >& graph){
    int n=graph.size();
    int cnt=0;
    vector<bool>vis(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});
    int sum=0;
    while(!q.empty()){
        auto curr=q.top();
        q.pop();
        if (vis[curr.second])
            continue;
        vis[curr.second]=1;
        sum+=curr.first;
        for(auto i:graph[curr.second]){
                if (vis[i.second]){
                    continue;
                }
                q.push(i);
        }
    }
    cout<<sum<<endl;
}
void solve(){
    int n,e;
    cin>>n>>e;
    vector<vector< pair<int,int>    > > graph(n);
    while(e--){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        graph[x].pb({z,y});
        graph[y].pb({z,x});
    }
   bfs(0,graph);
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