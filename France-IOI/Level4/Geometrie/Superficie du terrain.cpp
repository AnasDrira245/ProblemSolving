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
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll area=0;
    if (x2-x1>=0 && y2-y1>=0)
        area=(x2-x1)*(y2-y1);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
       ll xi1,yi1,xi2,yi2;
       cin>>xi1>>yi1>>xi2>>yi2;
        if (xi1>=x1 && xi2<=x2 && yi1>=y1 &&  yi2<=y2  ){
            area-=abs( xi1-xi2)*abs(yi1-yi2);
        }
        else{
        int x=0,y=0;
        if (xi2<=x2 && xi2>=x1)
        {
            x=min(abs(xi2-xi1),abs(xi2-x1));
        }
        else if (xi1>=x1 && xi1<=x2){
            x=min(abs(x2-xi1),abs(xi2-xi1));
        }
        else if (xi1<x1 && xi2>x2){
            x=(x2-x1);
        }
        if (yi2<=y2 && yi2>=y1)
        {
           y=min(abs(yi2-yi1),abs(yi2-y1));
        }
        else if (yi1>=y1 && yi1<=y2){
            y=min(abs(y2-yi1),abs(yi2-yi1));
        }
        else if (yi1<y1 && yi2>y2){
            y=(y2-y1);
        }
        area-=x*y;
       }
    }
    cout<<area<<endl;
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