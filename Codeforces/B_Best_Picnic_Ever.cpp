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

map<int,int>vis;
int cnt[N];
vector<int> g[N];

void dfs(int u){
    vis[u] = 1;
    cnt[u]++;
    for(auto v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve(){
    int n, m, k;

    cin >> k >> n >> m;
    vector<int> a(k);
    for(auto &x: a)cin >> x;
    for(int i = 0; i <= n; i++){
        g[i].clear();
        cnt[i] = 0;
    }

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i = 0; i < k; i++){
        vis.clear();
        dfs(a[i]);
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(cnt[i] == k)ans++;
    }

    cout<<ans<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
    cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

