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
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            a.pb({y,x});
    }
    sort(a.begin(),a.end());
    vector<int>ans;
    ans.pb(a[0].first);
    for(int i=1;i<n;i++){
            if (ans.back()<a[i].second){
                ans.pb(a[i].first);
            }
    }
    cout<<ans.size()<<endl;
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