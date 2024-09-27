#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int long long int

const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> g[N];
int a[N], b[N], n;
bool f;

void dfs(int u, int p, int x){
    if(x > M * N){
        f = 0;return;
    }
    for(auto v : g[u]){
        int y = x - a[v];
        y = max(0ll, y);
        dfs(v,u,x + y);
    }
    if(g[u].size() == 0){
        f &= (a[u] >= x);
    }
}

bool ok(int x){
    f = 1;
    dfs(1,0,max(0ll,x - a[1]));
    return f;
}


void solve(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear();
    }
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 2; i <= n; i++){
        int p; cin >> p;
        g[p].push_back(i);
    }

    int l = 0, r = M * N;
    
    while(r - l > 0){
        int m = (l + r + 1) / 2;
        if(ok(m))l = m;
        else r = m - 1;
    }
    cout << l << '\n';
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