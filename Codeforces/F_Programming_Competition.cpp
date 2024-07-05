#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
int dp[N], sz[N];

void dfs(int u){
    sz[u] = 0;
    for(auto v : g[u]){
        dfs(v);
        sz[u] += sz[v];
    }
    //cout << u << "->" << sz[u] << '\n';
    dp[u] = 0;
    for(auto v : g[u]){
        dp[u] = max(dp[u], dp[v] - (sz[u] - sz[v]));
    }
    sz[u]++;
    dp[u]++;   
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        g[i].clear();
    }
    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        g[p].push_back(i);
    }
   dfs(1);

    cout << (n - dp[1]) / 2 << '\n';
  
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
