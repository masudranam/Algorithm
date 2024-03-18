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
const int N = 1e5 + 10;

vector<int> g[N];
int lpf[N],vis[N],vis1[N],a[N];
vector<int>pfs;

void sieve() {
    for(int i=2; i<N; i++) {
        if(!lpf[i]) {
            pfs.push_back(i);
            lpf[i]=i;
        }
        for(int j=0; j<pfs.size() && pfs[j]<=lpf[i]&& i*pfs[j]<N; j++) {
            lpf[i*pfs[j]]=pfs[j];
        }
    }
}

void dfs(int u){
    vis[u] = 1;
    int x = a[u];
    vector<int> p;
    while(x > 1){
        int y = lpf[x];
        p.push_back(y);
        while(x % y == 0) x /= y;
    }
    for(auto y: p){
        if(vis1[y])continue;
        vis1[y] = 1;
        for(auto v: g[y]){
            if(!vis[v])dfs(v);
        }
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int x = a[i];
        while(x > 1){
            int y = lpf[x];
            g[y].push_back(i);
            while(x % y == 0)x/=y,a[i]/=y;
            a[i] *= y;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i])dfs(i),ans++;
    }
    cout<<ans<<endl;

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);
sieve();
   int t = 1; //  cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

