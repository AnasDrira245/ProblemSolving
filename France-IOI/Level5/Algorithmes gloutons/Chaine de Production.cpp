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
    int m1;
    cin>>m1;
    vector<int>a(m1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    stack<int>st;
    for(int i=0;i<m1;i++){
        cin>>a[i];
        q.push({a[i],a[i]});
    }
    int ans=1e7;
    while(n){
        auto curr=q.top();
        q.push({curr.first+curr.second,curr.second});
        st.push(curr.first);
        ans=curr.first;
        q.pop();
        n--;
    }
    cout<<ans<<endl;
    while(!q.empty()){
        //cout<<q.top().first<<endl;
        q.pop();
    }
    int m2;
    cin>>m2;
    vector<int>b(m2);
    for(int i=0;i<m2;i++){
        cin>>b[i];
        q.push({b[i],b[i]});
    }
    ans=0;
    while(!st.empty()){
        auto curr=q.top();
        auto curr2=st.top();
        q.push({curr.first+curr.second,curr.second});
        ans=max(ans,curr2+curr.first);
        q.pop();
        st.pop();
    }
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