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

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
char directions[] = {'U', 'D', 'L', 'R'};
int n,m;
pair<int, int> get_next(int x, int y, char dir) {
    if (dir == 'U') return {x - 1, y};
    if (dir == 'D') return {x + 1, y};
    if (dir == 'L') return {x, y - 1};
    return {x, y + 1};
}
vector<vector<int>> dp;
vector<vector<int>> visited;

bool detect_cycle(int x, int y, vector<vector<char>>& grid) {

    if (dp[x][y] != -1) return dp[x][y] == 1;


    if (visited[x][y] == 1) return true;

    if (visited[x][y] == 2) return false;

    visited[x][y] = 1;

    bool trapped = false;
    if (grid[x][y] == '?') {
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                trapped |= detect_cycle(nx, ny, grid);
            }
        }
    } else {
        auto [nx, ny] = get_next(x, y, grid[x][y]);
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            trapped = detect_cycle(nx, ny, grid);
        }
    }

    visited[x][y] = 2;

    dp[x][y] = trapped ? 1 : 0;
    return trapped;
}


void solve(){

    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    dp.assign(n, vector<int>(m, -1));
    visited.assign(n, vector<int>(m, 0));
    int cycle_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (detect_cycle(i, j, grid)) {
                cycle_count++;
            }
        }
    }
    cout<<cycle_count<<endl;




}

int main()
{
     //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
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