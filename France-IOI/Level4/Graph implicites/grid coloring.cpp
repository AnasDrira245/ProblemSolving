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
int l,h;
bool valid(int x,int y){
    return x>=0 && y>=0 && x<h&& y<l;
}
void solve(){
    cin>>l>>h;
    char grid[h][l];
    for(int i=0;i<h;i++){
        for(int j=0;j<l;j++){
            cin>>grid[i][j];
        }
    }
    pair<int,int>pion1={0,0};
    pair<int,int>pion2={h-1,l-1};
    queue<pair<int,int>>q;
    q.push(pion1);
    q.push(pion2);
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    set<pair<  pair<int,int>       ,    pair<int,int>      > > st;
    st.insert (make_pair( pion1,pion2   ));
    while(!q.empty()){
        auto curr1=q.front();
        q.pop();
        auto curr2=q.front();
        q.pop();
        if (curr2.first==0 && curr2.second==0 && curr1.first==h-1 && curr1.second==l-1  ){
            cout<<1<<endl;
            return;
        }
        for(int k=0;k<4;k++){
                for(int z=0;z<4;z++){
                    pair<int,int>curr_position1={curr1.first+dx[k],curr1.second+dy[k]};
                    pair<int,int>curr_position2={curr2.first+dx[z],curr2.second+dy[z]};
                    if (valid(curr_position1.first,curr_position1.second) && valid(curr_position2.first,curr_position2.second)){
                        if (grid[curr_position1.first][curr_position1.second]==grid[curr_position2.first][curr_position2.second]){
                            if (!st.count(  make_pair( curr_position1,curr_position2 )  )){
                            st.insert( make_pair( curr_position1,curr_position2 )    );
                            q.push(curr_position1);
                            q.push(curr_position2);
                            }
                        }
                    }
                }
            }
        }
    cout<<0<<endl;
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