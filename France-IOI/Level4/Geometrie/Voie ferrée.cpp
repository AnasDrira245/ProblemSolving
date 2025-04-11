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
double dist(double x,double y,double x1,double y1){
    return sqrt( pow((x1-x),2) +  pow((y1-y),2));
}
double f(double xa,double ya,double xb,double yb , double xp,double yp){
    double a=(yb-ya)/(xb-xa);
    double b = ya-(a *xa);
   // cout<<a<<" "<<b<<endl;
    double g=( xb-xa+a*(yb-ya)  );
    double xh=  ((xb-xa)*xp+(yb-ya)*yp-(yb-ya)*b)/g;
    double yh= a*xh + b;
   // cout<<xh<<" "<<yh<<endl;
    double d1=dist(xa,ya,xh,yh);
   // cout<<xh-xa<<endl;
    //return 0;
    return dist(xh,yh,xp,yp);
}
void solve(){
    double xa,ya,xb,yb;
    cin>>xa>>ya>>xb>>yb;
    int n;
    cin>>n;
    double ans=0;
    pair<double,double>p;
    for(int i=0;i<n;i++){
        double xp,yp;
        cin>>xp>>yp;
        double x= f(xa,ya,xb,yb,xp,yp);
        if (x>ans){
            ans=x;
            p.first=xp;
            p.second=yp;
        }
    }
    cout<<p.first<<" "<<p.second<<endl;
}
int main()
{
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
      FAST ;
      int t = 1  ;
          //  cin>> t;
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