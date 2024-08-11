#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
map<int,int> cnt[N];
int a[N], ans;

void dfs(int u, int p){
    int mx = -1;
    for(auto v : g[u])if(v != p){
        dfs(v,u);
        if(mx == -1 || cnt[v].size() > cnt[mx].size()){
            mx = v;
        }
    }
    
    for(auto v : g[u]){
         if(v == p || v == mx)continue;
         for(auto it : cnt[v]){
           if(it.first != a[u]) ans += cnt[mx][it.first] * it.second;
            cnt[mx][it.first] += it.second;
         }
    }
    if(mx != -1)swap(cnt[u],cnt[mx]);
    ans += cnt[u][a[u]];
    cnt[u][a[u]] = 1;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();cnt[i].clear();
    }   
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    dfs(0,-1);
    cout << ans << '\n';
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