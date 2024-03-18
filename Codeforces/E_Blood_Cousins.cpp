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

int anc[N][20], cnt,siz[N];
vector<int>g[N];
vector<int> lvl[N];
int dep[N],mp[N];

void dfs(int u,int p,int d){

anc[u][0]=p;
lvl[d].push_back(++cnt);
mp[u] = cnt;
dep[u] = d;
siz[u] = 1;

for(int i=1;i<19;i++){
    if(anc[u][i-1] == 0){
        anc[u][i] = 0;
    }else{
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }
}
// anc[u][i]=~anc[u][i-1]?anc[anc[u][i-1]][i-1]:-1;
for(int v:g[u]){
    dfs(v,u,d+1);
    siz[u] += siz[v];
}
}

int kth(int u, int k){
    for(int i = 19; i >= 0; i--){
        if(k & (1<<i))u = anc[u][i];
    }
    return u;
}

void solve(){
    int n; cin >> n;
    vector<int> p(n+1);

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        if(p[i])g[p[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        if(!p[i])dfs(i,0,0);
    }

    cin >> n;

    while(n--){
        int v,k;
        cin >> v >> k;
        int u = kth(v,k);
        if(u == 0){
            cout << 0 <<' ';
            continue;
        }
        int l = mp[u], r = mp[u]+siz[u]-1;
        auto ans = upper_bound(all(lvl[dep[v]]),r)-lower_bound(all(lvl[dep[v]]),l);
        cout << ans - 1 <<' ';        
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

