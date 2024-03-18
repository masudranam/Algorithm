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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int > g[n+1], vis(n+1), ans;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cur = 1;
    vis[1] = 1;
    ans.push_back(1);

    while(true){
        for(auto v : g[cur]){
            if(!vis[v]){
                cur = v;
                ans.push_back(v);
                vis[cur] = sz(ans);
                break;
            }
            if(vis[cur] - vis[v]>= k){
                cout << vis[cur] - vis[v] + 1<< endl;
                for(int i = vis[v]-1; i < vis[cur]; i++){
                    cout << ans[i] <<' ';
                }
                cout << endl; return;
            }
        }
    }
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

