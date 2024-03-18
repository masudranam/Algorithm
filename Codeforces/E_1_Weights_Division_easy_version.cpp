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

vector<ar<int,2>> g[N];
int siz[N];

int d(int w, int cnt){
    return (w-(w/2))*cnt;
}
void dfs(int u, int p = 0){
    if(u != 1 && sz(g[u]) == 1)siz[u] = 1;
    for(auto v: g[u]){
        if(v[0] == p)continue;
        dfs(v[0],u);
        siz[u] += siz[v[0]];
    }
}
multiset<ar<int,3>> st;
int tot ;

void dfs1(int u, int p = 0){
    for(auto v: g[u]){
        if(v[0] == p)continue;
        dfs1(v[0],u);
        tot += v[1]*siz[v[0]];
        st.insert({d(v[1],siz[v[0]]),v[1]/2,siz[v[0]]});
    }
}


void solve(){
    int n, s;
    cin >> n >> s;
    for(int i = 0; i <= n; i++){
        g[i].clear();
        siz[i] = 0;
    }
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        int w; cin >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    st.clear();
    tot = 0;
    
    dfs(1);
    dfs1(1);
    int ans = 0;
    while(tot > s){
        ar<int,3> t = *st.rbegin();
        st.erase(--st.end());
        tot -= t[0];
        ans ++;
        st.insert({d(t[1],t[2]),t[1]/2,t[2]});
    }

    cout<<ans<<endl;
}

signed main() {
   ios_base::sync_with_stdio (0);
   cin.tie (0);

   int t = 1;   cin >> t;
   for (int tc = 1; tc <= t; tc++) {
      solve();
   }
   return 0;
}

