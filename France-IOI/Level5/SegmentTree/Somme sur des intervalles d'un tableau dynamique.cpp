#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const int N = 1e5 + 2;
int a[N];
int n,q,l,r;
char t;
int tree[4*N];
int mrg(int x, int y){
    return x+y;
}
void build(int id=0,int ns = 0, int ne = n-1){
    if(ns==ne){
        tree[id] = a[ns];
        return ;
    }
    int l = 2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    build(l, ns, md);
    build(r, md+1, ne);
    tree[id] = mrg(tree[l],tree[r]);
}
int query(int qs, int qe, int id=0, int ns=0, int ne=n-1){
    if(ns>qe || qs>ne){
        return 0; ///infnity
    }
    if(qs<=ns && qe>=ne){
        return tree[id];
    }
    int l = 2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    return mrg(query(qs, qe, l, ns, md), query(qs, qe,r, md+1,ne));
}
void upd(int pos , int val , int id=0, int ns=0,int ne=n-1){
    if(ns>pos || pos>ne){
        return;
    }
    if(ns==ne){
        tree[id]=val;
        return ;
    }
    int l = 2*id+1;
    int r = l+1;
    int md = ns+(ne-ns)/2;
    upd(pos, val,l, ns, md);
    upd(pos, val, r, md+1, ne);
    tree[id] = mrg(tree[l],tree[r]);
}
int main()
{
    FAST;
    cin >> n ;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    build();
    cin>>q;
    while(q--){
        cin >> t >> l >> r;
        if (t=='M')
            upd(l,r);
        else
            cout<<query(l,r)<<endl;
    }
    return 0;
}