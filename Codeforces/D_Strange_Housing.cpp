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
const int N = 3e5 + 10;

vector<int> g[N];
int col[N],vis[N];
int n, m;

void dfs(int u){
    vis[u] = 1;
    col[u] = 1;
    for(auto v: g[u]){
        if(col[v] == 1)col[u] = 0;
    }
    for(auto v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        col[i] = -1,vis[i] = 0;
        g[i].clear();
    }

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout<<"NO\n";
            return;
        }
        if(col[i])ans.push_back(i);
    }
    cout<<"YES\n";
    cout<<sz(ans)<<'\n';
    print(ans);
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

