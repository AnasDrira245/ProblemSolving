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
    int x,y;
    cin>>x>>y;
    vector<array<int,3>>edges;
    for(int i=0;i<y;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    vector<int>distance(x+1,1e7);
    distance[1]=0;
    for(int i=1;i<=x+1;i++){
        for(auto e:edges){
            if (distance[e[1]]>distance[e[0]]+e[2]){
                distance[e[1]]=distance[e[0]]+e[2];
                if (i==x+1){
                    cout<<"ERREUR"<<endl;
                    return;
                }
            }
        }
    }
    cout<<distance[x]<<endl;
}
int main()
{
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
      FAST ;
      int t = 1  ;
        //    cin>> t;
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