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
const int N = 5500 + 10;

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

int cnt = 1;
vector<int> a;

void dfs1(int u = 0, int p = -1){
  //  a[u] = cnt++;
    for(auto v: g[u]){
        if(v == p)continue;
        dfs1(v,u);
    }
    a[u] = cnt++;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int p; cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    a = vector<int>(n,-1);
    dfs1();

    set<int> st;
    for(int i = 0; i <= n; i++){
        st.insert(i);
    }

    dfs();

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int l = lca(i,j);
            if(i == l || j == l)continue;
            if(a[l] > a[i] && a[l] < a[j])ans++;
            else if(a[l] < a[i] && a[l] > a[j])ans++;
        }
    }
    cout << ans << endl;



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

