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
const int N = 3e5 + 10;
const int p1 = 311, p2 = 313;

int p[N], a[N],cnt[N],c[N],h[N],h1[N];
set<pair<int,int>> st[N];
vector<int> g[N];


int get(int x){
    if(p[x] == x)return x;
    return p[x] = get(p[x]);
}

void Merge(int a, int b){
    a = get(a), b = get(b);
    if(a == b) return;
    if(sz(st[a]) < sz(st[b]))swap(a,b);
    for(auto x: st[b]){
        st[a].insert(x);
    }
    st[b].clear();
    p[b] = a;
}

void dfs(int u, int par){
    h[u] = (h[par]*p1 + a[u])%M;
    h1[u] = (h1[par]*p2 + a[u])%M;
    st[u].insert({h[u],h1[u]});

    for(auto v: g[u]){
        if(v == par)continue;
        dfs(v,u);
        Merge(u,v);
    }
    cnt[u] = sz(st[get(u)]);
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    string s; cin >> s;
    for(int i = 0; i < n; i++){
        a[i+1] = (s[i]-'a'+1);
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i <= n; i++){
        p[i] = i;
    }

    dfs(1,0);
    int mx = 0, ans = 0;

    for(int i = 1; i <= n; i++){
        if(cnt[i]+c[i] > mx)mx = cnt[i]+c[i],ans = 1;
        else if(mx == cnt[i]+c[i])ans++;
    }

    cout<<mx<<endl;
    cout<<ans<<endl;
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

