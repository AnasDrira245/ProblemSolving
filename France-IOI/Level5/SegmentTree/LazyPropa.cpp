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
struct node{
    int lazy,sum;
    bool upd;
    node(){
        upd=0;
        lazy=0;
        sum=0;
    }
    node(int s,int l,bool up){
        sum=s;
        lazy=l;
        upd=up;
    }
};
const int N=(1<<17)+2;
int n,q;
node tree[4*N];
node mrg(node &x,node &y){
    return node(x.sum+y.sum,0,0);
}
void unlazy(int id=0,int ns=0,int ne=n-1){
    if (!tree[id].upd){
        return;
    }
    if (ns!=ne){
        int left = 2*id + 1;
        int right = left + 1;
        int mid = (ns+ne)/2;
        tree[left].upd = true;
        tree[right].upd = true;
        tree[left].lazy+=tree[id].lazy;
        tree[right].lazy+=tree[id].lazy;
        tree[left].sum+=(mid-ns+1)*tree[id].lazy;
        tree[right].sum+=(ne-mid)*tree[id].lazy;
    }
    tree[id].lazy=0;
    tree[id].upd=0;
}
void update(int qs,int qe,int v,int id=0,int ns=0,int ne=n-1){
    unlazy(id,ns,ne);
    if (qs>ne || ns>qe){
        return;
    }
    if (qs<=ns && ne<=qe){
        tree[id].sum+=(ne-ns+1)*v;
        tree[id].lazy+=v;
        tree[id].upd=true;
        return;
    }
    int l=2*id+1;
    int r=l+1;
    int md=(ns+ne)/2;
    update(qs,qe,v,l,ns,md);
    update(qs,qe,v,r,md+1,ne);
    tree[id]=mrg(tree[l],tree[r]);
}
node query(int qs,int qe,int id=0,int ns=0,int ne=n-1){
    unlazy(id,ns,ne);
    if (qs>ne || ns>qe){
        return node(0,0,false);
    }
    if (qs<=ns && ne<=qe){
        return tree[id];
    }
    int l=2*id+1;
    int r=l+1;
    int md=(ns+ne)/2;
    node node1=query(qs,qe,l,ns,md);
    node node2=query(qs,qe,r,md+1,ne);
    return mrg(node1,node2);
}
void solve(){
    cin>>n;
    n=(1<<n);
    cin>>q;
    while(q--){
        char x;
        cin>>x;
        if (x=='D'){
            int l,r,v;
            cin>>l>>r>>v;
            update(l,r,v);
        }
        else{
            int l;
            cin>>l;
            cout<<query(l,l).sum<<endl;
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