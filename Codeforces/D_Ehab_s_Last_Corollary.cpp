#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
#define int   long long int
#define endl '\n'
#define ar array
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m, k;

vector<int> g[N],col[2];
int d[N],par[N],vis[N];


void dfs(int u,int p = 0){
    vis[u] = 1;
    d[u] = d[p]+1;
    par[u] = p;
    int mn = M,en;
    for(int v: g[u]){
        if(!vis[v]){
            dfs(v,u);
        }else{
            int dist = d[u]-d[v]+1;
            if(dist >= 3 && dist < mn){
                mn = dist;
                en = u;
            }
        }
    }
    if(mn < M){
        vector<int> ans;
        while(mn--){
            ans.push_back(en);
            en = par[en];
        }
        if(sz(ans) <= k){
            cout<<2<<'\n'<<sz(ans)<<endl;
            print(ans);
        }else{
            cout<<1<<'\n';

            for(int i = 0 ,j = (k+1)/2; i < sz(ans) && j--; i += 2){
                cout<<ans[i]<<' ';
            }
        }
        exit(0);
    }
}

void dfs1(int u, int p = 0, int c = 0){
    col[c].push_back(u);
    vis[u] = 1;
    for(auto v: g[u]){
        if(!vis[v])
        dfs1(v,u,c^1);
    }
}

void solve(){
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int src = rnd()%n+1;
    dfs(src);
    for(int i = 0; i <= n; i++)vis[i] = 0;
    dfs1(src);
    
    cout<<1<<endl;
    if(sz(col[0]) >= (k+1)/2){
        for(int i = 0;i < (k+1)/2; i++){
            cout<<col[0][i]<<' ';
        }
    }else{
        assert(sz(col[1]) >= (k+1)/2);
        for(int i = 0; i < (k+1)/2; i++){
            cout<<col[1][i]<<' ';
        }
    }

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

