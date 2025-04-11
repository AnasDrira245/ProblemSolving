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
bool op(vector<int>x,vector<int> y){
    return x[1]<y[1];
}
void solve(){
    int n,s;
    cin>>n>>s;
    vector<vector<int>>film;
    for(int i=0;i<s;i++){
        int x,y;
        cin>>x>>y;
        film.push_back({x,y,i});
    }
    sort(film.begin(),film.end(),op);
    vector<int>last(n);
    vector<int>ans(s);
    last[0]=film[0][1];
    ans[film[0][2]]=0;
    for(int i=1;i<s;i++){
        bool test=false;
        for(int j=0;j<n;j++){
            if (film[i][0]>=last[j]){
                last[j]=film[i][1];
                ans[film[i][2]]=j;
                test=true;
                break;
            }
        }
        if (!test){
            cout<<"NON"<<endl;
            return;
        }
    }
    cout<<"OUI"<<endl;
    for(auto i:ans){
        cout<<i+1<<" ";
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