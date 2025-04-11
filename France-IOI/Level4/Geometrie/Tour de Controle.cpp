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
double dist(int x,int y,int x1,int y1){
    return sqrt( pow((x1-x),2) +  pow((y1-y),2));
}
void solve(){
    int x,y;
    cin>>x>>y;
    int n;
    cin>>n;
    double dista=1e9;
    pair<int,int>ans;
    for(int i=0;i<n;i++){
        int x1,y1;
        cin>>x1>>y1;
        double curr=dist(x,y,x1,y1);
        if (dist(x,y,x1,y1)<dista){
            dista=curr;
            ans.first=x1;
            ans.second=y1;
        }
    }
    cout<<ans.first<<" "<<ans.second<<endl;
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