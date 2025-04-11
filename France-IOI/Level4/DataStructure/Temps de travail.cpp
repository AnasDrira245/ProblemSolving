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
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    multiset<int>st;
    int sum=0;
    for(int i=0;i<n;i++){
        int x=a[i].first;
        int y=a[i].second;
        if (!st.size()){
            sum+=y-x;
            st.insert(x);
            st.insert(y);
        }
        else{
            if (x<*st.begin()){
                sum+=*(st.begin())-x;
                st.insert(x);
            }
            if (x<*(--st.end())){
                if (y>*(--st.end())){
                    sum+=(y-*(--st.end()));
                    st.insert(y);
                }
            }
            else{
                sum+=y-x;
                st.insert(x);
                st.insert(y);
            }
        }
    }
    cout<<sum<<endl;
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