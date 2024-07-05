#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int lose[N], ans[N];
vector<int> g[N];

void dfs(int u, int p){
    for(auto v : g[u]){
        if(v == p)continue;
        dfs(v,u);
        lose[u] += (lose[v] == 0);
    }
}

void calc(int u, int p){
    ans[u] = lose[u] > 0;
    for(auto v : g[u]){
        if(v == p)continue;
        lose[u] -= (lose[v] == 0);
        lose[v] += (lose[u] == 0);
        calc(v,u);
        lose[v] -= (lose[u] == 0);
        lose[u] += (lose[v] == 0);
    }
}

void solve(){
    int n; cin >> n;
    int q; cin >> q;

    for(int i = 0; i <= n; i++){
        g[i].clear(); lose[i] = ans[i] = 0;
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);
    calc(1,0);

    for(int i = 0; i < q; i++){
        int root; cin >> root;
        if(ans[root])cout << "Ron\n";
        else cout << "Hermione\n";
    }

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
