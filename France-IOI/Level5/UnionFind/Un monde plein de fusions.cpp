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
struct unionfind{
    vector<int>ranks;
    vector<int>parent;
    int forest;
    unionfind(int n){
        forest=n;
        parent.resize(n);
        ranks.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            ranks[i]=1;
        }
    }
    int find_set(int a){
        if (parent[a]==a){
            return a;
        }
        return parent[a]=find_set(parent[a]);
    }
    bool link(int a,int b){
        if (ranks[a]>ranks[b]){
            swap(a,b);
        }
        parent[a]=b;
        if (ranks[a]==ranks[b]){
            ranks[b]++;
        }
    }
    bool union_set(int a,int b){
        a=find_set(a),b=find_set(b);
        if (a!=b){
            link(a,b);
            forest--;
        }
        return a!=b;
    }
};
void solve(){
    int x,y;
    cin>>x>>y;
    unionfind dsu(x);
    for(int i=0;i<y;i++){
        int a,b;
        cin>>a>>b;
        bool op=dsu.union_set(a,b);
        if (op){
            cout<<a<<" "<<b<<endl;
        }
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