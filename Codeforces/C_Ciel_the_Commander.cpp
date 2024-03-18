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

set<int> g[N];
int siz[N];

int get_sz(int u, int p){
    siz[u] = 1;
    for(auto v: g[u]){
        if(v == p)continue;
        get_sz(v,u);
        siz[u] += siz[v];
    }
    return siz[u];
}

int Centroid(int u, int p, int n){
    for(auto v: g[u]){
        if(p == v)continue;
        if(siz[v] > n/2)return Centroid(v,u,n);
    }
    return u;
}
vector<char>ans(N);

void dfs(int u, int p = -1, int d = 0){
    int n = get_sz(u,p);
    int centroid = Centroid(u,p,n);
    ans[centroid] = ('A'+d);
    for(auto v: g[centroid]){
        g[v].erase(centroid);
        dfs(v,centroid,d+1);
    }
}


void solve(){
    int n; cin >> n;

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    dfs(1);

    for(int i = 1; i <= n; i++)cout << ans[i] <<' ';

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

