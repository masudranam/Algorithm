#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define int   long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
int deg[N],d[N],s[N],vis[N], k, n;


int get(int x){
    for(int i = 0; i <= n; i++){
        d[i] = deg[i];
        s[i] = 1;vis[i] = 0;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(d[i] == 1){
            q.push(i),d[i]--;vis[i] = 1;
        }
    }

    int cnt = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
      //  debug(u);debug(s[u]);

        if(s[u] >= x){
            s[u] = 0;
            cnt++;
        }
       
        for(auto v : g[u]){
            s[v] += s[u];
            if(vis[v])continue;
            d[v]--;
            
              
            if(d[v] == 1){
                q.push(v);
                vis[v] = 1;
            }
        }
       
    }

    return cnt > k;
}

void solve(){

    cin >> n >> k;
    for(int i = 0; i <= n; i++){
        deg[i] = 0;
        g[i].clear();
        deg[i] = 0;
        vis[i] = 0;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++,deg[v]++;
    
    }

    int l = 0, r = n;
    while(r-l>0){
        int m = (l+r+1)/2;
        if(get(m))l = m;
        else r = m-1;
    }

    if(l == 0)cout << -1 << endl;
    else cout << l << endl;

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

