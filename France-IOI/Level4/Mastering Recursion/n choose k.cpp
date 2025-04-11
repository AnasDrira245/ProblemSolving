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
vector<vector<int>>v;
void recursion(int n,int k,vector<int>&ans,int index)
{
    if (k==0)
    {
        v.push_back(ans);
        return;
    }
    for(int i=index+1;i<n;i++)
    {
            if (n-index+1<k)
                return;
            ans.push_back(i+1);
            recursion(n,k-1,ans,i);
            ans.pop_back();
    }
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>ans;
    recursion(n,k,ans,-1);
    for(auto i:v)
    {
        for(auto j:i)
        {
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