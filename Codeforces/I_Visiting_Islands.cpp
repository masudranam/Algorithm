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

int vis[N];
vector<int> g[N];
int cnt;

ar<int,2> dfs(int u, int p){
    ar<int,2> ret={-1,u};
    vis[u] = 1;cnt++;
    if(sz(g[u])==1)ret[0]=0;
    for(auto v: g[u]){
        if(v==p)continue;
        ar<int,2> x=dfs(v,u);
        if(x[0]==-1)continue;
        if(x[0]+1>ret[0])ret[0]=x[0]+1,ret[1]=x[1];
    }
    return ret;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        g[i].clear();
        vis[i] = 0;
    }


    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ar<int,2>>v;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ar<int,2> x = dfs(i,0);
            cnt = 0;
            x = dfs(x[1],0);
            v.push_back({x[0],cnt});
        }
    }

    vector<int> ans(N+1,M*N);

    for(auto x : v){
        int len = x[0], tot = x[1];
        for(int i = 1; i <= tot; i++){
            if(len + 1 >= i ){
                ans[i] = i-1;
                continue;
            } 
            int extra = i - len -1;
            ans[i] = min(ans[i],2*extra + len);
        }
    }

    int q; cin >>q;
    while(q--){
        int k; cin >> k;
        if(ans[k] >= M)cout<<"impossible\n";
        else cout<<ans[k]<<endl;
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
    cout<<"Case "<<tc<<":\n";
      solve();
   }
   return 0;
}

