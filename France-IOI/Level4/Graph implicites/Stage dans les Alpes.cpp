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
vector<int>res;
void dfs(int node ,int n,int k){
    if (res.size()==k){
        for(auto i:res){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=node;i<=n;i++){
        res.push_back(i);
        dfs(i,n,k);
        res.pop_back();
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>vis(n,0);
    dfs(1,n,k);
    //cout<<"ok"<<endl;
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