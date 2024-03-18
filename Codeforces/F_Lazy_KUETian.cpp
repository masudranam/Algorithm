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
const int N = 2e3 + 10;
int n, m, k, s;

vector<ar<int,3>>g[N];

vector<int> dijkstra() {
    vector<int>d(N,M*M);
    priority_queue<ar<int,3>,vector<ar<int,3>>,greater<ar<int,3>>>q;
    d[s]=0;
    q.push({0,s,0});
    while(q.size()) {
        array<int,3> u=q.top();
        q.pop();
        if(u[0]>d[u[1]])continue;
        for(array<int,3>v:g[u[1]]) {
            if((d[v[1]]>u[0]+v[0]) && (u[2]+v[2] <= k)) {
                d[v[1]]=u[0]+v[0];
                q.push({d[v[1]],v[1],v[2]+u[2]});
            }
        }
    }
    return d;
}


void solve(){
    cin >> n >> m >> k >> s;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({w,v,0});
        g[v].push_back({2*w,u,1});
    }

    vector<int> d = dijkstra();
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(d[x] >= 10*M*N){
            cout<<-1<<endl;
        }else{
            cout<<d[x]<<endl;
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

