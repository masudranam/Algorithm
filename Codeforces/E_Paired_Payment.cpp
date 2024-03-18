#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<endl
#define all(a) (a).begin(),(a).end()
#define sz(a) (int)(a.size())
//#define int   long long int
#define endl '\n'
#define ar array
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<ar<int,2>>g[N],t[N];

vector<int> dijkstra(int src,int n) {
    vector<int>d(n+1,M);
    priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>>q;
    d[src]=0;
    q.push({0,src});
    while(q.size()) {
        array<int,2> u=q.top();
        q.pop();
        if(u[0]>d[u[1]])continue;
        for(array<int,2>v:g[u[1]]) {
            if(d[v[1]]>u[0]+v[0]) {
                d[v[1]]=u[0]+v[0];
                q.push({d[v[1]],v[1]});
            }
        }
    }
    return d;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        int w; cin >> w;
        t[u].push_back({w,v});
        t[v].push_back({w,u});
      
    }

    for(int i = 1; i <= n; i++){
        for(auto u: t[i]){
            for(auto v: t[u[1]]){
                int x = u[0]+v[0];
                g[i].push_back({x*x,v[1]});
            }
        }
    }

    vector<int> ans = dijkstra(1,n);

    for(int i = 1; i <= n; i++){
        if(ans[i] >= M)cout<<-1<<' ';
        else cout<<ans[i]<<' ';
    }

   
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

