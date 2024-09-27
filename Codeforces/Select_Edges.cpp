#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 3e5 + 10;

vector<pair<int,int>> g[N];
int dp[N][2], deg[N];

void dfs(int u, int p){
    vector<int> vec;
    for(auto it : g[u]){
        int v = it.first, w = it.second;
        if(v == p)continue;
        dfs(v, u);
        vec.push_back(dp[v][0] + w - dp[v][1]);
        dp[u][0] += dp[v][1], dp[u][1] += dp[v][1];
    }
    sort(vec.rbegin(), vec.rend());
    for(int i = 0; i < (int)vec.size(); i++){
        if(vec[i] <= 0)break;
        if(i < deg[u])dp[u][1] += vec[i];
        if(i < deg[u] - 1)dp[u][0] += vec[i];
    }
    if(deg[u] == 0)dp[u][0] = -M * 10;
}
void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> deg[i];
    }
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
