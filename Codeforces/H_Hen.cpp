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

int n, m;
vector<int> g[N],gr[N];
vector<int> vis,order,cmp;

void dfs1(int u){
   vis[u] = 1;
   for(auto v: g[u]){
      if(!vis[v])dfs1(v);
   }
   order.push_back(u);
}

void dfs2(int u){
   vis[u] = 1;
   cmp.push_back(u);
   for(auto v: gr[u]){
      if(!vis[v])dfs2(v);
   }
}

vector<int>root_nodes,cg[N];
int roots[N];

int val[N];

void CondensationGraph(){
   vis = vector<int>(n+1,0);
   for(int i = 1; i <= n; i++){
      if(!vis[i])dfs1(i);
   }

   reverse(all(order));
   vis = vector<int>(n+1,0);

   for(auto v: order){
      if(!vis[v]){
         cmp.clear();
         dfs2(v);
         int r = cmp.front();
         root_nodes.push_back(r);
         val[r] = sz(cmp);
         for(auto u: cmp)roots[u] = r;
      }
   }

   for(int u = 1; u <= n; u++){
      for(auto v: g[u]){
         int y = roots[v];
         int x = roots[u];
         if(x != y){
            cg[x].push_back(y);
         }
      }
   }
}

int cnt;
void dfs(int u){
   vis[u] = 1;
   cnt += val[u];
   for(auto v: cg[u]){
      if(!vis[v])dfs(v);
   }
}


void solve(){
   cin >> n >> m;

   for(int i = 0; i < m; i++){
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      gr[v].push_back(u);
   }

   CondensationGraph();
   int ans = 0;

   for(int i = 0; i < sz(root_nodes); i++){
      for(auto x: root_nodes){
      vis[x] = 0;
      }
      cnt = 0;
      dfs(root_nodes[i]);
      ans = max(ans,cnt);
   }

   cout<<ans<<endl;
}


signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
   // cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

