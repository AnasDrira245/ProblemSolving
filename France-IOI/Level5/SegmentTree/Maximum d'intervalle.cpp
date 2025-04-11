#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll MOD = 1e9+7  ;
// const int MOD = 998244353  ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll prime = 1000003;
//const ll prime2 = 101 ;
const int N=1e5+2;
int n,q;
int a[N];
int tree[4*N];
int mrg(int x,int y)
{
    return max(x,y);
}
void build(int id=0,int ns=0,int ne=n-1){
    if (ns==ne){
        tree[id]=a[ns];
        return;
    }
    int l=2*id+1;
    int r=l+1;
    int md=ns+(ne-ns)/2;
    build(l,ns,md);
    build(r,md+1,ne);
    tree[id]=mrg(tree[l],tree[r]);
}
int query(int qs,int qe,int id=0,int ns=0,int ne=n-1){
    if (qs>ne|| qe<ns){
        return -1e7;
    }
    if (qs<=ns && ne<=qe){
        return tree[id];
    }
    int l=2*id+1;
    int r=l+1;
    int md=ns+(ne-ns)/2;
    return mrg(query(qs,qe,l,ns,md),query(qs,qe,r,md+1,ne));
}
void upd(int pos,int val,int id=0,int ns=0,int ne=n-1){
    if (pos<ns || pos>ne){
        return;
    }
    if (ns==ne){
        tree[id]=val;
        return;
    }
    int l=2*id+1;
    int r=l+1;
    int md=ns+(ne-ns)/2;
    upd(pos,val,l,ns,md);
    upd(pos,val,r,md+1,ne);
    tree[id]=mrg(tree[l],tree[r]);
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    build();
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(l,r)<<endl;
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