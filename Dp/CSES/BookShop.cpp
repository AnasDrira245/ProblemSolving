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
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define karr(x) cout<<(#x)<<": ";_print(x);cout<<endl;
#define F first
#define S second
#define kar trace
#define wow cout<<"YES"<<endl;
 
 
 
// old template
void _print(int x) {cout << x;}
void _print(long x) {cout << x;}
void _print(long long x) {cout << x;}
void _print(unsigned x) {cout << x;}
void _print(unsigned long x) {cout << x;}
void _print(unsigned long long x) {cout << x;}
void _print(float x) {cout << x;}
void _print(double x) {cout << x;}
void _print(long double x) {cout << x;}
void _print(char x) {cout << '\'' << x << '\'';}
void _print(const char *x) {cout << '\"' << x << '\"';}
void _print(const string &x) {cout << '\"' << x << '\"';}
void _print(bool x) {cout << (x ? "True" : "False");}
//
//
template<typename T, typename V>
void _print(const pair<T, V> &x) {cout << '{'; _print(x.first); cout << ','; _print(x.second); cout << '}';}
template<typename T>
void _print(const T &x) {int f = 0; cout << '['; for (auto &i: x) cout << (f++ ? " " : ""), _print(i); cout << "]";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {_print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
 
 
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
 
// colored debug with all possible data strucutres stl with cout
#define all(x) x.begin(),x.end()
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[1;34m"
#define PURPLE "\033[1;35m"
#define BLUE "\033[1;36m"
#define trace(...) __f(__LINE__,#__VA_ARGS__, __VA_ARGS__) ;
#define Trace(color,...) __f(__LINE__,color,#__VA_ARGS__, __VA_ARGS__)
 
 
//IO operators for vectors, pairs, sets, maps and __int128 so I can print just about anything
template <typename U, typename V>istream &operator >>(istream &in, pair<U, V> &p){in>>p.first>>p.second;return in;}
template <typename U, typename V>ostream &operator <<(ostream &ost, pair<U, V> p){if (&ost == &cout)ost << "{" << p.first << "," << p.second << "}";else ost << p.first << " " << p.second << " ";return ost;}
ostream &operator<<(ostream &ost, __int128_t x){string output = "";while(x)output += '0'+x%10, x /= 10;reverse(all(output)); ost << output;  return ost;}
istream &operator>>(istream &in, __int128_t &x){x=0;string num;cin >> num;for(char c:num) x *= 10, x += c-'0';return in;}
template <typename T>istream &operator>>(istream &in, vector<T> &v){for (auto &i : v)in >> i;return in;}
template <typename T>ostream &operator<<(ostream &ost, vector<T> v){if(&ost == &cout){cout <<"[";int cnt = v.size();for(auto x:v){cout << x;cnt--;if(cnt) cout << ", ";}cout << "]";}else for(auto i:v)ost << i << " ";return ost;}
template <typename T>ostream &operator<<(ostream &ost, set<T> s){if(&ost == &cout){cout <<"[";int cnt = s.size();for(auto x:s){cout << x;cnt--;if(cnt) cout << ", ";}cout << "]";}else for(auto i:s)ost << i << " ";return ost;}
template <typename T>ostream &operator<<(ostream &ost, multiset<T> s){if(&ost == &cout){cout <<"[";int cnt = s.size();for(auto x:s){cout << x;cnt--;if(cnt) cout << ", ";}cout << "]";}else for(auto i:s)ost << i << " ";return ost;}
template <typename U, typename V>ostream &operator <<(ostream &ost, map<U,V> &m){if(&ost == &cout){cout <<"[";int cnt = m.size();for(auto x:m){cout << x; cnt--;if(cnt) cout << ", ";}cout << "]";}else for(auto i:m)ost << i;return ost;}
 
 
//Variadic IO
template <typename... T>void read(T &...args){((cin >> args), ...);}
template <typename... T>void print(T... args){((cout << args << " "), ...);cout << endl;}
template <typename Arg1>
void __f(int line,  const char* name, Arg1&& arg1){
    cout << "(Ln " << line << ") " << name << ": " << arg1 << " " << endl;
}
template <typename Arg1, typename... Args>
void __f(int line, const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cout << "(Ln " << line << ") ";
    cout.write(names, comma - names) << ": " << arg1 << " " << endl;
    __f(line,comma+1, args...);
}
 
const ll mod = 1e9+7;
 
void solve() {
 
    ll n,x;
    cin>>n>>x;
 
    vector<ll>h(n);
    vector<ll>s(n);
    for(int i=0;i<n;i++) {
        cin>>h[i];
    }
    for(int i=0;i<n;i++) {
        cin>>s[i];
    }
    vector<vector<ll>>dp(2,vector<ll>(x+1));
    for (int i=0;i<n;i++) {
        for (int j=0;j<=x;j++) {
            if (i){
                if (j>=h[i])
                    dp[i%2][j] = dp[(i-1)%2][j-h[i]]+s[i];
                dp[i%2][j]=max(dp[i%2][j],dp[(i-1)%2][j]);
            }
            else {
                if (j>=h[i])
                    dp[i%2][j]=s[i];
            }
        }
    }
 
    ll ans=0;
    for (int i=0;i<n;i++) {
        ans = max(ans, dp[i%2][x]);
    }
    cout << ans << endl;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    FAST;
    int t = 1;
 //   cin>>t;
    while (t--) {
        solve();
    }
}