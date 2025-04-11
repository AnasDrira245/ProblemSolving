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
 
vector<vector<int>>graph;
vector<bool>parent;
vector<int>par2;
vector<int>vis;
vector<int>v;
vector<int>ans;
int n,m;
bool test=false;
void dfs(int node,int par) {
    if (test)return;
    vis[node]=1;
    parent[node]=1;
    par2[node]=par;
    for (auto x:graph[node]) {
 
        if (test)break;
        if (x==par)continue;
 
        if (!vis[x]) {
            //par2[x]=node;
            dfs(x,node);
        }
        else if (vis[x] && parent[x]) {
            if (test)continue;
           // ans.clear();
            ans.pb(x);
            int curr=node;
            while (curr!=x) {
                ans.pb(curr);
                curr=par2[curr];
            }
            ans.pb(x);
            if (ans.size()>=4) {
                test=true;
            }
        }
    }
    parent[node]=0;
 
 
}
void solve() {
    cin>>n>>m;
    graph=vector<vector<int>>(n+1);
    vis=vector<int>(n+1,false);
    parent=vector<bool>(n+1,false);
    par2=vector<int>(n+1,-1);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i] && !test) {
            dfs(i,-1);
        }
    }
 
    if (!test) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
 
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for (auto x:ans) {
            cout<<x<<" ";
 
        }
 
    }
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