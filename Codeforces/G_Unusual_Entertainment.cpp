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
const int N = 2e5+ 10;

vector<int> g[N];
vector<ar<int,3>> q[N];
set<int> st[N];
vector<string> ans;
int p[N];

int get(int x){
    if(p[x] == x)return x;
    return p[x] = get(p[x]);
}

void Merge(int a, int b){
    a = get(a), b = get(b);
    if(a == b)return;
    if(sz(st[a]) < sz(st[b]))swap(a,b);
    for(auto x: st[b]){
        st[a].insert(x);
    }
    st[b].clear();
    p[b] = a;
}

void dfs(int u, int par = -1){
    for(auto v: g[u]){
        if(par == v)continue;
        dfs(v,u);
        Merge(v,u);
    }
    int root = get(u);
    for(auto x : q[u]){
        int l = x[0], r = x[1], id = x[2];
       // cout<<u<<" "<<l <<' '<<r<<endl;
        auto it = st[root].lower_bound(l);
        if(it != st[root].end() && *it <= r){
            ans[id] = "YES";
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    for(int i = 0; i <= n; i++){
        g[i].clear();
        q[i].clear();
        st[i].clear();
        p[i] = i;
    }

    for(int i = 1; i < n; i++){
        int u, v; 
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
       
    }

    for(int i = 0;i < n; i++){
        int x; cin >> x;
        st[x-1].insert(i);
    }

    for(int i = 0; i < k; i++){
        int l, r, x;
        cin >> l >> r >> x;
        l--,r--,x--;
        q[x].push_back({l,r,i});
    }
    ans = vector<string>(k,"NO");

    dfs(0);

    for(int i = 0; i < k; i++){
        cout << ans[i] <<endl;
    }
    cout<<endl;
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

