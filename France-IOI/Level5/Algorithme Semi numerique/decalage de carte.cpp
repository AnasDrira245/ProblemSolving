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
    int n;
    cin>>n;
    vector<int>a(n);
    a[0]=n;
    for(int i=1;i<n;i++){
        a[i]=i;
    }
    vector<pair<int,int>>e1;
    vector<pair<int,int>>e2;
    for(int i=1;i<=n/2;i++){
            if (a[i]==a[n-i])
                continue;
            e1.push_back({i+1,n-i+1 } );
            swap(a[i],a[n-i]);
    }
    for(int i=0;i<n/2;i++){
        if (a[i]==a[n-i-1]){
            continue;
        }
        e2.push_back({i+1,n-i} );
        swap(a[i],a[n-i-1]);
    }
    cout<<e1.size()<<" "<<e2.size()<<endl;
    for(auto i:e1){
        cout<<i.first<< " " << i.second<<endl;
    }
   for(auto i:e2){
        cout<<i.first<< " " << i.second<<endl;
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