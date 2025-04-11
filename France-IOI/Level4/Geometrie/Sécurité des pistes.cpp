#include<bits/stdc++.h>
#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll MOD = 1e9 + 7;
const int N = 505;
const ll INF = 1e18;
void solve() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double a = (y1 - y2) / (x1 - x2);
    double b = y1 - a * x1;
    double x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    double c = (y3 - y4) / (x3 - x4);
    double d = y4 - c * x4;
    if (x1 == x2) {
        cout<<x1<<" "<<c*x1+d<<endl;
        return;
    }
    if (x3 == x4) {
        cout<<x3<<" "<<a*x3+b<<endl;
        return;
    }
    double ans1 = (b - d) / (c - a);
    double ans2 = a * ans1 + b;
    cout << setprecision(20) << ans1 << " " << ans2 << endl;
}
int main() {
    FAST;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}