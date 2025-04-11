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
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int>a(q);
    for(int i=0;i<q;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<q;i++){
        auto it=lower_bound(a.begin(),a.end(),a[i]+n+1);
        it--;
        int x=(it-a.begin());
        ans=max(ans,x-i+1);
    }
    cout<<ans<<endl;
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