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
vector<vector<int>>adjList,comps;
vector<int>dfn,lowLink,inStack,comp;
stack<int>stk;
int ndfn=0;
vector<pair<int,int>>bridges;
void tarjan(int node,int par) {
   lowLink[node] = dfn[node] = ndfn++;
   for(auto ch: adjList[node]) {
      if (dfn[ch] == -1) {
         tarjan(ch,node);
         lowLink[node] = min(lowLink[node], lowLink[ch]);
      } else if (ch!=par)
         lowLink[node] = min(lowLink[node], dfn[ch]);
   }
   if (lowLink[node]==dfn[node] &&  par!=-1){
            bridges.push_back({par,node});
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    adjList.resize(n);
    dfn.resize(n,-1);
    lowLink.resize(n,-1);
    comp.resize(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    tarjan(0,-1);
    /*for(int i=0;i<n;i++){
        cout<<i+1<<" "<<  dfn[i]<<"  " <<lowLink[i]<<endl;
    }*/
  sort(bridges.begin(),bridges.end());
    cout<<bridges.size()<<endl;
    for(auto i:bridges){
        cout<<i.first+1<<" "<<i.second+1<<endl;
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