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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> g[n+1],x(n+1),y(n+1);
    vector<int> sf(n+2), pf(n+2);
    pair<int,int> d[n+1];

    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
        d[i] = {x[i]-y[i], i};
    }

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    sort(d+1, d+n+1);
    for(int i = 1; i <= n; i++){
        pf[i] = pf[i-1] + x[d[i].second];
    }
    for(int i = n; i >= 1; i--){
        sf[i] = sf[i+1] + y[d[i].second];
    }

    int ans[n+1];

    for(int i = 1; i <= n; i++){
        int u = d[i].second;
        int res = pf[i-1] + sf[i+1] + (n-i)*x[u] + (i-1)*y[u];
        for(auto v : g[u]){
            res -= min(x[u]+y[v],x[v]+y[u]);
        }
        ans[u] = res;
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i] <<" \n"[i==n];
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

