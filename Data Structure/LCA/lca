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
const int N = 2e5 + 100;

vector<int>g[N];
int anc[N][26], d[N];

void dfs (int u, int p = -1) {
   anc[u][0] = p;
   for (int i = 1; i < 19; i++)
      anc[u][i] = ~anc[u][i - 1] ? anc[anc[u][i - 1]][i - 1] : -1;
   for (int v : g[u]) {
      if (v == p) continue;
      d[v] = d[u] + 1;
      dfs (v, u);
   }
}

int lca (int u, int v) {
   if (d[u] < d[v])
      swap (u, v);
   for (int i = 18; ~i; i--)
      if (d[u] - (1 << i) >= d[v])
         u = anc[u][i];
   if (u == v)
      return u;
   for (int i = 18; ~i; i--)
      if (anc[u][i]^anc[v][i])
         u = anc[u][i], v = anc[v][i];
   return anc[u][0];
}

void solve() {

}


signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout << "Case " << tc << ": ";
      solve();
   }
   return 0;
}
