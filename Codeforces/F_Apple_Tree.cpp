#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
int siz[N];

void dfs(int u, int p = 0){
    if(sz(g[u]) == 1 && u != 1)siz[u] = 1;
    for(auto v: g[u]){
        if(v == p)continue;
        dfs(v,u);
        siz[u] += siz[v];
    }
}


void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
        siz[i] = 0;
    }
    
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);

    cin >> n;
    while(n--){
        int u, v; cin >> u >> v;
        cout<< siz[u]*siz[v] << endl;
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

