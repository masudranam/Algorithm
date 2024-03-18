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
const int N = 4e5 + 10;

vector<int> g[N];
int in[N],out[N],timer;

void dfs(int u, int p = -1){
    in[u] = timer++;
    for(auto v: g[u]){
        if(p == v)continue;
        dfs(v,u);
    }
    out[u] = timer;
}

int st[4*N],lazy[4*N];
int n, m;


void push(int i, int s, int e){
    if(!lazy[i])return;
    st[i] = lazy[i];
    if(s^e)
    lazy[2*i] = lazy[2*i+1] = lazy[i];
    lazy[i] = 0;
}

void upd(int i, int s, int e, int l, int r, int x){
    push(i,s,e);
    if(r<s || e<l)return;
    if(l<=s && e<=r){
        lazy[i] = (1ll<<x);
        push(i,s,e);
        return;
    }
    int m2 = (s+e)/2;
    upd(2*i,s,m2,l,r,x);
    upd(2*i+1,m2+1,e,l,r,x);
    st[i] = st[2*i]|st[2*i+1];
}

int qry(int i, int s, int e, int l, int r){
    push(i,s,e);
    if(r<s || e<l)return 0;
    if(l<=s && e <= r)return st[i];
    int m2 = (s+e)/2;
    return qry(2*i,s,m2,l,r)|qry(2*i+1,m2+1,e,l,r);
}


void solve(){
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v, u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);
    for(int i = 0; i < n; i++){
        cout<<in[i]<<' '<<out[i]<<endl;
    }
    for(int i = 0; i < n; i++){
        upd(1,0,n-1,in[i],in[i],a[i]);
    }

    while(m--){
        int t; cin >> t;
        if(t == 1){
            int v, x;
            cin >> v >> x, v--;
            upd(1,0,n-1,in[v],out[v]-1,x);
        }else{
            int v; cin >> v, v--;
            int x = qry(1,0,n-1,in[v],out[v]-1);
            cout<<__builtin_popcountll(x)<<endl;
        }
    }
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;  //cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

