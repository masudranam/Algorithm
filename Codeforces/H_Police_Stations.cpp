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
const int N = 3e5 + 10;

vector<ar<int,2>> g[N];
int vis[N];

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    queue<ar<int,2>> q;
    for(int i = 0; i < m; i++){
        int p; cin >> p;
        q.push({p,p});
        vis[p] = 1;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    set<int> ans;
    vector<int> vis1(n+1);

    while(sz(q)){
        ar<int,2> u = q.front();
        q.pop();
        for(auto v : g[u[0]]){
            if(vis1[v[1]])continue;

            if(!vis[v[0]]){
                q.push({v[0],u[0]});
                vis1[v[1]] = 1;
                vis[v[0]] = 1;
            }else{
                ans.insert(v[1]);
                vis1[v[1]] = 1;
            }
        }
    }

    cout << sz(ans) << endl;
    print(ans);

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  // cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

