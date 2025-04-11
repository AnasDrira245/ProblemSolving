#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
#define pb push_back
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
    vector<pair<int,int>>stock;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        stock.pb({x,y});
    }
    int r;
    cin>>r;
    vector<pair<int,int>>commande;
    for(int i=0;i<r;i++){
        int x,y;
        cin>>x>>y;
        commande.pb({x,y});
    }
    sort(commande.begin(),commande.end());
    int cnt=0;
    vector<bool>visited(n);
    for(int i=r-1;i>=0;i--){
        pair<int,int>best={0,1e7};
        int last=-1;
        for(int j=0;j<n;j++){
            if (stock[j].first>=commande[i].first && stock[j].second>=commande[i].second){
                if (!visited[j] && stock[j].second<=best.second){
                    best=stock[j];
                    last=j;
                }
            }
        }
        if (best.first!=0 && best.second!=1e7){
            cnt++;
            visited[last]=1;
        }
    }
    cout<<cnt<<endl;
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