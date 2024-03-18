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
int ans[N],cur,siz[N],a[N],n;

void dfs1(int u = 1, int p = 0){
    siz[u] = 1;
    for(auto v: g[u]){
        if(v == p)continue;
        dfs1(v,u);
        siz[u] += siz[v];
        cur += (a[u] ^ a[v]) * siz[v];
    }
}

void dfs2(int u = 1, int p = 0){
    ans[u] = cur;
    for(auto v: g[u]){
        if(v == p)continue;
        cur -= (a[u] ^ a[v])*siz[v];
        cur += (a[u] ^ a[v])*(siz[1] - siz[v]);
        dfs2(v,u);
        cur += (a[u] ^ a[v])*siz[v];
        cur -= (a[u] ^ a[v])*(siz[1] - siz[v]);
    }
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        g[i].clear(),siz[i] = 0;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cur = 0;
    dfs1();
    dfs2();

    for(int i = 1; i <= n; i++){
        cout<<ans[i]<<" \n"[i == n];
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

