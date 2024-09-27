#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
int cycle[N], par[N], vis[N], n;


bool dfs(int u, int p){
    
    if(vis[u] == 1){
        int cur = p;
        cycle[cur] = 1;
        do{
            cur = par[cur];
            cycle[cur] = 1;
        }while(cur != u);
        return true;
    }

    vis[u] = 1;
    par[u] = p;
    for(auto v : g[u]){
        if(v == p)continue;
        if(dfs(v,u)) return true;
    }
    vis[u] = 2;
    return false;
}

int cnt(int u, int p){
    int res = 1;
    for(auto v : g[u]){
        if(v == p || cycle[v])continue;
        res += cnt(v,u);
    }
    return res;
}

void solve(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();vis[i] = cycle[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        int u, v; cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(1,0);

    int res = 0;
    for(int i = 1; i <= n; i++){
        if(!cycle[i])continue;
        int cur = cnt(i,0);
        res += ((cur * (cur - 1) / 2) + (cur * (n - cur)));
    }
    cout << res << '\n';

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
