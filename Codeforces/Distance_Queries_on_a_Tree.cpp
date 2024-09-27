#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x:a)cout<<x<<' ';cout<<'\n';
#define debug(x) cout<<#x<<" "<<x<<'\n'
#define int   long long int
 
const int M = 1e9 + 7;
const int N = 2e5 + 10;


int anc[N][25],d[N], in[N], out[N], dist[N], idx[N], a[N], timer;
vector<pair<int,int>>g[N];

void dfs(int u=0,int p=-1){
anc[u][0]=p;
in[u] = ++timer;
for(int i=1;i<19;i++)
    anc[u][i]=~anc[u][i-1]?anc[anc[u][i-1]][i-1]:-1;
for(auto it:g[u]){
    int v = it.first, w = it.second;
    if(v==p)continue;
    d[v]=d[u]+1;
    dist[v] = dist[u] + w;
    dfs(v,u);
}
out[u] = timer;
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


struct node {
    int mn,s,mx,lz;
    node(){
        mx = -M, mn = M, s = 0, lz = -1;
    }
};
struct ST {
    vector<node> t;  
    int n;
    ST(int _n){
        n = _n; t.assign(4*n + 10, node());
    }

    node Merge(node a, node b){
        node res;
        res.s = a.s + b.s;
        return res;
    }

    void upd(int L,int x,int i,int l,int r) {
        if(l > L || r < L)return;
        if(l==r) {
            t[i].s += x;
            return;
        }
        int m = (l+r)/2;
        if(L <= m) upd(L, x, 2*i, l, m);
        else upd(L, x, 2*i+1, m+1, r);
        t[i] = Merge(t[2*i], t[2*i+1]);
    }
    void upd(int l, int val){
        upd(l,val,1,1,n);
    }

    node qry(int L,int R,int i,int l,int r) {
        if(l >= L && r <= R) return t[i];
        if(l > R || r < L)return node();
        int m=(l+r)/2;

        node left , right;
        if(L <= m)left = qry(L, R, 2*i, l, m);
        if(m < R)right = qry(L, R, 2*i+1, m+1, r);
        return Merge(left, right);
    }
    node qry(int l, int r){
        return qry(l,r,1,1,n);
    }  
};

struct edge{
    int u, v, w;
};

void solve(){
    int n; cin >> n;
    vector<edge> e(n);
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1);
    for (int i=1; i<=n; i++) idx[in[i]] = i;
    for (int i=1; i<=n; i++) a[i] = dist[idx[i]] - dist[idx[i-1]];

    ST st(n);
    for(int i = 1; i <= n; i++){
        st.upd(i, a[i]);
    }

    for(int i = 1; i <= n; i++){
        cout << st.qry(1, i).s << '\n';
    }

    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int i, x; cin >> i >> x;
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if(anc[u][0] == v)swap(u, v);
            st.upd(in[v],x - w);
            st.upd(out[v] + 1, w - x);
            e[i].w = x;
        }else{
            int u, v; cin >> u >> v;
            int k = lca(u, v);
            cout << st.qry(1, in[u]).s + st.qry(1, in[v]).s - 2 * st.qry(1, in[k]).s << '\n';
        }
    }
     
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1; 
   //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      //cout<<"Case "<<tc<<": ";
      solve();
   }
   return 0;
}
