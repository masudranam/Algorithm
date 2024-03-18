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
int vis[N];

void dfs(int u){
    vis[u] = 1;
    for(auto v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve(){
    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }  

    if(m != n-1){
        cout<<"NO\n";
        return;
    }  

    dfs(1);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

