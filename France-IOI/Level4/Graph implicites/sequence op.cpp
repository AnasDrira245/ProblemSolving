#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll MOD = 1e9+7  ;
// const int MOD = 998244353  ;
const int N = 1e5+2 ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll prime = 1000003;
//const ll prime2 = 101 ;
void solve(){
    vector<bool>vis(N);
    stack<int>q;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int n,m;
    cin>>n>>m;
    q.push(n);
    vis[n]=true;
    while(!q.empty()){
        int curr=q.top();
        q.pop();
        if (curr==m){
            cout<<1<<endl;
            return;
        }
        if (curr+a<N && !vis[curr+a]){
            vis[curr+a]=1;
            q.push(curr+a);
        }
        if (curr-b>=0 && !vis[curr-b]){
            vis[curr-b]=1;
            q.push(curr-b);
        }
        if (curr*c<N && !vis[curr*c]){
            vis[curr*c]=1;
            q.push(curr*c);
        }
        if (d!=0 && curr%d==0 && !vis[curr/d]){
            vis[curr/d]=1;
            q.push(curr/d);
        }
    }
    cout<<0<<endl;
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