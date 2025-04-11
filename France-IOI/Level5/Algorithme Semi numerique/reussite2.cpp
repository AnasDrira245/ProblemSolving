
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
set<int> factors(int n) {
    set<int> f;
    for (int x = 2; x*x <=n; x++) {
        if (n%x==0){
            f.insert(x);
            f.insert(n/x);
        }
    }
    return f;
}
void solve(){
    int x,n;
    cin>>x;
    set<int> st= factors(x);
    if (st.size()){
    int ans=0;
    for(auto i:st){
        cout<<i<<endl;
    }
    
}else{
   
    cout<<0<<endl;
    }
    
    
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