#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int dp[1<<21], a[N], x[N], y[N];
int n, k, d[N];
vector<pair<int,int>>g[N];

bool get(int u, int p, int t, int i){
    if(u == t)return true;
    for(auto v : g[u]){
        if(v.first == p)continue;
        if(get(v.first,u,t,i)){
            a[v.second] |= (1<<i);
            return true;
        }
    }
    return false;
}
 
void solve(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
        d[i] = a[i] = 0;
    }
    for(int i = 0; i <= (1<<k); i++){
        a[i] = 0;
    }
    for(int i = 1; i< n; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    cin >> k;
    for(int j = 0; j < k; j++){
        int u, v; cin >> u >> v;
        u--, v--;
        get(u,-1,v,j);
    }
    vector<int> st,vis(1<<k);
    for(int i = 1; i < n; i++){
        if(vis[a[i]])continue;
        st.push_back(a[i]);
        vis[a[i]] = 1;
    }
    for(int j = 0; j <= (1<<k); j++){
        dp[j] = M;
    }

    dp[0] = 0;

    for(auto mask : st){
        for(int i = 0; i < (1<<k); i++){
            dp[i|mask] = min(dp[i] + 1, dp[i|mask]);
        }
    }
    cout << dp[(1<<k)-1] << '\n';
   
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
