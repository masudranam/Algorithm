#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<pair<int,int>> g[N];
bool ok[N];

struct Node{
    int w, node, h;
    bool operator > (const Node &a)const{
        return w > a.w;
    }
};

void djkstra(int src, vector<vector<int>> &d){
    d[src][0] = 0;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({0, src, 0});
    while(!pq.empty()){
        Node cur = pq.top();
        pq.pop();
        
        if(d[cur.node][cur.h] != cur.w){
            continue;
        }
        if(ok[cur.node]) cur.h = 1;

        for(auto it : g[cur.node]){
            int val = cur.w;
            if(cur.h) val += it.second / 2;
            else val += it.second;
            if(val < d[it.first][cur.h]){
                d[it.first][cur.h] = val;
                pq.push({val, it.first, cur.h});
            }
        }
    }
}

void solve(){
    int n, m, h;
    cin >> n >> m >> h;
    for(int i = 1; i <= n; i++){
        g[i].clear();
        ok[i] = 0;
    }
    for(int i = 1; i <= h; i++){
        int x; cin >> x;
        ok[x] = 1;
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    vector<vector<int>> d1(n + 1, vector<int>(2, M * N));
    vector<vector<int>> d2 = d1;

    djkstra(1, d1); djkstra(n, d2);
    int res = M * N;
    for(int i = 1; i <= n; i++){
        res = min(res, max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1])));
    }
  

    if(res == N * M)cout << - 1 << '\n';
    else cout << res << '\n';
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
