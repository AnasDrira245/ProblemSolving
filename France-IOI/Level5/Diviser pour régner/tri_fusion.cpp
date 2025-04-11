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
vector<int> mrg(vector<int>&left,vector<int>&right){
    vector<int>res;
    int i=0;
    int j=0;
    int n1=left.size();
    int n2=right.size();
    while(i<n1 && j<n2){
        if (left[i]==right[j]){
            res.push_back(left[i]);
            res.push_back(right[j]);
            i++;
            j++;
        }
        else if (left[i]<right[j]){
            res.push_back(left[i]);
            i++;
        }
        else{
            res.push_back(right[j]);
            j++;
        }
    }
    while(i<n1){
        res.push_back(left[i]);
        i++;
    }
     while(j<n2){
        res.push_back(right[j]);
       j++;
    }
    return res;
}
vector<int> merge_sort(int s,int e,vector<int>&a){
    if (s==e){
        return {a[s]};
    }
    int md=s+(e-s)/2;
    vector<int>left= merge_sort(s,md,a);
    vector<int>right= merge_sort(md+1,e,a);
    return mrg(left,right);
}
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>res = merge_sort(0,n-1,a);
    for(auto i:res){
        cout<<i<<" ";
    }
}
int main()
{
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
      FAST ;
      int t = 1  ;
          //  cin>> t;
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