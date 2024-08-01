#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int in[N],low[N],timer, sz[N], n , ans;
vector<int> g[N];

int get(int x, int y){
    return (x*(x-1)/2) + (y*(y-1)/2);
 }

 void dfs(int u,int p=-1){
     in[u] = low[u] = ++timer;
     sz[u] = 1;
     for(auto v:g[u]){
        if(v == p)continue;
        if(in[v] == 0){
        dfs(v,u);
        sz[u] += sz[v];

        low[u]=min(low[v],low[u]); 
        if(low[v]>in[u])
            ans = min(ans, get(sz[v],n - sz[v]));
        } else{
         low[u]=min(low[u],in[v]);
        }
   }
 }

 
void solve(){
    int  m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        g[i].clear(); in[i] = low[i] = vis[i] = sz[i] = 0;
    }
    timer = 0;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = n*(n-1)/2, cnt = 0;
    dfs(1);
    
    cout << ans << '\n';

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}