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

vector<ar<int,2>>g[N];
int col[N],res[N];
bool ok;

void dfs(int u){
    col[u] = 1;
    for(auto v: g[u]){
        if(col[v[0]] == 0){
            dfs(v[0]);
            res[v[1]] = 1;
        }else if(col[v[0]] == 2){
            res[v[1]] = 1;
        }else{
            res[v[1]] = 2;
            ok = true;
        }
    }
    col[u] = 2;
}

void solve(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u].push_back({v,i});
    }

    for(int i = 1; i<= n; i++){
        if(col[i] == 0){
            dfs(i);
        }
    }

    if(!ok){
        cout<<1<<endl;
        for(int i = 0; i < m; i++)cout<<1<<' ';
        cout<<endl;return;
    }
    cout<<2<<endl;
    for(int i = 0; i< m; i++){
        cout<<res[i]<<' ';
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

