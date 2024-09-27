#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];

int res = 0;
void dfs(int u, int p){
    if(g[u].size() == 1)res += 3;
    else res += 2;
    for(auto v : g[u]){
        if(p == v)continue;
        dfs(v, u);
    }
}
void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    res = 0;
    dfs(1, 0);
    cout << res << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
