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
    vector<vector<int>>adj(x+1,vector<int>(x+1,1e7));
    for(int i=0;i<y;i++){
            int a,b,c;
            cin>>a>>b>>c;
            adj[a][b]=c;
    }
    vector<vector<int>>distance(x+1,vector<int>(x+1,1e7));
    for(int i=1;i<=x;i++){
        for(int j=1;j<=x;j++){
            if (i==j){
            distance[i][i]=0;
            }
            else if (adj[i][j]!=1e7){
                distance[i][j]=adj[i][j];
            }
        }
    }
    for(int k=1;k<=x;k++){
        for(int i=1;i<=x;i++){
            for(int j=1;j<=x;j++){
                distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
                if (distance[i][j]==1e7)
                    cout<<'.'<<"  ";
                else
                cout<<distance[i][j]<<"  ";
            }
            cout<<endl;
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