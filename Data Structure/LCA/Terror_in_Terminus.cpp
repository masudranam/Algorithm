#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int anc[N][25],d[N];
vector<int>g[N];

void dfs(int u=0,int p=-1){
anc[u][0]=p;
for(int i=1;i<19;i++)
    anc[u][i]=~anc[u][i-1]?anc[anc[u][i-1]][i-1]:-1;
for(int v:g[u]){
    if(v==p)continue;
    d[v]=d[u]+1;
    dfs(v,u);
}
}
int lca(int u,int v){
if(d[u]<d[v])
    swap(u,v);
for(int i=18;~i;i--)
    if(d[u]-(1<<i)>=d[v])
    u=anc[u][i];
if(u==v)
    return u;
for(int i=18;~i;i--)
    if(anc[u][i]^anc[v][i])
    u=anc[u][i],v=anc[v][i];
return anc[u][0];
}

int dia(int u, int v){
    return d[u]+d[v]-2*d[lca(u,v)];
}

int kth(int u, int k) {
    
    for (int i = 18; k > 0 && u != -1; i--) {
        
        if (k & (1 << i)) {
            u = anc[u][i]; 
            k -= (1<<i);  
        }
    }
    return u; 
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i <= n; i++){
        g[i].clear(); d[i] = 0;
    }

    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);

    int q; cin >> q;
    

    while(q--){
        int u, v; cin >> u >> v;
        u--, v--;
        int x = lca(u, v);
        int d = dia(u,v);
        //cout <<'('<<u<<","<<v<<") "<< x <<' ' << d <<'\n';

        if(d <= 1){
            cout << u + 1 << '\n';
            continue;
        }

        if(dia(u, x) >= d / 2){
            cout << kth(u, d/2) + 1 << '\n';
        }else{
            cout << kth(v, (d + 1) / 2) + 1 << '\n';
        }
    }

}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
