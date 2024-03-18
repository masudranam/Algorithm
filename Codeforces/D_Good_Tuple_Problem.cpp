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

vector<int> g[N];
int vis[N],col[N];

void dfs(int u, int p){
    vis[u] = 1;
    col[u] = p;
    for(auto v: g[u]){
        if(vis[v]){
            if(col[v] == p){
                //cout<<u<<" "<<v<<endl;
                cout<<"No\n";
                exit(0);
            }
        }else{
            dfs(v,p^1);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    
    int u[m], v[m];

    for(auto &x: u)cin >> x;
    for(auto &x: v)cin >> x;

    for(int i = 0;i < m; i++){
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i])dfs(i,0);
    }
    cout<<"Yes\n";
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}

