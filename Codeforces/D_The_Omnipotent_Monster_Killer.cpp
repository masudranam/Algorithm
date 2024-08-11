#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 3e5 + 10;

int a[N], dp[N][50];
vector<int> g[N];

int dfs(int u, int i, int p){
    int &ret = dp[u][i];
    if(ret != -1) return ret;
    ret = a[u] * i;
    for(auto v : g[u]){
        if(v == p)continue;
        int tmp = M*M;
        for(int j = 1; j < 15; j++){
            if(i == j)continue;
            tmp = min(tmp, dfs(v,j,u));
        }        
        ret += tmp;
    }
    return ret;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
        for(int j = 0; j < 15; j++){
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res = M*M;
    for(int i = 1; i < 15; i++){
        res = min(res, dfs(0,i,-1));
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