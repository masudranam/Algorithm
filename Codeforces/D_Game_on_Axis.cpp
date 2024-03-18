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
int vis[N],cnt = 0;

bool dfs(int u){
    vis[u] = 1;
    cnt++;
    for(auto v: g[u]){
        if(vis[v])return true;
        if(dfs(v))return true;
    }
    return false;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
        g[i].clear();
    }

    for(int u = 1; u <= n; u++){
        int v; cin >> v;
        v = v + u;
        if(v >=1 && v <= n){
            g[u].push_back(v);
        }
    }

    int bad = 0, ans = n*(2*n + 1);
    for(int i = 1; i <= n; i++){
        if(sz(g[i]) == 0){
            cnt = 0;
            if(dfs(i))bad += cnt;
        }
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i])bad++;
    }
    
    for(int i = 1; i <= n; i++)vis[i] = 0;
    cnt = 0;

    if(dfs(1)){
        ans -= cnt*cnt;
        ans -= cnt*(bad-cnt);
    }else{
        ans -= cnt*(cnt+1)/2;
    }

    cout<<ans<<endl;


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

