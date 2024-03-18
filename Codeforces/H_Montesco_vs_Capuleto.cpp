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
int vis[N],col[N],vis1[N];

vector<int> v;

int cnt,tot;

void dfs(int u){
    vis1[u] = 1;
    for(auto v: g[u]){
        if(!vis1[v])dfs(v);
    }
}

bool Bipart(int u,int c=0){
 col[u]=c;
 vis[u] = 1;
 tot++,cnt+=c==1;
 for(auto v:g[u]){
    if(!vis[v]){
        if(!Bipart(v,c^1))return false;
    }else if(col[v]==col[u])return false;
 }
 return true;
}

void solve(){

    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
        vis[i] = 0;
        vis1[i] = 0;
        col[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        int m; cin >> m;
        while(m--){
            int u;
            cin >> u;
            if(u > n)continue;
            g[u].insert(i);
            g[i].insert(u);
        }
    }
    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(!vis1[i]){
            dfs(i);
            cnt=0,tot=0;
            if(Bipart(i)){
               ans += max(cnt,tot-cnt);
            }
        }
    }
    cout << ans << endl;

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

