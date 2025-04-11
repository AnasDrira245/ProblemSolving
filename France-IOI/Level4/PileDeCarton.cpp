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
void dfs(int node,vector<vector<int>>&adj){
    if (node!=0)
        cout<<"A"<<" "<<node<<endl;
    for(auto i:adj[node])
    {
        dfs(i,adj);
    }
    if (node!=0)
        cout<<"R"<<" "<<node<<endl;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<=n;i++)
    {
        int x;
        cin>>x;
        while(x--)
        {
            int y;
            cin>>y;
            adj[i].push_back(y);
        }
    }
    dfs(0,adj);
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