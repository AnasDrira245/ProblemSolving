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
const int N = 505 ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll prime = 1000003;
//const ll prime2 = 101 ;
string s;
int f(){
    int valeur1;
    char x1,x2,op;
    if (scanf("%d",&valeur1)){
        return valeur1;
    }
    scanf("%c",&x1);
    int y = f();
    scanf("%c",&op);
    int z = f();
    scanf("%c",&x2);
    if (op=='+'){
        return y+z;
    }
    if (op=='-'){
        return y-z;
    }
    if (op=='*'){
        return y*z;
    }
    if(op=='/'){
        return y/z;
    }
    return y%z;
}
void solve(){
   cout<<f()<<endl;
}
int main()
{
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
      FAST ;
      int t = 1  ;
         //   cin>> t;
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