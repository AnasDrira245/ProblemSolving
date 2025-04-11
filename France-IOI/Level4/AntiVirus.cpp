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
bool ok(string &s,string &s1){
    if (s.size()!=s1.size())
        return false;
    if (s[0]=='?' && s1[0]=='0')
        return false;
    for(int x=0;x<s.size();x++)
    {
        if (s[x]!='?' && s[x]!=s1[x])
            return false;
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    vector<int>v;
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    string s;
    cin>>s;
    queue<int>q;
    for(auto i:adj[0])
        q.push(i);
    while(!q.empty()){
        int curr=q.front();
        v.push_back(curr);
        q.pop();
        for(auto i:adj[curr])
        {
            q.push(i);
        }
    }
    for(auto i:v)
    {
        string s1=to_string(i);
        if (ok(s,s1))
        {
            cout<<i<<" ";
        }
    }
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