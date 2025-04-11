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
vector<vector<int>>dp(101,vector<int>(101,-1));
int rec(int left,int right,vector<int>&col){
    if (dp[left][right]!=-1){
        return dp[left][right];
    }
    if (right-left<3){
        int curr=0;
        for(int i=left;i<=right;i++){
            curr=max(curr,col[i]);
        }
        return dp[left][right] = curr;
    }
    int ans=1e7;
    for(int k=left;k<=right-1;k++){
        int call1 = rec(left,k,col);
        int call2= rec(k+1,right,col);
        ans=min(ans,call1+call2);
    }
    return dp[left][right] = ans;
}
void solve(){
    int x,y;
    cin>>x>>y;
    vector<int>col(x+1);
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        col[a]=max(col[a],b);
    }
    int ans=rec(1,x,col);
    cout<<ans<<endl;
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