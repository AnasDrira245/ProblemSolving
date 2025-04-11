#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0) //, cout.tie(0)
#define ll long long
#define ld long double
#define pb push_back
#define pi pair<ll,ll>
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define endl "\n"
using namespace std;
const ll MOD = 1e9+7  ;
// const int MOD = 998244353  ;
const int N = 505 ;
const ll INF = 1e18 ;
const ll MIN = -1e18 ;
const ll prime = 1000003;
//const ll prime2 = 101 ;
#include<iostream>
using namespace std;
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]"<<endl;}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << #x << " = ["; _print(x)
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

vector<vector<int>>dp;
int rec(int cnt1,int cnt2 ,vector<string>&s) {


    if (cnt1<0 || cnt2<0) {
        return -1e7;
    }
    if (cnt1==0 && cnt2==0) return 0;

    if (dp[cnt1][cnt1%3]!=-1) {
        return dp[cnt1][cnt1%3];
    }
    int x =  abs (cnt1-cnt2);

    int ans = 0;
    if (x==0) {
        ans =max(ans,  ((  (s[0][cnt1-1]=='A')+(s[0][cnt1-2]=='A')+(s[0][cnt1-3]=='A'))>=2) + ((  (s[1][cnt1-1]=='A')+(s[1][cnt1-2]=='A')+(s[1][cnt1-3]=='A'))>=2)  )   + rec(cnt1-3,cnt2-3,s);
        ans=max(ans,(( (s[0][cnt1-1]=='A') +(s[0][cnt1-2]=='A')+(s[1][cnt2-1]=='A'))>=2) + rec(cnt1-2,cnt2-1,s));
        ans=max(ans,(((s[0][cnt1-1]=='A')+(s[1][cnt2-1]=='A')+(s[1][cnt2-2]=='A'))>=2) + rec(cnt1-1,cnt2-2,s));
    }
    else {
        if (cnt1>cnt2) {
            ans=max(ans,(( (s[0][cnt1-1]=='A')+(s[0][cnt1-2]=='A')+(s[0][cnt1-3]=='A'))>=2) + (( (s[1][cnt2-1]=='A') +(s[1][cnt2-2]=='A')+(s[1][cnt2-3]=='A'))>=2) + rec(cnt1-3,cnt2-3,s));
            ans=max(ans,(( (s[0][cnt1-1]=='A') +(s[0][cnt1-2]=='A')+(s[1][cnt2-1]=='A'))>=2) +rec(cnt1-2,cnt2-1,s));
        }
        else {
            ans=max(ans,(((s[0][cnt1-1]=='A')+(s[0][cnt1-2]=='A')+(s[0][cnt1-3]=='A'))>=2) + (((s[1][cnt2-1]=='A')+(s[1][cnt2-2]=='A')+(s[1][cnt2-3]=='A'))>=2) +rec(cnt1-3,cnt2-3,s));
            ans=max(ans,(( (s[0][cnt1-1]=='A')+(s[1][cnt2-1]=='A')+(s[1][cnt2-2]=='A'))>=2) + rec(cnt1-1,cnt2-2,s));
        }


    }
    return dp[cnt1][cnt1%3] = ans;







}
void solve(){
    vector<string>s(2);
    int n;
    cin>>n;
    dp.assign(n+5,vector<int>(5,-1));

    for (int i=0;i<2;i++) {
        cin>>s[i];
    }
    cout<<rec(n,n,s)<<endl;

}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r",stdin), freopen("output.txt", "w",stdout);
#endif
    FAST ;
    int t = 1  ;
    cin>> t;
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