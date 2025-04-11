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
    int b,n1,n2;
    cin>>b>>n1>>n2;
    vector<int>a1;
    vector<int>a2;
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        a1.push_back(x);
    }
    reverse(a1.begin(),a1.end());
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        a2.push_back(x);
    }
    reverse(a2.begin(),a2.end());
    if (n1<n2){
        swap(n1,n2);
        swap(a1,a2);
    }
    // n1 houa kbir
    int i=0;
    int carry=0;
    while(i<n1 && i<n2){
        a1[i]+=a2[i];
        a1[i]+=carry;
        carry=a1[i]/b;
        a1[i]=a1[i]%b;
        i++;
    }
    while(i<n1){
        a1[i]+=carry;
        carry=a1[i]/b;
        a1[i]=a1[i]%b;
        i++;
    }
    while(carry){
        a1.push_back(carry);
        i++;
        carry=a1[i]/b;
        a1[i]=a1[i]%b;
    }
    reverse(a1.begin(),a1.end());
    for(auto i:a1){
        cout<<i<<" ";
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