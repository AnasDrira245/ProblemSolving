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
int l,w;
bool valid(int x,int y){
    return (x>=0 && y>=0 && x<l && y<w);
}
void solve(){
    int n,m,c;
    cin>>n>>m>>c;
    l=n;
    w=m;
    
    vector<int>last(m,0);
    vector<int>curr(m,0);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        if  (i==0){
            last[a]=b;
        }
        else{
            for(int j=0;j<m;j++){
                curr[j]=0;
            }
            curr[a]=b;
            for(int j=0;j<m;j++){
                int call1=0,call2=0,call3=0;
                if (valid(i-1,j+1)){
                    call1 = last[j+1];
                }
                if (valid(i-1,j-1))
                    call2 = last[j-1];
                if (valid(i-1,j))
                    call3 = last[j];
                curr[j]+=max({call1,call2,call3});
            }
            last=curr;
        }
    }
    
    //one more iteration <3 <3
    int i=n-1;
    for(int j=0;j<m;j++){
                curr[j]=0;
    }
    for(int j=0;j<m;j++){
        int call1=0,call2=0,call3=0;
            if (valid(i-1,j+1)){
                    call1 = last[j+1];
                }
                if (valid(i-1,j-1))
                    call2 = last[j-1];
                if (valid(i-1,j))
                    call3 = last[j];
                curr[j]+=max({call1,call2,call3});
    }
            last=curr;
    cout<<curr[c]<<endl;
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