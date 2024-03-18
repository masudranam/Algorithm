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
vector<int>order,vis;

void dfs(int u){
    vis[u] = 1;
    for(auto v: g[u]){
        if(!vis[v])dfs(v);
    }
    order.push_back(u);
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<ar<int,2>>edges;
    for(int i = 1; i <= n;i ++){
        g[i].clear();
    }
    for(int i = 0; i < m; i++){
        int t; cin >> t;
        int u, v; cin >> u >> v;
        if(t == 1)g[u].push_back(v);
        edges.push_back({u,v});
    }

    vis.assign(n+1,0);
    order.clear();

    for(int i = 1; i <= n; i++){
        if(!vis[i])dfs(i);
    }
    reverse(all(order));

    vector<int>pos(n+1);
    for(int i = 0; i < n; i++){
        pos[order[i]] = i;
    }

    for(int i = 1; i <= n; i++){
        for(auto x: g[i]){
            if(pos[x] < pos[i]){
                cout<<"NO\n";return;
            }
        }
    }
    cout<<"YES\n";

    for(auto x: edges){
        if(pos[x[0]] > pos[x[1]])cout<<x[1]<<' '<<x[0]<<endl;
        else cout<<x[0]<<' '<<x[1]<<endl;
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

