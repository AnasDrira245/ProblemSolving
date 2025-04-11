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
vector<vector<unsigned long long >>dp;
unsigned long long f(int n,int k){
    if (dp[n][k]!=1){
        return dp[n][k];
    }
    if (k==0){
        return 1;
    }
    if (n==0){
        return 0;
    }
    return dp[n][k] = f(n,k-1)+f(n-1,k);
}
void solve(){
    int n,k;
    cin>>n>>k;
    dp.resize(n+1,vector<unsigned long long>(k+1,1));
    cout<<f(n,k)<<endl;
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