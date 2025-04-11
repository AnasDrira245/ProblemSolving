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
void bfs(int node,int node2 ,vector<vector<array<int,2>>>&graph,int x,int y){
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
    vector<int>distance(1001,1e7);
    vector<bool>vis(1001);
    vector<int>edges(1001);
    distance[node]=0;
    q.push({0,node});
    edges[node]=-1;
    while(!q.empty()){
        auto curr=q.top();
        q.pop();
        if (vis[curr[1]]){
            continue;
        }
        vis[curr[1]]=true;
        for(auto i:graph[curr[1]]){
            if (vis[i[1]])
                continue;
            if (distance[i[1]]>distance[curr[1]]+i[0])
                {distance[i[1]]=distance[curr[1]]+i[0];
                    edges[i[1]]=curr[1];
                }
            q.push({distance[i[1]],i[1]});
        }
    }
    vector<int>ans;
    int ans2=distance[node2];
    while(node2!=-1){
        ans.push_back(node2);
        node2 = edges[node2];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans2<<" "<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
}
void solve(){
    int x,y,z,f;
    cin>>x>>y>>z>>f;
    vector<vector<array<int,2>>>graph(1000+1);
    for(int i=0;i<y;i++){
        int x1,y1,z1;
        cin>>x1>>y1>>z1;
        graph[x1].push_back({z1,y1});
        graph[y1].push_back({z1,x1});
    }
    bfs(z,f,graph,x,y);
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