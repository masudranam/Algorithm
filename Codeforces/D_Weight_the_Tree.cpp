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
const int N = 2e5;

vector<int> g[N];
pair<int,int> dp[N][2];
int good[N];

pair<int,int> dfs(int u, int f, int p){

    pair<int,int> &res = dp[u][f];
    if(res.first >= 0) return res;
    res = {f, f ? -sz(g[u]) : -1};

    for(auto v : g[u]){
        if(p != v){
            pair<int,int> mx = dfs(v,0,u);
            if(f == 0) mx = max(mx, dfs(v,1,u));
            res.first += mx.first;
            res.second += mx.second;
        }
    }
    return res;
}

void get(pair<int,int> cur, int u, int p){
    if(cur == dfs(u,0,p)){
        good[u] = 0;
        for(auto v : g[u]){
            if(v != p){
                get(max(dfs(v,0,u),dfs(v,1,u)),v,u);
            }
        }
    }else{
        good[u] = 1;
        for(auto v : g[u]){
            if(v != p){
                get(dfs(v,0,u),v,u);
            }
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
        dp[i][0] = dp[i][1] = {-1,-1};
        good[i] = 0;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(n == 2){
        cout << 2 <<' '<< 2 << endl;
        cout <<"1 1\n";
        return;
    }

    pair<int,int> res = max(dfs(1,0,0),dfs(1,1,0));

    cout << res.first <<' '<< -res.second << endl;

    get(res,1,0);

    for(int i = 1; i <= n; i++){
        if(good[i]) cout << sz(g[i]) <<' ';
        else cout << 1 <<' ';
    }
    cout << endl;
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

