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
const ll MOD = 1e9+7  ;
// const int MOD = 998244353  ;
const int N = 505 ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll prime = 1000003;
//const ll prime2 = 101 ;
void djkstra(int node,vector<vector<pair<int,int>>>&adj,int n,int e){
    vector<int>dist(n+1,1e7);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >>q;
    vector<bool>vis(n+1);
    dist[node]=0;
    q.push({dist[node],node});
    while(!q.empty()){
        auto curr = q.top();
        q.pop();
        vis[curr.second]=true;
        for(auto i:adj[curr.second]){
            if (vis[i.first])continue;
            if (dist[curr.second] + i.second < dist[i.first]){
                dist[i.first]=dist[curr.second] + i.second;
                q.push({dist[i.first],i.first});
            }
        }
    }
    vector<pair<int,int>>ans;
    for(int i=1;i<=n;i++){
        ans.pb({dist[i],i});
    }
    sort(ans.begin(),ans.end());
    for(auto i:ans){
        if (i.first==1e7)continue; 
        cout<<i.first<<" "<<i.second<<endl;
    }
}
void solve(){
    int n;
    cin>>n;
    int e;
    cin>>e;
    int start;
    cin>>start;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }
    djkstra(start,adj,n,e);
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