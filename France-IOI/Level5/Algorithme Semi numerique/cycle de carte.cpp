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
    vector<int>mp(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    vector<int>vis(n+1);
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        vector<int>tmp;
        bool test=false;
        while(a[i]!=i+1 && !vis[a[i]]){
            test=true;
            vis[a[i]]=true;
            tmp.push_back(a[i]);
            swap( a[i],a[ a[i]-1 ]     );
        }
        if (!vis[a[i]])
            tmp.push_back(a[i]);
        if (tmp.size())
            ans.push_back(tmp);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
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