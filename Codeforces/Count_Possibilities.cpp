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
int ans[N],siz[N];
int n;

void dfs(int u, int lvl){
    siz[u] = 1;
    for(auto v: g[u]){
        dfs(v,lvl+1);
        siz[u] += siz[v];
    }
    int l = lvl, r = n-siz[u]+2;
    ans[l]++,ans[r]--;
}

void solve(){
    cin >> n;
    for(int i = 0; i <= n+5; i++){
        g[i].clear();
        siz[i] = ans[i] = 0;
    }

    int root ;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        if(i == 1)root = u;
    }
    dfs(root,1);

    for(int i = 1; i <= n; i++){
        ans[i] += ans[i-1];
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

