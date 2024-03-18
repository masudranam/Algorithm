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

vector<int>  g[N];
int n,m,a,b,c;

vector<int> bfs(int x){
    vector<int> d(n+1),vis(n+1);
    d[x] = 0, vis[x] = 1;
    queue<int> q; q.push(x);
    while(sz(q)){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(!vis[v]){
                d[v] = d[u]+1;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return d;
}

void solve(){
    cin >> n >> m >> a >> b >> c;

    vector<int> p(m),ps(4*m);
    for(int i = 0; i <= n; i++)g[i].clear();

    for(int i = 0; i < m; i++){
        cin >> p[i];
    }
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    sort(all(p));

    for(int i = 0; i < m; i++){
        ps[i+1] = ps[i]+p[i];
    }


    vector<int> ax = bfs(a), bx = bfs(b), cx = bfs(c);
    int ans = M*M;

    for(int i = 1; i <= n; i++){
        int tot = ax[i] + bx[i] + cx[i];
        //cout<<i<<' '<<tot<<' '<<bx[i]<<endl;
        if(tot <= m)
        ans = min(ans,ps[tot] + ps[bx[i]]);
    }
    cout<<ans<<endl;

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

