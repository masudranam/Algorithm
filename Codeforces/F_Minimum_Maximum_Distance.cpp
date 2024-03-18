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
    int n, k;
    cin >> n >> k;
    vector<int>vis(n);

    for(int i = 0; i < k; i++){
        int x; cin >> x;
        x--;
        vis[x] = 1;
    }

    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dis(n);
    auto bfs = [&](int s){
        queue<int> q;
        dis.assign(n,-1);
        dis[s] = 0;
        q.push(s);
        while(sz(q)){
            int u = q.front();
            q.pop();
            for(auto v: g[u]){
                if(dis[v] == -1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        int t = -1;
        for(int i = 0; i < n; i++){
            if(vis[i] && (t == -1 || dis[i] > dis[t])){
                t = i;
            }
        }
        return t;
    };

    int a = bfs(0);
    int b = bfs(a);
    vector<int> f = dis;
    bfs(b);

    for(int i = 0; i < n; i++){
        f[i] = max(f[i],dis[i]);
    }
    
    cout<<*min_element(all(f))<<endl;
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

