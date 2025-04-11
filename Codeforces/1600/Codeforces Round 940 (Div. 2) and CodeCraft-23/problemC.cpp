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
const int N = 3e5+5 ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll prime = 1000003;
//const ll prime2 = 101 ;

ll dp[N];
ll rec(ll n){
    if (dp[n]!=-1)return dp[n];
    if (n<0)return 0;
    if (n<=1)return 1;
    return dp[n] = (2*(n-1)*rec(n-2)%MOD+rec(n-1)%MOD)%MOD;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    set<ll>st;
    for(ll i=1;i<=n;i++){
        st.insert(i);
    }
    for(ll i=0;i<k;i++){
        ll r1,c1;
        cin>>r1>>c1;
        if (r1==c1){
            st.erase(c1);
            continue;
        }
        st.erase(r1);
        st.erase(c1);
    }
    ll x=st.size();
    cout<<rec(x)<<endl;
}



int main()
{

    memset(dp,-1,sizeof(dp));
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
      FAST ;
      int t = 1  ;
            cin>> t;
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